# _IS_SCRIPT_GLOBAL_SHAKING

--- ns: CAM aliases: ["0xC912AF078AF19212"] --- ## IS_SCRIPT_GLOBAL_SHAKING  // 0xC912AF078AF19212 0x6AEFE6A5 BOOL IS_SCRIPT_GLOBAL_SHAKING();  Determines if a global camera shake is currently active. You can stop the currently active global camera shake using [STOP_SCRIPT_GLOBAL_SHAKING](#_0x1C9D7949FA533490).  NativeDB Introduced: v323  ## Return value Returns `true` if a scripted global camera shake is currently in effect, otherwise `false`.  ## Examples -- Print whether a global camera shake is currently active print(IsScriptGlobalShaking()) // Print whether a global camera shake is currently active console.log(IsScriptGlobalShaking()); using static CitizenFX.Core.Native.API;  // Print whether a global camera shake is currently active Debug.WriteLine(IsScriptGlobalShaking());

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x6AEFE6A5
* Build: 323
* In drunk_controller.c4, sub_309
if (CAM::IS_SCRIPT_GLOBAL_SHAKING()) {
    CAM::STOP_SCRIPT_GLOBAL_SHAKING(0);
}

