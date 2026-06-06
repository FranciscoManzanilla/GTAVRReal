# _SET_PLAYER_WANTED_LEVEL_NO_DROP

--- ns: PLAYER --- ## SET_PLAYER_WANTED_LEVEL_NO_DROP  // 0x340E61DE7F471565 0xED6F44F5 void SET_PLAYER_WANTED_LEVEL_NO_DROP(Player player, int wantedLevel, BOOL delayedResponse);  ## Parameters * **player**: the target player * **wantedLevel**: the wanted level 1-5 * **delayedResponse**: false = 0-10sec police spawn response time, true = 10-20sec police spawn response time  ## Examples local player = PlayerId() SetPlayerWantedLevelNoDrop(player, 5, false) -- 5 star wanted level

### Parameters
* Player player
* int wantedLevel
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0xED6F44F5
* Build: 323
* p2 is always false in R* scripts

