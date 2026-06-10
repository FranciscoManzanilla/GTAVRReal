#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <psapi.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

static volatile LONG g_running = 1;
static char g_logPath[MAX_PATH] = {};
static uint8_t* g_rvrData = nullptr;

using RVRGetFrameDescFn = int(__fastcall*)(uint8_t, void*);
using RVRSeqCheckFn = void(__fastcall*)(uint8_t);
using RVRWaitTrackFn = void*(__fastcall*)(void*, uint32_t);
using RVRPoseDescFn = uint32_t(__fastcall*)(const void*, void*);
using AsiAdjustViewFn = void(__fastcall*)(void*);

static RVRGetFrameDescFn g_origGetFrameDesc = nullptr;
static RVRSeqCheckFn g_origSeqCheck = nullptr;
static RVRWaitTrackFn g_origWaitTrack = nullptr;
static RVRPoseDescFn g_origPoseDesc = nullptr;
static AsiAdjustViewFn g_origAsiAdjustView = nullptr;

static volatile LONG g_hookReentry = 0;
static volatile LONG64 g_hookCalls = 0;
static volatile LONG64 g_hookSceneBefore = 0;
static volatile LONG64 g_hookSceneAfter = 0;
static volatile LONG64 g_hookSceneConsumed = 0;
static volatile LONG64 g_seqCalls = 0;
static volatile LONG64 g_waitCalls = 0;
static volatile LONG64 g_poseDescCalls = 0;
static volatile LONG64 g_asiAdjustCalls = 0;

#ifndef GTAVRSPY_ENABLE_INLINE_HOOKS
#define GTAVRSPY_ENABLE_INLINE_HOOKS 0
#endif

static void DetourSeqCheck(uint8_t cl);
static void* DetourWaitTrack(void* a0, uint32_t a1);
static uint32_t DetourPoseDesc(const void* poseBuf, void* outDesc);
static void DetourAsiAdjustView(void* view);

