// =============================================================================
// RealVR.cpp
//
// Main script thread, DllMain, keyboard handler, and per-frame VR logic.
//
// THREAD MODEL
// ------------
// GTA V with ScriptHookV runs script code in a dedicated script thread.
// The render thread runs concurrently and calls the engine functions that
// the patch sites intercept.
//
// Data flow between threads:
//
//   Script thread (this file)          Render thread (RVRHandlersCpp.cpp)
//   --------------------------         -----------------------------------
//   Calls GTA natives                  Calls engine render functions
//   Updates g_cachedCamType            Reads g_cachedCamType
//   Updates g_config                   Reads g_config
//   Calls RVRWaitAndTrackHMD(0x00)     ViewInverseHandler intercepts view matrix
//   Calls RVRGetPoseFrame              AdjustViewInverse writes g_RVRData
//   Reads ring-buffer (RVR_GetPoseRing)
//   Applies yaw/pitch to gameplay cam
//
// There is no mutex protecting g_cachedCamType or g_config reads. These
// are single-word reads/writes on x64 (naturally atomic for aligned data)
// and a torn read would only affect one frame's worth of VR orientation,
// which is visually negligible.
//
// INITIALIZATION SEQUENCE
// ------------------------
// Mirrors the sequence logged in the runtime session (2026-05-29 16:43:40):
//
//   1. RVRBridge::Resolve()     - find proxy d3d11.dll, resolve symbols
//   2. RVRConfig::Load()        - read RealVR.ini
//   3. RVR_CheckGameVersion()   - verify game version (expected 73)
//   4. FindAllPatches()         - pattern scan for 6 sites + 2 pools
//   5. ApplyPatches()           - write 16-byte trampolines
//   6. InitHandlers()           - create continuation stubs
//   7. Read g_RVRData[0]        - verify VR API type
//   8. RVRWaitAndTrackHMD(0x55) - initialize frame sequence
//
// Steps 5-6 are deferred to the first tracking tick if D3D is not yet
// initialized at the time RVR_Initialize() runs. The trampoline targets
// must be in executable memory before the render thread reaches the sites.
//
// PER-FRAME TRACKING TICK
// -----------------------
//   1. RVRWaitAndTrackHMD(0x00)    - signal frame start to DLL
//   2. RVRGetPoseFrame(buf, 0)     - get pointer to HMD pose struct
//   3. Read frameIndex from pose   - track slot rotation
//   4. DetectCameraType()          - classify CT_1ST_FOOT, CT_CUTSCENE, etc.
//   5. UpdateWorldRot()            - accumulate world-space HMD orientation
//   6. Read ring-buffer            - get yaw/pitch from AdjustViewInverse
//   7. SetGameplayCamRawYaw/Pitch  - inject HMD orientation into game camera
//   8. RVR_TrackProj()             - update HMD projection matrix
//   9. FoldWorldRotIntoRenderPose()- finalize pose for DLL render system
//
// WHAT COULD STILL BE IMPROVED
// ------------------------------
// - SetCamMetadataPitch: the original ASI used the camera metadata pool to
//   override pitch in specific cutscene scenarios. The pool pointer is
//   located but the struct layout is not confirmed. Not implemented.
//
// - DominantEye: the original ASI shifted the rendered image left or right
//   based on which eye is dominant (for aiming down sights). The direction
//   and magnitude of the shift have not been reversed from the binary.
//
// - CamParamsHandler: near/far plane override for VR comfort. The near/far
//   field offsets within pCamParams are not yet confirmed.
//
// - Full asymmetric HMD projection: RVRGetFrameDesc output format is not
//   yet reversed. Symmetric tangents from INI HMDFovDeg are used instead.
//
// IMPLEMENTED (previously pending)
// ---------------------------------
// - StereoInCutscenes mode 2: FoldWorldRotIntoRenderPose is skipped during
//   cutscenes when stereoInCutscenes == 2, leaving the proxy DLL with the
//   unmodified game view matrix for flat mono rendering.
//
// - Script hash dispatch: GetCurrentScriptHash() is called every frame and
//   mapped to ScriptCategory. SC_FLIGHT disables heading control; SC_MINIGAME
//   suppresses HMD FOV override.
//
// - ZoomOverride: modes 0-3 now gate whether RVR_TrackProj is called,
//   suppressing the HMD FOV in cutscenes / non-cutscenes / always.
//
// - HMDFovDeg: the 100-degree symmetric FOV is now read from INI instead of
//   being hardcoded, allowing per-headset tuning without recompiling.
// =============================================================================

#include "RVRTypes.h"
#include "PatternScanner.h"
#include "RVRPatches.h"
#include "ScriptHashes.h"
#include "RVRFileLog.h"
#include "RVRNatives.h"
#include "main.h"
#include "natives.h"
#include <cmath>
#include <cstring>

#ifdef _MSC_VER
  #define RVR_TRY       __try
  #define RVR_EXCEPT(x) __except(x)
#else
  #define RVR_TRY       if(true)
  #define RVR_EXCEPT(x) else
#endif

extern "C" RVRPoseSlot* RVR_GetPoseRing();
extern "C" int          RVR_GetPoseCount();
extern "C" void         RVR_ClearPoseRing();
extern "C" void         RVR_AdjustViewInverse(RVRMatrix44*,RVRBridge*,uint32_t,float,bool,int);
extern "C" volatile long g_e0SeenCount, g_i10SeenCount, g_i11SeenCount, g_sceneSeenCount;
extern "C" volatile long g_managerSeenCount, g_frameDescCalls, g_frameDescNoScene;
extern "C" volatile long g_df50SeenCount, g_d789SeenCount;
extern "C" volatile long g_frameDescErrors, g_managerGateTrue, g_managerGateFalse;
extern "C" volatile long g_managerGateErrors, g_aviCallCount;
extern "C" volatile long g_captureArmCount, g_captureArmSkipped;
extern "C" void         RVR_TrackProj(RVRBridge*,float,float,float,float,float,float,float);
void InitHandlers(const GamePointers& gp);
bool RVR_CheckGameVersion(RVRBridge&);

