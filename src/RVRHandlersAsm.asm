; =============================================================================
; RVRHandlersAsm.asm
;
; Six naked handler functions installed as trampolines in GTA5.exe.
;
; CALLING CONVENTION
; ------------------
; These functions are NOT called with CALL -- they are entered via JMP from
; the 16-byte trampoline written into GTA5.exe. There is no return address
; on the stack. Each handler must:
;   1. Build a valid stack frame for calling into C++ (16-byte aligned).
;   2. Save all registers that the engine may rely on being preserved.
;   3. Extract the relevant parameter from the engine's register state.
;   4. Call the corresponding C++ function.
;   5. Restore all registers.
;   6. JMP to the continuation stub (s_cont[N]), which re-executes the
;      original overwritten bytes and then jumps to site + 16.
;
; REGISTER CONTEXT AT EACH SITE
; ------------------------------
; Determined by RE of the original ASI and the disassembly at each site
; in GTA5.exe (version 73):
;
;   ViewInverse : rbx = pCamObj
;     Site instruction: movss [rbx+0x70], xmm1
;     The engine has just written view matrix row 0 to the camera object.
;
;   Proj        : rcx = pProjObj
;     Site instruction: mov [rcx+0x170], rbx
;     The engine is writing projection matrix column 0.
;
;   FOV1stCar   : rbx = pCamObj, xmm0 = fov (float)
;     Site instruction: movss [rbp+0x43], xmm0
;     Engine writing first-person in-vehicle FOV.
;
;   FOV3rd      : rbx = pCamObj, xmm0 = fov (float)
;     Site instruction: movss [rbx+0x90], xmm0
;     Engine writing third-person FOV.
;
;   FOVUni      : rbx = pCamObj, xmm0/xmm8 = fov (float)
;     Site instruction: movss [rbx+0x90], xmm8
;     Engine writing universal FOV (applies across modes).
;     xmm8 is not saved in SAVE_ALL; the C++ side reads the cached value.
;
;   CamParams   : rcx = pCamParams, rdx = second argument
;     Site instruction: sub rsp, 0xB0 (function prologue)
;     Engine entering camera parameter setup function.
;
; STACK LAYOUT AFTER SAVE_ALL (0xE0 = 224 bytes)
; ------------------------------------------------
;   [rsp+00h..1Fh] = shadow space (32 bytes, required for CALL)
;   [rsp+20h]      = rcx
;   [rsp+28h]      = rdx
;   [rsp+30h]      = r8
;   [rsp+38h]      = r9
;   [rsp+40h]      = r10
;   [rsp+48h]      = r11
;   [rsp+50h]      = rax
;   [rsp+58h]      = rbx
;   [rsp+60h..6Fh] = xmm0
;   [rsp+70h..7Fh] = xmm1
;   [rsp+80h..8Fh] = xmm2
;   [rsp+90h..9Fh] = xmm3
;   [rsp+A0h..AFh] = xmm4
;   [rsp+B0h..BFh] = xmm5
;   [rsp+C0h..CFh] = xmm6
;   [rsp+D0h..DFh] = xmm7
;
; xmm6 and xmm7 are non-volatile in the x64 ABI (callee-saved), but are
; saved here because some engine code paths use them as temporaries before
; the site. Saving them avoids corruption if the C++ side uses them.
; xmm8-xmm15 are NOT saved; the C++ functions do not use them.
; =============================================================================

EXTERN RVR_ViewInverseC : PROC
EXTERN RVR_ProjC        : PROC
EXTERN RVR_FOV1stCarC   : PROC
EXTERN RVR_FOV3rdC      : PROC
EXTERN RVR_FOVUniC      : PROC
EXTERN RVR_CamParamsC   : PROC
EXTERN s_cont           : QWORD

.CODE

; SAVE_ALL / RESTORE_ALL use MOVUPS (unaligned) instead of MOVAPS to avoid
; alignment faults. Our trampolines are entered via JMP (not CALL), so RSP
; may not be 16-byte aligned at the time we subtract 0xE0. MOVUPS is safe
; regardless of alignment and has identical performance on modern CPUs.
SAVE_ALL MACRO
    sub  rsp, 0E0h
    mov  [rsp+20h], rcx
    mov  [rsp+28h], rdx
    mov  [rsp+30h], r8
    mov  [rsp+38h], r9
    mov  [rsp+40h], r10
    mov  [rsp+48h], r11
    mov  [rsp+50h], rax
    mov  [rsp+58h], rbx
    movups [rsp+60h],  xmm0
    movups [rsp+70h],  xmm1
    movups [rsp+80h],  xmm2
    movups [rsp+90h],  xmm3
    movups [rsp+0A0h], xmm4
    movups [rsp+0B0h], xmm5
    movups [rsp+0C0h], xmm6
    movups [rsp+0D0h], xmm7
ENDM

