# _GET_CURRENT_PED_VEHICLE_WEAPON

--- ns: WEAPON --- ## GET_CURRENT_PED_VEHICLE_WEAPON  // 0x1017582BCD3832DC 0xF26C5D65 BOOL GET_CURRENT_PED_VEHICLE_WEAPON(Ped ped, Hash* weaponHash);  ## Parameters * **ped**: * **weaponHash**:  ## Return value

### Parameters
* Ped ped
* Hash* weaponHash

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xF26C5D65
* Build: 323
* Example in VB

    Public Shared Function GetVehicleCurrentWeapon(Ped As Ped) As Integer
        Dim arg As New OutputArgument()
        Native.Function.Call(Hash.GET_CURRENT_PED_VEHICLE_WEAPON, Ped, arg)
        Return arg.GetResult(Of Integer)()
    End Function

Usage:
If GetVehicleCurrentWeapon(Game.Player.Character) = -821520672 Then ...Do something
Note: -821520672 = VEHICLE_WEAPON_PLANE_ROCKET

