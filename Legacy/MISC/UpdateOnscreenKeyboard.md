# _UPDATE_ONSCREEN_KEYBOARD

--- ns: MISC --- ## UPDATE_ONSCREEN_KEYBOARD  // 0x0CF2B696BBF945AE 0x23D0A1CE int UPDATE_ONSCREEN_KEYBOARD();  Returns the current state of the text input box.  enum eOSKStatus { OSK_INVALID = -1, OSK_PENDING = 0, OSK_SUCCESS = 1, OSK_CANCELLED = 2, OSK_FAILED = 3 };  ## Return value Returns a value from the list above.

### Return Value
* int

### Notes
* AP Hash: 0x0x23D0A1CE
* Build: 323
* Returns the current status of the onscreen keyboard, and updates the output.

Status Codes:

-1: Keyboard isn't active
0: User still editing
1: User has finished editing
2: User has canceled editing

