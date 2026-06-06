# _GET_NEXT_AUDIBLE_BEAT

--- ns: AUDIO aliases: ["0xC64A06D939F826F5"] --- ## GET_NEXT_AUDIBLE_BEAT  // 0xC64A06D939F826F5 BOOL GET_NEXT_AUDIBLE_BEAT(float* timeInSeconds, cs_type(AnyPtr) float* bpm, int* beatNum);  ## Parameters * **timeInSeconds**: time in seconds until the start of the next beat * **bpm**: current tempo in beats per minute, * **beatNum**: integer beat within the bar  ## Return value Returns information on beat information for any audible music.

### Parameters
* float* out1
* float* out2
* int* out3

### Return Value
* BOOL

### Notes
* Build: 1493

