# _GET_GLOBAL_ACTIONSCRIPT_FLAG

--- ns: HUD aliases: ["0xE3B05614DCE1D014"] --- ## GET_GLOBAL_ACTIONSCRIPT_FLAG  // 0xE3B05614DCE1D014 0xD217EE7E int GET_GLOBAL_ACTIONSCRIPT_FLAG(int flagIndex);  Returns the ActionScript flagValue. ActionScript flags are global flags that scaleforms use Flags found during testing 0: Returns 1 if the web_browser keyboard is open, otherwise 0 1: Returns 1 if the player has clicked back twice on the opening page, otherwise 0 (web_browser) 2: Returns how many links the player has clicked in the web_browser scaleform, returns 0 when the browser gets closed 9: Returns the current selection on the mobile phone scaleform There are 20 flags in total.  ## Parameters * **flagIndex**:  ## Return value

### Parameters
* int flagIndex

### Return Value
* int

### Notes
* AP Hash: 0x0xD217EE7E
* Build: 323
* Returns the ActionScript flagValue.
ActionScript flags are global flags that scaleforms use
Flags found during testing
0: Returns 1 if the web_browser keyboard is open, otherwise 0
1: Returns 1 if the player has clicked back twice on the opening page, otherwise 0 (web_browser)
2: Returns how many links the player has clicked in the web_browser scaleform, returns 0 when the browser gets closed
9: Returns the current selection on the mobile phone scaleform

There are 20 flags in total.

