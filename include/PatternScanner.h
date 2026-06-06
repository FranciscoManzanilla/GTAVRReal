#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <cstdint>

// =============================================================================
// PatternScanner.h
//
// Byte pattern scanner for GTA5.exe, reconstructed from the original ASI's
// internal scanner (functions at RVA 0x1a60 and 0x1b30).
//
// ORIGINAL ALGORITHM (0x1a60)
// ----------------------------
// 1. GetModuleHandle(NULL)      -> base address of GTA5.exe
// 2. K32GetModuleInformation    -> image size
// 3. Linear scan byte-by-byte with mask:
//      'x' (0x78) = compare byte exactly
//      any other  = wildcard (skip comparison)
//
// This implementation extends the original with:
// - Restriction to the .text section to avoid scanning unmapped PE gaps,
//   which caused occasional access violations in the original.
// - RIP-relative resolution helper (ResolveRIP) for patterns that locate
//   an instruction whose operand is itself the target address.
// - String anchor search (FindString + FindLEAReferences) as a more
//   version-stable alternative to raw byte patterns for some sites.
//
// THREAD SAFETY
// -------------
// All functions are read-only with respect to the scanned memory. They are
// safe to call from the script thread during initialization. Do not call
// them from the render thread during active gameplay.
//
// PATTERN STABILITY
// -----------------
// Raw byte patterns can break on game updates because the compiler may
// reorder or re-encode instructions. The string anchor approach is more
// stable since GTA's debug/error strings rarely change between updates.
// For the six patch sites in this mod, raw patterns are used because the
// confirmed addresses were derived from a runtime log and the patterns are
// short enough to be unique.
//
// WHAT COULD BE IMPROVED
// -----------------------
// - The RestrictToText heuristic searches for a section named exactly ".text".
//   Some GTA builds may use a different section layout. A fallback to full
//   image scan would make this more robust.
// - MaskScan performs a linear byte comparison. A Boyer-Moore or similar
//   approach would be faster, though the scan runs only once at startup so
//   performance is not critical.
// =============================================================================

namespace Scanner {

// ----------------------------------------------------------------------------
// Module
// Represents the address range of a loaded module to scan.
// Main() returns the .text section of GTA5.exe.
// Named() returns the full image range of any named module.
// ----------------------------------------------------------------------------
struct Module {
    uintptr_t base = 0;
    size_t    size = 0;

    static Module Main() {
        Module m;
        HMODULE h = GetModuleHandleA(nullptr);
        MODULEINFO mi{};
        K32GetModuleInformation(GetCurrentProcess(), h, &mi, sizeof(mi));
        m.base = (uintptr_t)mi.lpBaseOfDll;
        m.size = mi.SizeOfImage;
        m.RestrictToText(h);
        return m;
    }

    static Module Named(const char* name) {
        Module m;
        HMODULE h = GetModuleHandleA(name);
        if (!h) return m;
        MODULEINFO mi{};
        K32GetModuleInformation(GetCurrentProcess(), h, &mi, sizeof(mi));
        m.base = (uintptr_t)mi.lpBaseOfDll;
        m.size = mi.SizeOfImage;
        return m;
    }

    // Restrict the scan range to the .text section to avoid unmapped gaps.
    void RestrictToText(HMODULE h) {
        auto dos = (IMAGE_DOS_HEADER*)h;
        if (dos->e_magic != IMAGE_DOS_SIGNATURE) return;
        auto nt = (IMAGE_NT_HEADERS*)((uint8_t*)h + dos->e_lfanew);
        if (nt->Signature != IMAGE_NT_SIGNATURE) return;
        auto sec = IMAGE_FIRST_SECTION(nt);
        for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i) {
            if (memcmp(sec[i].Name, ".text", 5) == 0) {
                base = (uintptr_t)h + sec[i].VirtualAddress;
                size = sec[i].Misc.VirtualSize;
                return;
            }
        }
    }
};

// ----------------------------------------------------------------------------
// MaskScan
// Linear scan with an explicit mask string. 'x' = match, anything else = skip.
// Reproduces the original ASI scanner loop exactly.
// Returns 0 if not found.
// ----------------------------------------------------------------------------
inline uintptr_t MaskScan(const Module& mod, const uint8_t* pattern, const char* mask) {
    size_t len = strlen(mask);
    const uint8_t* base = (const uint8_t*)mod.base;
    for (size_t i = 0; i + len <= mod.size; ++i) {
        bool found = true;
        for (size_t j = 0; j < len; ++j) {
            if (mask[j] == 'x' && base[i+j] != pattern[j]) {
                found = false; break;
            }
        }
        if (found) return mod.base + i;
    }
    return 0;
}

