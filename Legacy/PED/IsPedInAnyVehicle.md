# _IS_PED_IN_ANY_VEHICLE

--- ns: PED --- ## IS_PED_IN_ANY_VEHICLE  // 0x997ABD671D25CA0B 0x3B0171EE BOOL IS_PED_IN_ANY_VEHICLE(Ped ped, BOOL atGetIn);  Returns whether the specified ped is in any vehicle. If `atGetIn` is set to true, also returns true if the ped is currently in the process of entering a vehicle (a specific stage check for `CTaskEnterVehicle`).  ## Parameters * **ped**: The ped to check. * **atGetIn**: `true` to also consider attempting to enter a vehicle.  ## Return value Whether or not the ped is currently involved in any vehicle.  ## Examples if IsPedInAnyVehicle(PlayerPedId(), false) then print('Local player is in a vehicle!') end

### Parameters
* Ped ped
* BOOL atGetIn

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x3B0171EE
* Build: 323
* Gets a value indicating whether the specified ped is in any vehicle.

If 'atGetIn' is false, the function will not return true until the ped is sitting in the vehicle and is about to close the door. If it's true, the function returns true the moment the ped starts to get onto the seat (after opening the door). Eg. if false, and the ped is getting into a submersible, the function will not return true until the ped has descended down into the submersible and gotten into the seat, while if it's true, it'll return true the moment the hatch has been opened and the ped is about to descend into the submersible.

