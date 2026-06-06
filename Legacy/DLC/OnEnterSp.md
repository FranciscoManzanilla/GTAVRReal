# _ON_ENTER_SP

--- ns: DLC aliases: ["0xD7C10C4A637992C9","_LOAD_SP_DLC_MAPS"] --- ## ON_ENTER_SP  // 0xD7C10C4A637992C9 0x8BF60FC3 void ON_ENTER_SP();  Unloads GROUP_MAP (GTAO/MP) DLC data and loads GROUP_MAP_SP DLC. Neither are loaded by default, 0888C3502DBBEEF5 is a cognate to this function and loads MP DLC (and unloads SP DLC by extension). The original (and wrong) definition is below: This unload the GTA:O DLC map parts (like high end garages/apartments). Works in singleplayer.

### Return Value
* void

### Notes
* AP Hash: 0x0x8BF60FC3
* Build: 323
* Unloads GROUP_MAP (GTAO/MP) DLC data and loads GROUP_MAP_SP DLC. Neither are loaded by default, ON_ENTER_MP is a cognate to this function and loads MP DLC (and unloads SP DLC by extension).
Works in singleplayer.