// =============================================================================
// Module globals
// =============================================================================
RVRBridge              g_bridge;
GamePointers           g_game;
RVRConfig              g_config;
bool                   g_vrActive    = true;
bool                   g_initialized = false;
uint32_t               g_frameSeq    = 0;
CameraType             g_cachedCamType = CT_OTHER;  // read by render thread
RVRHash::ScriptCategory g_cachedScriptCat = RVRHash::SC_NONE;

// Live HMD pose, read from the RVRGetPoseFrame buffer (posePtr+0x00) on the
// script thread and consumed by the render thread's AdjustViewInverse.
// Layout confirmed by RE: posePtr+0x00 = quaternion [x,y,z,w], +0x10 = position.
extern "C" float g_hmdQuat[4] = {0.f, 0.f, 0.f, 1.f};  // x, y, z, w
extern "C" float g_hmdPos[3]  = {0.f, 0.f, 0.f};       // x, y, z (meters)

// Frame-begin flag (0x00 stable / 0x55 full stereo cycle). Toggle with 'B'.
// Default 0x55 now that the 2-arg handshake no longer crashes.
static uint8_t g_frameBeginFlag = 0x55;

// Head-tracking on/off (toggle with 'H'). OFF by default: the view matrix is
// passed through unrotated (the known-working image). ON applies the HMD
// quaternion (may need axis tuning).
extern "C" int g_headTrackOn = 1;   // head-tracking ON by default (now relative-safe)
extern "C" int g_htMode = 0;   // quaternion convention (0-5), cycle with 'K'
extern "C" volatile long g_viewInverseCalls;  // defined in RVRHandlersCpp.cpp

// HMD recenter reference: the delta published to the render thread is relative
// to this captured orientation. Cleared on F11 so the next frame re-captures it.
static float g_hmdQuatRef[4] = {0.f, 0.f, 0.f, 1.f};
static bool  g_hmdRefSet     = false;

// Head yaw/pitch in degrees (from the relative HMD quaternion), used to drive
// the GAME camera via natives so the world rotates with the head.
static float g_headYawDeg   = 0.f;
static float g_headPitchDeg = 0.f;

static HMODULE g_hModule        = nullptr;
static bool    g_patchesApplied = false;

// World rotation state -- accumulated by UpdateWorldRot each frame.
static RVRQuat g_worldRot           = {0.f, 0.f, 0.f, 1.f};
static float   g_lastCutYaw         = 0.f;
static float   g_lastCutPitch       = 0.f;
static bool    g_cutsceneWasActive  = false;
static uint8_t g_poseOutBuf[256]    = {};

// =============================================================================
// Quaternion and matrix utilities
// =============================================================================
static RVRQuat QuatNormalize(const RVRQuat& q) {
    float len = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
    if (len < 1e-6f) return {0,0,0,1};
    float inv = 1.f/len;
    return {q.x*inv, q.y*inv, q.z*inv, q.w*inv};
}
static RVRQuat QuatFromAxisAngle(float ax, float ay, float az, float a) {
    float s = sinf(a*.5f), c = cosf(a*.5f);
    return QuatNormalize({ax*s, ay*s, az*s, c});
}
static RVRQuat QuatMul(const RVRQuat& a, const RVRQuat& b) {
    return {
        a.w*b.x+a.x*b.w+a.y*b.z-a.z*b.y,
        a.w*b.y-a.x*b.z+a.y*b.w+a.z*b.x,
        a.w*b.z+a.x*b.y-a.y*b.x+a.z*b.w,
        a.w*b.w-a.x*b.x-a.y*b.y-a.z*b.z
    };
}
static void QuatToMatrix3x3(const RVRQuat& q, float m[9]) {
    float x=q.x, y=q.y, z=q.z, w=q.w;
    m[0]=1-2*(y*y+z*z); m[1]=  2*(x*y-z*w); m[2]=  2*(x*z+y*w);
    m[3]=  2*(x*y+z*w); m[4]=1-2*(x*x+z*z); m[5]=  2*(y*z-x*w);
    m[6]=  2*(x*z-y*w); m[7]=  2*(y*z+x*w); m[8]=1-2*(x*x+y*y);
}
static float WrapAngle(float a) {
    while (a >  3.14159265f) a -= 6.28318530f;
    while (a < -3.14159265f) a += 6.28318530f;
    return a;
}

// =============================================================================
// DetectCameraType
// Classifies the current camera mode using GTA natives. Must only be called
// from the script thread. Result is cached in g_cachedCamType for use by
// the render-thread handlers.
// =============================================================================
static CameraType DetectCameraType() {
    Ped ped = RVRNat::PlayerPed();
    if (RVRNat::IsCutsceneActive())         return CT_CUTSCENE;
    bool inVehicle   = RVRNat::IsPedInVehicle(ped);
    bool firstPerson = RVRNat::IsFirstPersonView();
    if (inVehicle) return firstPerson ? CT_1ST_VEHICLE : CT_3RD_VEHICLE;
    return firstPerson ? CT_1ST_FOOT : CT_3RD_FOOT;
}

