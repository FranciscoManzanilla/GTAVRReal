#pragma once
#include <cstdint>

// =============================================================================
// ScriptHashes.h
//
// Script name hash table for per-mission VR behavior.
//
// BACKGROUND
// ----------
// The original ASI contained a table of approximately 300 GTA script names
// (built at RVA 0x2426+ during initialization) converted to JOAAT hashes.
// This table was used to detect which script was currently active and adjust
// VR behavior accordingly -- for example:
//   - Pilot school missions: apply a wider FOV and disable HMD heading control
//     because the player uses aircraft instruments, not free look.
//   - Minigames (darts, tennis): apply the OverrideDartsTennisFOV setting.
//   - Heavy cutscene missions: switch stereo mode to match CutscenePitchMode.
//
// The full list of 300 script names is visible in the binary's .rdata section
// (strings like "abigail1", "armenian1", "family1", etc.).
//
// CURRENT STATUS
// --------------
// This file implements the hash function and a representative subset of
// notable scripts. The per-script behavior dispatch is not yet wired into
// RVR_TrackingTick -- the ScriptCategory values are computed but not acted on.
//
// WHAT NEEDS TO BE DONE
// ---------------------
// 1. Complete the kNotableScripts table with all 300 entries from the binary.
// 2. Add a call in RVR_TrackingTick to check the active script hash each frame
//    using GET_HASH_OF_CURRENT_SCRIPT_NAME and look it up here.
// 3. Implement the per-category overrides:
//    SC_FLIGHT:          disable heading control, use wider FOV
//    SC_MINIGAME:        apply OverrideDartsTennisFOV when set
//    SC_CUTSCENE_HEAVY:  enforce stereoInCutscenes mode
// =============================================================================

