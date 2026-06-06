# _IS_CONTROL_RELEASED

--- ns: PAD --- ## IS_CONTROL_RELEASED  // 0x648EE3E7F38877DD 0x1F91A06E BOOL IS_CONTROL_RELEASED(int padIndex, int control);  Returns whether a control is currently _not_ pressed.  ## Parameters * **padIndex**: The control system instance to use. See [`ENABLE_ALL_CONTROL_ACTIONS`](#_0xA5FFE9B05F199DE7). * **control**: The [control ID](https://docs.fivem.net/docs/game-references/controls/#controls) to check.  ## Return value True if the control is not pressed.

### Parameters
* int control
* int action

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x1F91A06E
* Build: 323
* Returns whether a control is currently _not_ pressed.
control: see IS_CONTROL_ENABLED

