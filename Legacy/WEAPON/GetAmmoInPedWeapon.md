# _GET_AMMO_IN_PED_WEAPON

--- ns: WEAPON --- ## GET_AMMO_IN_PED_WEAPON  // 0x015A522136D7F951 0x0C755733 int GET_AMMO_IN_PED_WEAPON(Ped ped, Hash weaponhash);  WEAPON::GET_AMMO_IN_PED_WEAPON(PLAYER::PLAYER_PED_ID(), a_0) From decompiled scripts Returns total ammo in weapon GTALua Example : natives.WEAPON.GET_AMMO_IN_PED_WEAPON(plyPed, WeaponHash)  ## Parameters * **ped**: * **weaponhash**:  ## Return value

### Parameters
* Ped ped
* Hash weaponhash

### Return Value
* int

### Notes
* AP Hash: 0x0x0C755733
* Build: 323
* WEAPON::GET_AMMO_IN_PED_WEAPON(PLAYER::PLAYER_PED_ID(), a_0)

From decompiled scripts
Returns total ammo in weapon

GTALua Example :
natives.WEAPON.GET_AMMO_IN_PED_WEAPON(plyPed, WeaponHash)
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

