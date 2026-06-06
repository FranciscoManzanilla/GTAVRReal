# _SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE

No description available.

### Parameters
* Hash modelHash
* float x
* float y
* float z
* BOOL locked
* float xRotMult
* float yRotMult
* float zRotMult

### Return Value
* void

### Notes
* AP Hash: 0x0x4E0A260B
* Build: 323
* Hardcoded not to work in multiplayer environments.
When you set locked to 0 the door open and to 1 the door close
OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(${prop_gate_prison_01}, 1845.0, 2605.0, 45.0, 0, 0.0, 50.0, 0);  //door open

OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(${prop_gate_prison_01}, 1845.0, 2605.0, 45.0, 1, 0.0, 50.0, 0);  //door close

