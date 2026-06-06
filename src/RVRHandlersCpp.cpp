// =============================================================================
// RVRHandlersCpp.cpp
//
// C++ implementations of the six patch-site handlers.
//
// ROLE IN THE PIPELINE
// --------------------
// The assembly stubs in RVRHandlersAsm.asm extract engine registers and
// call these functions. Each function performs any VR-specific work and
// returns. The assembly stub then jumps to the continuation, which re-runs
// the original bytes and returns to the engine.
//
// These functions run on the ENGINE RENDER THREAD, not the script thread.
// Restrictions:
//   - Do NOT call GTA natives (script thread only).
//   - Do NOT allocate memory or take locks that the script thread also holds.
//   - Camera type and config are read from globals updated by the script
//     thread each frame (g_cachedCamType, g_config).
//
// CAMERA OBJECT OFFSETS (version 73, confirmed by RE)
// ----------------------------------------------------
// The engine camera object layout at the ViewInverse site:
//   pCamObj + 0x70 = view matrix row 0  (float[4], right vector)
//   pCamObj + 0x80 = view matrix row 1  (float[4], up vector)
//   pCamObj + 0x90 = view matrix row 2  (float[4], forward vector)
//   pCamObj + 0xA0 = view matrix row 3  (float[4], position)
//
// FOV field offsets:
//   pCamObj + 0x43 = FOV float for first-person in-vehicle (FOV1stCar site)
//   pCamObj + 0x90 = FOV float for third-person and universal (FOV3rd/FOVUni)
//   Note: 0x90 is the same offset as view row 2. These are different objects
//   accessed at different sites in different code paths.
//
// Projection object offset (Proj site):
//   pProjObj + 0x170 = projection matrix (column-major float[16])
//   pProjObj + 0x17C = second column element
//
// CONTINUATION STUBS
// ------------------
// InitHandlers() must be called after ApplyPatches() to create the
// continuation stubs. Each stub is:
//   [16 original bytes from s_saved[i].orig]
//   mov r11, <site + 16>
//   jmp r11
//
// The original bytes are copied as-is. This is only safe if they do not
// contain RIP-relative addressing. This has been verified for all six sites.
//
// WHAT IS NOT YET FULLY IMPLEMENTED
// -----------------------------------
// CamParamsHandler: the near/far plane override for VR comfort. The offset
//   of near/far within pCamParams is not confirmed. The handler is a no-op.
//
// FOV handlers use g_fRVRGameProj[0] as the HMD FOV source. This value is
//   written by RVR_TrackProj in AdjustViewInverse.cpp. On the first few
//   frames before TrackProj has been called, the value may be 0, in which
//   case the handlers fall through without modifying the FOV.
// =============================================================================

#include "RVRTypes.h"
#include "RVRFileLog.h"
#include "RVRPatches.h"
#include <cstring>
#include <cmath>
#include <Windows.h>
#include <xmmintrin.h>

extern RVRBridge    g_bridge;
extern GamePointers g_game;
extern RVRConfig    g_config;
extern uint32_t     g_frameSeq;
extern bool         g_vrActive;
extern bool         g_initialized;
extern CameraType   g_cachedCamType;

extern "C" void RVR_AdjustViewInverse(RVRMatrix44*, RVRBridge*, uint32_t, float, bool, int);
extern "C" void RVR_TrackProj(RVRBridge*, float, float, float, float, float, float, float);
extern "C" void RVR_ClearPoseRing();
extern "C" int  RVR_GetPoseCount();

typedef void(*ContinuationFn)();
extern "C" ContinuationFn s_cont[6] = {};

// RVRPatches::s_saved is defined in this translation unit because the ASM
// file references s_cont (also here) and both need the same linkage scope.
namespace RVRPatches { SavedPatch s_saved[6] = {}; }

