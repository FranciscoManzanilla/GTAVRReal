#pragma once
#include "PatternScanner.h"
#include "RVRTypes.h"
#include <Windows.h>
#include <Psapi.h>
#include <cstring>

// =============================================================================
// RVRPatches.h
//
// Memory patch system for GTA5.exe.
//
// OVERVIEW
// --------
// Six locations in GTA5.exe are overwritten with 16-byte trampolines that
// redirect execution to handler functions defined in this module. Each
// handler performs its VR work and then jumps to a continuation stub that
// re-executes the original overwritten bytes and returns to game code at
// site + 16.
//
// This approach allows the VR layer to intercept the following engine events:
//   ViewInverse  -- the engine has just written a new view matrix
//   Proj         -- the engine has just written a projection matrix
//   FOV1stCar    -- the engine is about to set first-person in-vehicle FOV
//   FOV3rd       -- the engine is about to set third-person FOV
//   FOVUni       -- the engine is about to set the universal FOV value
//   CamParams    -- the engine is initializing camera parameters (near/far)
//
// WHY NOT USE THE ORIGINAL ASI HANDLERS
// --------------------------------------
// An earlier approach (v5) loaded the original RealVR.asi with LoadLibrary
// and redirected the trampolines to its handler functions. This failed because
// the original handlers use RIP-relative addressing to access their own .data
// globals (config, bridge pointers, ring buffer). Those RIP offsets are
// fixed at link time relative to the original ASI's load address. Jumping
// into those functions from GTA5.exe means the VR logic runs correctly, but
// reads and writes the original ASI's state, not ours. The two modules'
// data are completely separate.
//
// The correct approach is to implement the handlers inside our own module,
// so all RIP-relative accesses resolve to our own globals.
//
// TRAMPOLINE FORMAT (16 bytes)
// ----------------------------
//   49 BB <addr:8>   mov r11, imm64   (10 bytes)
//   41 FF E3         jmp r11          ( 3 bytes)
//   90 90            nop nop          ( 2 bytes, padding to 16)
//   -- implicit 1 byte for alignment --
//
// r11 is used because it is volatile (caller-saved) in the x64 ABI, so
// overwriting it in the trampoline does not break the engine's register state.
// The handlers in RVRHandlersAsm.asm save and restore all registers anyway.
//
// CONTINUATION STUBS
// ------------------
// After ApplyPatches writes the trampolines, InitHandlers (called from
// RVRHandlersCpp.cpp) creates per-patch continuation stubs in executable
// memory. Each stub is:
//   <original 16 bytes>      -- the bytes that were overwritten
//   49 BB <site+16: 8>       -- mov r11, return address
//   41 FF E3                 -- jmp r11
//
// The handler jumps to this stub after its VR work is done, which replays
// the original instructions and returns to normal game code flow.
//
// IMPORTANT: The 16 original bytes must not contain RIP-relative instructions
// (e.g. MOV reg, [RIP+disp32]). If they did, the displacement would be wrong
// after relocation into the stub. The patterns chosen for this mod were
// verified to contain only register-relative or immediate addressing.
//
// PATTERN SCAN
// ------------
// Addresses are found at runtime by scanning GTA5.exe's .text section.
// Patterns were derived from the confirmed absolute addresses in the
// runtime log (game version 73, base 0x7FF630C11000) and cross-checked
// against the disassembly.
//
// WHAT IS NOT YET IMPLEMENTED
// ----------------------------
// - CamParams handler: the near/far plane adjustment for VR comfort.
//   The offset of the near plane field within pCamParams is not yet known.
//   The handler currently passes through without modification.
// - SetCamMetadataPitch: the original ASI manipulated camera metadata to
//   control pitch in certain scripted scenarios. The pool pointer is located
//   but the struct layout has not been fully reversed.
// =============================================================================

