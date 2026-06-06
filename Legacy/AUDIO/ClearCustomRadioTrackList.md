# _CLEAR_CUSTOM_RADIO_TRACK_LIST

--- ns: AUDIO aliases: ["0x1654F24A88A8E3FE"] --- ## CLEAR_CUSTOM_RADIO_TRACK_LIST  // 0x1654F24A88A8E3FE 0x1D766976 void CLEAR_CUSTOM_RADIO_TRACK_LIST(char* radioStation);  Clears the previously queued custom track lost for the given radio station.  ## Parameters * **radioStation**:

### Parameters
* const char* radioStation

### Return Value
* void

### Notes
* AP Hash: 0x0x1D766976
* Build: 323
* 3 calls in the b617d scripts, removed duplicate.

AUDIO::CLEAR_CUSTOM_RADIO_TRACK_LIST("RADIO_16_SILVERLAKE");
AUDIO::CLEAR_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK");

