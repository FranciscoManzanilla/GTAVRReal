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
static RVRGetFrameDescFn g_origGetFrameDesc = nullptr;
static volatile LONG g_hookReentry = 0;
static volatile LONG64 g_hookCalls = 0;
static volatile LONG64 g_hookSceneBefore = 0;
static volatile LONG64 g_hookSceneAfter = 0;
static volatile LONG64 g_hookSceneConsumed = 0;

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

    SpyLog("proxy=%s base=%p", modPath, h);
    SpyLog("exports g_RVRData=%p g_fRVRGameProj=%p RVRGetFrameDesc=%p(rva=%X) RVRGetPoseDesc=%p(rva=%X) RVRSeqCheck=%p(rva=%X) RVRWaitAndTrackHMD=%p(rva=%X) RVRLog=%p(rva=%X)",
           base, gameProj,
           getFrame, RvaOf(h, getFrame),
           getPoseDesc, RvaOf(h, getPoseDesc),
           seqCheck, RvaOf(h, seqCheck),
           waitTrack, RvaOf(h, waitTrack),
           rvrLog, RvaOf(h, rvrLog));
    SpyLog("watching target=[g_RVRData-0x1950], scene=[g_RVRData-0x1948], flags=[0x10,0x11,0x79,0xE0,0x840]");
    InstallGetFrameDescHook(getFrame);

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
            SpyLog("BEAT samples=%llu sceneNonNull=%llu targetNonNull=%llu e0NonZero=%llu df50NonZero=%llu sceneChanges=%llu targetChanges=%llu h890Changes=%llu h910Changes=%llu hookCalls=%lld hookSceneBefore=%lld hookSceneAfter=%lld hookConsumed=%lld",
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
                   (long long)hookConsumed);
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