RESTORE_ALL MACRO
    movups xmm7, [rsp+0D0h]
    movups xmm6, [rsp+0C0h]
    movups xmm5, [rsp+0B0h]
    movups xmm4, [rsp+0A0h]
    movups xmm3, [rsp+90h]
    movups xmm2, [rsp+80h]
    movups xmm1, [rsp+70h]
    movups xmm0, [rsp+60h]
    mov  rbx, [rsp+58h]
    mov  rax, [rsp+50h]
    mov  r11, [rsp+48h]
    mov  r10, [rsp+40h]
    mov  r9,  [rsp+38h]
    mov  r8,  [rsp+30h]
    mov  rdx, [rsp+28h]
    mov  rcx, [rsp+20h]
    add  rsp, 0E0h
ENDM

; -----------------------------------------------------------------------------
; ViewInverseHandler
; rbx = pCamObj (engine camera object containing the just-written view matrix)
; -----------------------------------------------------------------------------
ViewInverseHandler PROC
    SAVE_ALL
    mov  rcx, rbx               ; arg1 = pCamObj
    call RVR_ViewInverseC
    RESTORE_ALL
    mov  r11, [s_cont]          ; s_cont[0]: continuation for ViewInverse
    test r11, r11
    jnz  @vi_go
    ret
@vi_go:
    jmp  r11
ViewInverseHandler ENDP

; -----------------------------------------------------------------------------
; ProjHandler
; Site instruction: mov [rbx+0x170], rcx  (confirmed by RE of saved bytes)
; The projection object base is RBX, not RCX. rbx is unchanged by SAVE_ALL,
; so it still holds the engine value at the call.
; -----------------------------------------------------------------------------
ProjHandler PROC
    SAVE_ALL
    mov  rcx, rbx              ; arg1 = pProjObj (base of "mov [rbx+0x170], rcx")
    call RVR_ProjC
    RESTORE_ALL
    mov  r11, [s_cont+8]        ; s_cont[1]: continuation for Proj
    test r11, r11
    jnz  @proj_go
    ret
@proj_go:
    jmp  r11
ProjHandler ENDP

; -----------------------------------------------------------------------------
; FOV1stCarHandler
; Site instruction: movss [rbp+0x43], xmm0  (confirmed by RE of saved bytes)
; The cam object base is RBP, not RBX. rbp is unchanged by SAVE_ALL.
; xmm0 is saved at [rsp+60h]; pass it as xmm1 to the C++ function.
; -----------------------------------------------------------------------------
FOV1stCarHandler PROC
    SAVE_ALL
    mov   rcx, rbp              ; arg1 = pCamObj (base of "movss [rbp+0x43], xmm0")
    movss xmm1, DWORD PTR [rsp+60h]      ; arg2 = original xmm0 = fov
    call  RVR_FOV1stCarC
    RESTORE_ALL
    mov   r11, [s_cont+16]     ; s_cont[2]
    test  r11, r11
    jnz   @f1_go
    ret
@f1_go:
    jmp   r11
FOV1stCarHandler ENDP

; -----------------------------------------------------------------------------
; FOV3rdHandler
; rbx = pCamObj, xmm0 = fov value (float)
; -----------------------------------------------------------------------------
FOV3rdHandler PROC
    SAVE_ALL
    mov   rcx, rbx
    movss xmm1, DWORD PTR [rsp+60h]
    call  RVR_FOV3rdC
    RESTORE_ALL
    mov   r11, [s_cont+24]     ; s_cont[3]
    test  r11, r11
    jnz   @f3_go
    ret
@f3_go:
    jmp   r11
FOV3rdHandler ENDP

; -----------------------------------------------------------------------------
; FOVUniHandler
; rbx = pCamObj, xmm8 = fov (note: xmm8 is NOT saved in SAVE_ALL).
; The C++ side reads the cached HMD FOV from g_fRVRGameProj instead of
; relying on the xmm8 value, which avoids the need to save xmm8-15.
; -----------------------------------------------------------------------------
FOVUniHandler PROC
    SAVE_ALL
    mov   rcx, rbx              ; arg1 = pCamObj
    movss xmm1, DWORD PTR [rsp+60h]      ; arg2 = xmm0 if available; xmm8 not captured
    call  RVR_FOVUniC
    RESTORE_ALL
    mov   r11, [s_cont+32]     ; s_cont[4]
    test  r11, r11
    jnz   @fu_go
    ret
@fu_go:
    jmp   r11
FOVUniHandler ENDP

; -----------------------------------------------------------------------------
; CamParamsHandler
; rcx = pCamParams, rdx = second argument (recovered from saved stack).
; -----------------------------------------------------------------------------
CamParamsHandler PROC
    SAVE_ALL
    mov  rcx, [rsp+20h]        ; recover rcx = pCamParams
    mov  rdx, [rsp+28h]        ; recover rdx = second arg
    call RVR_CamParamsC
    RESTORE_ALL
    mov  r11, [s_cont+40]      ; s_cont[5]
    test r11, r11
    jnz  @cp_go
    ret
@cp_go:
    jmp  r11
CamParamsHandler ENDP

END
