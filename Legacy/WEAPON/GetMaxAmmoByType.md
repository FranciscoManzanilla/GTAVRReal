# _GET_MAX_AMMO_BY_TYPE

--- ns: WEAPON aliases: ["0x585847C5E4E11709","_GET_MAX_AMMO_2"] --- ## _GET_MAX_AMMO_BY_TYPE  // 0x585847C5E4E11709 BOOL _GET_MAX_AMMO_BY_TYPE(Ped ped, cs_type(Any) Hash ammoType, int* ammo);   ## Parameters * **ped**: * **ammoType**: * **ammo**:  ## Return value

### Parameters
* Ped ped
* Hash ammoTypeHash
* int* ammo

### Return Value
* BOOL

### Notes
* Build: 1103
* Returns the max ammo for an ammo type. Ammo types: https://gist.github.com/root-cause/faf41f59f7a6d818b7db0b839bd147c1

