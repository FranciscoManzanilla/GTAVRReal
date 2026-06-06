# _TOGGLE_PAUSED_RENDERPHASES

--- ns: GRAPHICS aliases: ["_ENABLE_GAMEPLAY_CAM","_SET_FROZEN_RENDERING_DISABLED"] --- ## TOGGLE_PAUSED_RENDERPHASES  // 0xDFC252D8A3E15AB7 0x30ADE541 void TOGGLE_PAUSED_RENDERPHASES(BOOL toggle);  Switches the rendering display to exclude everything except PostFX, resulting in a frozen screen before the UI pass.  ## Parameters * **toggle**: Setting it to `false` will exclude render updates as mentioned in the description, until it's set back to `true`.

### Parameters
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x30ADE541
* Build: 323

