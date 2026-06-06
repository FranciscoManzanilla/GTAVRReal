# _DISPLAY_HELP_TEXT_THIS_FRAME

--- ns: HUD --- ## DISPLAY_HELP_TEXT_THIS_FRAME  // 0x960C9FF8F616E41C 0x18E3360A void DISPLAY_HELP_TEXT_THIS_FRAME(char* pTextLabel, BOOL bCurvedWindow);  Shows a help message for one frame. Do note that this message doesn't get added to the Pause Menu info section.  ## Parameters * **pTextLabel**: Text label for this message. * **bCurvedWindow**: Unused parameter.

### Parameters
* const char* message
* BOOL p1

### Return Value
* void

### Notes
* AP Hash: 0x0x18E3360A
* Build: 323
* The messages are localized strings.
Examples:
"No_bus_money"
"Enter_bus"
"Tour_help"
"LETTERS_HELP2"
"Dummy"

**The bool appears to always be false (if it even is a bool, as it's represented by a zero)**
--------
p1 doesn't seem to make a difference, regardless of the state it's in. 


picture of where on the screen this is displayed? 

