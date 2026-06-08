// =============================================================================
// AdjustViewInverse.cpp
//
// HMD pose application and view matrix pipeline.
//
// OVERVIEW
// --------
// This file contains two exported functions:
//
//   RVR_AdjustViewInverse  -- applies HMD rotation to the engine view matrix
//                             and writes the result to g_RVRData for rendering
//
//   RVR_TrackProj          -- writes an HMD-corrected projection matrix to
//                             g_fRVRGameProj in the proxy DLL
//
// ADJUST VIEW INVERSE -- DETAILED FLOW
// --------------------------------------
// Reconstructed from RE of the ViewInverse handler at RVA 0x3970 in the
// original ASI:
//
// 1. Read HMD pose from g_RVRData:
//      slot = frameIndex & 3
//      base = (uint8_t*)g_RVRData + slot * 0x1C + 0x77C
//      hmdPitch = base[0]  (radians)
//      hmdYaw   = base[4]  (radians)
//      hmdRoll  = base[8]  (radians)
//      headOffX = base[12] (meters, for position tracking)
//    These values are written by the proxy DLL after each WaitGetPoses call.
//
// 2. Build a 3x3 rotation matrix from the HMD Euler angles.
//    Rotation order: Ry(yaw) * Rx(pitch) * Rz(roll)  (YXZ convention).
//    This is the convention used by the original ASI for the FPS camera.
//
// 3. Compute: finalView = hmdRot * gameView
//    Only the 3x3 rotation block is transformed. The translation row is
//    passed through from the engine's view matrix.
//
// 4. Apply head offset along the right axis (row 0) if position tracking
//    is enabled and the camera is in first-person foot mode.
//
// 5. Write the result to g_RVRData for the render DLL:
//      slot = frameIndex & 3
//      [g_RVRData + slot * 256 + 0x890] = row-major float[16]
//      [g_RVRData + slot * 256 + 0x910] = column-major (transposed) float[16]
//    The row-major copy is read by the engine; the column-major copy is
//    used by the HLSL shaders in the proxy DLL.
//
// 6. Store one entry in the local ring-buffer (s_poseRing) so the script
//    thread can read the current HMD yaw/pitch without accessing g_RVRData.
//
// TRACK PROJ -- DETAILED FLOW
// ----------------------------
// Writes a standard asymmetric perspective projection matrix to
// g_fRVRGameProj (a float[16] inside the proxy DLL):
//
//   P[0][0] = 2 / (right - left)
//   P[1][1] = 2 / (top - bottom)
//   P[2][0] = (right + left) / (right - left)   off-axis X
//   P[2][1] = (top + bottom) / (top - bottom)   off-axis Y
//   P[2][2] = -far / (far - near)
//   P[2][3] = -1
//   P[3][2] = -far * near / (far - near)
//
// The proxy DLL reads this matrix each frame to project the scene into the
// HMD with the correct field of view.
//
// KNOWN ISSUES / TODO
// --------------------
// - Pose read offsets (0x77C, stride 0x1C) are specific to DLL version r7.
//   If a runtime update changes the DLL layout, these offsets must be updated.
//   The log line "AdjustViewInverse() fixed the gameplay camera to {yaw=X}"
//   will show all zeros if the read offsets are wrong.
//
// - The view matrix write offsets (0x890, 0x910) are likewise version-specific.
//   If the VR image appears but is not oriented correctly, these are the
//   first offsets to verify.
//
// - The projection matrix currently uses symmetric tangents (50 degrees on
//   each side). The actual HMD uses asymmetric tangents for each eye. The
//   correct values should be read from RVRGetFrameDesc once its output
//   format is reversed.
//
// - The local ring-buffer (s_poseRing) has 4 slots matching the frame slot
//   count. RVR_ClearPoseRing() is called once per ViewInverse invocation;
//   the ring count is reset to 0 and then incremented to 1 on write.
//   Multiple ViewInverse calls per frame (e.g. stereo left/right) will
//   overwrite slot 0 -- only the last pose is retained. This is correct
//   behavior for single-eye heading control.
// =============================================================================

#include "RVRTypes.h"
#include "RVRFileLog.h"
#include <cmath>
#include <cstring>
#include <xmmintrin.h>

// Live HMD orientation quaternion, published by the script thread (RealVR.cpp).
extern "C" float g_hmdQuat[4];
extern "C" int   g_headTrackOn;   // 0 = pass-through view, 1 = apply HMD quat
extern "C" int   g_htMode;        // quaternion convention selector (cycled with 'J')

// Ring-buffer: local copy of the processed view matrix for the script thread.
static RVRPoseSlot s_poseRing[4];
static int         s_poseCount = 0;

