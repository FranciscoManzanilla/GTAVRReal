# _DISABLE_CONTROL_ACTION

--- ns: PAD --- ## DISABLE_CONTROL_ACTION  // 0xFE99B66D079CF6BC 0x3800C0DC void DISABLE_CONTROL_ACTION(int padIndex, int control, BOOL disable);   [Control values and meaning](https://docs.fivem.net/docs/game-references/controls/#controls)  Example: `CONTROLS::DISABLE_CONTROL_ACTION(2, 19, true)` disables the switching UI from appearing both when using a keyboard and Xbox 360 controller. Needs to be executed each frame. Control group 1 and 0 gives the same results as 2. Same results for all players.   ## Parameters * **padIndex**: * **control**: * **disable**:

### Parameters
* int control
* int action
* BOOL disableRelatedActions

### Return Value
* void

### Notes
* AP Hash: 0x0x3800C0DC
* Build: 323
* control: see IS_CONTROL_ENABLED

