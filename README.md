# RealVRCompat ASI

Compatibility shim for the original `RealVR.asi` on newer GTA V builds, tested against
GTA V `1.0.3788.0` with ScriptHookV `v3788.0/1013.34`.

## What It Does

`00_RealVRCompat.asi` is loaded before `RealVR.asi` and patches the original binary in
memory only. It does not modify `RealVR.asi` on disk.

Current responsibilities:

- Detects `GTA5.exe` file version and maps `1.0.3788.0` to ScriptHook game version id `101`.
- Expands RealVR's accepted version range at `RealVR+0x1CA7`.
- Writes the detected version id to `RealVR+0x35A50`.
- Loads the local RealVR proxy `d3d11.dll` explicitly when it is not already loaded.
- Resolves and writes proxy exports into RealVR slots:
  - `g_RVRData` -> `RealVR+0x38020`
  - `g_fRVRGameProj` -> `RealVR+0x380B0`
  - `RVRLog` -> `RealVR+0x38018`
  - `RVRGetFrameDesc` -> `RealVR+0x380C0`
  - `RVRGetPoseDesc` -> `RealVR+0x37FD8`
  - `RVRSeqCheck` -> `RealVR+0x37FE0`
  - `RVRWaitAndTrackHMD` -> `RealVR+0x37FF0`
- NOPs internal RealVR log calls that crash when `RealVR+0x38018` is zeroed by the original init path.
- Forces the CamMetadata resolver fallback at `RealVR+0x28D0` to avoid stale-offset crashes on newer builds.
- Installs a vectored exception logger/repair path for known crashes while debugging.
- Resolves or preserves the camera metadata pool slot at `RealVR+0x38098`; this is required for stable first-person and vehicle transition behavior.
- Keeps a VEH repair for the first-person block `RealVR+0x5477..0x562A` as a guard when the metadata array is null or stale.
- Registers a small ScriptHook script through RealVR's own imported ScriptHook slots. The script detects vehicle exit while first-person is wanted, briefly reapplies GTA first-person camera natives, and logs RealVR's first-person state around vehicle transitions.
- Supports `RealVRCompat.ini` patch toggles for bisecting camera/control issues during first-person and vehicle transitions, including runtime control of RealVR's six original engine patches.

## Install

Place these files in the GTA V game folder:

- `00_RealVRCompat.asi`
- `RealVR.asi`
- RealVR proxy `d3d11.dll`
- `RealVR.ini`
- ScriptHookV/ASI loader files

The `00_` prefix is intentional so the compat shim loads before `RealVR.asi`.

## Expected Log

Successful startup should include:

```text
GTA5.exe file version=1.0.3788.0 detectedRealVRId=101
version range RealVR+0x1CA7 ... patch=OK
version global +0x35A50 ... target=101 patch=OK
loaded local RVR proxy path=...\d3d11.dll
proxy slot g_RVRData ... patch=OK
proxy slot RVRGetFrameDesc ... patch=OK
cam metadata fallback RealVR+0x28D0 ... patch=OK
```

## Known Patch Points

| Purpose | RVA |
| --- | --- |
| Version global | `RealVR+0x35A50` |
| Version range immediate | `RealVR+0x1CA7` |
| Internal log callback slot | `RealVR+0x38018` |
| Proxy data slot `g_RVRData` | `RealVR+0x38020` |
| Camera metadata pool slot | `RealVR+0x38098` |
| CamMetadata fallback branch | `RealVR+0x28D0` |
| First-person null-pool guard | `RealVR+0x5477` |
| First-person mode flag | `RealVR+0x38040` |
| First-person active flag | `RealVR+0x38041` |
| Original patcher function for the 6 engine hooks | `RealVR+0x1B30` |

## Notes

- Active engine trampoline patching through the original RealVR patcher is controlled by `ActiveEnginePatches` in `RealVRCompat.ini`.
- The six original engine hooks are observed before being applied by the compat shim. RealVR normally installs them from its own `RealVR+0x1C40` path after its `main()` starts and the VR proxy data is ready. The compat fallback waits up to `EnginePatchDelaySec`, then applies them only if RealVR did not already populate all six continuation slots.
- The local `d3d11.dll` proxy must be loaded explicitly. Without this, `g_RVRData` can remain null and the original ASI crashes at `RealVR+0x9EFB`.
- On GTA V `1.0.3788.0`, the current recommended test config keeps the camera metadata resolver on the older `-0x28` offset path, lets RealVR run its original first-person camera block, and uses VEH as the safety net if the metadata array faults: `FirstPersonJump=0`, `VehicleCamNop=0`, `CamPoolWriteNop=0`, `ForceFallback=0`, `CamPoolResolve=1`, `CamMetaOldOffset=1`, `RestoreCamMetadata=1`, `RestoreRVRState=1`, `ActiveEnginePatches=1`, `EnginePatchDelaySec=60..70`.
- The current vehicle-exit first-person workaround disables the old pulse paths: `FirstPersonRearmFrames=0`, `FirstPersonGuardPulseFrames=0`, `FirstPersonResetRearmFrames=0`, and `FirstPersonFlagHold=0`.
- `FirstPersonControlFixFrames` enables GTA look controls every frame after vehicle exit while still in first person. It is currently recommended as `0`, because the broken-yaw state was observed even while this fix was active.
- `FirstPersonUnclampFrames` releases gameplay camera yaw/pitch clamps after vehicle/ragdoll transitions. `FirstPersonResetRearmFrames` performs a short adaptive first-person rearm only when the runtime state matches the observed reset (`g_RVRData+0x840=1` and `RealVR+0x38041=0`).
- `FirstPersonSoftReset=1` is the active approach: after vehicle exit while first-person is wanted, it briefly bridges to third-person follow camera and then returns to first-person after `FirstPersonSoftResetFrames`. This is intended to mimic the clean first-person camera rebuild observed after hospital respawn.
- `KeepVehicleFirstPerson=1` keeps independent vehicle/bike camera contexts in first person when entering a vehicle from first-person-on-foot. This avoids `vehView=1` while `pedView=4` after enabling independent camera modes.
