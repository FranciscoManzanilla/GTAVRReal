# _STOP_SCRIPT_GLOBAL_SHAKING

--- ns: CAM aliases: ["0x1C9D7949FA533490"] --- ## STOP_SCRIPT_GLOBAL_SHAKING  // 0x1C9D7949FA533490 0x26FCFB96 void STOP_SCRIPT_GLOBAL_SHAKING(BOOL bStopImmediately);  Stops the currently active global camera shake that was initiated by a script. You can check if a global camera shake is active using [IS_SCRIPT_GLOBAL_SHAKING](#_0xC912AF078AF19212).  NativeDB Introduced: v323  ## Parameters * **bStopImmediately**: A boolean indicating whether the camera shake should stop instantly (TRUE) or gradually fade out (FALSE).  ## Examples -- Stops the currently active global camera shake with a gradual fade out if IsScriptGlobalShaking() then StopScriptGlobalShaking(false) end // Stops the currently active global camera shake with a gradual fade out if (IsScriptGlobalShaking()) { StopScriptGlobalShaking(false); } using static CitizenFX.Core.Native.API;  // Stops the currently active global camera shake with a gradual fade out if (IsScriptGlobalShaking()) { StopScriptGlobalShaking(false); }

### Parameters
* BOOL p0

### Return Value
* void

### Notes
* AP Hash: 0x0x26FCFB96
* Build: 323
* In drunk_controller.c4, sub_309
if (CAM::IS_SCRIPT_GLOBAL_SHAKING()) {
    CAM::STOP_SCRIPT_GLOBAL_SHAKING(0);
}

