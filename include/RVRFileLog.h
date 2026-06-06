#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstdarg>
#include <cstring>

// =============================================================================
// RVRFileLog.h
//
// File-based logger that writes to GTAVRReal.log in the GTA V directory.
//
// MOTIVATION
// ----------
// The proxy d3d11.dll exposes RVRLog for in-DLL logging, but that system is
// unavailable until the bridge is resolved. If initialization fails, RVRLog
// never works. This logger writes independently of the bridge and is the
// primary diagnostic tool for debugging initialization problems.
//
// OUTPUT FILE
// -----------
// GTAVRReal.log, placed alongside GTA5.exe.
// The file is truncated on each DLL load (Init()) and appended during the
// session. Each line carries a wall-clock timestamp with milliseconds.
//
// DESIGN NOTES
// ------------
// - Each Write() call opens, appends one line, and closes the file.
//   This is intentionally slow but guarantees the log is flushed to disk
//   even if the game crashes immediately after the write.
// - No mutex is used. The logger is only called from the script thread
//   and the DllMain thread. Concurrent calls from the render thread
//   (via bridge.RVRLog) go to the d3d11.dll log, not this file.
// - The RVR_LOG macro writes to this file only. Bridge log calls
//   (bridge.RVRLog) write to the DLL's own internal log. In practice,
//   both logs are written for most events so they can be cross-referenced.
//
// WHAT COULD BE IMPROVED
// -----------------------
// - A mutex and a persistent FILE* would reduce open/close overhead for
//   high-frequency logging (e.g. per-frame debug output).
// - The log could mirror to OutputDebugStringA for DebugView capture.
// =============================================================================

namespace RVRFileLog {

inline const char* LogPath() {
    static char path[MAX_PATH] = {};
    if (path[0] == 0) {
        GetModuleFileNameA(nullptr, path, MAX_PATH);
        char* slash = strrchr(path, '\\');
        if (slash)
            strcpy_s(slash + 1, MAX_PATH - (slash + 1 - path), "GTAVRReal.log");
    }
    return path;
}

// Thread-safety: the trace points added for crash diagnosis are called from
// BOTH the script thread (tracking tick) and the render thread (trampoline
// handlers). Without serialization, concurrent fopen("a") calls cause sharing
// violations and lose exactly the lines we need most. A critical section
// guarantees every line reaches disk in order.
inline CRITICAL_SECTION& Lock() {
    static CRITICAL_SECTION cs;
    static bool init = false;
    if (!init) { InitializeCriticalSection(&cs); init = true; }
    return cs;
}

inline void Init() {
    InitializeCriticalSection(&Lock());  // ensure the CS exists early
    FILE* f = nullptr;
    fopen_s(&f, LogPath(), "w");
    if (!f) return;
    SYSTEMTIME st; GetLocalTime(&st);
    fprintf(f, "==============================================\n");
    fprintf(f, " GTAVRReal log -- %04d-%02d-%02d %02d:%02d:%02d\n",
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    fprintf(f, "==============================================\n");
    fclose(f);
}

inline void Write(const char* fmt, ...) {
    // Build the message once into a stack buffer so we hold the lock briefly
    // and can also mirror to the debugger output.
    char line[1024];
    SYSTEMTIME st; GetLocalTime(&st);
    int hdr = sprintf_s(line, "[%02d:%02d:%02d.%03d] ",
                        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    va_list ap; va_start(ap, fmt);
    int body = vsnprintf(line + hdr, sizeof(line) - hdr - 2, fmt, ap);
    va_end(ap);
    int len = hdr + (body > 0 ? body : 0);
    if (len > (int)sizeof(line) - 2) len = (int)sizeof(line) - 2;
    if (len == 0 || line[len-1] != '\n') { line[len++] = '\n'; line[len] = 0; }

    EnterCriticalSection(&Lock());
    FILE* f = nullptr;
    fopen_s(&f, LogPath(), "a");
    if (f) { fputs(line, f); fflush(f); fclose(f); }
    LeaveCriticalSection(&Lock());

    // Mirror to the debugger so DebugView / a VS debug session also captures it,
    // surviving even if the file write fails on a hard crash.
    OutputDebugStringA(line);
}

} // namespace RVRFileLog

#define RVR_LOG(...)  RVRFileLog::Write(__VA_ARGS__)

// One-shot trace: logs only the first time this exact call site fires, so it is
// safe to drop into per-frame render-thread code without flooding the log.
#define RVR_TRACE_ONCE(...)                            \
    do {                                               \
        static bool _rvr_once = false;                 \
        if (!_rvr_once) { _rvr_once = true; RVR_LOG(__VA_ARGS__); } \
    } while (0)