// =============================================================================
// UpdateWorldRot
// Computes the world-space orientation quaternion for the current frame.
// This represents the "base orientation" that the HMD rotates on top of.
//
// For foot cameras: tracks gameplay camera yaw and pitch.
// For vehicle cameras: tracks vehicle rotation (with optional gyro roll/pitch).
// For cutscenes: tracks cutscene camera with configurable pitch mode.
// =============================================================================
static void UpdateWorldRot(CameraType camType) {
    const float D2R = 3.14159265f / 180.f;

    if (camType == CT_CUTSCENE) {
        Vector3 cr  = RVRNat::GetGameplayCamRot(2);
        float yaw   = cr.z * D2R;
        float pitch = cr.x * D2R;
        bool cutChanged = (fabsf(WrapAngle(yaw - g_lastCutYaw)) > 0.5f ||
                           fabsf(WrapAngle(pitch - g_lastCutPitch)) > 0.5f)
                          && !g_cutsceneWasActive;
        // cutscenePitchMode 1 = relative: hold orientation on cuts, update smoothly
        if (!g_cutsceneWasActive || cutChanged || g_config.cutscenePitchMode != 1) {
            g_worldRot = QuatNormalize(QuatMul(
                QuatFromAxisAngle(0,1,0, yaw),
                QuatFromAxisAngle(1,0,0, pitch)));
            g_lastCutYaw = yaw; g_lastCutPitch = pitch;
        }
        g_cutsceneWasActive = true;
    } else {
        g_cutsceneWasActive = false;
        if (camType == CT_1ST_VEHICLE || camType == CT_3RD_VEHICLE) {
            Entity v = PED::GET_VEHICLE_PED_IS_IN(RVRNat::PlayerPed(), FALSE);
            if (v) {
                Vector3 rot = ENTITY::GET_ENTITY_ROTATION(v, 2);
                float y = rot.z * D2R;
                // gyroVehicle: include pitch and roll from the vehicle rotation
                float p = g_config.gyroVehicle ? rot.x * D2R : 0.f;
                float r = g_config.gyroVehicle ? rot.y * D2R : 0.f;
                g_worldRot = QuatNormalize(QuatMul(
                    QuatFromAxisAngle(0,1,0,y), QuatMul(
                    QuatFromAxisAngle(1,0,0,p),
                    QuatFromAxisAngle(0,0,1,r))));
            }
        } else {
            Vector3 cr  = RVRNat::GetGameplayCamRot(2);
            float y     = cr.z * D2R;
            float p     = cr.x * D2R;
            // Suppress pitch when aiming from cover unless Allow1stCoverAimHeading is set.
            if (RVRNat::IsPedAimingFromCover(RVRNat::PlayerPed()) &&
                !g_config.allow1stCoverAimHeading)
                p = 0.f;
            g_worldRot = QuatNormalize(QuatMul(
                QuatFromAxisAngle(0,1,0,y),
                QuatFromAxisAngle(1,0,0,p)));
        }
    }
}

// =============================================================================
// FoldWorldRotIntoRenderPose
// Applies the accumulated world rotation to the ring-buffer pose and
// increments the frame sequence counter. This is the final step in the
// per-frame pipeline -- after this, the DLL has all the data it needs
// to render the next stereo frame.
// =============================================================================
static void FoldWorldRotIntoRenderPose() {
    if (RVR_GetPoseCount() <= 0) return;

    float wm[9];
    QuatToMatrix3x3(g_worldRot, wm);
    const RVRPoseSlot& pose = RVR_GetPoseRing()[0];

    // result = wm * pose (rotation 3x3 only)
    float folded[12];
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            folded[row*4+col] =
                wm[row*3+0]*pose.row0[col] +
                wm[row*3+1]*pose.row1[col] +
                wm[row*3+2]*pose.row2[col];
        }
        folded[row*4+3] = 0.f;
    }

    if (g_bridge.RVRLog) {
        float yaw   =  atan2f(folded[2], folded[10]) * 57.2957795f;
        float pitch = -asinf(fmaxf(-1.f, fminf(1.f, folded[6]))) * 57.2957795f;
        g_bridge.RVRLog("World yaw = %.2f, pitch = %.2f, roll = 0.00\n", yaw, pitch);
    }
    ++g_frameSeq;
}