extern "C" RVRPoseSlot* RVR_GetPoseRing()  { return s_poseRing; }
extern "C" int          RVR_GetPoseCount() { return s_poseCount; }
extern "C" void         RVR_ClearPoseRing(){ s_poseCount = 0; }

// Dense render-thread sampling of the proxy capture-gate flags. AdjustViewInverse
// runs ~1944x/sec, so these counters reveal whether the capture ever fires during
// gameplay (the 2s script-thread heartbeat sampling was too coarse for per-frame
// transient flags). Read+reset from the script-thread heartbeat.
extern "C" volatile long g_e0SeenCount    = 0;  // times g_RVRData[0xE0] != 0
extern "C" volatile long g_sceneSeenCount = 0;  // times [0x36BDC8] != NULL
extern "C" volatile long g_aviCallCount   = 0;  // total AdjustViewInverse calls

// g_RVRData layout constants (proxy DLL r7) -- CORRECTED from RE of the
// original AdjustViewInverse (RVA 0x3F02): the view matrix output uses a
// per-slot stride of 64 bytes (shl rax,6), NOT 256, and is stored as four
// 16-byte row vectors at 0x890/0x8A0/0x8B0/0x8C0. There is NO column-major
// copy at 0x910 -- with a 64-byte stride, 0x910 is slot 2's row-major data,
// so the previous "column-major" write was corrupting another slot.
static const uint32_t POSE_IN_STRIDE  = 0x1C;   // 28 bytes per slot (imul 28, confirmed)
static const uint32_t POSE_IN_BASE    = 0x77C;  // byte offset to first pose slot
static const uint32_t POSE_OUT_STRIDE = 64;     // 64 bytes per slot (shl r9, 6)
static const uint32_t POSE_OUT_ROW    = 0x910;  // row-major view matrix output (proxy reads here)
static const uint32_t POSE_OUT_SLOTS  = 4;      // ring of 4 slots

static inline void Transpose4x4(const float* __restrict src, float* __restrict dst) {
    __m128 r0 = _mm_loadu_ps(src + 0);
    __m128 r1 = _mm_loadu_ps(src + 4);
    __m128 r2 = _mm_loadu_ps(src + 8);
    __m128 r3 = _mm_loadu_ps(src + 12);
    _MM_TRANSPOSE4_PS(r0, r1, r2, r3);
    _mm_storeu_ps(dst + 0,  r0);
    _mm_storeu_ps(dst + 4,  r1);
    _mm_storeu_ps(dst + 8,  r2);
    _mm_storeu_ps(dst + 12, r3);
}

