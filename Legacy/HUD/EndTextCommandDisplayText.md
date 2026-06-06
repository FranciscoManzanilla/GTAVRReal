# _END_TEXT_COMMAND_DISPLAY_TEXT

--- ns: HUD aliases: ["_DRAW_TEXT"] --- ## END_TEXT_COMMAND_DISPLAY_TEXT  // 0xCD015E5BB0D96A57 0x6F8350CE void END_TEXT_COMMAND_DISPLAY_TEXT(float x, float y);  After applying the properties to the text (See UI::SET_TEXT_), this will draw the text in the applied position. Also 0.0f < x, y < 1.0f, percentage of the axis.  NativeDB Added Parameter 3: int p2  ## Parameters * **x**: * **y**:

### Parameters
* float x
* float y
* int p2

### Return Value
* void

### Notes
* AP Hash: 0x0x6F8350CE
* Build: 323
* After applying the properties to the text (See HUD::SET_TEXT_), this will draw the text in the applied position. Also 0.0f < x, y < 1.0f, percentage of the axis.

Used to be known as _DRAW_TEXT

