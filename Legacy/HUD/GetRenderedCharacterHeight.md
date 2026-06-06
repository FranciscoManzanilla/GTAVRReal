# _GET_RENDERED_CHARACTER_HEIGHT

--- ns: HUD aliases: ["0xDB88A37483346780","_GET_TEXT_SCALE_HEIGHT"] --- ## GET_RENDERED_CHARACTER_HEIGHT  // 0xDB88A37483346780 0x3330175B float GET_RENDERED_CHARACTER_HEIGHT(float size, int font);  This gets the height of the FONT and not the total text. You need to get the number of lines your text uses, and get the height of a newline (I'm using a smaller value) to get the total text height. Old name: _GET_TEXT_SCALE_HEIGHT  ## Parameters * **size**: * **font**:  ## Return value

### Parameters
* float size
* int font

### Return Value
* float

### Notes
* AP Hash: 0x0x3330175B
* Build: 323
* This gets the height of the FONT and not the total text. You need to get the number of lines your text uses, and get the height of a newline (I'm using a smaller value) to get the total text height.