namespace RVRPatches {

// ----------------------------------------------------------------------------
// Trampoline -- 16-byte jump stub written into GTA5.exe at each patch site.
// ----------------------------------------------------------------------------
#pragma pack(push, 1)
struct Trampoline {
    uint16_t movR11 = 0xBB49;
    uint64_t target = 0;
    uint32_t jmpR11 = 0x90E3FF41;
    uint16_t pad    = 0x9090;
};
static_assert(sizeof(Trampoline) == 16, "Trampoline size must be 16 bytes");
#pragma pack(pop)

// ----------------------------------------------------------------------------
// SavedPatch -- holds the original bytes for one patch site, used to build
// the continuation stub and to restore the site on DLL_PROCESS_DETACH.
// ----------------------------------------------------------------------------
struct SavedPatch {
    uintptr_t addr   = 0;
    uint8_t   orig[16] = {};
    int       len    = 0;     // number of bytes overwritten (instruction-aligned)
    bool      saved  = false;
};

// Array indexed by patch order: 0=ViewInverse, 1=Proj, 2=FOV1stCar,
// 3=FOV3rd, 4=FOVUni, 5=CamParams.
extern SavedPatch s_saved[6];

// ----------------------------------------------------------------------------
// Per-site overwrite lengths (confirmed by RE of saved bytes, GTA5.exe ver 73).
//
// The trampoline core is 13 bytes (mov r11, imm64 = 10 + jmp r11 = 3). We must
// overwrite a whole number of instructions, so each site is patched up to the
// smallest instruction boundary >= 13. A fixed 16-byte overwrite cut three
// sites mid-instruction (ViewInverse, FOV1stCar, FOVUni), which corrupted the
// continuation's jmp target and crashed the game.
//
// Disassembly of the 16 saved bytes per site:
//   0 ViewInverse: movss[rbx+70] movss[rdi+74] comiss            -> boundary 13
//   1 Proj:        mov[rbx+170] mov[rbx+17C] mov rcx,rbx         -> boundary 16
//   2 FOV1stCar:   movss[rbp+43] movss[rbp+2B] movss[rbp+3F]     -> boundary 15
//   3 FOV3rd:      mov rcx,rbx movss[rbx+90] add rsp,20 pop rbx  -> boundary 16
//   4 FOVUni:      movaps movss[rbx+90] movaps                   -> boundary 14
//   5 CamParams:   sub rsp,B0 movss[rdx] movss[rdx+8]            -> boundary 16
// ----------------------------------------------------------------------------
static const int kPatchLen[6] = { 13, 16, 15, 16, 14, 16 };

// ----------------------------------------------------------------------------
// WritePatch
// Saves `len` original bytes at addr, then overwrites with a 13-byte trampoline
// (mov r11, handler; jmp r11) followed by NOP padding to `len`. patchIdx indexes
// s_saved[]. len must be in [13, 16].
// ----------------------------------------------------------------------------
inline bool WritePatch(uintptr_t addr, uint64_t handlerAddr, int patchIdx, int len) {
    if (!addr || !handlerAddr || len < 13 || len > 16) return false;
    SavedPatch& sp = s_saved[patchIdx];
    sp.addr = addr;
    sp.len  = len;
    DWORD old = 0;
    if (!VirtualProtect((void*)addr, len, PAGE_EXECUTE_READWRITE, &old))
        return false;
    memcpy(sp.orig, (void*)addr, len);
    sp.saved = true;

    uint8_t buf[16];
    memset(buf, 0x90, sizeof(buf));            // NOP padding
    buf[0] = 0x49; buf[1] = 0xBB;              // mov r11, imm64
    memcpy(buf + 2, &handlerAddr, 8);
    buf[10] = 0x41; buf[11] = 0xFF; buf[12] = 0xE3;  // jmp r11
    memcpy((void*)addr, buf, len);

    VirtualProtect((void*)addr, len, old, &old);
    FlushInstructionCache(GetCurrentProcess(), (void*)addr, len);
    return true;
}

// ----------------------------------------------------------------------------
// RestoreAllPatches
// Restores the original bytes at each patched site. Called on DLL unload.
// ----------------------------------------------------------------------------
inline void RestoreAllPatches(const GamePointers& gp) {
    uintptr_t addrs[6] = {
        gp.pViewInverse, gp.pProj, gp.pFOV1stCar,
        gp.pFOV3rd, gp.pFOVUni, gp.pCamParams
    };
    for (int i = 0; i < 6; ++i) {
        if (!s_saved[i].saved || !addrs[i]) continue;
        int len = s_saved[i].len ? s_saved[i].len : 16;
        DWORD old = 0;
        VirtualProtect((void*)addrs[i], len, PAGE_EXECUTE_READWRITE, &old);
        memcpy((void*)addrs[i], s_saved[i].orig, len);
        VirtualProtect((void*)addrs[i], len, old, &old);
        FlushInstructionCache(GetCurrentProcess(), (void*)addrs[i], len);
        s_saved[i].saved = false;
    }
}

} // namespace RVRPatches

// ----------------------------------------------------------------------------
// Forward declarations for the six handler entry points defined in
// RVRHandlersAsm.asm. Declared as extern "C" to match the unmangled labels
// that MASM emits (no C++ namespace decoration).
// ----------------------------------------------------------------------------
extern "C" {
    void ViewInverseHandler();
    void ProjHandler();
    void FOV1stCarHandler();
    void FOV3rdHandler();
    void FOVUniHandler();
    void CamParamsHandler();
}

