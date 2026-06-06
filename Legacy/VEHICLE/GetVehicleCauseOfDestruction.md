# _GET_VEHICLE_CAUSE_OF_DESTRUCTION

--- ns: VEHICLE --- ## GET_VEHICLE_CAUSE_OF_DESTRUCTION  // 0xE495D1EF4C91FD20 0x7F8C20DD Hash GET_VEHICLE_CAUSE_OF_DESTRUCTION(Vehicle vehicle);   ## Parameters * **vehicle**: The vehicle to get the cause of destruction of.  ## Return value A hash representing the destruction cause. These can be weapon hashes.  ## Examples local destructionCauseHash = GetVehicleCauseOfDestruction(GetVehiclePedIsIn(PlayerPedId(), true)) if destructionCauseHash == GetHashKey("weapon_stickybomb") then -- It looks like the vehicle was destroyed by a sticky bomb Citizen.Trace('Vehicle was destroyed by a sticky bomb!') elseif destructionCauseHash ~= 0 then -- It looks like the vehicle was destroyed by something else! Citizen.Trace('Vehicle was destroyed by: ' .. destructionCauseHash) end

### Parameters
* Vehicle vehicle

### Return Value
* Hash

### Notes
* AP Hash: 0x0x7F8C20DD
* Build: 323
* iVar3 = get_vehicle_cause_of_destruction(uLocal_248[iVar2]);
if (iVar3 == joaat("weapon_stickybomb"))
{
	func_171(726);
	iLocal_260 = 1;
}

