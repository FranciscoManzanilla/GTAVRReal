# _GET_RADIO_STATION_NAME

--- ns: AUDIO --- ## GET_RADIO_STATION_NAME  // 0xB28ECA15046CA8B9 0x3DF493BC char* GET_RADIO_STATION_NAME(int stationIndex);  ## Parameters * **stationIndex**:  ## Return value Returns the name of the radio station with the specified index. This serves as the text label.

### Parameters
* int radioStation

### Return Value
* const char*

### Notes
* AP Hash: 0x0x3DF493BC
* Build: 323
* Converts radio station index to string. Use HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION to get the user-readable text.