namespace RVRPatches {

// ----------------------------------------------------------------------------
// FindAllPatches
// Scans GTA5.exe .text for all six injection sites. Logs results if verbose.
// Does not write anything to memory.
//
// Pattern notes (version 73):
//   ViewInverse -- "F3 0F 11 4B 70 F3 0F 10 57 74 0F 2F D3"
//     movss [rbx+0x70], xmm1  ; engine writing view row 0 to camObj
//   FOV1stCar   -- "F3 0F 11 45 43 F3 0F 11 55 2B"
//     movss [rbp+0x43], xmm0  ; engine writing first-person vehicle FOV
//   Proj        -- "48 89 8B 70 01 00 00 89 8B 7C 01 00 00"
//     mov [rcx+0x170], rbx    ; engine writing projection column 0
//   FOV3rd      -- "48 8B CB F3 0F 11 83 90 00 00 00 48 83"
//     movss [rbx+0x90], xmm0  ; engine writing third-person FOV
//   FOVUni      -- "0F 28 C8 F3 0F 11 8B 90 00 00 00 0F 28 C8"
//     movss [rbx+0x90], xmm8  ; engine writing universal FOV
//   CamParams   -- "48 81 EC B0 00 00 00 F3 0F 10 02 F3 0F 10"
//     sub rsp, 0xB0            ; start of camera parameter setup function
// ----------------------------------------------------------------------------
inline bool FindAllPatches(GamePointers& gp, const RVRBridge& bridge, bool verbose) {
    auto mod = Scanner::Module::Main();

    struct P { const char* name; const char* pat; uintptr_t* out; };
    P pats[] = {
        {"ViewInverse", "F3 0F 11 4B 70 F3 0F 10 57 74 0F 2F D3",       &gp.pViewInverse},
        {"FOV1stCar",   "F3 0F 11 45 43 F3 0F 11 55 2B",                &gp.pFOV1stCar  },
        {"Proj",        "48 89 8B 70 01 00 00 89 8B 7C 01 00 00",       &gp.pProj       },
        {"FOV3rd",      "48 8B CB F3 0F 11 83 90 00 00 00 48 83",       &gp.pFOV3rd     },
        {"FOVUni",      "0F 28 C8 F3 0F 11 8B 90 00 00 00 0F 28 C8",    &gp.pFOVUni     },
        {"CamParams",   "48 81 EC B0 00 00 00 F3 0F 10 02 F3 0F 10",    &gp.pCamParams  },
    };
    for (auto& p : pats) {
        *p.out = Scanner::TextScan(mod, p.pat);
        if (verbose && bridge.RVRLog)
            bridge.RVRLog("  %-12s : 0x%llX  [%s]\n",
                p.name, (uint64_t)*p.out, *p.out ? "OK" : "FAIL");
    }
    return gp.AllPatchesOk();
}

// ----------------------------------------------------------------------------
// ApplyPatches
// Writes trampolines at all six sites, pointing to our own handler functions.
// Called once from RVR_Initialize (or deferred to the first tracking tick
// if D3D is not yet ready at init time).
// ----------------------------------------------------------------------------
inline bool ApplyPatches(const GamePointers& gp, const RVRBridge& bridge) {
    if (!gp.AllPatchesOk()) return false;
    bool ok = true;
    ok &= WritePatch(gp.pViewInverse, (uint64_t)::ViewInverseHandler,  0, kPatchLen[0]);
    ok &= WritePatch(gp.pProj,        (uint64_t)::ProjHandler,         1, kPatchLen[1]);
    ok &= WritePatch(gp.pFOV1stCar,   (uint64_t)::FOV1stCarHandler,    2, kPatchLen[2]);
    ok &= WritePatch(gp.pFOV3rd,      (uint64_t)::FOV3rdHandler,       3, kPatchLen[3]);
    ok &= WritePatch(gp.pFOVUni,      (uint64_t)::FOVUniHandler,       4, kPatchLen[4]);
    ok &= WritePatch(gp.pCamParams,   (uint64_t)::CamParamsHandler,    5, kPatchLen[5]);
    if (bridge.RVRLog)
        bridge.RVRLog(ok ? "All patches applied successfully\n"
                         : "[RVR] Some patches failed to apply\n");
    return ok;
}

// ----------------------------------------------------------------------------
// FindPools
// Locates the camera metadata pool pointer and the viewport pointer in
// GTA5.exe. These are needed by SetCamMetadataPitch (not yet implemented).
// ----------------------------------------------------------------------------
inline bool FindPools(GamePointers& gp, const RVRBridge& bridge, bool verbose) {
    auto mod = Scanner::Module::Main();

    uintptr_t camHit = Scanner::TextScan(mod, "88 50 41 48 8B 47 40");
    if (camHit) gp.camMetadataPool = camHit;

    uintptr_t vpHit = Scanner::TextScan(mod,
        "48 8B 15 ?? ?? ?? ?? 48 8D 2D ?? ?? ?? ?? 48 8B CD");
    if (vpHit) gp.viewPort = Scanner::ResolveRIP(vpHit, 3, 7);

    if (verbose && bridge.RVRLog) {
        bridge.RVRLog("  CamMetadataPool: 0x%llX  [%s]\n",
            (uint64_t)gp.camMetadataPool, gp.camMetadataPool ? "OK" : "FAIL");
        bridge.RVRLog("  ViewPort       : 0x%llX  [%s]\n",
            (uint64_t)gp.viewPort, gp.viewPort ? "OK" : "FAIL");
        if (!gp.camMetadataPool)
            bridge.RVRLog("ERROR: Unable to set g_pCamMetadataPool\n");
        if (!gp.viewPort)
            bridge.RVRLog("ERROR: Unable to set g_pViewPort\n");
    }
    return gp.camMetadataPool && gp.viewPort;
}

} // namespace RVRPatches
