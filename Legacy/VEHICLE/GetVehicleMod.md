# _GET_VEHICLE_MOD

--- ns: VEHICLE --- ## GET_VEHICLE_MOD  // 0x772960298DA26FDB 0xDC520069 int GET_VEHICLE_MOD(Vehicle vehicle, int modType);  ## Parameters * **vehicle**: The vehicle to get the mod of. * **modType**: Refer to eVehicleModType in [`SET_VEHICLE_MOD`](#_0x6AF0636DDEDCB6DD).  ## Return value Returns the current modIndex, or `-1` if the mod is stock.

### Parameters
* Vehicle vehicle
* int modType

### Return Value
* int

### Notes
* AP Hash: 0x0xDC520069
* Build: 323
* In b944, there are 50 (0 - 49) mod types. See SET_VEHICLE_MOD for the list.

Returns -1 if the vehicle mod is stock

