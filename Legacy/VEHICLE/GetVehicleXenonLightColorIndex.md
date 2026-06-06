# _GET_VEHICLE_XENON_LIGHT_COLOR_INDEX

No description available.

### Parameters
* Vehicle vehicle

### Return Value
* int

### Notes
* Build: 1604
* Returns the headlight color index from the vehicle. Value between 0, 12.
Use SET_VEHICLE_XENON_LIGHT_COLOR_INDEX to set the headlights color for the vehicle.
Must enable xenon headlights before it'll take affect.

Returns an int, value between 0-12 or 255 if no color is set.

