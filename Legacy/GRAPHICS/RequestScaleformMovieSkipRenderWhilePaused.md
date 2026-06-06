# _REQUEST_SCALEFORM_MOVIE_SKIP_RENDER_WHILE_PAUSED

--- ns: GRAPHICS aliases: ["_REQUEST_SCALEFORM_MOVIE3", "_REQUEST_SCALEFORM_MOVIE_INTERACTIVE"] --- ## REQUEST_SCALEFORM_MOVIE_SKIP_RENDER_WHILE_PAUSED  // 0xBD06C611BB9048C2 int REQUEST_SCALEFORM_MOVIE_SKIP_RENDER_WHILE_PAUSED(char* scaleformName);  Requests a scaleform movie that doesn't render when the game is paused (With [`SET_GAME_PAUSED`](#_0x577D1284D6873711)).  ## Parameters * **scaleformName**:  ## Return value

### Parameters
* const char* scaleformName

### Return Value
* int

### Notes
* Build: 323
* Similar to REQUEST_SCALEFORM_MOVIE, but seems to be some kind of "interactive" scaleform movie?

These seem to be the only scaleforms ever requested by this native:
"breaking_news"
"desktop_pc"
"ECG_MONITOR"
"Hacking_PC"
"TEETH_PULLING"

Note: Unless this hash is out-of-order, this native is next-gen only.


