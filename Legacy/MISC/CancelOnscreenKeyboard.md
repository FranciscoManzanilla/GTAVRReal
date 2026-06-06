# _CANCEL_ONSCREEN_KEYBOARD

--- ns: MISC aliases: ["0x58A39BE597CE99CD", "_CANCEL_ONSCREEN_KEYBOARD"] --- ## CANCEL_ONSCREEN_KEYBOARD  // 0x58A39BE597CE99CD 0x196444BB void CANCEL_ONSCREEN_KEYBOARD();  Closes the onscreen keyboard on console versions of the game.  **NOTE:** Do not use this native in FiveM/PC, because [`UPDATE_ONSCREEN_KEYBOARD`](#_0x0CF2B696BBF945AE) value doesn't get cleaned up and stays as `0`. You should use [`FORCE_CLOSE_TEXT_INPUT_BOX`](#_0x8817605C2BA76200) instead.

### Return Value
* void

### Notes
* Build: 757
* DO NOT use this as it doesn't clean up the text input box properly and your script will get stuck in the UPDATE_ONSCREEN_KEYBOARD() loop.
Use FORCE_CLOSE_TEXT_INPUT_BOX instead.

