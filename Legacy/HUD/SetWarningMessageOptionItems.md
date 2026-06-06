# _SET_WARNING_MESSAGE_OPTION_ITEMS

--- ns: HUD aliases: ["0x0C5A80A9E096D529", "_SET_WARNING_MESSAGE_LIST_ROW"] --- ##  // 0x0C5A80A9E096D529 BOOL SET_WARNING_MESSAGE_OPTION_ITEMS(int index, char* name, int cash, int rp, int lvl, int colour);  Adds options on a warning message.  ## Parameters * **index**: * **name**: * **cash**: * **rp**: * **lvl**: * **colour**:  ## Return value

### Parameters
* int index
* const char* name
* int cash
* int rp
* int lvl
* int colour

### Return Value
* BOOL

### Notes
* Build: 323
* Some sort of list displayed in a warning message. Yet unknown how to prevent repeating.
Param names copied from the corresponding scaleform function "SET_LIST_ROW".
Example: https://i.imgur.com/arKvOYx.png