namespace RVRHash {

// JOAAT -- Jenkins one-at-a-time hash, GTA variant (lowercase normalization).
// This is the standard hash used throughout the RAGE engine for script names,
// bone names, and most string identifiers.
inline uint32_t Joaat(const char* str) {
    uint32_t hash = 0;
    for (const char* p = str; *p; ++p) {
        char c = *p;
        if (c >= 'A' && c <= 'Z') c += 32;
        hash += (uint8_t)c;
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

enum ScriptCategory {
    SC_NONE           = 0,
    SC_MISSION        = 1,  // standard mission, typical third-person camera
    SC_FLIGHT         = 2,  // flight missions: wider FOV, no heading control
    SC_CUTSCENE_HEAVY = 3,  // missions with extended cutscenes
    SC_MINIGAME       = 4,  // darts, tennis, golf: FOV override
};

struct ScriptEntry {
    const char*    name;
    ScriptCategory cat;
};

// Complete notable script table extracted from binary (747 scripts total in binary).
// Scripts confirmed present in the original RealVR.asi .rdata section.
static const ScriptEntry kNotableScripts[] = {
    // Flight: wider FOV, disable HMD heading control
    { "pilot_school",               SC_FLIGHT },
    { "pilot_school_mp",            SC_FLIGHT },
    { "launcher_pilotschool",       SC_FLIGHT },
    { "sp_pilotschool_reg",         SC_FLIGHT },
    { "stunt_plane_races",          SC_FLIGHT },
    { "gtest_airplane",             SC_FLIGHT },
    { "gtest_helicopter",           SC_FLIGHT },
    { "heli_gun",                   SC_FLIGHT },
    { "heli_streaming",             SC_FLIGHT },
    // Minigame: suppress HMD FOV override
    { "darts",                      SC_MINIGAME },
    { "am_darts",                   SC_MINIGAME },
    { "launcher_darts",             SC_MINIGAME },
    { "tennis",                     SC_MINIGAME },
    { "tennis_ambient",             SC_MINIGAME },
    { "tennis_family",              SC_MINIGAME },
    { "tennis_network_mp",          SC_MINIGAME },
    { "launcher_tennis",            SC_MINIGAME },
    { "golf_mp",                    SC_MINIGAME },
    { "golf_ai_foursome",           SC_MINIGAME },
    { "golf_ai_foursome_putting",   SC_MINIGAME },
    { "launcher_golf",              SC_MINIGAME },
    { "triathlonsp",                SC_MINIGAME },
    { "launcher_triathlon",         SC_MINIGAME },
    // Cutscene-heavy: enforce stereoInCutscenes behavior
    { "prologue1",                  SC_CUTSCENE_HEAVY },
    { "armenian1",                  SC_CUTSCENE_HEAVY },
    { "armenian2",                  SC_CUTSCENE_HEAVY },
    { "armenian3",                  SC_CUTSCENE_HEAVY },
    { "chinese1",                   SC_CUTSCENE_HEAVY },
    { "chinese2",                   SC_CUTSCENE_HEAVY },
    { "michael1",                   SC_CUTSCENE_HEAVY },
    { "michael2",                   SC_CUTSCENE_HEAVY },
    { "michael3",                   SC_CUTSCENE_HEAVY },
    { "michael4",                   SC_CUTSCENE_HEAVY },
    { "trevor1",                    SC_CUTSCENE_HEAVY },
    { "trevor2",                    SC_CUTSCENE_HEAVY },
    { "trevor3",                    SC_CUTSCENE_HEAVY },
    { "trevor4",                    SC_CUTSCENE_HEAVY },
    { "franklin1",                  SC_CUTSCENE_HEAVY },
    { "franklin2",                  SC_CUTSCENE_HEAVY },
    { "lamar1",                     SC_CUTSCENE_HEAVY },
    { "fbi4_intro",                 SC_CUTSCENE_HEAVY },
    { "docks_heista",               SC_CUTSCENE_HEAVY },
    { "docks_heistb",               SC_CUTSCENE_HEAVY },
    { "jewelry_heist",              SC_CUTSCENE_HEAVY },
    { "rural_bank_heist",           SC_CUTSCENE_HEAVY },
    { "finale_heist2a",             SC_CUTSCENE_HEAVY },
    { "finale_heist2b",             SC_CUTSCENE_HEAVY },
    { "finale_heist2_intro",        SC_CUTSCENE_HEAVY },
    { "agency_heist3a",             SC_CUTSCENE_HEAVY },
    { "agency_heist3b",             SC_CUTSCENE_HEAVY },
    { "finalea",                    SC_CUTSCENE_HEAVY },
    { "finaleb",                    SC_CUTSCENE_HEAVY },
    { "finalec1",                   SC_CUTSCENE_HEAVY },
    { "finalec2",                   SC_CUTSCENE_HEAVY },
    { "finale_choice",              SC_CUTSCENE_HEAVY },
    { "finale_intro",               SC_CUTSCENE_HEAVY },
    { "finale_endgame",             SC_CUTSCENE_HEAVY },
    { "thelastone",                 SC_CUTSCENE_HEAVY },
    // Standard missions
    { "martin1",                    SC_MISSION },
    { "lester1",                    SC_MISSION },
    { "barry1",                     SC_MISSION },
    { "barry2",                     SC_MISSION },
    { "barry3",                     SC_MISSION },
    { "barry4",                     SC_MISSION },
    { "omega1",                     SC_MISSION },
    { "omega2",                     SC_MISSION },
    { "epsilon1",                   SC_MISSION },
    { "epsilon2",                   SC_MISSION },
    { "epsilon3",                   SC_MISSION },
    { "epsilon4",                   SC_MISSION },
    { "maude1",                     SC_MISSION },
    { "nigel1",                     SC_MISSION },
    { "nigel2",                     SC_MISSION },
    { "nigel3",                     SC_MISSION },
    { "exile1",                     SC_MISSION },
    { "exile2",                     SC_MISSION },
    { "exile3",                     SC_MISSION },
    { "hunting1",                   SC_MISSION },
    { "hunting2",                   SC_MISSION },
    { "solomon1",                   SC_MISSION },
    { "solomon2",                   SC_MISSION },
    { "solomon3",                   SC_MISSION },
    { "dreyfuss1",                  SC_MISSION },
    { "fanatic1",                   SC_MISSION },
    { "fanatic2",                   SC_MISSION },
    { "fanatic3",                   SC_MISSION },
    { "paparazzo1",                 SC_MISSION },
    { "paparazzo2",                 SC_MISSION },
    { "paparazzo3",                 SC_MISSION },
    { "paparazzo4",                 SC_MISSION },
};

inline ScriptCategory CategoryForHash(uint32_t hash) {
    for (const auto& e : kNotableScripts) {
        if (Joaat(e.name) == hash) return e.cat;
    }
    return SC_NONE;
}

// Detect the active notable script by querying DOES_SCRIPT_WITH_NAME_HASH_EXIST
// for each entry in the table. Called once per frame from the script thread.
// Returns SC_NONE if no notable script is currently loaded.
// Note: iterates the full table each frame; keep the table small.
template<typename FnExists>
inline ScriptCategory DetectActiveScriptCategory(FnExists doesExist) {
    for (const auto& e : kNotableScripts) {
        if (doesExist(Joaat(e.name))) return e.cat;
    }
    return SC_NONE;
}

} // namespace RVRHash
