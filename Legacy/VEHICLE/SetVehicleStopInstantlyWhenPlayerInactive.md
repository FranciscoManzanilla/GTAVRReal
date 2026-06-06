# _SET_VEHICLE_STOP_INSTANTLY_WHEN_PLAYER_INACTIVE

No description available.

### Parameters
* Vehicle vehicle
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x847F1304
* Build: 323
* sfink: sets bit in vehicle's structure, used by maintransition, fm_mission_controller, mission_race and a couple of other scripts. see dissassembly: 
CVehicle *__fastcall sub_140CDAA10(signed int a1, char a2)
{
    CVehicle *result; // rax@1

    result = EntityAsCVehicle(a1);
    if ( result )
    {
        result->field_886 &= 0xEFu;
        result->field_886 |= 16 * (a2 & 1);
    }
    return result;
}

