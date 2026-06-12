# RealVRCompat ASI

Compatibility shim for the original `RealVR.asi` on newer GTA V builds, tested against GTA V `1.0.3788.0` with ScriptHookV `v3788.0/1013.34`.

## Problem Solved

After exiting a vehicle in first-person mode, HMD head tracking breaks - the camera no longer rotates with head movement and only responds to controller input. Hospital respawn restores tracking automatically, but this workaround is not practical during gameplay.

## Solution

**Instant Player Model Reset on Vehicle Exit**: When the player exits a vehicle, the mod instantly changes the player's ped to the same model (preserving appearance, velocity, and falling animations). This triggers RealVR's internal re-initialization, restoring HMD head tracking immediately without any freeze or animation interruption.

**Key Features**:
- Restores HMD tracking instantly when exiting vehicles (cars, motorcycles, helicopters, airplanes)
- Preserves exact player appearance (clothes, accessories) - captured before entering vehicle
- Maintains falling/falling animations - velocity is preserved during model change
- Works on death and arrest - applies same model reset to restore camera on respawn
- No visual freeze - model change is immediate and non-blocking
- Automatic appearance restoration - happens after falling animation completes

## How It Works

### Vehicle Exit Handling
1. **Detect Exit**: When player exits a vehicle, instantly call `InstantPlayerModelReset()`
2. **Change Model**: `SET_PLAYER_MODEL(player, savedModel)` - apply same model immediately
3. **Restore Appearance**: After falling animation ends (via `IS_PED_FALLING`), restore all saved:
   - Component variations (12 types: head, beard, hair, torso, legs, hands, feet, etc.)
   - Prop variations (8 types: hats, glasses, ears, watches, bracelets, etc.)
4. **Preserve Camera**: GTA V automatically preserves HMD tracking after model change

### Appearance Capture
- When entering vehicle: capture exact model hash and all 12 component + 8 prop variations
- Uses `GET_PED_DRAWABLE_VARIATION`, `GET_PED_TEXTURE_VARIATION`, `GET_PED_PALETTE_VARIATION`
- Also captures prop indices and textures via `GET_PED_PROP_INDEX`, `GET_PED_PROP_TEXTURE_INDEX`

### Death/Arrest Handling
- On death or arrest: instantly apply model change to restore camera state
- Clean up all cached state to prevent stale data from interfering after respawn
- Prevent camera breaking when respawning in hospital (critical for helicopters/airplanes)

## Installation

Place these files in the GTA V game folder:

- `00_RealVRCompat.asi` - The compatibility shim (load before RealVR.asi)
- `RealVR.asi` - Original VR mod
- RealVR proxy `d3d11.dll`
- `RealVR.ini` - Configuration
- ScriptHookV/ASI loader files

The `00_` prefix is intentional so the compat shim loads before `RealVR.asi`.

## Building

**Prerequisites**:
- Visual Studio 2022
- ScriptHookV SDK (v3788.0 or compatible)
- Windows SDK

**Build Steps**:
```bash
cd "path\to\GTAVRVSC"
"C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\msbuild.exe" RealVRCompat.vcxproj /p:Configuration=Release /p:Platform=x64
```

Output: `bin\00_RealVRCompat.asi`

## Configuration

Edit `RealVRCompat.ini` to control behavior:

### Vehicle/Death/Arrest Response
- `ScriptCamReset=1` - Enable model change on vehicle exit
- `ScriptCamResetFrames=2` - Frames before starting model change (safety margin)

### Camera Restoration
All the original patch controls still apply:
- `ForceFallback=0` - Use metadata fallback resolver
- `CamMetaOldOffset=1` - Use old offset for camera metadata
- `RestoreCamMetadata=1` - Restore camera metadata if RealVR clears it
- `RestoreRVRState=1` - Restore RealVR internal flags after transitions
- `ActiveEnginePatches=1` - Apply RealVR's 6 engine patches
- `EnginePatchDelaySec=70` - Delay before applying patches

## Technical Details

### Native Functions Used
- `SET_PLAYER_MODEL` (0x00A1CADD00108836) - Change player model
- `GET_ENTITY_MODEL` (0x9F47B058362C84B5) - Get current model
- `GET_PED_DRAWABLE_VARIATION` (0x67F3780DD425D4FC) - Get component variation
- `GET_PED_TEXTURE_VARIATION` (0x04A355E041E004E6) - Get texture variation
- `GET_PED_PALETTE_VARIATION` (0xE3DD5F2A84B42281) - Get palette variation
- `SET_PED_COMPONENT_VARIATION` (0x262B14F48D29DE80) - Set component variation
- `GET_PED_PROP_INDEX` (0x898CC20EA75BACD8) - Get prop index
- `GET_PED_PROP_TEXTURE_INDEX` (0xE131A28626F81AB2) - Get prop texture
- `SET_PED_PROP_INDEX` (0x93376B65A266EB5F) - Set prop
- `CLEAR_PED_PROP` (0x0943E5B8E078E76E) - Clear prop
- `IS_PED_FALLING` (0xFB92A102F1C4DFA3) - Check if falling
- `IS_PLAYER_BEING_ARRESTED` (0x388A47C51ABDAC8E) - Check arrest state

### Global State Management
```cpp
// Vehicle state
static uint32_t g_saved_player_model = 0;           // Model before entering vehicle
static ComponentData g_saved_components[12];         // Clothes/appearance
static PropData g_saved_props[8];                    // Accessories

// Appearance restoration timing
static bool g_restore_appearance_next_frame = false; // Defer restoration
static int g_appearance_restore_ped = 0;            // Target ped for restoration

// Delayed model change (for long ejection animations)
static bool g_pending_delayed_model_change = false;
static int g_pending_delayed_model_change_frames = 0;
```

### State Cleanup on Death/Arrest
When `dead && !wasDead` or `arrested && !wasArrested`:
1. Reset all vehicle state variables
2. Clear appearance cache
3. Reset RealVR state snapshots (`g_savedRVRStateValid = false`)
4. Clear camera metadata pool references

This prevents stale state from interfering after respawn in hospital.

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

## Recommended Config

For stable first-person tracking and smooth vehicle transitions:

```ini
[patches]
FirstPersonJump=0
VehicleCamNop=0
CamPoolWriteNop=0
ForceFallback=0
CamPoolResolve=1
CamMetaOldOffset=1
RestoreCamMetadata=1
RestoreRVRState=1
ActiveEnginePatches=1
EnginePatchDelaySec=70

[script]
ScriptCamReset=1
ScriptCamResetFrames=2
```

## Troubleshooting

**Camera still breaks after vehicle exit**:
- Ensure `ScriptCamReset=1` in RealVRCompat.ini
- Check that player model is being captured (look for logs: "saved player model 0x...")
- Verify native hashes are correct for your game version

**Appearance is wrong after exiting vehicle**:
- The exact model and appearance are captured when entering the vehicle
- If you change appearance while in vehicle, those changes are lost on exit
- This is expected behavior - it restores what you looked like before entering

**Can't rotate head after respawning from death/arrest**:
- Model reset is applied automatically
- If still broken, check that `RestoreRVRState=1` is enabled

## Project Cleanup

This project has been cleaned to include only RealVRCompat-related files:
- Removed GTAVRReal project and other unused components
- Removed reference/analysis files
- Updated .gitignore to prevent re-adding removed files
- Kept only essential files: source, headers, SDK, and build configuration

## License

See LICENSE.txt

## Compatibility

-  GTA V build 1.0.3788.0
-  Idk if the same code works in Enhanced