// ----------------------------------------------------------------------------
// InitHandlers
// Creates continuation stubs for each patch site. Called from RealVR.cpp
// after ApplyPatches() has populated s_saved[].
//
// Each stub layout (29 bytes):
//   Bytes  0..15: original engine bytes (saved before trampoline was written)
//   Bytes 16..17: 0x49 0xBB  (mov r11, imm64 prefix)
//   Bytes 18..25: <site + 16 as uint64_t>
//   Bytes 26..28: 0x41 0xFF 0xE3  (jmp r11)
// ----------------------------------------------------------------------------
void InitHandlers(const GamePointers& gp) {
    const uintptr_t sites[6] = {
        gp.pViewInverse, gp.pProj,      gp.pFOV1stCar,
        gp.pFOV3rd,      gp.pFOVUni,    gp.pCamParams
    };
    for (int i = 0; i < 6; ++i) {
        if (!sites[i] || !RVRPatches::s_saved[i].saved) {
            RVR_LOG("InitHandlers: s_cont[%d] not created "
                    "(site=0x%llX saved=%d)",
                    i, (uint64_t)sites[i],
                    (int)RVRPatches::s_saved[i].saved);
            continue;
        }
        int len = RVRPatches::s_saved[i].len;
        if (len < 13 || len > 16) len = 16;  // safety fallback
        uintptr_t retAddr = sites[i] + len;
        uint8_t* stub = (uint8_t*)VirtualAlloc(
            nullptr, 32, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (!stub) {
            RVR_LOG("InitHandlers: VirtualAlloc failed for s_cont[%d]", i);
            continue;
        }
        // Continuation stub layout (len + 13 bytes):
        //   [len original bytes][49 BB <site+len:8>][41 FF E3]
        // Copies exactly the overwritten instructions then jumps back to the
        // first untouched instruction at site+len.
        const uint8_t* o = RVRPatches::s_saved[i].orig;
        memcpy(stub, o, len);
        stub[len + 0] = 0x49; stub[len + 1] = 0xBB;
        memcpy(stub + len + 2, &retAddr, 8);
        stub[len + 10] = 0x41; stub[len + 11] = 0xFF; stub[len + 12] = 0xE3;
        FlushInstructionCache(GetCurrentProcess(), stub, len + 13);
        s_cont[i] = (ContinuationFn)stub;
        RVR_LOG("InitHandlers: s_cont[%d] len=%d at %p -> returns to 0x%llX",
                i, len, stub, (uint64_t)retAddr);
    }
}

// ----------------------------------------------------------------------------
// ReadViewMatrix
// Reads the 4x4 row-major view matrix from a GTA camera object.
// Offsets confirmed from RE of the ViewInverse site in version 73.
// ----------------------------------------------------------------------------
static inline void ReadViewMatrix(const void* camObj, RVRMatrix44& out) {
    const uint8_t* p = (const uint8_t*)camObj;
    memcpy(&out.m[0],  p + 0x70, 16);
    memcpy(&out.m[4],  p + 0x80, 16);
    memcpy(&out.m[8],  p + 0x90, 16);
    memcpy(&out.m[12], p + 0xa0, 16);
}

// ----------------------------------------------------------------------------
// RVR_ViewInverseC
// Called from ViewInverseHandler when the engine writes a new view matrix.
// This is the central VR interception point -- everything else feeds from here.
//
// Flow:
//   1. Read the view matrix from the camera object.
//   2. Pass it to RVR_AdjustViewInverse, which:
//      a. Reads the HMD pose from g_RVRData.
//      b. Applies HMD rotation to the view matrix.
//      c. Writes the result back to g_RVRData for the render DLL.
//      d. Stores the result in the local ring-buffer for the script thread.
// ----------------------------------------------------------------------------
extern "C" void RVR_ViewInverseC(void* camObj) {
    RVR_TRACE_ONCE("[RT] RVR_ViewInverseC FIRST ENTER (camObj=%p)", camObj);
    if (!camObj || !g_initialized || !g_vrActive) return;
    if (!g_bridge.IsReady()) return;
    __try {
        const uint32_t vrState = *(const uint32_t*)g_bridge.g_RVRData;
        if (vrState == 0) return;

        RVR_TRACE_ONCE("[RT] ViewInverse: reading view matrix");

        // DIAGNOSTIC: dump camObj as floats from 0x00..0xFC to locate the real
        // view matrix (its rotation rows are unit vectors, values in [-1,1]).
        {
            static bool dumped = false;
            if (!dumped) {
                dumped = true;
                const float* f = (const float*)camObj;
                for (int base = 0; base < 0x100; base += 0x10) {
                    int idx = base / 4;
                    RVR_LOG("[RT] camObj+0x%02X: %12.4f %12.4f %12.4f %12.4f",
                            base, f[idx+0], f[idx+1], f[idx+2], f[idx+3]);
                }
            }
        }

        RVRMatrix44 view{};
        ReadViewMatrix(camObj, view);

        bool applyTrans = (g_cachedCamType == CT_1ST_FOOT && g_config.positionTracking);

        RVR_TRACE_ONCE("[RT] ViewInverse: calling AdjustViewInverse");
        RVR_ClearPoseRing();
        RVR_AdjustViewInverse(&view, &g_bridge, g_frameSeq, 0.f, applyTrans, g_config.dominantEye);
        RVR_TRACE_ONCE("[RT] RVR_ViewInverseC FIRST EXIT OK");
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        static bool once = false;
        if (!once) { once = true; RVR_LOG("[RT] EXCEPTION in RVR_ViewInverseC (suppressed)"); }
    }
}

// ----------------------------------------------------------------------------
// RVR_ProjC
// Called when the engine writes a new projection matrix.
// Reads the near/far planes from the engine's matrix and calls RVR_TrackProj
// to write the HMD-corrected projection to g_fRVRGameProj in the DLL.
// ----------------------------------------------------------------------------
extern "C" void RVR_ProjC(void* projObj) {
    RVR_TRACE_ONCE("[RT] RVR_ProjC FIRST ENTER (projObj=%p)", projObj);
    if (!projObj || !g_initialized || !g_vrActive) return;
    if (!g_bridge.IsReady() || !g_bridge.g_fRVRGameProj) return;
    if (g_config.universalFOVFix == 0) return;

    __try {
        const float* P = (const float*)((uint8_t*)projObj + 0x170);
        float zoom = P[0];

        float nearP = 0.05f, farP = 10000.f;
        float p22 = P[10], p32 = P[14];
        if (fabsf(p22 + 1.f) > 1e-4f) {
            farP  = p32 / (p22 + 1.f);
            nearP = p32 / (p22 - 1.f);
        }

        float tanHalf = tanf(g_config.hmdFovDeg * 0.5f * 3.14159265f / 180.f);
        RVR_TrackProj(&g_bridge, zoom,
            -tanHalf, tanHalf, -tanHalf, tanHalf, nearP, farP);
        RVR_TRACE_ONCE("[RT] RVR_ProjC FIRST EXIT OK");
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        static bool once = false;
        if (!once) { once = true; RVR_LOG("[RT] EXCEPTION in RVR_ProjC (suppressed)"); }
    }
}

// ----------------------------------------------------------------------------
// RVR_FOV1stCarC
// Intercepts the FOV write for first-person in-vehicle mode.
// Replaces the engine's FOV with the HMD's effective FOV if UniversalFOVFix
// is active. Writes directly to the FOV field at pCamObj + 0x43.
// ----------------------------------------------------------------------------
extern "C" void RVR_FOV1stCarC(void* camObj, float /*engineFov*/) {
    RVR_TRACE_ONCE("[RT] RVR_FOV1stCarC FIRST ENTER (camObj=%p)", camObj);
    if (!camObj || !g_bridge.IsReady()) return;
    if (g_config.universalFOVFix == 0 || !g_bridge.g_fRVRGameProj) return;
    __try {
        float cot = g_bridge.g_fRVRGameProj[0];
        if (cot < 0.1f) return;
        *(float*)((uint8_t*)camObj + 0x43) = 2.f * atanf(1.f / cot) * 57.2957795f;
        RVR_TRACE_ONCE("[RT] RVR_FOV1stCarC FIRST EXIT OK");
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        RVR_TRACE_ONCE("[RT] EXCEPTION in RVR_FOV1stCarC (suppressed)");
    }
}

extern "C" void RVR_FOV3rdC(void* camObj, float /*engineFov*/) {
    RVR_TRACE_ONCE("[RT] RVR_FOV3rdC FIRST ENTER (camObj=%p)", camObj);
    if (!camObj || !g_bridge.IsReady()) return;
    if (g_config.universalFOVFix == 0 || !g_bridge.g_fRVRGameProj) return;
    __try {
        float cot = g_bridge.g_fRVRGameProj[0];
        if (cot < 0.1f) return;
        *(float*)((uint8_t*)camObj + 0x90) = 2.f * atanf(1.f / cot) * 57.2957795f;
        RVR_TRACE_ONCE("[RT] RVR_FOV3rdC FIRST EXIT OK");
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        RVR_TRACE_ONCE("[RT] EXCEPTION in RVR_FOV3rdC (suppressed)");
    }
}

extern "C" void RVR_FOVUniC(void* camObj, float /*engineFov*/) {
    RVR_TRACE_ONCE("[RT] RVR_FOVUniC FIRST ENTER (camObj=%p)", camObj);
    if (!camObj || !g_bridge.IsReady()) return;
    if (g_config.universalFOVFix == 0 || !g_bridge.g_fRVRGameProj) return;
    bool apply = false;
    switch (g_config.universalFOVFix) {
        case 1: apply = (g_cachedCamType == CT_CUTSCENE); break;
        case 2: apply = (g_cachedCamType != CT_CUTSCENE); break;
        case 3: apply = true; break;
    }
    if (!apply) return;
    __try {
        float cot = g_bridge.g_fRVRGameProj[0];
        if (cot < 0.1f) return;
        *(float*)((uint8_t*)camObj + 0x90) = 2.f * atanf(1.f / cot) * 57.2957795f;
        RVR_TRACE_ONCE("[RT] RVR_FOVUniC FIRST EXIT OK");
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        RVR_TRACE_ONCE("[RT] EXCEPTION in RVR_FOVUniC (suppressed)");
    }
}

// ----------------------------------------------------------------------------
// RVR_CamParamsC
// Intercepts the camera parameter setup function.
// Currently a no-op. Intended use: adjust the near plane to prevent clipping
// during HMD head translation. The near plane offset within pCamParams has
// not been confirmed and requires additional RE.
// ----------------------------------------------------------------------------
extern "C" void RVR_CamParamsC(void* camParams, void* camData) {
    RVR_TRACE_ONCE("[RT] RVR_CamParamsC FIRST ENTER (camParams=%p camData=%p)",
                   camParams, camData);
    // Not yet implemented. Continuation runs the original function.
}