// =============================================================================
// RVR_Initialize
// Full initialization sequence. Verbose = true logs every step.
// Returns true if all required systems are ready.
// =============================================================================
static bool RVR_Initialize(bool verbose) {
    RVR_LOG("=== RVR_Initialize ===");
    char exePath[MAX_PATH]; GetModuleFileNameA(nullptr, exePath, MAX_PATH);
    RVR_LOG("GTA5.exe: %s", exePath);
    RVR_LOG("getGameVersion() = %d", (int)getGameVersion());
    auto mod = Scanner::Module::Main();
    RVR_LOG("Module base=0x%llX size=0x%zX", (uint64_t)mod.base, mod.size);

    if (!g_bridge.Resolve(verbose)) {
        RVR_LOG("Bridge: NOT AVAILABLE");
        return false;
    }
    RVR_LOG("Bridge (d3d11.dll 3DmiGTA): RESOLVED OK");
    RVR_LOG("  g_RVRData=%p  RVRGetPoseFrame=%p  RVRWaitAndTrackHMD=%p",
        g_bridge.g_RVRData, (void*)g_bridge.RVRGetPoseFrame,
        (void*)g_bridge.RVRWaitAndTrackHMD);

    char iniPath[MAX_PATH]; GetModuleFileNameA(nullptr, iniPath, MAX_PATH);
    char* sl = strrchr(iniPath,'\\');
    if (sl) strcpy_s(sl+1, MAX_PATH-(sl+1-iniPath), "RealVR.ini");
    g_config.Load(iniPath);
    RVR_LOG("RealVR.ini: HeadingControl=%d UniversalFOVFix=%d DominantEye=%d "
            "CutscenePitchMode=%d GyroVehicle=%d SlowMotion=%d HMDFovDeg=%.1f",
        g_config.headingControl, g_config.universalFOVFix, g_config.dominantEye,
        g_config.cutscenePitchMode, (int)g_config.gyroVehicle,
        (int)g_config.slowMotion, g_config.hmdFovDeg);

    RVR_CheckGameVersion(g_bridge);

    RVR_LOG("--- Searching for 6 engine patches ---");
    bool patchesOk = RVRPatches::FindAllPatches(g_game, g_bridge, true);

    RVR_LOG("--- Searching for pools (CamMetadataPool, ViewPort) ---");
    bool poolsOk = RVRPatches::FindPools(g_game, g_bridge, true);

    if (!patchesOk || !poolsOk) {
        RVR_LOG("RESULT: patches/pools failed -- cannot continue");
        return false;
    }
    RVR_LOG("RESULT: All patches applied successfully");

    if (!RVRPatches::ApplyPatches(g_game, g_bridge)) {
        RVR_LOG("ApplyPatches FAILED");
        return false;
    }
    RVR_LOG("Trampolines written to GTA5.exe OK");
    g_patchesApplied = true;

    InitHandlers(g_game);

    const uint32_t vrState = *(const uint32_t*)g_bridge.g_RVRData;
    const char* vrName = (vrState == 0) ? "NONE (no runtime!)"
                       : (vrState == 1) ? "OpenVR/SteamVR"
                       : (vrState == 2) ? "Oculus"
                       : "unknown";
    RVR_LOG("VR API ACTIVE = %u -> %s  %s",
            vrState, vrName,
            (vrState == 0) ? "[PROBLEM: proxy DLL did not init a VR runtime]"
                           : "[OK: runtime is live]");

    if (vrState != 0 && g_bridge.RVRWaitAndTrackHMD) {
        g_bridge.RVRWaitAndTrackHMD(0x55);
        RVR_LOG("VR sequence initialized (cl=0x55)");
    }

    RVR_LOG("g_initialized = 1 (patches=1 bridge=1)");
    RVR_LOG("FoldWorldRotIntoRenderPose");
    return true;
}