static void BuildLogPath() {
    char path[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    char* slash = strrchr(path, '\\');
    if (slash) {
        slash[1] = '\0';
        strcpy_s(g_logPath, path);
        strcat_s(g_logPath, "GTAVRSpy.log");
    } else {
        strcpy_s(g_logPath, "GTAVRSpy.log");
    }
}

static void SpyLog(const char* fmt, ...) {
    if (!g_logPath[0]) BuildLogPath();

    FILE* f = nullptr;
    fopen_s(&f, g_logPath, "ab");
    if (!f) return;

    SYSTEMTIME st = {};
    GetLocalTime(&st);
    fprintf(f, "[%02u:%02u:%02u.%03u] ",
            st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
    fprintf(f, "\r\n");
    fclose(f);
}

template <typename T>
static bool ReadSafe(const void* addr, T& out) {
    if (!addr) return false;
    __try {
        out = *(const T*)addr;
        return true;
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        memset(&out, 0, sizeof(out));
        return false;
    }
}

static uint64_t HashRangeSafe(const void* addr, size_t len) {
    if (!addr || !len) return 0;
    uint64_t h = 1469598103934665603ull;
    __try {
        const uint8_t* p = (const uint8_t*)addr;
        for (size_t i = 0; i < len; ++i) {
            h ^= p[i];
            h *= 1099511628211ull;
        }
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        return 0;
    }
    return h;
}

static HMODULE FindProxyD3D11() {
    HMODULE mods[1024] = {};
    DWORD needed = 0;
    HANDLE proc = GetCurrentProcess();
    if (!K32EnumProcessModules(proc, mods, sizeof(mods), &needed)) return nullptr;

    int count = (int)(needed / sizeof(HMODULE));
    for (int i = 0; i < count; ++i) {
        char path[MAX_PATH] = {};
        if (!K32GetModuleFileNameExA(proc, mods[i], path, MAX_PATH)) continue;
        const char* name = strrchr(path, '\\');
        name = name ? name + 1 : path;
        if (_stricmp(name, "d3d11.dll") != 0) continue;
        if (GetProcAddress(mods[i], "g_RVRData") &&
            GetProcAddress(mods[i], "RVRWaitAndTrackHMD")) {
            return mods[i];
        }
    }
    return nullptr;
}

static HMODULE FindLoadedModuleByName(const char* wantedName) {
    HMODULE mods[1024] = {};
    DWORD needed = 0;
    HANDLE proc = GetCurrentProcess();
    if (!K32EnumProcessModules(proc, mods, sizeof(mods), &needed)) return nullptr;

    int count = (int)(needed / sizeof(HMODULE));
    for (int i = 0; i < count; ++i) {
        char path[MAX_PATH] = {};
        if (!K32GetModuleFileNameExA(proc, mods[i], path, MAX_PATH)) continue;
        const char* name = strrchr(path, '\\');
        name = name ? name + 1 : path;
        if (_stricmp(name, wantedName) == 0) return mods[i];
    }
    return nullptr;
}

static uint32_t ModuleSize(HMODULE h) {
    MODULEINFO mi = {};
    if (!h || !K32GetModuleInformation(GetCurrentProcess(), h, &mi, sizeof(mi))) return 0;
    return mi.SizeOfImage;
}

static void HexBytesSafe(const void* addr, size_t len, char* out, size_t outLen) {
    if (!out || !outLen) return;
    out[0] = '\0';
    if (!addr || outLen < 4) return;

    size_t pos = 0;
    __try {
        const uint8_t* p = (const uint8_t*)addr;
        for (size_t i = 0; i < len && pos + 4 < outLen; ++i) {
            int n = sprintf_s(out + pos, outLen - pos, "%02X%s", p[i], (i + 1 == len) ? "" : " ");
            if (n <= 0) break;
            pos += (size_t)n;
        }
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        strcpy_s(out, outLen, "<read-failed>");
    }
}

static void LogModuleByName(const char* name) {
    HMODULE h = FindLoadedModuleByName(name);
    if (!h) {
        SpyLog("module %s not loaded", name);
        return;
    }

    char path[MAX_PATH] = {};
    K32GetModuleFileNameExA(GetCurrentProcess(), h, path, MAX_PATH);
    char bytes3970[96] = {};
    HexBytesSafe((uint8_t*)h + 0x3970, 24, bytes3970, sizeof(bytes3970));
    SpyLog("module %s base=%p size=0x%X path=%s rva3970=%s hash000=%016llX hash3970=%016llX",
           name, h, ModuleSize(h), path, bytes3970,
           (unsigned long long)HashRangeSafe(h, 0x1000),
           (unsigned long long)HashRangeSafe((uint8_t*)h + 0x3970, 0x100));
}

static uint32_t RvaOf(HMODULE h, FARPROC p) {
    if (!h || !p) return 0;
    return (uint32_t)((uintptr_t)p - (uintptr_t)h);
}

struct Sample {
    uint32_t state;
    uint32_t f34;
    uint32_t f3c;
    uint8_t i10;
    uint8_t i11;
    uint8_t d789;
    uint8_t e0;
    uint8_t df50;
    void* mgr;
    void* c0;
    void* target;
    void* scene;
    uint64_t h000;
    uint64_t h77c;
    uint64_t h890;
    uint64_t h910;
};

static Sample TakeSample(uint8_t* base) {
    Sample s = {};
    if (!base) return s;

    ReadSafe(base + 0x00, s.state);
    ReadSafe(base + 0x34, s.f34);
    ReadSafe(base + 0x3C, s.f3c);
    ReadSafe(base + 0x10, s.i10);
    ReadSafe(base + 0x11, s.i11);
    ReadSafe(base + 0x79, s.d789);
    ReadSafe(base + 0xE0, s.e0);
    ReadSafe(base + 0x840, s.df50);
    ReadSafe(base + 0x08, s.mgr);
    ReadSafe(base + 0xC0, s.c0);
    ReadSafe(base - 0x1950, s.target); // proxy global 0x36BDC0
    ReadSafe(base - 0x1948, s.scene);  // proxy global 0x36BDC8

    s.h000 = HashRangeSafe(base + 0x00, 0x120);
    s.h77c = HashRangeSafe(base + 0x77C, 0x70);
    s.h890 = HashRangeSafe(base + 0x890, 0x200);
    s.h910 = HashRangeSafe(base + 0x910, 0x200);
    return s;
}

static bool PointerStateChanged(const Sample& a, const Sample& b) {
    return a.mgr != b.mgr || a.c0 != b.c0 || a.target != b.target ||
           a.scene != b.scene || a.i10 != b.i10 || a.i11 != b.i11 ||
           a.d789 != b.d789 || a.e0 != b.e0 || a.df50 != b.df50;
}

static void LogSample(const char* tag, const Sample& s) {
    SpyLog("%s state=%u [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u mgr=%p c0=%p target=%p scene=%p h000=%016llX h77c=%016llX h890=%016llX h910=%016llX",
           tag, s.state, s.f34, s.f3c, s.i10, s.i11, s.d789, s.e0, s.df50,
           s.mgr, s.c0, s.target, s.scene,
           (unsigned long long)s.h000,
           (unsigned long long)s.h77c,
           (unsigned long long)s.h890,
           (unsigned long long)s.h910);
}

static void WriteAbsJump(uint8_t* p, void* target) {
    p[0] = 0x48; // mov rax, imm64
    p[1] = 0xB8;
    *(uint64_t*)(p + 2) = (uint64_t)target;
    p[10] = 0xFF; // jmp rax
    p[11] = 0xE0;
}

static void ReadCoreState(void** scene, uint32_t* f34, uint32_t* f3c, uint8_t* i10,
                          uint8_t* i11, uint8_t* e0, uint8_t* df50, uint8_t* d789) {
    if (scene) *scene = nullptr;
    if (f34) *f34 = 0;
    if (f3c) *f3c = 0;
    if (i10) *i10 = 0;
    if (i11) *i11 = 0;
    if (e0) *e0 = 0;
    if (df50) *df50 = 0;
    if (d789) *d789 = 0;
    if (!g_rvrData) return;

    if (scene) ReadSafe(g_rvrData - 0x1948, *scene);
    if (f34) ReadSafe(g_rvrData + 0x34, *f34);
    if (f3c) ReadSafe(g_rvrData + 0x3C, *f3c);
    if (i10) ReadSafe(g_rvrData + 0x10, *i10);
    if (i11) ReadSafe(g_rvrData + 0x11, *i11);
    if (d789) ReadSafe(g_rvrData + 0x79, *d789);
    if (e0) ReadSafe(g_rvrData + 0xE0, *e0);
    if (df50) ReadSafe(g_rvrData + 0x840, *df50);
}

static void LogHotCall(const char* name, LONG64 callNo, const char* fmt, ...) {
    if (callNo > 128 && (callNo & 0x3F) != 0) return;

    char payload[512] = {};
    va_list ap;
    va_start(ap, fmt);
    vsprintf_s(payload, fmt, ap);
    va_end(ap);
    SpyLog("HOOK %s call=%lld %s", name, (long long)callNo, payload);
}

static void DetourSeqCheck(uint8_t cl) {
    void* sceneBefore = nullptr;
    void* sceneAfter = nullptr;
    uint32_t f34 = 0, f3c = 0;
    uint8_t i10 = 0, i11 = 0, e0 = 0, df50 = 0, d789 = 0;
    ReadCoreState(&sceneBefore, &f34, &f3c, &i10, &i11, &e0, &df50, &d789);

    LONG64 callNo = InterlockedIncrement64(&g_seqCalls);
    if (g_origSeqCheck) g_origSeqCheck(cl);

    ReadCoreState(&sceneAfter, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    LogHotCall("RVRSeqCheck", callNo,
               "cl=0x%02X [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u scene_before=%p scene_after=%p",
               cl, f34, f3c, i10, i11, d789, e0, df50, sceneBefore, sceneAfter);
}

static void* DetourWaitTrack(void* a0, uint32_t a1) {
    void* sceneBefore = nullptr;
    void* sceneAfter = nullptr;
    uint32_t f34 = 0, f3c = 0;
    uint8_t i10 = 0, i11 = 0, e0 = 0, df50 = 0, d789 = 0;
    ReadCoreState(&sceneBefore, &f34, &f3c, &i10, &i11, &e0, &df50, &d789);

    LONG64 callNo = InterlockedIncrement64(&g_waitCalls);
    void* ret = nullptr;
    if (g_origWaitTrack) ret = g_origWaitTrack(a0, a1);

    ReadCoreState(&sceneAfter, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    LogHotCall("RVRWaitAndTrackHMD", callNo,
               "rcx=%p edx=0x%08X ret=%p [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u scene_before=%p scene_after=%p",
               a0, a1, ret, f34, f3c, i10, i11, d789, e0, df50, sceneBefore, sceneAfter);
    return ret;
}

static uint32_t DetourPoseDesc(const void* poseBuf, void* outDesc) {
    void* sceneBefore = nullptr;
    void* sceneAfter = nullptr;
    uint32_t f34 = 0, f3c = 0;
    uint8_t i10 = 0, i11 = 0, e0 = 0, df50 = 0, d789 = 0;
    ReadCoreState(&sceneBefore, &f34, &f3c, &i10, &i11, &e0, &df50, &d789);

    LONG64 callNo = InterlockedIncrement64(&g_poseDescCalls);
    uint32_t ret = 0;
    if (g_origPoseDesc) ret = g_origPoseDesc(poseBuf, outDesc);

    ReadCoreState(&sceneAfter, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    LogHotCall("RVRGetPoseDesc", callNo,
               "pose=%p out=%p ret=%u [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u scene_before=%p scene_after=%p",
               poseBuf, outDesc, ret, f34, f3c, i10, i11, d789, e0, df50, sceneBefore, sceneAfter);
    return ret;
}

static void DetourAsiAdjustView(void* view) {
    void* sceneBefore = nullptr;
    void* sceneAfter = nullptr;
    uint32_t f34 = 0, f3c = 0;
    uint8_t i10 = 0, i11 = 0, e0 = 0, df50 = 0, d789 = 0;
    ReadCoreState(&sceneBefore, &f34, &f3c, &i10, &i11, &e0, &df50, &d789);

    LONG64 callNo = InterlockedIncrement64(&g_asiAdjustCalls);
    if (g_origAsiAdjustView) g_origAsiAdjustView(view);

    ReadCoreState(&sceneAfter, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    LogHotCall("ASI AdjustViewInverse", callNo,
               "view=%p [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u scene_before=%p scene_after=%p",
               view, f34, f3c, i10, i11, d789, e0, df50, sceneBefore, sceneAfter);
}

static bool InstallCopiedHook(const char* name, FARPROC fn, const uint8_t* expected,
                              size_t patchLen, void* detour, void** originalOut) {
    if (!fn || !expected || !detour || !originalOut || patchLen < 12) return false;
    uint8_t* target = (uint8_t*)fn;
    if (memcmp(target, expected, patchLen) != 0) {
        char got[128] = {};
        HexBytesSafe(target, patchLen, got, sizeof(got));
        SpyLog("HOOK %s skipped: unexpected prologue %s", name, got);
        return false;
    }

    uint8_t* tramp = (uint8_t*)VirtualAlloc(nullptr, patchLen + 32, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!tramp) {
        SpyLog("HOOK %s failed: VirtualAlloc error %lu", name, GetLastError());
        return false;
    }
    memcpy(tramp, target, patchLen);
    WriteAbsJump(tramp + patchLen, target + patchLen);
    *originalOut = tramp;

    DWORD old = 0;
    if (!VirtualProtect(target, patchLen, PAGE_EXECUTE_READWRITE, &old)) {
        SpyLog("HOOK %s failed: VirtualProtect error %lu", name, GetLastError());
        return false;
    }
    WriteAbsJump(target, detour);
    if (patchLen > 12) memset(target + 12, 0x90, patchLen - 12);
    FlushInstructionCache(GetCurrentProcess(), target, patchLen);
    VirtualProtect(target, patchLen, old, &old);

    SpyLog("HOOK %s installed target=%p trampoline=%p len=%llu", name, target, tramp, (unsigned long long)patchLen);
    return true;
}

static bool InstallSeqCheckHook(FARPROC fn) {
    if (!fn) return false;
    uint8_t* target = (uint8_t*)fn;
    const uint8_t expected[16] = {
        0x40, 0x57,
        0x48, 0x83, 0xEC, 0x20,
        0x80, 0x3D, 0xFF, 0xA9, 0x2E, 0x00, 0x00,
        0x0F, 0xB6, 0xF9
    };
    if (memcmp(target, expected, sizeof(expected)) != 0) {
        char got[128] = {};
        HexBytesSafe(target, sizeof(expected), got, sizeof(got));
        SpyLog("HOOK RVRSeqCheck skipped: unexpected prologue %s", got);
        return false;
    }

    uint8_t* tramp = (uint8_t*)VirtualAlloc(nullptr, 96, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!tramp) {
        SpyLog("HOOK RVRSeqCheck failed: VirtualAlloc error %lu", GetLastError());
        return false;
    }

    size_t o = 0;
    const uint8_t pushSub[] = { 0x40, 0x57, 0x48, 0x83, 0xEC, 0x20 };
    memcpy(tramp + o, pushSub, sizeof(pushSub)); o += sizeof(pushSub);
    tramp[o++] = 0x48; // mov rax, imm64
    tramp[o++] = 0xB8;
    *(uint64_t*)(tramp + o) = (uint64_t)(target + 13 + 0x2EA9FF);
    o += 8;
    const uint8_t cmpMovzx[] = { 0x80, 0x38, 0x00, 0x0F, 0xB6, 0xF9 };
    memcpy(tramp + o, cmpMovzx, sizeof(cmpMovzx)); o += sizeof(cmpMovzx);
    WriteAbsJump(tramp + o, target + sizeof(expected));
    g_origSeqCheck = (RVRSeqCheckFn)tramp;

    DWORD old = 0;
    if (!VirtualProtect(target, sizeof(expected), PAGE_EXECUTE_READWRITE, &old)) {
        SpyLog("HOOK RVRSeqCheck failed: VirtualProtect error %lu", GetLastError());
        return false;
    }
    WriteAbsJump(target, (void*)DetourSeqCheck);
    memset(target + 12, 0x90, sizeof(expected) - 12);
    FlushInstructionCache(GetCurrentProcess(), target, sizeof(expected));
    VirtualProtect(target, sizeof(expected), old, &old);

    SpyLog("HOOK RVRSeqCheck installed target=%p trampoline=%p", target, tramp);
    return true;
}

static bool InstallGetFrameDescHook(FARPROC fn) {
    if (!fn) return false;
    uint8_t* target = (uint8_t*)fn;

    const uint8_t expected[14] = {
        0x48, 0x83, 0xEC, 0x38,             // sub rsp,38h
        0x4C, 0x8B, 0xD2,                   // mov r10,rdx
        0x4C, 0x8D, 0x05, 0xBA, 0x4B, 0x23, 0x00 // lea r8,[base+0x2B96F8]
    };
    if (memcmp(target, expected, sizeof(expected)) != 0) {
        SpyLog("HOOK RVRGetFrameDesc skipped: unexpected prologue %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
               target[0], target[1], target[2], target[3], target[4], target[5], target[6],
               target[7], target[8], target[9], target[10], target[11], target[12], target[13]);
        return false;
    }

    uint8_t* tramp = (uint8_t*)VirtualAlloc(nullptr, 96, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!tramp) {
        SpyLog("HOOK RVRGetFrameDesc failed: VirtualAlloc error %lu", GetLastError());
        return false;
    }

    size_t o = 0;
    // Recreate the stolen 14-byte prologue, translating RIP-relative lea to movabs.
    const uint8_t subRsp[] = { 0x48, 0x83, 0xEC, 0x38 };
    memcpy(tramp + o, subRsp, sizeof(subRsp)); o += sizeof(subRsp);
    const uint8_t movR10Rdx[] = { 0x4C, 0x8B, 0xD2 };
    memcpy(tramp + o, movR10Rdx, sizeof(movR10Rdx)); o += sizeof(movR10Rdx);
    tramp[o++] = 0x49; // mov r8, imm64
    tramp[o++] = 0xB8;
    *(uint64_t*)(tramp + o) = (uint64_t)(target + 14 + 0x234BBA);
    o += 8;
    WriteAbsJump(tramp + o, target + 14);
    g_origGetFrameDesc = (RVRGetFrameDescFn)tramp;

    DWORD old = 0;
    if (!VirtualProtect(target, sizeof(expected), PAGE_EXECUTE_READWRITE, &old)) {
        SpyLog("HOOK RVRGetFrameDesc failed: VirtualProtect error %lu", GetLastError());
        return false;
    }
    WriteAbsJump(target, (void*)+[](uint8_t counter, void* out) -> int {
        void* sceneBefore = nullptr;
        void* sceneAfter = nullptr;
        uint32_t f34 = 0, f3c = 0;
        uint8_t i10 = 0, i11 = 0, e0 = 0, df50 = 0, d789 = 0;

        if (g_rvrData) {
            ReadSafe(g_rvrData - 0x1948, sceneBefore);
            ReadSafe(g_rvrData + 0x34, f34);
            ReadSafe(g_rvrData + 0x3C, f3c);
            ReadSafe(g_rvrData + 0x10, i10);
            ReadSafe(g_rvrData + 0x11, i11);
            ReadSafe(g_rvrData + 0x79, d789);
            ReadSafe(g_rvrData + 0xE0, e0);
            ReadSafe(g_rvrData + 0x840, df50);
        }

        InterlockedIncrement64(&g_hookCalls);
        if (sceneBefore) InterlockedIncrement64(&g_hookSceneBefore);

        int rc = 0;
        if (g_origGetFrameDesc) rc = g_origGetFrameDesc(counter, out);

        if (g_rvrData) ReadSafe(g_rvrData - 0x1948, sceneAfter);
        if (sceneAfter) InterlockedIncrement64(&g_hookSceneAfter);
        if (sceneBefore && !sceneAfter) InterlockedIncrement64(&g_hookSceneConsumed);

        LONG depth = InterlockedIncrement(&g_hookReentry);
        LONG64 callNo = InterlockedCompareExchange64(&g_hookCalls, 0, 0);
        if (depth == 1 && (callNo <= 256 || sceneBefore || sceneAfter || (callNo & 0x3F) == 0)) {
            SpyLog("HOOK GetFrameDesc call=%lld ctr=%u out=%p rc=%d [34]=%u [3C]=%u i10=%u i11=%u d789=%u e0=%u df50=%u scene_before=%p scene_after=%p",
                   (long long)callNo, counter, out, rc, f34, f3c, i10, i11, d789, e0, df50, sceneBefore, sceneAfter);
        }
        InterlockedDecrement(&g_hookReentry);
        return rc;
    });
    memset(target + 12, 0x90, sizeof(expected) - 12);
    FlushInstructionCache(GetCurrentProcess(), target, sizeof(expected));
    VirtualProtect(target, sizeof(expected), old, &old);

    SpyLog("HOOK RVRGetFrameDesc installed target=%p trampoline=%p", target, tramp);
    return true;
}

static bool InstallWaitTrackHook(FARPROC fn) {
    const uint8_t expected[16] = {
        0x40, 0x55,
        0x56,
        0x57,
        0x41, 0x55,
        0x41, 0x56,
        0x48, 0x8D, 0xAC, 0x24, 0x40, 0x40, 0xFF, 0xFF
    };
    return InstallCopiedHook("RVRWaitAndTrackHMD", fn, expected, sizeof(expected),
                             (void*)DetourWaitTrack, (void**)&g_origWaitTrack);
}

static bool InstallPoseDescHook(FARPROC fn) {
    const uint8_t expected[15] = {
        0x48, 0x8B, 0xC4,
        0x48, 0x89, 0x58, 0x10,
        0x57,
        0x48, 0x81, 0xEC, 0xA0, 0x00, 0x00, 0x00
    };
    return InstallCopiedHook("RVRGetPoseDesc", fn, expected, sizeof(expected),
                             (void*)DetourPoseDesc, (void**)&g_origPoseDesc);
}

static bool InstallAsiAdjustHook(HMODULE asi) {
    if (!asi) return false;
    uint8_t* fn = (uint8_t*)asi + 0x3970;
    const uint8_t expected[16] = {
        0x40, 0x55,
        0x53,
        0x48, 0x8D, 0xAC, 0x24, 0x28, 0xDD, 0xFF, 0xFF,
        0xB8, 0xD8, 0x23, 0x00, 0x00
    };
    return InstallCopiedHook("RealVR.asi AdjustViewInverse", (FARPROC)fn, expected, sizeof(expected),
                             (void*)DetourAsiAdjustView, (void**)&g_origAsiAdjustView);
}

static DWORD WINAPI SpyThread(void*) {
    BuildLogPath();
    DeleteFileA(g_logPath);
    SpyLog("GTAVRSpy starting");

    HMODULE h = nullptr;
    while (InterlockedCompareExchange(&g_running, 1, 1) && !h) {
        h = FindProxyD3D11();
        if (!h) Sleep(250);
    }
    if (!h) return 0;

    char modPath[MAX_PATH] = {};
    K32GetModuleFileNameExA(GetCurrentProcess(), h, modPath, MAX_PATH);

    uint8_t* base = (uint8_t*)GetProcAddress(h, "g_RVRData");
    g_rvrData = base;
    FARPROC gameProj = GetProcAddress(h, "g_fRVRGameProj");
    FARPROC getFrame = GetProcAddress(h, "RVRGetFrameDesc");
    FARPROC getPoseDesc = GetProcAddress(h, "RVRGetPoseDesc");
    FARPROC seqCheck = GetProcAddress(h, "RVRSeqCheck");
    FARPROC waitTrack = GetProcAddress(h, "RVRWaitAndTrackHMD");
    FARPROC rvrLog = GetProcAddress(h, "RVRLog");

    LogModuleByName("RealVR.asi");
    LogModuleByName("GTAVRSpy.asi");

    SpyLog("proxy=%s base=%p", modPath, h);
    SpyLog("exports g_RVRData=%p g_fRVRGameProj=%p RVRGetFrameDesc=%p(rva=%X) RVRGetPoseDesc=%p(rva=%X) RVRSeqCheck=%p(rva=%X) RVRWaitAndTrackHMD=%p(rva=%X) RVRLog=%p(rva=%X)",
           base, gameProj,
           getFrame, RvaOf(h, getFrame),
           getPoseDesc, RvaOf(h, getPoseDesc),
           seqCheck, RvaOf(h, seqCheck),
           waitTrack, RvaOf(h, waitTrack),
           rvrLog, RvaOf(h, rvrLog));
    SpyLog("watching target=[g_RVRData-0x1950], scene=[g_RVRData-0x1948], flags=[0x10,0x11,0x79,0xE0,0x840]");
#if GTAVRSPY_ENABLE_INLINE_HOOKS
    InstallGetFrameDescHook(getFrame);
    InstallSeqCheckHook(seqCheck);
    InstallWaitTrackHook(waitTrack);
    InstallPoseDescHook(getPoseDesc);
    InstallAsiAdjustHook(FindLoadedModuleByName("RealVR.asi"));
#else
    SpyLog("inline hooks disabled: passive memory/module spy only");
#endif

    Sample prev = TakeSample(base);
    LogSample("FIRST", prev);

    DWORD lastStateMs = GetTickCount();
    DWORD lastBeatMs = lastStateMs;
    uint64_t samples = 0;
    uint64_t sceneNonNull = 0;
    uint64_t targetNonNull = 0;
    uint64_t e0NonZero = 0;
    uint64_t df50NonZero = 0;
    uint64_t sceneChanges = 0;
    uint64_t targetChanges = 0;
    uint64_t hash890Changes = 0;
    uint64_t hash910Changes = 0;

    while (InterlockedCompareExchange(&g_running, 1, 1)) {
        Sleep(5);
        Sample cur = TakeSample(base);
        ++samples;
        if (cur.scene) ++sceneNonNull;
        if (cur.target) ++targetNonNull;
        if (cur.e0) ++e0NonZero;
        if (cur.df50) ++df50NonZero;
        if (cur.scene != prev.scene) ++sceneChanges;
        if (cur.target != prev.target) ++targetChanges;
        if (cur.h890 != prev.h890) ++hash890Changes;
        if (cur.h910 != prev.h910) ++hash910Changes;

        DWORD now = GetTickCount();
        if (PointerStateChanged(prev, cur)) {
            LogSample("EDGE", cur);
        } else if (now - lastStateMs >= 250) {
            LogSample("STATE", cur);
            lastStateMs = now;
        }

        if (now - lastBeatMs >= 2000) {
            LONG64 hookCalls = InterlockedExchange64(&g_hookCalls, 0);
            LONG64 hookBefore = InterlockedExchange64(&g_hookSceneBefore, 0);
            LONG64 hookAfter = InterlockedExchange64(&g_hookSceneAfter, 0);
            LONG64 hookConsumed = InterlockedExchange64(&g_hookSceneConsumed, 0);
            LONG64 seqCalls = InterlockedExchange64(&g_seqCalls, 0);
            LONG64 waitCalls = InterlockedExchange64(&g_waitCalls, 0);
            LONG64 poseCalls = InterlockedExchange64(&g_poseDescCalls, 0);
            LONG64 asiCalls = InterlockedExchange64(&g_asiAdjustCalls, 0);
            SpyLog("BEAT samples=%llu sceneNonNull=%llu targetNonNull=%llu e0NonZero=%llu df50NonZero=%llu sceneChanges=%llu targetChanges=%llu h890Changes=%llu h910Changes=%llu hookCalls=%lld hookSceneBefore=%lld hookSceneAfter=%lld hookConsumed=%lld seqCalls=%lld waitCalls=%lld poseDescCalls=%lld asiAdjustCalls=%lld",
                   (unsigned long long)samples,
                   (unsigned long long)sceneNonNull,
                   (unsigned long long)targetNonNull,
                   (unsigned long long)e0NonZero,
                   (unsigned long long)df50NonZero,
                   (unsigned long long)sceneChanges,
                   (unsigned long long)targetChanges,
                   (unsigned long long)hash890Changes,
                   (unsigned long long)hash910Changes,
                   (long long)hookCalls,
                   (long long)hookBefore,
                   (long long)hookAfter,
                   (long long)hookConsumed,
                   (long long)seqCalls,
                   (long long)waitCalls,
                   (long long)poseCalls,
                   (long long)asiCalls);
            samples = sceneNonNull = targetNonNull = e0NonZero = df50NonZero = 0;
            sceneChanges = targetChanges = hash890Changes = hash910Changes = 0;
            lastBeatMs = now;
        }

        prev = cur;
    }

    SpyLog("GTAVRSpy stopping");
    return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        InterlockedExchange(&g_running, 1);
        HANDLE t = CreateThread(nullptr, 0, SpyThread, nullptr, 0, nullptr);
        if (t) CloseHandle(t);
    } else if (reason == DLL_PROCESS_DETACH) {
        InterlockedExchange(&g_running, 0);
    }
    return TRUE;
}
