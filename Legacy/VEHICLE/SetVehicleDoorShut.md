# _SET_VEHICLE_DOOR_SHUT

--- ns: VEHICLE --- ## SET_VEHICLE_DOOR_SHUT  // 0x93D9BD300D7789E5 0x142606BD void SET_VEHICLE_DOOR_SHUT(Vehicle vehicle, int doorIndex, BOOL closeInstantly);  Sets the specified door index shut on the passed vehicle.  enum eDoorId { VEH_EXT_DOOR_DSIDE_F = 0, VEH_EXT_DOOR_DSIDE_R = 1, VEH_EXT_DOOR_PSIDE_F = 2, VEH_EXT_DOOR_PSIDE_R = 3, VEH_EXT_BONNET = 4, VEH_EXT_BOOT = 5, // 0x872E72B8 = 0xFFFFFFFF, }  ## Parameters * **vehicle**: Vehicle. * **doorIndex**: Index of the door you want to close. * **closeInstantly**: Whether the doors close instantly.  ## Examples local Vehicle = GetVehiclePedIsUsing(PlayerPedId()) for i = 0, 5 do SetVehicleDoorShut(Vehicle, i, false) -- will close all doors from 0-5 end

### Parameters
* Vehicle vehicle
* int doorId
* BOOL closeInstantly

### Return Value
* void

### Notes
* AP Hash: 0x0x142606BD
* Build: 323
* enum eDoorId
{
	VEH_EXT_DOOR_INVALID_ID = -1,
	VEH_EXT_DOOR_DSIDE_F,
	VEH_EXT_DOOR_DSIDE_R,
	VEH_EXT_DOOR_PSIDE_F,
	VEH_EXT_DOOR_PSIDE_R,
	VEH_EXT_BONNET,
	VEH_EXT_BOOT
};

