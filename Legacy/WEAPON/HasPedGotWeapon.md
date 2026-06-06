# _HAS_PED_GOT_WEAPON

--- ns: WEAPON --- ## HAS_PED_GOT_WEAPON  // 0x8DECB02F88F428BC 0x43D2FA82 BOOL HAS_PED_GOT_WEAPON(Ped ped, Hash weaponHash, BOOL p2);  p2 should be FALSE, otherwise it seems to always return FALSE Bool does not check if the weapon is current equipped, unfortunately.  ## Parameters * **ped**: * **weaponHash**: * **p2**:  ## Return value

### Parameters
* Ped ped
* Hash weaponHash
* BOOL p2

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x43D2FA82
* Build: 323
* p2 should be FALSE, otherwise it seems to always return FALSE

Bool does not check if the weapon is current equipped, unfortunately.
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

