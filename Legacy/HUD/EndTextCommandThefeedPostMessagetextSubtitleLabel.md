# _END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_SUBTITLE_LABEL

No description available.

### Parameters
* const char* txdName
* const char* textureName
* BOOL flash
* int iconType
* const char* sender
* const char* subject

### Return Value
* int

### Notes
* Build: 323
* This function can show pictures of every texture that can be requested by REQUEST_STREAMED_TEXTURE_DICT.

Needs more research.

Only one type of usage in the scripts:

HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_SUBTITLE_LABEL("CHAR_ACTING_UP", "CHAR_ACTING_UP", 0, 0, "DI_FEED_CHAR", a_0);

