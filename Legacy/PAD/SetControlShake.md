# _SET_CONTROL_SHAKE

No description available.

### Parameters
* int control
* int duration
* int frequency

### Return Value
* void

### Notes
* Build: 323
* control: see IS_CONTROL_ENABLED
duration in milliseconds 
frequency should range from about 10 (slow vibration) to 255 (very fast)

example:
SET_CONTROL_SHAKE(PLAYER_CONTROL, 100, 200);

