# _SET_PLAYER_WANTED_LEVEL

--- ns: PLAYER --- ## SET_PLAYER_WANTED_LEVEL  // 0x39FF19C64EF7DA5B 0xB7A0914B void SET_PLAYER_WANTED_LEVEL(Player player, int wantedLevel, BOOL delayedResponse);  ## Parameters * **player**: the target player * **wantedLevel**: the wanted level 1-5 * **delayedResponse**: false = 0-10sec police spawn response time, true = 10-20sec police spawn response time  ## Examples local player = PlayerId() SetPlayerWantedLevel(player, 5, false) -- 5 star wanted level

### Parameters
* Player player
* int wantedLevel
* BOOL disableNoMission

### Return Value
* void

### Notes
* AP Hash: 0x0xB7A0914B
* Build: 323
* Call SET_PLAYER_WANTED_LEVEL_NOW for immediate effect

wantedLevel is an integer value representing 0 to 5 stars even though the game supports the 6th wanted level but no police will appear since no definitions are present for it in the game files

disableNoMission-  Disables When Off Mission- appears to always be false