extern "C" void RVR_AdjustViewInverse(
    RVRMatrix44* gameView,
    RVRBridge*   bridge,
    uint32_t     frameIndex,
    float        headOffsetHint,
    bool         applyTrans,
    int          dominantEye)
{
    if (!gameView || !bridge) return;

    // ------------------------------------------------------------------
    // Step 1+2: Build the HMD rotation matrix from the live quaternion that the
    // script thread publishes (posePtr+0x00). g_RVRData+0x77C is unused (it is
    // never populated -- it reads as zero -- because that depends on a proxy
    // call we cannot make). The quaternion gives full head orientation.
    // ------------------------------------------------------------------
    float headOffset = headOffsetHint;

    // Pass the game view matrix through UNROTATED. Head-tracking is now done by
    // the proxy's reprojection (it reads the HMD quaternion the script thread
    // writes to g_RVRData+0x77C). Rotating the matrix here too would double-apply.
    // (g_htMode/K kept for future use; not applied in proxy-reprojection mode.)
    float qx = 0.f, qy = 0.f, qz = 0.f, qw = 1.f;
    (void)g_htMode;

    RVR_TRACE_ONCE("[RT] GameView read: r0=[%.3f %.3f %.3f] pos=[%.3f %.3f %.3f] quat=[%.3f %.3f %.3f %.3f]",
        gameView->at(0,0), gameView->at(0,1), gameView->at(0,2),
        gameView->at(3,0), gameView->at(3,1), gameView->at(3,2),
        qx, qy, qz, qw);

    // Quaternion -> 3x3 rotation matrix (row-major).
    // NOTE: axis convention OpenVR(Y-up,-Z-fwd) vs GTA may need sign tweaks;
    // start with the direct mapping and adjust signs based on observed behavior.
    const float xx=qx*qx, yy=qy*qy, zz=qz*qz;
    const float xy=qx*qy, xz=qx*qz, yz=qy*qz;
    const float wx=qw*qx, wy=qw*qy, wz=qw*qz;
    const float hmdRot[9] = {
        1.f-2.f*(yy+zz),  2.f*(xy-wz),     2.f*(xz+wy),
        2.f*(xy+wz),      1.f-2.f*(xx+zz), 2.f*(yz-wx),
        2.f*(xz-wy),      2.f*(yz+wx),     1.f-2.f*(xx+yy)
    };

    // ------------------------------------------------------------------
    // Step 3: result = hmdRot * gameView  (rotation rows only)
    // ------------------------------------------------------------------
    RVRMatrix44 result{};
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            result.at(row, col) =
                hmdRot[row*3+0] * gameView->at(0, col) +
                hmdRot[row*3+1] * gameView->at(1, col) +
                hmdRot[row*3+2] * gameView->at(2, col);
        }
        result.at(row, 3) = 0.f;
    }
    // Pass translation row through from the engine view.
    result.at(3, 0) = gameView->at(3, 0);
    result.at(3, 1) = gameView->at(3, 1);
    result.at(3, 2) = gameView->at(3, 2);
    result.at(3, 3) = 1.f;

    // ------------------------------------------------------------------
    // Step 4: Head offset (position tracking).
    // Translates the camera along its local right axis by the HMD's
    // lateral head displacement. Only applied in first-person on foot.
    // ------------------------------------------------------------------
    if (applyTrans && fabsf(headOffset) > 1e-6f) {
        result.at(3, 0) += headOffset * result.at(0, 0);
        result.at(3, 1) += headOffset * result.at(0, 1);
        result.at(3, 2) += headOffset * result.at(0, 2);
    }

    // ------------------------------------------------------------------
    // Step 5: Write the view matrix and projection to g_RVRData.
    //
    // RE of the original ASI binary (RVA 0x3EEB..0x41D6) revealed the exact
    // layout the proxy reads. Slot index = frameIndex & 3, stride = 64 bytes.
    //
    // Layout per slot (base = g_RVRData, s = slot = frameIndex & 3):
    //   base + s*64 + 0x890 : Eye-0 view matrix row 0..3  (float[16], row-major)
    //   base + s*64 + 0x910 : g_fRVRGameProj rows 0..3    (float[16])  <- copied verbatim
    //   base + s*64 + 0x990 : Eye-1 view matrix row 0..3  (float[16], row-major)
    //   base + s*64 + 0xA10 : Projection elements sign-flipped and copied from 0x910
    //                         (only X/Y/Z elements; W column is not touched)
    //
    // We write all 4 slots so the proxy never reads stale data regardless of
    // which slot its Present hook picks.
    // ------------------------------------------------------------------
    if (bridge->g_RVRData) {
        uint8_t* base = (uint8_t*)bridge->g_RVRData;

        // Dense capture-gate sampling (see globals above).
        ++g_aviCallCount;
        __try {
            if (*(volatile uint8_t*)(base + 0xE0) != 0) ++g_e0SeenCount;
            if (*(void* volatile*)(base - 0x1948) != nullptr) ++g_sceneSeenCount;
        } __except(EXCEPTION_EXECUTE_HANDLER) {}

        // NOTE: forcing g_RVRData[0xE0]=1 here FROZE THE WHOLE GAME -- proof that
        // [0xE0] is a per-draw toggle the proxy sets only around the main-scene
        // draw (set before, cleared after). Pinning it to 1 makes every draw enter
        // the capture path -> render thread saturates -> game stalls, and the
        // capture's end-phase never finalizes so [0x36BDC8] stays NULL. Do NOT
        // force it. The real fix is to make the proxy's own scene-begin fire
        // during gameplay (under investigation).

        // ---------------------------------------------------------------
        // FRAME COUNTER & SLOT CALCULATION (Lockstep with Proxy)
        // The proxy maintains its own frame counter at g_RVRData[0x34].
        // We read it, increment it by 1, and use it to determine the slot.
        // The original ASI does this exactly:
        //   mov edi, dword ptr [rdi+34h]
        //   inc edi
        //   ...
        //   imul rax, r9, 1Ch  (where r9 = edi & 3, except the original ASI
        //                       used a slightly different masking for r9,
        //                       but essentially used edi % 4).
        // ---------------------------------------------------------------
        uint32_t proxyCounter = *(volatile uint32_t*)(base + 0x34);
        uint32_t currentFrame = proxyCounter + 1;
        uint32_t slot = currentFrame % POSE_OUT_SLOTS;

        // Retrieve the HMD orientation for the current slot
        float* rawPose = (float*)(base + POSE_IN_BASE + (slot * POSE_IN_STRIDE));

        __try {
            const float halfIPD = 0.032f;  // ~64mm IPD / 2
            float rightX = result.at(0,0);
            float rightY = result.at(0,1);
            float rightZ = result.at(0,2);

            // Build the two eye matrices (left = slot 0/2, right = slot 1/3).
            float eyeMat[2][16];
            for (int eye = 0; eye < 2; ++eye) {
                memcpy(eyeMat[eye], result.m, 64);
                eyeMat[eye][3] = eyeMat[eye][7] = eyeMat[eye][11] = 0.f;
                eyeMat[eye][15] = 1.f;
                float sign = (eye == 0) ? -1.f : +1.f; // left=-IPD, right=+IPD
                eyeMat[eye][12] += sign * halfIPD * rightX;
                eyeMat[eye][13] += sign * halfIPD * rightY;
                eyeMat[eye][14] += sign * halfIPD * rightZ;
            }

            for (uint32_t s = 0; s < POSE_OUT_SLOTS; ++s) {
                int eye = (int)(s & 1u);  // even slots = left, odd slots = right
                uint8_t* slot = base + s * POSE_OUT_STRIDE;

                // 0x890: Eye view matrix (float[16])
                memcpy(slot + 0x890, eyeMat[eye], 64);
                // Zero the homogeneous column of the 3x3 rotation block + set [3][3]=1
                ((float*)(slot + 0x890))[3]  = 0.f;
                ((float*)(slot + 0x890))[7]  = 0.f;
                ((float*)(slot + 0x890))[11] = 0.f;
                ((float*)(slot + 0x890))[15] = 1.f;

                // 0x910: g_fRVRGameProj (float[16]) -- copied verbatim from proxy buffer
                if (bridge->g_fRVRGameProj) {
                    memcpy(slot + 0x910, bridge->g_fRVRGameProj, 64);
                    // Original ASI zeros the position column / sets W row as it would
                    // for a pure projection (no translation).
                    ((float*)(slot + 0x910))[12] = 0.f;
                    ((float*)(slot + 0x910))[13] = 0.f;
                    ((float*)(slot + 0x910))[14] = 0.f;
                    ((float*)(slot + 0x910))[15] = 1.f;
                }

                // 0x990: Second-eye view matrix (the opposite eye from 0x890)
                int eye2 = eye ^ 1;
                memcpy(slot + 0x990, eyeMat[eye2], 64);
                ((float*)(slot + 0x990))[3]  = 0.f;
                ((float*)(slot + 0x990))[7]  = 0.f;
                ((float*)(slot + 0x990))[11] = 0.f;
                ((float*)(slot + 0x990))[15] = 1.f;

                // 0xA10: Sign-flipped copy of XYZ from 0x910 (confirmed from disasm)
                // Only the first 3 floats of each row are copied (sign flipped).
                if (bridge->g_fRVRGameProj) {
                    float* src910 = (float*)(slot + 0x910);
                    float* dst_A10 = (float*)(slot + 0xA10);
                    // Row 0: flip X,Y,Z; leave W
                    dst_A10[0] = -src910[0]; dst_A10[1] = -src910[1];
                    dst_A10[2] = -src910[2]; dst_A10[3] = src910[3];
                    // Row 1 XYZ
                    dst_A10[4] = -src910[4]; dst_A10[5] = -src910[5];
                    dst_A10[6] = -src910[6]; dst_A10[7] = src910[7];
                    // Row 2 XYZ (reusing the src930 values from disasm)
                    dst_A10[8]  = src910[8];  dst_A10[9]  = src910[9];
                    dst_A10[10] = src910[10]; dst_A10[11] = src910[11];
                    // Row 3 from 0x920 in disasm
                    dst_A10[12] = src910[8];  dst_A10[13] = src910[9];
                    dst_A10[14] = src910[10]; dst_A10[15] = src910[11];
                }
            }
            (void)dominantEye;

            // ---------------------------------------------------------------
            // CRITICAL: Write the incremented counter to g_RVRData[0x3C].
            //
            // Confirmed from RE of the original ASI (RVA 0x41E3):
            //   mov dword ptr [r8+3Ch], edi
            // The proxy Present hook reads this value and only submits to the
            // HMD when it differs from the last submitted value.
            // By echoing the proxy's own counter + 1, we ensure perfect 1:1
            // AER sync without advancing 27 times per frame.
            // ---------------------------------------------------------------
            *(volatile uint32_t*)(base + 0x3C) = currentFrame;

            // ---------------------------------------------------------------
            // RENDER-THREAD SUBMIT (freeze fix).
            //
            // RE of the proxy (d3d11_disasm.txt, RVRGetFrameDesc core @0x86DF6):
            //   The per-frame path reads the captured scene-color resource from
            //   the proxy global at absolute 0x36BDC8 (= g_RVRData - 0x1948),
            //   uploads it to the HMD eye, then CLEARS it back to 0
            //   (mov [0x36BDC8], 0). That global is repopulated (non-NULL) by
            //   the proxy's draw-call interception ONLY on the render thread,
            //   once per rendered frame.
            //
            //   Our previous design called RVRGetFrameDesc (the consumer that
            //   clears that resource) from the SCRIPT thread in an independent
            //   72 Hz loop. That races the render thread: most of the time the
            //   resource is NULL when we consume it (-> nothing presented ->
            //   frozen image), and only occasionally (e.g. when paused and the
            //   render thread is idle) does a single capture survive long enough
            //   to be presented. That exactly matches the observed symptom.
            //
            //   The fix: perform the submit HERE, on the render thread, inside
            //   the ViewInverse hook, and ONLY when a fresh scene has actually
            //   been captured (resource pointer non-NULL). RVRGetFrameDesc then
            //   consumes the freshly-captured frame in lockstep with its
            //   producer. ViewInverse runs ~27x/frame; the first invocation
            //   after a capture consumes it and the proxy clears the pointer, so
            //   subsequent invocations in the same frame simply skip.
            // ---------------------------------------------------------------
            if (bridge->RVRGetFrameDesc) {
                void** sceneResSlot = (void**)(base - 0x1948); // abs 0x36BDC8
                if (*sceneResSlot != nullptr) {
                    static char s_descOut[256];
                    bridge->RVRGetFrameDesc(proxyCounter, s_descOut);
                }
            }

        } __except(EXCEPTION_EXECUTE_HANDLER) {
            RVR_LOG("RVR_AdjustViewInverse: exception writing g_RVRData");
        }
    }

    // ------------------------------------------------------------------
    // Step 6: Update local ring-buffer for the script thread.
    // ------------------------------------------------------------------
    if (s_poseCount < 4) {
        RVRPoseSlot& ps = s_poseRing[s_poseCount];
        memcpy(ps.row0, &result.at(0,0), 12); ps.row0[3] = 0.f;
        memcpy(ps.row1, &result.at(1,0), 12); ps.row1[3] = 0.f;
        memcpy(ps.row2, &result.at(2,0), 12); ps.row2[3] = 0.f;
        memcpy(ps.row3, &result.at(3,0), 12); ps.row3[3] = 1.f;
        ++s_poseCount;
    }

    if (s_poseCount == 1 && bridge->RVRLog) {
        float yaw   =  atan2f(result.at(0,2), result.at(2,2)) * 57.2957795f;
        float pitch = -asinf(fmaxf(-1.f, fminf(1.f, result.at(1,2)))) * 57.2957795f;
        float roll  =  atan2f(result.at(1,0), result.at(1,1)) * 57.2957795f;
        bridge->RVRLog(
            "AdjustViewInverse() fixed the gameplay camera to "
            "{yaw = %.2f, pitch = %.2f, roll = %.2f; "
            "pos = (%.3f, %.3f, %.3f)}[F] and set nextFrameIndex to %u\n",
            yaw, pitch, roll,
            result.at(3,0), result.at(3,1), result.at(3,2),
            frameIndex + 1);
    }
}

