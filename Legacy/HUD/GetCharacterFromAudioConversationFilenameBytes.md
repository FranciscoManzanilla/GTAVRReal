# _GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_BYTES

No description available.

### Parameters
* const char* text
* int startPosition
* int endPosition

### Return Value
* const char*

### Notes
* AP Hash: 0x0xFA6373BB
* Build: 323
* Returns a substring that is between two specified positions. The length of the string will be calculated using (endPosition - startPosition).

Example:
// Get "STRING" text from "MY_STRING"
subStr = HUD::GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_BYTES("MY_STRING", 3, 9);
// Overflows are possibly replaced with underscores (needs verification)
subStr = HUD::GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_BYTES("MY_STRING", 3, 10); // "STRING_"?

