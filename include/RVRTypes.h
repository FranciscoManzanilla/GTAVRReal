#pragma once
#include <cstdint>
#include <Windows.h>

// =============================================================================
// RVRTypes.h
//
// Core data types, structures, and the RVR bridge interface.
//
// BRIDGE ARCHITECTURE
// -------------------
// The VR runtime is not a standalone DLL loaded by this ASI. Instead, it is
// delivered as a proxy d3d11.dll placed in the GTA V game directory by the
// 3DmiGTA runtime package. When GTA V loads d3d11.dll, it loads the proxy,
// which chains to the real system d3d11.dll and additionally exposes the RVR
// symbol set via GetProcAddress.
//
// Because both the proxy and the real system d3d11.dll share the same name,
// two modules named "d3d11.dll" may be loaded simultaneously. The proxy is
// identified by checking which one exports "RVRWaitAndTrackHMD" with a
// non-null address (see RVRBridge::Resolve in RVRBridge.cpp).
//
// SYMBOL NAME REMAPPING (confirmed by RE of ASI @ 0x180002340)
// -------------------------------------------------------------
// GetProcAddress is called in this order, but the results are stored in
// slots whose names do NOT match the symbol strings:
//
//   GetProcAddress("g_RVRData")          -> g_RVRData        (void*)
//   GetProcAddress("g_fRVRGameProj")     -> g_fRVRGameProj   (float*)
//   GetProcAddress("RVRLog")             -> RVRLog
//   GetProcAddress("RVRGetFrameDesc")    -> RVRGetFrameDesc
//   GetProcAddress("RVRGetPoseDesc")     -> stored in RVRSeqCheck slot
//   GetProcAddress("RVRSeqCheck")        -> stored in RVRWaitAndTrackHMD slot
//   GetProcAddress("RVRWaitAndTrackHMD") -> stored in RVRGetPoseFrame slot
//
// The names used in this header reflect what each function DOES, not the
// GetProcAddress string used to obtain it.
//
// VR API TYPE (g_RVRData[0])
// --------------------------
//   0 = none / not initialized
//   1 = OpenVR  (SteamVR)
//   2 = Oculus  (Oculus Runtime)
//
// SEQUENCE INITIALIZATION
// -----------------------
// After the bridge is resolved, RVRWaitAndTrackHMD must be called once with
// cl = 0x55 to initialize the frame sequence counter in the DLL.
// On each subsequent frame, it is called with cl = 0x00.
//
// g_RVRData LAYOUT
// ----------------
// g_RVRData is a direct pointer to the VR data buffer inside d3d11.dll.
// There is NO double dereference -- GetProcAddress("g_RVRData") already
// returns the address of the buffer, not a pointer-to-pointer.
//
// Pose input (written by d3d11.dll after WaitGetPoses):
//   stride = 0x1C (28 bytes per slot)
//   base   = g_RVRData + 0x77C
//   slot   = frameIndex & 3
//   [slot * 0x1C + 0x77C + 0x00] = float  hmd pitch   (radians)
//   [slot * 0x1C + 0x77C + 0x04] = float  hmd yaw     (radians)
//   [slot * 0x1C + 0x77C + 0x08] = float  hmd roll    (radians)
//   [slot * 0x1C + 0x77C + 0x0C] = float  head offset (meters, X axis)
//
// View matrix output (written by AdjustViewInverse for the render thread):
//   stride = 256 bytes per slot
//   slot   = frameIndex & 3
//   [slot * 256 + 0x890] = float[16]  row-major view matrix
//   [slot * 256 + 0x910] = float[16]  column-major (transposed) for HLSL shaders
//
// STATUS
// ------
// - Layout confirmed from RE of ViewInverse handler in original ASI.
// - Offsets 0x77C and 0x890 are specific to the version 73 / r7 runtime.
//   A future runtime update may shift these. If the HMD pose reads as
//   {0,0,0} in the log, these offsets are the first thing to verify.
//
// WHAT IS NOT YET KNOWN
// ---------------------
// - The layout of g_RVRData[0] beyond the VR API type byte.
// - The full structure of the pose struct returned by RVRGetPoseFrame.
//   Currently only bytes [0x00..0x18] are used (pose float[4] + frameIndex).
// - The second eye offset for stereo rendering. The DLL presumably handles
//   the eye separation internally once the view matrix is written.
// =============================================================================