// =============================================================================
// RVR_TrackProj
// Writes a perspective projection matrix for the HMD to g_fRVRGameProj.
// Parameters:
//   zoom             = engine's cotangent(fovH/2), used only for logging
//   left/right       = horizontal frustum tangent limits
//   top/bottom       = vertical frustum tangent limits
//   nearP / farP     = near and far clip planes (meters)
// =============================================================================
extern "C" void RVR_TrackProj(
    RVRBridge* bridge,
    float zoom,
    float left,  float right,
    float top,   float bottom,
    float nearP, float farP)
{
    if (!bridge || !bridge->g_fRVRGameProj) return;

    float* P = bridge->g_fRVRGameProj;
    memset(P, 0, 16 * sizeof(float));

    float idx = 1.f / (right - left);
    float idy = 1.f / (top - bottom);
    float idz = 1.f / (farP - nearP);

    P[0]  = 2.f * idx;
    P[5]  = 2.f * idy;
    P[8]  = (right + left) * idx;
    P[9]  = (top + bottom) * idy;
    P[10] = -farP * idz;
    P[11] = -1.f;
    P[14] = -farP * nearP * idz;

    if (bridge->RVRLog)
        bridge->RVRLog("ProjFOV = %.4f Near = %.4f Far = %.4f\n",
            zoom, nearP, farP);
}
