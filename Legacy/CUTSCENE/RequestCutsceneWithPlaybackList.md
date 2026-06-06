# _REQUEST_CUTSCENE_WITH_PLAYBACK_LIST

--- ns: CUTSCENE aliases: ["0xC23DE0E91C30B58C","_REQUEST_CUTSCENE_EX"] --- ## REQUEST_CUTSCENE_WITH_PLAYBACK_LIST  // 0xC23DE0E91C30B58C 0xD98F656A void REQUEST_CUTSCENE_WITH_PLAYBACK_LIST(char* cutsceneName, int playbackFlags, int flags);  playbackFlags: Which scenes should be played. Example: 0x105 (bit 0, 2 and 8 set) will enable scene 1, 3 and 9.  ## Parameters * **cutsceneName**: * **playbackFlags**: * **flags**: Usually 8

### Parameters
* const char* cutsceneName
* int playbackFlags
* int flags

### Return Value
* void

### Notes
* AP Hash: 0x0xD98F656A
* Build: 323
* flags: Usually 8

playbackFlags: Which scenes should be played.
Example: 0x105 (bit 0, 2 and 8 set) will enable scene 1, 3 and 9.
Full list of cutscene names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/cutsceneNames.json