// =============================================================================
// RVR_TrackingTick
// Called every frame from ScriptMain. Drives the HMD tracking pipeline.
// =============================================================================
static void RVR_TrackingTick() {
    RVR_TRACE_ONCE("[ST] RVR_TrackingTick FIRST CALL");
    if (!g_initialized || !g_vrActive) return;
    if (!g_bridge.IsReady()) return;

    const uint32_t vrState = *(const uint32_t*)g_bridge.g_RVRData;
    if (vrState == 0) return;

    // Original proxy capture writers require g_RVRData[0x10] (0x36D720) and
    // the rest of the ASI state machine keeps it in sync with [0x11]. Our
    // reconstruction must keep both asserted while VR is active.
    if (g_bridge.g_RVRData) {
        RVR_TRY {
            uint8_t* b = (uint8_t*)g_bridge.g_RVRData;
            b[0x10] = 1;
            b[0x11] = 1;
        } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {}
    }

    // Guard: wait until the player ped is loaded before calling any natives.
    // During the loading screen PLAYER_PED_ID() returns an invalid entity.
    // Calling gameplay natives on an invalid ped crashes the game.
    {
        Ped ped = PLAYER::PLAYER_PED_ID();
        if (!ENTITY::DOES_ENTITY_EXIST(ped)) {
            RVR_TRACE_ONCE("[ST] Waiting for player ped to exist (loading screen)");
            return;
        }
    }
    RVR_TRACE_ONCE("[ST] Player ped exists -- tracking begins");

    // Deferred patch application: if D3D was not ready during Init,
    // attempt to apply patches now. Retry each tick until successful.
    if (!g_patchesApplied) {
        if (RVRPatches::ApplyPatches(g_game, g_bridge)) {
            g_patchesApplied = true;
            InitHandlers(g_game);
            RVR_LOG("Trampolines applied on first tick OK");
            if (g_bridge.RVRLog)
                g_bridge.RVRLog("All patches applied successfully\n");
        }
        return;
    }

    // Step 1: signal frame start to DLL (RVRSeqCheck equivalent)
    // Frame-begin flag, selectable at runtime (default 0x00 = stable).
    //   0x00 : proxy frame cycle does not fully start -> slow (~1 fps) but STABLE.
    //   0x55 : matches the original Update(); starts the real stereo cycle, but
    //          the proxy then renders stereo with data we cannot fully reproduce
    //          and crashes after ~1s. Toggle with the 'B' hotkey to experiment.
    RVR_TRACE_ONCE("[ST] Tick step 1: RVRWaitAndTrackHMD(0x%02X)", g_frameBeginFlag);
    g_bridge.RVRWaitAndTrackHMD(g_frameBeginFlag);

    // Step 2: get pose pointer from DLL
    void* posePtr = nullptr;
    RVR_TRY {
        posePtr = g_bridge.RVRGetPoseFrame(g_poseOutBuf, 0);
    } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {
        static bool once = false;
        if (!once) { once=true; RVR_LOG("Exception in RVRGetPoseFrame (HMD not ready?)"); }
        return;
    }
    if (!posePtr) return;
    RVR_TRACE_ONCE("[ST] Tick step 2: pose pointer OK (%p)", posePtr);

    // Step 3: read frameIndex from pose struct offset 0x18
    uint32_t frameIndex = g_frameSeq;
    RVR_TRY {
        frameIndex = *(const uint32_t*)((const uint8_t*)posePtr + 0x18);
    } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {}

    // Step 3b: complete the per-frame handshake (RVRSeqCheck + RVRGetFrameDesc).
    // Now that frame-begin uses the correct flag (0x55), the proxy is in a valid
    // frame state for these completion calls. A begun frame MUST be completed or
    // the proxy desyncs and crashes (observed: 0x55 begin without completion
    // crashed after ~1s). Full per-frame order matches the original Update():
    //   RVRWaitAndTrackHMD(0x55) -> RVRGetPoseFrame -> RVRSeqCheck -> RVRGetFrameDesc
    // Static buffers avoid any stack overflow from the DLL writing the output.
    if (g_frameBeginFlag == 0x55) {
        // RVRGetPoseDesc (our RVRSeqCheck) takes TWO args: rcx=poseBuf, rdx=outDesc.
        // It reads poseBuf[0x00..0x1B] and WRITES the pose descriptor to outDesc.
        // The missing outDesc arg was the crash cause (it wrote to a garbage rdx).
        static uint8_t s_poseBuf[4096];
        static uint8_t s_poseDescOut[4096];
        RVR_TRACE_ONCE("[ST] 3b: before RVRSeqCheck (2-arg)");
        RVR_TRY {
            memcpy(s_poseBuf, posePtr, 0x20);  // it reads up to +0x1B
            if (g_bridge.RVRSeqCheck)
                g_bridge.RVRSeqCheck(s_poseBuf, s_poseDescOut);
            RVR_TRACE_ONCE("[ST] 3b: after RVRSeqCheck (pose processed)");

            // NOTE: RVRGetFrameDesc (the per-frame SUBMIT/consume) is NO LONGER
            // called here. It was moved to the render thread (RVR_AdjustViewInverse,
            // ViewInverse hook), where it runs in lockstep with the proxy's scene
            // capture. Calling it from this script-thread loop raced the render
            // thread and consumed/cleared the captured-scene resource out of sync,
            // which froze the image (1 random frame, updating only on pause).
            // See AdjustViewInverse.cpp "RENDER-THREAD SUBMIT (freeze fix)".
            RVR_TRACE_ONCE("[ST] 3b: pose handshake complete OK (submit on render thread)");
        } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {
            RVR_TRACE_ONCE("[ST] 3b: EXCEPTION in handshake (suppressed)");
        }
    }

    // Step 3a: read the live HMD pose from posePtr (quaternion + position).
    // Safe: copy to a local first (posePtr+0x00..0x1F is mapped), then publish
    // to the globals consumed by the render thread. No proxy calls.
    {
        float local[8] = {};
        bool ok = false;
        RVR_TRY {
            memcpy(local, posePtr, sizeof(local));  // 0x20 bytes
            ok = true;
        } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) { ok = false; }
        if (ok) {
            // Normalize the raw HMD quaternion.
            float qx=local[0], qy=local[1], qz=local[2], qw=local[3];
            float len = sqrtf(qx*qx+qy*qy+qz*qz+qw*qw);
            if (len > 1e-6f) { float inv=1.f/len; qx*=inv; qy*=inv; qz*=inv; qw*=inv; }

            // Capture a reference orientation the first time (and after recenter,
            // which clears g_hmdRefSet). We then publish the RELATIVE rotation
            // delta = conj(ref) * current, so at the neutral pose the delta is
            // identity (no rotation, image unchanged) and head movement applies
            // a relative rotation. Applying the absolute quat is what made the
            // image vanish earlier.
            if (!g_hmdRefSet) {
                g_hmdQuatRef[0]=qx; g_hmdQuatRef[1]=qy; g_hmdQuatRef[2]=qz; g_hmdQuatRef[3]=qw;
                g_hmdRefSet = true;
            }
            // conj(ref)
            float rx=-g_hmdQuatRef[0], ry=-g_hmdQuatRef[1], rz=-g_hmdQuatRef[2], rw=g_hmdQuatRef[3];
            // delta = conj(ref) * current   (Hamilton product)
            float dx = rw*qx + rx*qw + ry*qz - rz*qy;
            float dy = rw*qy - rx*qz + ry*qw + rz*qx;
            float dz = rw*qz + rx*qy - ry*qx + rz*qw;
            float dw = rw*qw - rx*qx - ry*qy - rz*qz;
            g_hmdQuat[0]=dx; g_hmdQuat[1]=dy; g_hmdQuat[2]=dz; g_hmdQuat[3]=dw;

            // Head yaw/pitch from the delta quaternion's forward vector
            // (OpenVR: forward = -Z rotated). Used to drive the game camera.
            float fX = -2.f*(dx*dz + dw*dy);
            float fY = -2.f*(dy*dz - dw*dx);
            float fZ = -(1.f - 2.f*(dx*dx + dy*dy));
            // Invert the yaw to match the game engine's rotation direction
            g_headYawDeg   = -atan2f(fX, -fZ) * 57.2957795f;
            g_headPitchDeg = asinf(fmaxf(-1.f, fminf(1.f, fY))) * 57.2957795f;

            g_hmdPos[0]=local[4]; g_hmdPos[1]=local[5]; g_hmdPos[2]=local[6];
            RVR_TRACE_ONCE("[ST] HMD head yaw=%.1f pitch=%.1f", g_headYawDeg, g_headPitchDeg);

            // RE finding: the original writes the HMD quaternion to g_RVRData+0x77C
            // (16 bytes), inside a 0x38-byte pose struct (0x77C..0x7B3). The next
            // block (matrix) starts at 0x7B4. The earlier crash was from writing
            // 4 slots at stride 0x1C, which clobbered 0x7B4. Write ONLY 0x77C
            // (16 bytes) -- safe, within the pose struct -- so the proxy can use
            // the head pose for reprojection. Gated by 'H' so we can compare.
            if (g_headTrackOn && g_bridge.g_RVRData) {
                uint8_t* base = (uint8_t*)g_bridge.g_RVRData;
                RVR_TRY {
                    float* p = (float*)(base + 0x77C);
                    p[0]=qx; p[1]=qy; p[2]=qz; p[3]=qw;
                } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {}
            }
        }
    }

    // Steps 4-5: camera type and world rotation (natives are safe here)
    RVR_TRACE_ONCE("[ST] Tick step 4: DetectCameraType");
    g_cachedCamType = DetectCameraType();
    RVR_TRACE_ONCE("[ST] Tick step 5: UpdateWorldRot");
    UpdateWorldRot(g_cachedCamType);

    // Step 4b: script hash dispatch -- detect per-mission VR behavior category.
    // Throttled to once every 30 frames (~0.5s) to avoid hammering the native
    // layer with 83 DOES_SCRIPT_WITH_NAME_HASH_EXIST calls every tick.
    RVR_TRACE_ONCE("[ST] Tick step 4b: script hash dispatch");
    static uint32_t s_scriptCheckFrame = 0;
    if ((g_frameSeq - s_scriptCheckFrame) >= 30) {
        s_scriptCheckFrame = g_frameSeq;
        g_cachedScriptCat = RVRHash::DetectActiveScriptCategory(RVRNat::DoesScriptExist);
    }

    const bool inCutscene  = (g_cachedCamType == CT_CUTSCENE);
    const bool flightMode  = (g_cachedScriptCat == RVRHash::SC_FLIGHT);
    const bool minigame    = (g_cachedScriptCat == RVRHash::SC_MINIGAME);

    // Step 6: read processed pose from ring-buffer (written by render thread)
    RVR_TRACE_ONCE("[ST] Tick step 6: read pose ring (count=%d)", RVR_GetPoseCount());
    {
        // Step 7: drive the GAME camera with the head yaw/pitch so the world
        // rotates with the head (1st and 3rd person). Uses relative heading/pitch
        // (relative to the player body), which works for both camera modes.
        // g_htMode (key 'K') cycles the sign convention to dial in the correct
        // direction (head right -> view right, head up -> view up).
        bool applyHeading = g_headTrackOn && !flightMode && !inCutscene;
        if (g_config.headingControl == 2) applyHeading = false;
        if (applyHeading) {
            float yaw   = g_headYawDeg;
            float pitch = g_headPitchDeg;
            switch (g_htMode) {
                default:
                case 0: break;                       // yaw+, pitch+
                case 1: yaw = -yaw;            break; // yaw-, pitch+
                case 2: pitch = -pitch;       break; // yaw+, pitch-
                case 3: yaw = -yaw; pitch = -pitch; break; // both -
            }
            RVR_TRACE_ONCE("[ST] Tick step 7: drive cam heading=%.1f pitch=%.1f (mode %d)",
                           yaw, pitch, g_htMode);

            const bool is1stPerson = RVRNat::IsFirstPersonView();
            if (is1stPerson) {
                // In 1st person the ped body rotates to match the camera every frame.
                // Sending the absolute HMD yaw as a relative offset causes runaway
                // spin because each tick it adds on top of the body rotation.
                // Fix: send the per-frame DELTA so only the actual head movement
                // is applied, and apply it directly to the absolute camera yaw
                // so we don't fight the ped's relative rotation.
                static float s_prevHmdYaw   = 0.f;
                static float s_prevHmdPitch = 0.f;
                float deltaYaw = yaw - s_prevHmdYaw;
                float deltaPitch = pitch - s_prevHmdPitch;
                // Wrap delta to [-180, 180] to handle 360->0 wrap-around
                if (deltaYaw   >  180.f) deltaYaw   -= 360.f;
                if (deltaYaw   < -180.f) deltaYaw   += 360.f;
                if (deltaPitch >  180.f) deltaPitch -= 360.f;
                if (deltaPitch < -180.f) deltaPitch += 360.f;
                s_prevHmdYaw   = yaw;
                s_prevHmdPitch = pitch;
                
                // Get current relative heading and add delta
                float currentRelYaw = RVRNat::GetGameplayCamRelativeHeading();
                RVRNat::SetGameplayCamRelativeHeading(currentRelYaw + deltaYaw);
                
                if (g_config.pitchControl) {
                    float currentRelPitch = RVRNat::GetGameplayCamRelativePitch();
                    RVRNat::SetGameplayCamRelativePitch(currentRelPitch + deltaPitch);
                }
            } else {
                // 3rd person / cutscene: send the absolute HMD yaw as a relative
                // offset from the player body. The body does NOT auto-rotate in
                // 3rd person, so there is no feedback loop.
                RVRNat::SetGameplayCamRelativeHeading(yaw);
                if (g_config.pitchControl)
                    RVRNat::SetGameplayCamRelativePitch(pitch);
            }
        }

        if (g_config.showDebugText && g_bridge.RVRLog)
            g_bridge.RVRLog("HEAD yaw = %.2f, pitch = %.2f\n", g_headYawDeg, g_headPitchDeg);
    }

    // Step 8: update HMD projection matrix.
    //
    // ZoomOverride: suppresses HMD FOV and falls back to the game's own FOV in
    // certain situations, preventing the fixed HMD FOV from overriding zoom
    // scopes or minigame cameras.
    //   0 = never suppress (always use HMD FOV)
    //   1 = suppress in cutscenes only
    //   2 = suppress outside cutscenes (i.e. only active in cutscenes)
    //   3 = always suppress (never override game FOV)
    //
    // StereoInCutscenes mode 2 (flat screen): skip view matrix modification
    // during cutscenes so the proxy DLL receives the unmodified game view and
    // renders a flat mono image instead of a VR stereo image.
    bool suppressFOV = false;
    switch (g_config.zoomOverride) {
        case 1: suppressFOV = inCutscene;    break;
        case 2: suppressFOV = !inCutscene;   break;
        case 3: suppressFOV = true;          break;
    }
    // Minigame missions (darts, tennis, golf) always suppress HMD FOV so the
    // game can display the appropriate minigame view without a fixed VR FOV.
    if (minigame) suppressFOV = true;

    if (!suppressFOV && g_config.universalFOVFix > 0) {
        float gameFov  = RVRNat::GetGameplayCamFov();
        float zoom = 1.f / tanf(gameFov * 0.5f * 3.14159265f / 180.f);

        // Use symmetric FOV unconditionally. We suspected s_frameDescOut might
        // contain asymmetric tangents, but reading garbage here corrupts the
        // projection matrix with NaNs, causing the VR render to fail completely.
        float tanHalf  = tanf(g_config.hmdFovDeg * 0.5f * 3.14159265f / 180.f);
        float left   = -tanHalf;
        float right  =  tanHalf;
        float top    = -tanHalf;
        float bottom =  tanHalf;

        RVR_TrackProj(&g_bridge, zoom, left, right, top, bottom, 0.05f, 10000.f);
    }

    // StereoInCutscenes mode 2: do not fold world rotation into the render pose
    // during cutscenes. The proxy DLL receives the unmodified game matrix and
    // renders without HMD-driven stereo for that frame.
    bool skipRenderPose = (inCutscene && g_config.stereoInCutscenes == 2);
    if (!skipRenderPose) {
        RVR_TRACE_ONCE("[ST] Tick step 9: FoldWorldRotIntoRenderPose");
        FoldWorldRotIntoRenderPose();
    }

    // SlowMotion: apply reduced time scale for VR comfort during slow-mo sequences.
    // Confirmed by RE: calls SET_TIME_SCALE (0x1D408577D440E81E) when enabled.
    // The exact time scale value is loaded from g_RVRData in the original; we use
    // 0.5 as a reasonable default. Calling this every tick when enabled matches
    // the original behavior (the game resets time scale each frame otherwise).
    if (g_config.slowMotion)
        RVRNat::SetTimeScale(0.5f);

    RVR_TRACE_ONCE("[ST] RVR_TrackingTick FIRST FULL PASS COMPLETE");

    // Heartbeat: measure how many tracking ticks run per ~2s window. If this is
    // ~1-2 it means the script thread is blocked (RVRGetPoseFrame/WaitGetPoses
    // timing out). If it is high (>60) the loop is fine and the slowness is in
    // the proxy's Present/Submit path.
    {
        static uint64_t s_lastBeat = 0;
        static uint32_t s_tickCount = 0;
        s_tickCount++;
        uint64_t now = GetTickCount64();
        if (s_lastBeat == 0) s_lastBeat = now;
        if (now - s_lastBeat >= 2000) {
            static long s_lastVI = 0;
            long viNow = g_viewInverseCalls;
            uint32_t fidx34 = 0, fidx3c = 0;
            // Proxy scene-capture gate flags (RE of d3d11.dll capture func 0x879C0):
            //   capture is SKIPPED unless ALL of these are non-zero:
            //   g_RVRData[0xE0] (enable), g_RVRData[0x11] (init), g_RVRData[0xC0] (resource ptr).
            //   Also log the captured-scene resource [0x36BDC8] = g_RVRData-0x1948.
            unsigned e0 = 0, i10 = 0, i11 = 0, df50 = 0, d789 = 0; void* c0 = nullptr; void* scene = nullptr;
            void* mgr = nullptr; void* mgrVtbl = nullptr; void* mgrGate = nullptr;
            if (g_bridge.g_RVRData) {
                RVR_TRY {
                    const uint8_t* b = (const uint8_t*)g_bridge.g_RVRData;
                    fidx34 = *(const uint32_t*)(b + 0x34);
                    fidx3c = *(const uint32_t*)(b + 0x3C);
                    e0   = *(const uint8_t*)(b + 0xE0);
                    i10  = *(const uint8_t*)(b + 0x10);
                    i11  = *(const uint8_t*)(b + 0x11);
                    df50 = *(const uint8_t*)(b + 0x840);
                    d789 = *(const uint8_t*)(b + 0x79);
                    c0   = *(void* const*)(b + 0xC0);
                    scene= *(void* const*)(b - 0x1948);
                    mgr  = *(void* const*)(b + 0x8);
                    if (mgr) {
                        mgrVtbl = *(void* const*)mgr;
                        if (mgrVtbl) mgrGate = *(((void**)mgrVtbl) + 7); // vtable + 0x38
                    }
                } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {}
            }
            // Dense render-thread capture-gate counters (read+reset).
            long e0Seen   = g_e0SeenCount;      g_e0SeenCount = 0;
            long i10Seen  = g_i10SeenCount;     g_i10SeenCount = 0;
            long i11Seen  = g_i11SeenCount;     g_i11SeenCount = 0;
            long mgrSeen  = g_managerSeenCount; g_managerSeenCount = 0;
            long df50Seen = g_df50SeenCount;    g_df50SeenCount = 0;
            long d789Seen = g_d789SeenCount;    g_d789SeenCount = 0;
            long sceneSeen= g_sceneSeenCount;   g_sceneSeenCount = 0;
            long fdCalls  = g_frameDescCalls;   g_frameDescCalls = 0;
            long fdNoScn  = g_frameDescNoScene; g_frameDescNoScene = 0;
            long fdErr    = g_frameDescErrors;  g_frameDescErrors = 0;
            long gateT    = g_managerGateTrue;  g_managerGateTrue = 0;
            long gateF    = g_managerGateFalse; g_managerGateFalse = 0;
            long gateErr  = g_managerGateErrors; g_managerGateErrors = 0;
            long arm      = g_captureArmCount;  g_captureArmCount = 0;
            long armSkip  = g_captureArmSkipped; g_captureArmSkipped = 0;
            long aviCalls = g_aviCallCount;     g_aviCallCount = 0;
            RVR_LOG("[ST] HEARTBEAT: VI/2s=%ld | [34]=%u [3C]=%u | now:e0=%u i10=%u i11=%u df50=%u d789=%u c0=%p scene=%p mgr=%p gate=%p | dense:avi=%ld e0=%ld i10=%ld i11=%ld df50=%ld d789=%ld mgr=%ld scene=%ld fd=%ld noScene=%ld fdErr=%ld arm=%ld armSkip=%ld gateT/F/E=%ld/%ld/%ld",
                    (viNow - s_lastVI), fidx34, fidx3c,
                    e0, i10, i11, df50, d789, c0, scene, mgr, mgrGate,
                    aviCalls, e0Seen, i10Seen, i11Seen, df50Seen, d789Seen, mgrSeen, sceneSeen,
                    fdCalls, fdNoScn, fdErr, arm, armSkip, gateT, gateF, gateErr);
            
            s_lastVI = viNow;
            s_tickCount = 0;
            s_lastBeat = now;
        }
    }
}

