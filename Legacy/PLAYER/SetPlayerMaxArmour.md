# _SET_PLAYER_MAX_ARMOUR

--- ns: PLAYER --- ## SET_PLAYER_MAX_ARMOUR  // 0x77DFCCF5948B8C71 0xC6C3C53B void SET_PLAYER_MAX_ARMOUR(Player player, int value);  Default is 100. Use player id and not ped id. For instance: PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), 100); // main_persistent.ct4  ## Parameters * **player**: * **value**:

### Parameters
* Player player
* int value

### Return Value
* void

### Notes
* AP Hash: 0x0xC6C3C53B
* Build: 323
* Default is 100. Use player id and not ped id. For instance: PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), 100); // main_persistent.ct4