// ----------------------------------------------------------------------------
// RVRMatrix44
// A row-major 4x4 float matrix. at(row, col) provides readable access.
// ----------------------------------------------------------------------------
struct RVRMatrix44 {
    float m[16];
    float& at(int r, int c)       { return m[r*4+c]; }
    float  at(int r, int c) const { return m[r*4+c]; }
    static RVRMatrix44 Identity() {
        RVRMatrix44 r{};
        r.m[0] = r.m[5] = r.m[10] = r.m[15] = 1.f;
        return r;
    }
};

// ----------------------------------------------------------------------------
// RVRQuat
// Quaternion used for world rotation accumulation in the script thread.
// Not used for the HMD pose itself, which arrives as Euler angles.
// ----------------------------------------------------------------------------
struct RVRQuat { float x=0.f, y=0.f, z=0.f, w=1.f; };

// ----------------------------------------------------------------------------
// RVRPoseSlot
// One entry in the local ring-buffer maintained by AdjustViewInverse.
// The ring-buffer allows the script thread to read the latest processed
// HMD pose without racing against the render thread.
// Stride is 64 bytes (sizeof == 64, static_assert enforced).
// ----------------------------------------------------------------------------
struct RVRPoseSlot {
    float row0[4];  // right  vector, w = 0
    float row1[4];  // up     vector, w = 0
    float row2[4];  // forward vector, w = 0
    float row3[4];  // position, w = 1
};
static_assert(sizeof(RVRPoseSlot) == 64, "RVRPoseSlot size mismatch");

// ----------------------------------------------------------------------------
// RVRBridge
// Holds all resolved function pointers and data pointers from the proxy
// d3d11.dll. Populated by RVRBridge::Resolve() at initialization time.
//
// Function pointer types use the calling convention deduced from RE.
// The cl parameter of RVRWaitAndTrackHMD is an 8-bit flag:
//   0x55 = initialize sequence (call once at startup)
//   0x00 = begin frame signal (call every tick)
// ----------------------------------------------------------------------------
struct RVRBridge {
    void*  g_RVRData      = nullptr;   // direct pointer to VR data buffer
    float* g_fRVRGameProj = nullptr;   // pointer to 16-float projection matrix

    using RVRLog_t              = void  (__cdecl*)(const char*, ...);
    using RVRGetFrameDesc_t     = int   (__fastcall*)(char* outBuf, bool isRight);
    using RVRGetPoseFrame_t     = void* (__fastcall*)(void* outBuf, int flags);
    using RVRSeqCheck_t         = uint32_t (__fastcall*)(uint8_t flags);
    using RVRWaitAndTrackHMD_t  = void  (__fastcall*)(uint8_t cl);

    RVRLog_t             RVRLog             = nullptr;
    RVRGetFrameDesc_t    RVRGetFrameDesc    = nullptr;
    RVRGetPoseFrame_t    RVRGetPoseFrame    = nullptr;
    RVRSeqCheck_t        RVRSeqCheck        = nullptr;
    RVRWaitAndTrackHMD_t RVRWaitAndTrackHMD = nullptr;

    // Returns true when the minimum set of pointers needed for frame tracking
    // is available. g_fRVRGameProj and RVRGetFrameDesc are optional.
    bool IsReady() const {
        return g_RVRData && RVRWaitAndTrackHMD && RVRGetPoseFrame;
    }

    bool Resolve(bool verbose = true);
};

// ----------------------------------------------------------------------------
// GamePointers
// Addresses in GTA5.exe located by pattern scan at initialization.
// Six injection sites and two pool pointers.
//
// Confirmed addresses for game version 73, base 0x7FF630C11000:
//   pViewInverse  = base + 0x001FF0AB1
//   pProj         = base + 0x00F7136D
//   pFOV1stCar    = base + 0x00255FCC
//   pFOV3rd       = base + 0x002835D3
//   pFOVUni       = base + 0x002836AD
//   pCamParams    = base + 0x005826F0
//   camMetadataPool = base + 0x001E90C7
//   viewPort        = base + 0x01FDB6F0
// ----------------------------------------------------------------------------
struct GamePointers {
    uintptr_t pViewInverse   = 0;
    uintptr_t pProj          = 0;
    uintptr_t pFOV1stCar     = 0;
    uintptr_t pFOV3rd        = 0;
    uintptr_t pFOVUni        = 0;
    uintptr_t pCamParams     = 0;
    uintptr_t camMetadataPool= 0;
    uintptr_t viewPort       = 0;

