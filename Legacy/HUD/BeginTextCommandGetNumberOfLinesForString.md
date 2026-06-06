# _BEGIN_TEXT_COMMAND_GET_NUMBER_OF_LINES_FOR_STRING

No description available.

### Parameters
* const char* entry

### Return Value
* void

### Notes
* AP Hash: 0x0x94B82066
* Build: 323
* int GetLineCount(char *text, float x, float y)
    {
     BEGIN_TEXT_COMMAND_GET_NUMBER_OF_LINES_FOR_STRING("STRING");
                ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
      return BEGIN_TEXT_COMMAND_GET_NUMBER_OF_LINES_FOR_STRING(x, y);
    }

