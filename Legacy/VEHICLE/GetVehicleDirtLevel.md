# _GET_VEHICLE_DIRT_LEVEL

--- ns: VEHICLE --- ## GET_VEHICLE_DIRT_LEVEL  // 0x8F17BC8BA08DA62B 0xFD15C065 float GET_VEHICLE_DIRT_LEVEL(Vehicle vehicle);  A getter for [`SET_VEHICLE_DIRT_LEVEL`](#_0x79D3B596FE44EE8B).  ## Parameters * **vehicle**: The vehicle to check.  ## Return value A number between 0.0 and 15.0 representing the vehicles dirt level.  ## Examples local Vehicle = GetVehiclePedIsUsing(PlayerPedId()) if GetVehicleDirtLevel(Vehicle) > 0.0 then -- if the cars dirt level is more than 0.0 then clean it. SetVehicleDirtLevel(Vehicle, 0.0) -- set the vehicle dirt level to 0.0 end

### Parameters
* Vehicle vehicle

### Return Value
* float

### Notes
* AP Hash: 0x0xFD15C065
* Build: 323
* Dirt level does not become greater than 15.0