    bool AllPatchesOk() const {
        return pViewInverse && pProj && pFOV1stCar &&
               pFOV3rd && pFOVUni && pCamParams;
    }
};

// ----------------------------------------------------------------------------
// CameraType
// Detected each frame by the script thread using GTA natives and cached in
// g_cachedCamType for use by the render-thread handlers.
// ----------------------------------------------------------------------------
enum CameraType {
    CT_OTHER        = 0,
    CT_CUTSCENE     = 1,
    CT_1ST_FOOT     = 2,
    CT_3RD_FOOT     = 3,
    CT_1ST_VEHICLE  = 4,
    CT_3RD_VEHICLE  = 5,
};

// ----------------------------------------------------------------------------
// RVRConfig
// All settings loaded from RealVR.ini [Defaults].
// Mirrors the GetPrivateProfileIntA calls confirmed by RE of the original ASI binary.
// Keys are loaded from section [Defaults] of RealVR.ini.
//
// NOTE: StereoInCutscenes, ZoomOverride, Stereo, and VRAPI are NOT loaded by the
// ASI. Those keys are read directly by the proxy d3d11.dll. They are kept here
// as runtime state (not INI-driven) for our reconstruction's internal use.
// ----------------------------------------------------------------------------
struct RVRConfig {
    // -------------------------------------------------------------------------
    // ASI-owned config keys (confirmed from binary RE of original RealVR.asi)
    // -------------------------------------------------------------------------

    // Booleans (INI range 0-1)
    bool fixView              = true;   //       fix view matrix injection (default 1)
    bool pitchControl         = true;   //       apply HMD pitch to gameplay camera (default 1)
    bool overrideDartsTennisFOV = false;//       enable FOV override for darts/tennis/golf (default 0)
    bool allow1stCoverAimHeading= true; //       allow heading control while aiming from cover (default 1)
    bool decouple3rdPersonCam = true;   //       allow HMD to decouple from 3rd person camera (default 1)
    bool fullCamTrackInCutscene = true; //       full camera tracking in cutscenes (default 1)
    bool hotkeys              = false;  // F11:  enable runtime hotkeys (default 0)
    bool foldWorldRot         = true;   //       fold world rotation into render pose (default 1)
    bool gyroVehicle          = false;  // End:  use vehicle rotation for HMD stabilization (default 0)
    bool positionTracking     = true;   //       apply HMD X offset (head translation) (default 1)
    bool showDebugText        = false;  // N:    show debug overlay (default 0)
    bool slowMotion           = false;  //       enable slow-motion time scale effect (default 0)

    // Enums (INI range 0-2)
    int  dominantEye          = 2;  // T: 0=none, 1=left, 2=right (default 2)
    int  cutscenePitchMode    = 1;  // J: 0=absolute, 1=relative, 2=cut-relative (default 1)
    int  headingControl       = 1;  // Y: 0=always, 1=only aiming, 2=never (default 1)

    // Enums (INI range 0-3)
    int  universalFOVFix      = 0;  // 0=never, 1=cutscenes only, 2=aiming only, 3=always (default 0)

    // -------------------------------------------------------------------------
    // Proxy d3d11.dll-owned keys (NOT loaded from INI by the ASI).
    // These are kept here as runtime state for our reconstruction.
    // -------------------------------------------------------------------------
    int  stereoInCutscenes    = 1;  // 0=normal, 1=dynamic, 2=flat screen
    int  zoomOverride         = 0;  // 0=never, 1=cutscenes, 2=except cutscenes, 3=always
    bool stereo               = true;
    int  vrAPI                = 0;  // 0=autodetect, 1=Oculus, 2=OpenVR

    // -------------------------------------------------------------------------
    // Extension: configurable symmetric FOV (not in original ASI, added here
    // for tuning until RVRGetFrameDesc is fully reversed).
    // -------------------------------------------------------------------------
    float hmdFovDeg           = 100.f;  // INI key HMDFovDeg, range 60-130

    void Load(const char* iniPath);
};
