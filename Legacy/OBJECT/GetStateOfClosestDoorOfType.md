# _GET_STATE_OF_CLOSEST_DOOR_OF_TYPE

--- ns: OBJECT --- ## GET_STATE_OF_CLOSEST_DOOR_OF_TYPE  // 0xEDC1A5B84AEF33FF 0x4B44A83D void GET_STATE_OF_CLOSEST_DOOR_OF_TYPE(Hash type, float x, float y, float z, BOOL* locked, float* heading);  locked is 0 if no door is found locked is 0 if door is unlocked locked is 1 if door is found and unlocked. ------------- the locked bool is either 0(unlocked)(false) or 1(locked)(true)  ## Parameters * **type**: * **x**: * **y**: * **z**: * **locked**: * **heading**:

### Parameters
* Hash type
* float x
* float y
* float z
* BOOL* locked
* float* heading

### Return Value
* void

### Notes
* AP Hash: 0x0x4B44A83D
* Build: 323
* locked is 0 if no door is found
locked is 0 if door is unlocked
locked is 1 if door is found and unlocked.

-------------
the locked bool is either 0(unlocked)(false) or 1(locked)(true)

