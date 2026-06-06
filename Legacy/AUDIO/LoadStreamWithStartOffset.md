# _LOAD_STREAM_WITH_START_OFFSET

--- ns: AUDIO --- ## LOAD_STREAM_WITH_START_OFFSET  // 0x59C16B79F53B3712 0xE5B5745C BOOL LOAD_STREAM_WITH_START_OFFSET(char* streamName, int startOffset, char* soundSet);  Load in named stream. Optionally can specify a sound set which contains the sound specified by name.  ## Parameters * **streamName**: * **startOffset**: * **soundSet**:  ## Return value

### Parameters
* const char* streamName
* int startOffset
* const char* soundSet

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xE5B5745C
* Build: 323
* Example:
AUDIO::LOAD_STREAM_WITH_START_OFFSET("STASH_TOXIN_STREAM", 2400, "FBI_05_SOUNDS");

Only called a few times in the scripts.

Full list of audio / sound names by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/soundNames.json

