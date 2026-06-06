# _CLEAR_PRIMARY_VEHICLE_TASK

No description available.

### Parameters
* Vehicle vehicle

### Return Value
* void

### Notes
* Build: 1290
* This native is very useful when switching the player to a ped inside a vehicle that has a task assigned prior to the player switch.
It is necessary to clear the ped's tasks AND call this native with the vehicle the player is switching into in order to allow the player to control the vehicle after the player switches.

