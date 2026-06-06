#include "RVRTypes.h"
#include "RVRFileLog.h"
#include <cstdio>
#include <cstring>
#include <Psapi.h>
#include "main.h"

// =============================================================================
// RVRBridge.cpp
//
// Resolves the VR runtime interface from the proxy d3d11.dll.
//
// DISCOVERY STRATEGY
// ------------------
// The proxy d3d11.dll is identified by enumerating all loaded modules and
// finding the one named "d3d11.dll" that exports "RVRWaitAndTrackHMD" with
// a non-null address. The real system d3d11.dll will return null for that
// symbol, so the two can be distinguished even when both are loaded.
//
// If the proxy is not found via EnumProcessModules (e.g. it was not yet
// loaded at init time), a direct LoadLibrary from the game directory is
// attempted as a fallback.
//
// SYMBOL REMAPPING
// ----------------
// The GetProcAddress call order and the slot each result goes into do NOT
// match intuitively. This remapping was confirmed by RE of the Resolve
// function at RVA 0x180002340 in the original ASI:
//
//   GetProcAddress("g_RVRData")          -> stored as g_RVRData
//   GetProcAddress("g_fRVRGameProj")     -> stored as g_fRVRGameProj
//   GetProcAddress("RVRLog")             -> stored as RVRLog
//   GetProcAddress("RVRGetFrameDesc")    -> stored as RVRGetFrameDesc
//   GetProcAddress("RVRGetPoseDesc")     -> stored as RVRSeqCheck
//   GetProcAddress("RVRSeqCheck")        -> stored as RVRWaitAndTrackHMD
//   GetProcAddress("RVRWaitAndTrackHMD") -> stored as RVRGetPoseFrame
//
// In the update loop the ASI calls:
//   [RVRWaitAndTrackHMD slot] = calls RVRSeqCheck (synchronize)
//   [RVRGetPoseFrame slot]    = calls RVRWaitAndTrackHMD (returns pose pointer)
//
// This is counterintuitive but confirmed. "RVRWaitAndTrackHMD" (as a DLL
// export name) is the blocking call that waits for the next VR frame and
// returns a pointer to the pose struct. "RVRSeqCheck" is the lightweight
// synchronization call that does not block.
//
// WHAT IS NOT YET KNOWN
// ---------------------
// - The exact internal layout of the pose struct pointer returned by
//   RVRGetPoseFrame beyond bytes [0x00..0x18].
// - Whether the proxy DLL performs eye separation internally or expects
//   the ASI to provide separate left/right view matrices.
//   Current evidence suggests the DLL handles it once the shared view
//   matrix is written to g_RVRData + 0x890.
// =============================================================================

