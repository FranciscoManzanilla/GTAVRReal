# _GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_WITH_BYTE_LIMIT

No description available.

### Parameters
* const char* text
* int position
* int length
* int maxLength

### Return Value
* const char*

### Notes
* AP Hash: 0x0x0183A66C
* Build: 323
* Returns a substring of a specified length starting at a specified position. The result is guaranteed not to exceed the specified max length.

NOTE: The 'maxLength' parameter might actually be the size of the buffer that is returned. More research is needed. -CL69

Example:
// Condensed example of how Rockstar uses this function
strLen = HUD::GET_LENGTH_OF_LITERAL_STRING(MISC::GET_ONSCREEN_KEYBOARD_RESULT());
subStr = HUD::GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_WITH_BYTE_LIMIT(MISC::GET_ONSCREEN_KEYBOARD_RESULT(), 0, strLen, 63);

--

"fm_race_creator.ysc", line 85115:
// parameters modified for clarity
BOOL sub_8e5aa(char *text, int length) {
    for (i = 0; i <= (length - 2); i += 1) {
        if (!MISC::ARE_STRINGS_EQUAL(HUD::GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME_WITH_BYTE_LIMIT(text, i, i + 1, 1), " ")) {
            return FALSE;
        }
    }
    return TRUE;
}