// =============================================================================
// ScriptMain
// Entry point registered with ScriptHookV. Runs in the script thread.
// Retries initialization up to 50 times with 200ms delay.
// On success, enters the tracking loop.
// =============================================================================
void ScriptMain() {
    RVR_LOG("ScriptMain started -- waiting for game to load...");
    bool ok = false;
    for (int i = 0; i < 50 && !g_initialized; ++i) {
        RVR_TRY {
            if (RVR_Initialize(i == 0)) {
                g_initialized = true; ok = true;
            }
        } RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {
            if (i == 0) RVR_LOG("Exception during RVR_Initialize");
        }
        if (ok) break;
        WAIT(200);
    }
    if (!ok) RVR_LOG("=== Init incomplete -- see log above ===");

    while (true) {
        RVR_TRY { RVR_TrackingTick(); }
        RVR_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {
            static bool once = false;
            if (!once) { once=true; RVR_LOG("Exception in TrackingTick (suppressed)"); }
        }
        WAIT(0);
    }
}

// =============================================================================
// Keyboard handler
// Registered with ScriptHookV alongside ScriptMain.
// =============================================================================
static void OnKeyboard(DWORD key, WORD, BYTE, BOOL, BOOL, BOOL, BOOL isUpNow) {
    if (!isUpNow) return;
    switch (key) {
    case VK_F8:
        g_vrActive = !g_vrActive;
        RVR_LOG("VR %s (F8)", g_vrActive ? "ENABLED" : "DISABLED");
        break;
    case VK_F11:
        g_worldRot = {0,0,0,1}; g_frameSeq = 0;
        g_hmdRefSet = false;   // re-capture the neutral HMD orientation next frame
        RVR_LOG("HMD recentered (F11)");
        if (g_bridge.RVRLog) g_bridge.RVRLog("Script is asking to recenter HMD\n");
        break;
    case VK_NUMPAD2:
        g_config.stereo = !g_config.stereo;
        RVR_LOG("Stereo %s", g_config.stereo ? "ON" : "OFF");
        break;
    case 'T':
        g_config.dominantEye = (g_config.dominantEye + 1) % 3;
        RVR_LOG("DominantEye = %d", g_config.dominantEye);
        break;
    case 'B':
        g_frameBeginFlag = (g_frameBeginFlag == 0x00) ? 0x55 : 0x00;
        RVR_LOG("FrameBeginFlag = 0x%02X (%s)", g_frameBeginFlag,
                g_frameBeginFlag == 0x55 ? "EXPERIMENTAL stereo cycle" : "STABLE");
        break;
    case 'H':
        g_headTrackOn = !g_headTrackOn;
        RVR_LOG("HeadTracking = %s", g_headTrackOn ? "ON" : "OFF");
        break;
    case 'K':
        g_htMode = (g_htMode + 1) % 4;
        RVR_LOG("HeadTrack sign mode = %d (0:y+p+ 1:y-p+ 2:y+p- 3:y-p-)", g_htMode);
        break;
    case 'Y':
        g_config.headingControl = (g_config.headingControl + 1) % 3;
        RVR_LOG("HeadingControl = %d", g_config.headingControl);
        break;
    case VK_END:
        g_config.gyroVehicle = !g_config.gyroVehicle;
        RVR_LOG("GyroVehicle = %d", (int)g_config.gyroVehicle);
        break;
    case 'J':
        g_config.cutscenePitchMode = (g_config.cutscenePitchMode + 1) % 3;
        break;
    case VK_DECIMAL:
        g_config.zoomOverride = (g_config.zoomOverride + 1) % 4;
        break;
    }
}

// =============================================================================
// DllMain
// =============================================================================
BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID) {
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        g_hModule = hInstance;
        DisableThreadLibraryCalls(hInstance);
        RVRFileLog::Init();
        RVR_LOG("ASI loaded (DLL_PROCESS_ATTACH) -- BUILD: revert-e0-v30 (" __DATE__ " " __TIME__ ")");
        scriptRegister(hInstance, ScriptMain);
        keyboardHandlerRegister(OnKeyboard);
        break;
    case DLL_PROCESS_DETACH:
        RVR_LOG("ASI unloading (DLL_PROCESS_DETACH)");
        RVRPatches::RestoreAllPatches(g_game);
        scriptUnregister(hInstance);
        keyboardHandlerUnregister(OnKeyboard);
        break;
    }
    return TRUE;
}
