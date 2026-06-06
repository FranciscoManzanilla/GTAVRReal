# _GET_LOCAL_PLAYER_AIM_STATE

--- ns: PAD --- ## GET_LOCAL_PLAYER_AIM_STATE  // 0xBB41AFBBBC0A0287 0x81802053 int GET_LOCAL_PLAYER_AIM_STATE();  Returns the local player's targeting mode. See [`SET_PLAYER_TARGETING_MODE`](#_0xB1906895227793F3).  ## Return value

### Return Value
* int

### Notes
* AP Hash: 0x0x81802053
* Build: 323
* Hard-coded to return 3 if using KBM, otherwise same behavior as GET_LOCAL_PLAYER_GAMEPAD_AIM_STATE.