// ----------------------------------------------------------------------------
// TextScan
// Accepts a pattern as a human-readable hex string: "48 8B ?? 05 C3".
// '?' or '??' is a wildcard. Internally converts to byte/mask arrays and
// calls MaskScan.
// ----------------------------------------------------------------------------
inline uintptr_t TextScan(const Module& mod, const char* textPattern) {
    std::vector<uint8_t> bytes;
    std::vector<char>    mask;
    for (const char* p = textPattern; *p; ) {
        while (*p == ' ') ++p;
        if (!*p) break;
        if (p[0] == '?') {
            bytes.push_back(0); mask.push_back('?');
            p += (p[1] == '?') ? 2 : 1;
        } else {
            bytes.push_back((uint8_t)strtol(p, nullptr, 16));
            mask.push_back('x');
            p += 2;
        }
    }
    mask.push_back('\0');
    return MaskScan(mod, bytes.data(), mask.data());
}

// ----------------------------------------------------------------------------
// ResolveRIP
// Given the address of an instruction that contains a RIP-relative disp32
// operand, returns the absolute target address.
//   addr       = start of the instruction
//   dispOffset = byte offset within the instruction where disp32 begins
//   instrLen   = total length of the instruction
// Formula: target = addr + instrLen + (int32_t)disp32
// ----------------------------------------------------------------------------
inline uintptr_t ResolveRIP(uintptr_t addr, int dispOffset, int instrLen) {
    int32_t disp = *(int32_t*)(addr + dispOffset);
    return addr + instrLen + (intptr_t)disp;
}

// ----------------------------------------------------------------------------
// FindString
// Locates a null-terminated ASCII string literal inside the module image.
// Used as a stable anchor for version-independent pattern searching.
// ----------------------------------------------------------------------------
inline uintptr_t FindString(const Module& mod, const char* str) {
    size_t len = strlen(str);
    const uint8_t* base = (const uint8_t*)mod.base;
    for (size_t i = 0; i + len < mod.size; ++i) {
        if (memcmp(base + i, str, len) == 0 && base[i+len] == 0)
            return mod.base + i;
    }
    return 0;
}

// ----------------------------------------------------------------------------
// FindLEAReferences
// Finds all LEA reg, [RIP+disp32] instructions that resolve to targetAddr.
// Useful for locating functions that reference a known string or global.
// Only searches REX.W (48/4C) LEA with mod=00, rm=101 (RIP-relative).
// ----------------------------------------------------------------------------
inline std::vector<uintptr_t> FindLEAReferences(const Module& mod, uintptr_t targetAddr) {
    std::vector<uintptr_t> refs;
    const uint8_t* base = (const uint8_t*)mod.base;
    for (size_t i = 0; i + 7 < mod.size; ++i) {
        uint8_t rex = base[i];
        if ((rex == 0x48 || rex == 0x4C) && base[i+1] == 0x8D &&
            (base[i+2] & 0xC7) == 0x05) {
            uintptr_t instrAddr = mod.base + i;
            if (ResolveRIP(instrAddr, 3, 7) == targetAddr)
                refs.push_back(instrAddr);
        }
    }
    return refs;
}

// ----------------------------------------------------------------------------
// FindFunctionStart
// Walks backwards from an address to find the function prologue.
// Uses MSVC release-mode heuristics: INT3 padding between functions,
// or common prologue byte sequences (push rbx, sub rsp, mov [rsp+X], reg).
// ----------------------------------------------------------------------------
inline uintptr_t FindFunctionStart(const Module& mod, uintptr_t insideAddr) {
    const uint8_t* base = (const uint8_t*)mod.base;
    for (int back = 1; back < 4096; ++back) {
        uintptr_t a = insideAddr - back;
        if (a < mod.base) break;
        const uint8_t* p = (const uint8_t*)a;
        if (p[0] == 0xCC && p[1] != 0xCC) return a + 1;
        if (p[0] == 0x40 && p[1] == 0x53) return a;
        if (p[0] == 0x48 && p[1] == 0x83 && p[2] == 0xEC) return a;
        if (p[0] == 0x48 && p[1] == 0x89 &&
           (p[2] == 0x5C || p[2] == 0x4C || p[2] == 0x54) && p[3] == 0x24)
            return a;
    }
    return 0;
}

} // namespace Scanner