static HMODULE LoadRVRModuleDirect() {
    char path[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    char* slash = strrchr(path, '\\');
    if (!slash) return nullptr;
    strcpy_s(slash+1, MAX_PATH-(slash+1-path), "d3d11.dll");
    RVR_LOG("  Trying direct LoadLibrary: %s", path);
    HMODULE h = LoadLibraryA(path);
    if (!h) { RVR_LOG("  LoadLibrary failed (error %lu)", GetLastError()); return nullptr; }
    void* gData = (void*)GetProcAddress(h, "g_RVRData");
    void* wait  = (void*)GetProcAddress(h, "RVRWaitAndTrackHMD");
    RVR_LOG("  d3d11.dll loaded at %p", h);
    RVR_LOG("    g_RVRData=%p RVRWaitAndTrackHMD=%p", gData, wait);
    if (gData && wait) { RVR_LOG("    -> 3DmiGTA proxy confirmed"); return h; }
    RVR_LOG("    -> d3d11.dll does not export RVR symbols");
    return nullptr;
}

static HMODULE FindRVRModule() {
    HMODULE mods[1024]; DWORD needed = 0;
    HANDLE proc = GetCurrentProcess();
    if (!K32EnumProcessModules(proc, mods, sizeof(mods), &needed)) return nullptr;
    int count = needed / sizeof(HMODULE);
    RVR_LOG("  Enumerating %d loaded modules...", count);
    HMODULE result = nullptr;
    for (int i = 0; i < count; ++i) {
        char path[MAX_PATH] = {};
        if (!K32GetModuleFileNameExA(proc, mods[i], path, MAX_PATH)) continue;
        const char* name = strrchr(path, '\\'); name = name ? name+1 : path;
        if (_stricmp(name, "d3d11.dll") != 0) continue;
        void* gData = (void*)GetProcAddress(mods[i], "g_RVRData");
        void* wait  = (void*)GetProcAddress(mods[i], "RVRWaitAndTrackHMD");
        RVR_LOG("  d3d11.dll at: %s", path);
        RVR_LOG("    g_RVRData=%p RVRWaitAndTrackHMD=%p", gData, wait);
        if (gData && wait) {
            RVR_LOG("    -> This is the 3DmiGTA proxy (exports RVR symbols)");
            result = mods[i];
        }
    }
    return result;
}

bool RVRBridge::Resolve(bool verbose) {
#define BLOG(...) do { if (verbose) RVR_LOG(__VA_ARGS__); } while(0)
    BLOG("--- Resolving bridge with d3d11.dll ---");

    HMODULE h = nullptr;
    if (verbose) {
        h = FindRVRModule();
    } else {
        h = GetModuleHandleA("d3d11.dll");
        if (h && !GetProcAddress(h, "g_RVRData")) h = nullptr;
    }
    if (!h) {
        BLOG("  3DmiGTA not loaded yet. Attempting LoadLibrary...");
        h = LoadRVRModuleDirect();
    }
    if (!h) {
        BLOG("  RESULT: could not obtain d3d11.dll with RVR symbols.");
        return false;
    }

    // Symbol remapping confirmed by RE (see file header).
    g_RVRData      = (void*)   GetProcAddress(h, "g_RVRData");
    g_fRVRGameProj = (float*)  GetProcAddress(h, "g_fRVRGameProj");
    RVRLog         = (RVRLog_t)            GetProcAddress(h, "RVRLog");
    RVRGetFrameDesc= (RVRGetFrameDesc_t)   GetProcAddress(h, "RVRGetFrameDesc");
    RVRSeqCheck    = (RVRSeqCheck_t)       GetProcAddress(h, "RVRGetPoseDesc");      // remapped
    RVRWaitAndTrackHMD = (RVRWaitAndTrackHMD_t) GetProcAddress(h, "RVRSeqCheck");    // remapped
    RVRGetPoseFrame    = (RVRGetPoseFrame_t)    GetProcAddress(h, "RVRWaitAndTrackHMD"); // remapped

    BLOG("  Symbols resolved:");
    BLOG("    g_RVRData=%p g_fRVRGameProj=%p RVRLog=%p",
         g_RVRData, g_fRVRGameProj, (void*)RVRLog);
    BLOG("    RVRGetFrameDesc=%p RVRSeqCheck=%p",
         (void*)RVRGetFrameDesc, (void*)RVRSeqCheck);
    BLOG("    RVRWaitAndTrackHMD=%p RVRGetPoseFrame=%p",
         (void*)RVRWaitAndTrackHMD, (void*)RVRGetPoseFrame);

    if (!IsReady()) {
        BLOG("  RESULT: missing required symbols.");
        return false;
    }
    BLOG("  RESULT: bridge RESOLVED OK");
#undef BLOG
    return true;
}

bool RVR_CheckGameVersion(RVRBridge& bridge) {
    int ver = (int)getGameVersion();
    // The original ASI binary accepts TWO valid versions (confirmed by RE):
    // the format string reads "expected %d or %d" with values 63 and 64.
    // Our patch patterns were validated against version 73 from the runtime log.
    // We warn on unsupported versions but continue.
    static const int VER_A = 63, VER_B = 64, VER_C = 73;
    bool supported = (ver == VER_A || ver == VER_B || ver == VER_C);
    if (!supported) {
        char msg[128];
        snprintf(msg, sizeof(msg),
            "WARNING: This game version is unsupported (ver=%d, expected %d or %d). "
            "RVR might work incorrectly, or not at all", ver, VER_A, VER_B);
        RVR_LOG("%s", msg);
        if (bridge.RVRLog)
            bridge.RVRLog("WARNING: This game version is unsupported. "
                          "RVR might work incorrectly, or not at all\n");
    } else {
        RVR_LOG("Detected game version %d (expected %d or %d or %d)", ver, VER_A, VER_B, VER_C);
    }
    return supported;
}
