// =============================================================================
// RVRConfig.cpp
//
// INI file loader for RealVR.ini.
//
// Keys and defaults confirmed by RE of the original RealVR.asi binary.
// GetPrivateProfileIntA is called for each key from section [Defaults].
// The ASI clamps values to [0, max] at load time; we mirror that here.
//
// IMPORTANT: StereoInCutscenes, ZoomOverride, Stereo, and VRAPI are NOT read
// by the ASI. Those keys belong to the proxy d3d11.dll and are not loaded here.
//
// iniPath: full path to RealVR.ini, constructed by replacing the exe name
// at the end of GetModuleFileNameA() with "RealVR.ini".
// =============================================================================

#include "RVRTypes.h"
#include <Windows.h>
#include <cstdio>

void RVRConfig::Load(const char* iniPath) {
    // Helper: read int from [Defaults], clamp to [0, maxVal].
    auto geti = [&](const char* key, int def, int maxVal) -> int {
        int v = (int)GetPrivateProfileIntA("Defaults", key, def, iniPath);
        if (v < 0) v = 0;
        if (v > maxVal) v = maxVal;
        return v;
    };

    // Order and defaults match the original ASI binary exactly (confirmed by RE).
    fixView                = geti("FixView",                   1, 1) != 0;
    pitchControl           = geti("PitchControl",              1, 1) != 0;
    overrideDartsTennisFOV = geti("OverrideDartsTennisFOV",    0, 1) != 0;
    allow1stCoverAimHeading= geti("Allow1stCoverAimHeading",   1, 1) != 0;
    dominantEye            = geti("DominantEye",               2, 2);
    decouple3rdPersonCam   = geti("Decouple3rdPersonCam",      1, 1) != 0;
    fullCamTrackInCutscene = geti("FullCamTrackInCutscene",    1, 1) != 0;
    hotkeys                = geti("Hotkeys",                   0, 1) != 0;
    foldWorldRot           = geti("FoldWorldRotIntoRenderPose",1, 1) != 0;
    cutscenePitchMode      = geti("CutscenePitchMode",         1, 2);
    slowMotion             = geti("SlowMotion",                0, 1) != 0;
    gyroVehicle            = geti("GyroVehicle",               0, 1) != 0;
    positionTracking       = geti("PositionTracking",          1, 1) != 0;
    showDebugText          = geti("ShowDebugText",             0, 1) != 0;
    headingControl         = geti("HeadingControl",            1, 2);
    universalFOVFix        = geti("UniversalFOVFix",           0, 3);

    // HMDFovDeg: extension not in original ASI. Float read via string to avoid
    // locale-dependent decimal separator issues.
    char fovBuf[32] = "100";
    GetPrivateProfileStringA("Defaults", "HMDFovDeg", "100", fovBuf, sizeof(fovBuf), iniPath);
    float parsed = 100.f;
    if (sscanf_s(fovBuf, "%f", &parsed) == 1 && parsed >= 60.f && parsed <= 130.f)
        hmdFovDeg = parsed;
}
