# _SET_CUSTOM_RADIO_TRACK_LIST

--- ns: AUDIO aliases: ["0x4E404A9361F75BB2"] --- ## SET_CUSTOM_RADIO_TRACK_LIST  // 0x4E404A9361F75BB2 0x128C3873 void SET_CUSTOM_RADIO_TRACK_LIST(char* radioStation, char* trackListName, BOOL forceNow);  Queues up a custom track list on the specified radio station. The content in the track list will be played as soon as possible. The station does not have to be frozen.   ## Parameters * **radioStation**: * **trackListName**: * **forceNow**: wheter or not to interrupt the current track on the tracklist

### Parameters
* const char* radioStation
* const char* trackListName
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0x128C3873
* Build: 323
* Examples:

AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "END_CREDITS_KILL_MICHAEL", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "END_CREDITS_KILL_MICHAEL", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "END_CREDITS_KILL_TREVOR", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "END_CREDITS_SAVE_MICHAEL_TREVOR", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "OFF_ROAD_RADIO_ROCK_LIST", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_06_COUNTRY", "MAGDEMO2_RADIO_DINGHY", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_16_SILVERLAKE", "SEA_RACE_RADIO_PLAYLIST", 1);
AUDIO::SET_CUSTOM_RADIO_TRACK_LIST("RADIO_01_CLASS_ROCK", "OFF_ROAD_RADIO_ROCK_LIST", 1);

