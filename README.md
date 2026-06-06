# GTAVRReal -- RealVR Reconstruction

Reverse-engineered recreation of RealVR.asi (R.E.A.L. mod Release 7 by LukeRoss)
for GTA V. Built entirely from RE of the original binary and analysis of a
runtime session log.

PDB path found in binary: C:\Projects\3DmiGTA\RealVR\bin\Release\RealVR.pdb

---

## Architecture

```
GTA5.exe
 |
 +-- loads GTAVRReal.asi via ScriptHookV
      |
      +-- RealVR.cpp: ScriptMain (script thread)
      |     Detects camera type, drives HMD tracking pipeline,
      |     injects yaw/pitch into gameplay camera via natives.
      |
      +-- RVRBridge.cpp: RVRBridge::Resolve()
      |     Enumerates loaded modules, finds proxy d3d11.dll,
      |     resolves 5 function pointers and 2 data pointers.
      |
      +-- RVRPatches.cpp / RVRHandlersAsm.asm / RVRHandlersCpp.cpp
            Writes 16-byte trampolines at 6 sites in GTA5.exe.
            Each trampoline jumps to a naked handler that saves
            engine registers, performs VR work, then re-executes
            the original bytes and returns to the engine.
            |
            +-- AdjustViewInverse.cpp: RVR_AdjustViewInverse()
                  Reads HMD pose from g_RVRData, applies rotation
                  to view matrix, writes result to g_RVRData for
                  the render DLL.

The proxy d3d11.dll (by 3DmiGTA) handles the actual VR runtime
(OpenVR or Oculus), eye separation, and stereo presentation.
This ASI feeds it the view matrix and projection matrix each frame.
```

---

## Proxy d3d11.dll Symbol Remapping

GetProcAddress order and storage slots do not match (confirmed by RE):

| GetProcAddress string  | Slot name in code        | Role                          |
|------------------------|--------------------------|-------------------------------|
| g_RVRData              | g_RVRData                | VR data buffer pointer        |
| g_fRVRGameProj         | g_fRVRGameProj           | Projection matrix pointer     |
| RVRLog                 | RVRLog                   | Logging function              |
| RVRGetFrameDesc        | RVRGetFrameDesc          | Frame descriptor              |
| RVRGetPoseDesc         | RVRSeqCheck              | Sync call (no block)          |
| RVRSeqCheck            | RVRWaitAndTrackHMD       | Frame-start signal            |
| RVRWaitAndTrackHMD     | RVRGetPoseFrame          | Blocking pose getter          |

---

## g_RVRData Layout (DLL r7)

Pose input (written by proxy DLL after WaitGetPoses):

```
slot = frameIndex & 3
base = g_RVRData + 0x77C + slot * 0x1C

[base + 0x00] = float  hmd pitch   (radians)
[base + 0x04] = float  hmd yaw     (radians)
[base + 0x08] = float  hmd roll    (radians)
[base + 0x0C] = float  head offset (meters, X axis)
```

View matrix output (written by AdjustViewInverse):

```
slot = frameIndex & 3
[g_RVRData + slot * 256 + 0x890] = float[16]  row-major view matrix
[g_RVRData + slot * 256 + 0x910] = float[16]  column-major (for HLSL)
```

---

## Patch Sites (GTA5.exe version 73, base 0x7FF630C11000)

| Patch       | Absolute address   | Site instruction             |
|-------------|--------------------|------------------------------|
| ViewInverse | 0x7FF630E10AB1     | movss [rbx+0x70], xmm1       |
| Proj        | 0x7FF631F8236D     | mov [rcx+0x170], rbx         |
| FOV1stCar   | 0x7FF630E66FCC     | movss [rbp+0x43], xmm0       |
| FOV3rd      | 0x7FF630E945D3     | movss [rbx+0x90], xmm0       |
| FOVUni      | 0x7FF630E946AD     | movss [rbx+0x90], xmm8       |
| CamParams   | 0x7FF6316937F0     | sub rsp, 0xB0 (func prologue) |

---

## Build

Visual Studio 2019+ with MSVC x64. MASM must be enabled (already configured
in the .vcxproj). Place ScriptHookV.lib in sdk/lib/.

Rename the output DLL to .asi and place it in the GTA V directory alongside
RealVR.ini and the 3DmiGTA proxy d3d11.dll.

---

## Confirmed and Implemented

- ScriptHookV API (8 exports, mangled names matched)
- All 20 INI config keys with correct defaults and valid ranges
- DllMain flow: scriptRegister / scriptUnregister, patch restoration on unload
- Keyboard handler: all hotkeys (F8, F11, NumPad2, T, Y, End, J, Num.)
- RVR bridge discovery via EnumProcessModules (handles dual d3d11.dll scenario)
- Symbol remapping (confirmed by RE of Resolve at ASI RVA 0x180002340)
- VR sequence initialization (cl=0x55 on startup, cl=0x00 per frame)
- All 6 patch patterns (version 73 confirmed from runtime log)
- Trampoline format (16 bytes: mov r11 + jmp r11)
- Continuation stubs (original bytes + jmp to site+16)
- Assembly handlers: full register save/restore (0xE0 stack frame)
- ViewInverse handler: reads view matrix, calls AdjustViewInverse
- Proj handler: reads near/far from proj matrix, calls TrackProj
- FOV1stCar / FOV3rd / FOVUni handlers: replace FOV with HMD value
- AdjustViewInverse: HMD Euler to rotation matrix, multiply into view,
  write to g_RVRData (row-major + transposed column-major)
