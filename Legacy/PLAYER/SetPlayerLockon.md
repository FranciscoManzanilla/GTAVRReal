# _SET_PLAYER_LOCKON

--- ns: PLAYER --- ## SET_PLAYER_LOCKON  // 0x5C8B2F450EE4328E 0x0B270E0F void SET_PLAYER_LOCKON(Player player, BOOL toggle);  Used to toggle the square up aim.  ## Parameters * **player**: The player ID to toggle the lock on for. * **toggle**: Set to false to prevent lock on, set to true to allow for lock on.  ## Examples  local plyId = PlayerId() SetPlayerLockon(plyId, false)

### Parameters
* Player player
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x0B270E0F
* Build: 323
* Example from fm_mission_controler.ysc.c4:

PLAYER::SET_PLAYER_LOCKON(PLAYER::PLAYER_ID(), 1);

All other decompiled scripts using this seem to be using the player id as the first parameter, so I feel the need to confirm it as so.

No need to confirm it says PLAYER_ID() so it uses PLAYER_ID() lol.

