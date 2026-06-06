#pragma once
#include "natives.h"

// =============================================================================
// RVRNatives.h
//
// Curated subset of GTA V script natives used for VR camera control.
//
// CAMERA STRATEGY
// ---------------
// The original RealVR ASI drives the gameplay camera directly rather than
// creating a scripted camera. This is confirmed by the debug strings in the
// binary: "GAMEPLAY_CAM_ROT yaw = %.2f" and "CamRelH = %.2f".
//
// Using the gameplay camera has several advantages:
// - It stays synchronized with weapon aiming, cover transitions, and
//   cutscene camera blends automatically.
// - It does not require disabling the standard camera system.
// - _SET_GAMEPLAY_CAM_RAW_YAW and _SET_GAMEPLAY_CAM_RAW_PITCH write the
//   orientation directly without the smoothing/lag of the cover system.
//
// ALL HASHES VERIFIED
// -------------------
// Hashes cross-referenced against the Give-Two NativeDB (give-two.github.io),
// the current maintained replacement for the Alexander Blade NativeDB.
//
// THREAD SAFETY
// -------------
// All functions in this header call GTA natives. Natives must only be called
// from the script thread (the function registered with scriptRegister).
// The render-thread handlers in RVRHandlersAsm.asm must NOT call natives.
// Camera type and other state is cached in g_cachedCamType (updated each
// frame by the script thread) and read by the render thread handlers.
//
// WHAT IS NOT YET USED
// ---------------------
// - SET_GAMEPLAY_CAM_RELATIVE_HEADING / PITCH: alternative to the raw setters.
//   The raw setters match the original ASI behavior but the relative setters
//   may be more appropriate for the cover-aim case.
// - DISABLE_CAM_COLLISION_FOR_ENTITY: the original ASI may have called this
//   to prevent camera clipping during HMD head movement. Not yet confirmed.
// =============================================================================

namespace RVRNat {

// --- Gameplay camera read ---
inline Vector3 GetGameplayCamRot(int order = 2)  { return CAM::GET_GAMEPLAY_CAM_ROT(order); }
inline Vector3 GetGameplayCamCoord()              { return CAM::GET_GAMEPLAY_CAM_COORD(); }
inline float   GetGameplayCamFov()                { return CAM::GET_GAMEPLAY_CAM_FOV(); }
inline float   GetGameplayCamRelativeHeading()    { return CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING(); }
inline float   GetGameplayCamRelativePitch()      { return CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH(); }

// --- Gameplay camera write ---
// These are the two primary native calls used by the original ASI to inject
// the HMD orientation into the game camera each frame.
inline void SetGameplayCamRawYaw(float yaw)       { CAM::_SET_GAMEPLAY_CAM_RAW_YAW(yaw); }
inline void SetGameplayCamRawPitch(float pitch)   { CAM::_SET_GAMEPLAY_CAM_RAW_PITCH(pitch); }
inline void SetGameplayCamRelativeHeading(float h){ CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(h); }
inline void SetGameplayCamRelativePitch(float p)  { CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(p, 1.0f); }

// --- Camera state queries (for CameraType classification) ---
inline bool IsAimCamActive()            { return CAM::IS_AIM_CAM_ACTIVE(); }
inline bool IsFirstPersonAimCamActive() { return CAM::IS_FIRST_PERSON_AIM_CAM_ACTIVE(); }
inline bool IsGameplayCamRendering()    { return CAM::IS_GAMEPLAY_CAM_RENDERING(); }
inline int  GetFollowPedViewMode()      { return CAM::GET_FOLLOW_PED_CAM_VIEW_MODE(); }
inline int  GetFollowVehicleViewMode()  { return CAM::GET_FOLLOW_VEHICLE_CAM_VIEW_MODE(); }

// --- Player / ped state ---
inline Ped  PlayerPed()                 { return PLAYER::PLAYER_PED_ID(); }
inline bool IsPedInVehicle(Ped p)       { return PED::IS_PED_IN_ANY_VEHICLE(p, FALSE); }
inline bool IsPedAimingFromCover(Ped p) { return PED::IS_PED_AIMING_FROM_COVER(p); }
inline bool IsPedInCover(Ped p)         { return PED::IS_PED_IN_COVER(p, FALSE); }
inline bool IsPlayerFreeAiming()        { return PLAYER::IS_PLAYER_FREE_AIMING(PLAYER::PLAYER_ID()); }
inline bool IsCutsceneActive()          { return CUTSCENE::IS_CUTSCENE_ACTIVE(); }

// --- Script detection (for per-mission overrides) ---
// SCRIPT::GET_HASH_OF_THIS_SCRIPT_NAME returns the hash of the calling script (this ASI),
// not the active game script. To detect which mission is running we query known script hashes
// via DOES_SCRIPT_WITH_NAME_HASH_EXIST, which is how the original mod likely worked.
// The function is exposed here; ScriptHashes.h calls it for each notable entry.
inline bool DoesScriptExist(uint32_t hash) { return SCRIPT::DOES_SCRIPT_WITH_NAME_HASH_EXIST(hash); }

// --- Time scale (for SlowMotion VR comfort feature) ---
// Native hash confirmed: 0x1D408577D440E81E = GAMEPLAY::SET_TIME_SCALE
inline void SetTimeScale(float scale)    { GAMEPLAY::SET_TIME_SCALE(scale); }

// --- Entity ---
inline Vector3 GetEntityCoords(Entity e) { return ENTITY::GET_ENTITY_COORDS(e, TRUE); }
inline float   GetEntityHeading(Entity e){ return ENTITY::GET_ENTITY_HEADING(e); }

// First-person is view mode 4 in both ped and vehicle follow cameras.
inline bool IsFirstPersonView() {
    return GetFollowPedViewMode() == 4 || GetFollowVehicleViewMode() == 4;
}

} // namespace RVRNat
