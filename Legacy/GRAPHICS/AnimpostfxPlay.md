# _ANIMPOSTFX_PLAY

--- ns: GRAPHICS aliases: ["_START_SCREEN_EFFECT"] --- ## ANIMPOSTFX_PLAY  // 0x2206BF9A37B7F724 0x1D980479 void ANIMPOSTFX_PLAY(char* effectName, int duration, BOOL looped);  duration - is how long to play the effect for in milliseconds. If 0, it plays the default length if loop is true, the effect won't stop until you call ANIMPOSTFX_STOP on it. (only loopable effects)  ## Parameters * **effectName**: * **duration**: * **looped**:

### Parameters
* const char* effectName
* int duration
* BOOL looped

### Return Value
* void

### Notes
* AP Hash: 0x0x1D980479
* Build: 323
* duration - is how long to play the effect for in milliseconds. If 0, it plays the default length
if loop is true, the effect won't stop until you call ANIMPOSTFX_STOP on it. (only loopable effects)

Full list of animpostFX / screen effects by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animPostFxNamesCompact.json

