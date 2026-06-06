# _IS_VEHICLE_SIREN_ON

--- ns: VEHICLE --- ## IS_VEHICLE_SIREN_ON  // 0x4C9BF537BE2634B2 0x25EB5873 BOOL IS_VEHICLE_SIREN_ON(Vehicle vehicle); Returns whether the vehicle's lights and sirens are on.  ## Parameters * **vehicle**:  ## Return value Returns false if siren and lights are disabled or true if they are enabled.  ## Examples local veh = GetVehiclePedIsIn(PlayerPedId()) print(tostring(IsVehicleSirenOn(veh))

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x25EB5873
* Build: 323

