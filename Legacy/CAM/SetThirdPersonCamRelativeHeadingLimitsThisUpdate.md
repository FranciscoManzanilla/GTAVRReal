# _SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE

No description available.

### Parameters
* float minimum
* float maximum

### Return Value
* void

### Notes
* AP Hash: 0x0x749909AC
* Build: 323
* minimum: Degrees between -180f and 180f.
maximum: Degrees between -180f and 180f.

Clamps the gameplay camera's current yaw.

Eg. SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(0.0f, 0.0f) will set the horizontal angle directly behind the player.

