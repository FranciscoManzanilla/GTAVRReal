# _GET_ARE_CAMERA_CONTROLS_DISABLED

--- ns: PLAYER aliases: ["_IS_PLAYER_CAM_CONTROL_DISABLED", "0x7C814D2FB49F40C0"] --- ## GET_ARE_CAMERA_CONTROLS_DISABLED  // 0x7C814D2FB49F40C0 0x4C456AF2 BOOL GET_ARE_CAMERA_CONTROLS_DISABLED();  ## Return value  Returns `true` if the main player's camera controls are disabled. Also returns `true` if the there is no main player info.

### Return Value
* BOOL

### Notes
* Build: 323
* Returns true when the player is not able to control the cam i.e. when running a benchmark test, switching the player or viewing a cutscene.

Note: I am not 100% sure if the native actually checks if the cam control is disabled but it seems promising.

