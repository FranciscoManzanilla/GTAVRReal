# _IS_NITROUS_ACTIVE

--- ns: VEHICLE --- ## IS_NITROUS_ACTIVE  // 0x491E822B2C464FE4 BOOL IS_NITROUS_ACTIVE(Vehicle vehicle);  NativeDB Introduced: 3095  Determines if the nitrous is currently activated in the specified vehicle.  ## Parameters * **vehicle**: The vehicle to check.  ## Return value Returns `true` if nitrous is active, otherwise `false`.  ## Examples  -- Retrieve the player ped local playerPed = PlayerPedId()  -- Retrieve the vehicle the player is currently in. local vehicle = GetVehiclePedIsIn(playerPed, false)  -- Check if the vehicle exists in the game world. if vehicle == 0 then return end  -- Print whether nitrous is active in the vehicle (True or False). print(IsNitrousActive(vehicle))  // Retrieve the player ped const playerPed = PlayerPedId();  // Retrieve the vehicle the player is currently in. const vehicle = GetVehiclePedIsIn(playerPed, false);  // Check if the vehicle exists in the game world. if (vehicle == 0) return;  // Print whether nitrous is active in the vehicle (True or False). console.log(IsNitrousActive(vehicle));  using static CitizenFX.Core.Native.API;  // Retrieve the player ped int playerPed = PlayerPedId();  // Retrieve the vehicle the player is currently in. int vehicle = GetVehiclePedIsIn(playerPed, false);  // Check if the vehicle exists in the game world. if (vehicle == 0) return;  // Print whether nitrous is active in the vehicle (True or False). Debug.WriteLine(IsNitrousActive(vehicle));

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* Build: 3095