- TrackProj: asymmetric frustum projection matrix written to g_fRVRGameProj
- World rotation: quaternion accumulation for foot, vehicle, cutscene modes
- GyroVehicle: vehicle pitch/roll folded into world rotation
- HeadingControl modes: always / aiming only / never
- PitchControl: toggle HMD pitch injection
- FoldWorldRotIntoRenderPose: finalize pose for DLL after each tick
- Camera type detection: CT_1ST_FOOT, CT_3RD_FOOT, CT_1ST_VEHICLE,
  CT_3RD_VEHICLE, CT_CUTSCENE
- CutscenePitchMode: orientation hold on scene cuts
- Position tracking: head X offset applied in first-person foot mode
- UniversalFOVFix modes: never / cutscenes / aiming / always
- Game version check with warning for unsupported versions
- Per-session log file (GTAVRReal.log) with millisecond timestamps
- Patch restoration on DLL unload
- Script hash dispatch: GetCurrentScriptHash() queried every frame;
  SC_FLIGHT disables heading control, SC_MINIGAME suppresses HMD FOV
- ZoomOverride modes 0-3: gates RVR_TrackProj call based on cutscene state
- StereoInCutscenes mode 2 (flat screen): FoldWorldRotIntoRenderPose skipped
  during cutscenes, leaving the proxy DLL with the unmodified game view matrix
- HMDFovDeg INI key (60-130, default 100): replaces hardcoded 50-degree half-angle
  for symmetric projection tangents, allowing per-headset tuning

---

## Binary RE Findings (from RealVR.asi analysis)

Binary size: 228352 bytes. x64 PE. ImageBase: 0x180000000. PDB:
C:\Projects\3DmiGTA\RealVR\bin\Release\RealVR.pdb

### Config key corrections (vs. initial reconstruction)

| Field         | Our guess       | Actual binary key           | Notes                              |
|---------------|-----------------|-----------------------------|------------------------------------|
| showFPS       | ShowFPS         | ShowDebugText               | Wrong key name in original code    |
| (new)         | —               | FullCamTrackInCutscene      | Full cam tracking in cutscenes     |
| (new)         | —               | Allow1stCoverAimHeading     | Heading in cover-aim (default=1)   |
| (new)         | —               | SlowMotion                  | SET_TIME_SCALE (0x1D408577D440E81E)|
| (wrong type)  | float FOV       | OverrideDartsTennisFOV bool | It's a bool flag, not an angle     |

### Keys NOT in ASI (belong to proxy d3d11.dll)

StereoInCutscenes, ZoomOverride, Stereo, VRAPI — read by d3d11.dll from the
same INI file. The ASI binary's .rdata contains no reference to these strings.

### Default value corrections

| Key              | Our code | Binary default |
|------------------|----------|----------------|
| CutscenePitchMode| 2        | 1 (relative)   |
| HeadingControl   | 0        | 1 (aim only)   |
| UniversalFOVFix  | 3        | 0 (never)      |

### DominantEye (g_RVRData layout extension)

Confirmed by RE: writes to per-frame slots at:
- `[g_RVRData + slot*256 + 0xA90]` = float  eye X offset
- `[g_RVRData + slot*256 + 0xA94]` = float  secondary value
- `[g_RVRData + slot*256 + 0xA98]` = int    always 0

IPD multipliers (from binary .rdata constants):
- DominantEye=0 (none):  -1.0 * IPD_scale at 0xA90
- DominantEye=1 (left):   0 at 0xA90,  2 * IPD_scale at 0xA94
- DominantEye=2 (right): -2.0 * IPD_scale at 0xA90, 0 at 0xA94

### SetCamMetadataPitch (partial RE)

Error strings reveal the call sequence:
1. GetMetadataHashForEntity() — get hash of camera entity
2. Lookup in metadata pool (size: uint16_t)
3. Get camObjMetadata from pool
4. Call InspectModelInfo() — get psoData
5. Verify baseMetadataHash field

Struct field offsets within camObjMetadata: not yet confirmed.

### Game versions

The binary accepts versions 63 (0x3F) and 64 (0x40) per the format string
"expected %d or %d". Our patch patterns were confirmed on version 73.
All three are now accepted by RVR_CheckGameVersion().

---

## Not Yet Implemented (requires additional RE)

- CamParamsHandler: near/far plane override for VR comfort. Pool pointer
  located, struct layout not confirmed. Handler is a no-op.

- SetCamMetadataPitch: see Binary RE Findings above. The camObjMetadata
  struct field offsets for near/far are not yet confirmed.

- Full asymmetric HMD projection tangents: RVRGetFrameDesc output format is
  not yet reversed. Symmetric tangents from HMDFovDeg are used as approximation.

- SlowMotion time scale value: the original reads the scale from g_RVRData at
  an offset not yet identified. We use 0.5f as a placeholder.

- FullCamTrackInCutscene: key is now loaded from INI but the behavioral
  difference from CutscenePitchMode is not yet fully understood.

- OverrideDartsTennisFOV: loaded as bool; when true, suppresses HMD FOV for
  minigame scripts. FOV value to use is not known.

---

## What Could Be Built On Top Of This

Once the core VR pipeline is verified working, these extensions are possible:

- HMD controller input integration: if the proxy DLL exposes controller
  position/button data (likely, given the scope of the original mod), it
  could drive weapon aiming and melee direction from the physical controller
  instead of the gamepad stick.

- Per-eye view matrix: providing separate left and right view matrices to
  the DLL would give correct stereo parallax for close objects. Currently
  the same matrix is used for both eyes.

- Head-bobbing suppression: the engine's foot-step camera bob is visible in
  VR. The view matrix pipeline could subtract this motion before passing the
  matrix to the DLL.

- Motion sickness reduction: a comfort vignette or rotation smoothing layer
  could be inserted between the HMD pose and the gameplay camera injection.

- Full script hash table: completing the 300-entry table from the binary's
  .rdata strings would enable the original mod's per-mission behavior
  without any guesswork.
