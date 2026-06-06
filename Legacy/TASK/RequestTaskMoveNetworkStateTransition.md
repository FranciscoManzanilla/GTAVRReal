# _REQUEST_TASK_MOVE_NETWORK_STATE_TRANSITION

--- ns: TASK aliases: ["0xD01015C7316AE176"] --- ## REQUEST_TASK_MOVE_NETWORK_STATE_TRANSITION  // 0xD01015C7316AE176 0x885724DE BOOL REQUEST_TASK_MOVE_NETWORK_STATE_TRANSITION(Ped ped, char* name);   ## Parameters * **ped**: A ped handle. * **name**: The name of the target request state in the move network file.  ## Return value Technically a `void`. Scripts treat this as a boolean, but the game never sets the result, so it will return the ped handle instead.

### Parameters
* Ped ped
* const char* name

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x885724DE
* Build: 323

