# _SET_GAME_PAUSED

--- ns: MISC --- ## SET_GAME_PAUSED  // 0x577D1284D6873711 0x8230FF6C void SET_GAME_PAUSED(BOOL toggle);  Make sure to call this from the correct thread if you're using multiple threads because all other threads except the one which is calling SET_GAME_PAUSED will be paused which means you will lose control and the game remains in paused mode until you exit GTA5.exe  ## Parameters * **toggle**:

### Parameters
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x8230FF6C
* Build: 323
* Make sure to call this from the correct thread if you're using multiple threads because all other threads except the one which is calling SET_GAME_PAUSED will be paused which means you will lose control and the game remains in paused mode until you exit GTA5.exe

