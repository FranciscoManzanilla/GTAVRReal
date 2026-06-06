# _SET_VEHICLE_EXTRA

--- ns: VEHICLE --- ## SET_VEHICLE_EXTRA  // 0x7EE3A3C5E4A40CC9 0x642D065C void SET_VEHICLE_EXTRA(Vehicle vehicle, int extraId, BOOL disable);  Note: only some vehicle have extras extra ids are from 1 - 9 depending on the vehicle ------------------------------------------------- ^ not sure if outdated or simply wrong. Max extra ID for b944 is 14 ------------------------------------------------- p2 is not a on/off toggle. mostly 0 means on and 1 means off. not sure if it really should be a BOOL. ------------------------------------------------- Confirmed p2 does not work as a bool. Changed to int. [0=on, 1=off]  ## Parameters * **vehicle**: * **extraId**: * **disable**:

### Parameters
* Vehicle vehicle
* int extraId
* BOOL disable

### Return Value
* void

### Notes
* AP Hash: 0x0x642D065C
* Build: 323
* Available extraIds are 1-14, however none of the vehicles have extras above 12.

