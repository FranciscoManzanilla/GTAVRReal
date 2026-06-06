# _SET_VEHICLE_LIGHT_MULTIPLIER

--- ns: VEHICLE --- ## SET_VEHICLE_LIGHT_MULTIPLIER  // 0xB385454F8791F57C 0x48039D6A void SET_VEHICLE_LIGHT_MULTIPLIER(Vehicle vehicle, float multiplier);  This multiplier has no limit, by default the game has this set to `1.0`.  ## Parameters * **vehicle**: The vehicle handle. * **multiplier**: The multiplier applied to the vehicle's headlights.

### Parameters
* Vehicle vehicle
* float multiplier

### Return Value
* void

### Notes
* AP Hash: 0x0x48039D6A
* Build: 323
* multiplier = brightness of head lights.
this value isn't capped afaik.

multiplier = 0.0 no lights
multiplier = 1.0 default game value


