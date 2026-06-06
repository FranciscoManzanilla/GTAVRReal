# _SET_VEHICLE_NUMBER_PLATE_TEXT

--- ns: VEHICLE --- ## SET_VEHICLE_NUMBER_PLATE_TEXT  // 0x95A88F0B409CDA47 0x400F9556 void SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle vehicle, char* plateText);  ## Parameters * **vehicle**: The vehicle to set the plate for * **plateText**: The text to set the plate to, 8 chars maximum  ## Examples local playerPed = PlayerPedId() local vehicle = GetVehiclePedIsIn(playerPed) SetVehicleNumberPlateText(vehicle, "KING")

### Parameters
* Vehicle vehicle
* const char* plateText

### Return Value
* void

### Notes
* AP Hash: 0x0x400F9556
* Build: 323
* Sets a vehicle's license plate text.  8 chars maximum.

Example:
Ped playerPed = PLAYER::PLAYER_PED_ID();
Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
char *plateText = "KING";
VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, plateText);

