# _GIVE_DELAYED_WEAPON_TO_PED

--- ns: WEAPON --- ## GIVE_DELAYED_WEAPON_TO_PED  // 0xB282DC6EBD803C75 0x5868D20D void GIVE_DELAYED_WEAPON_TO_PED(Ped ped, Hash weaponHash, int ammoCount, BOOL bForceInHand);  Gives a weapon to PED with a delay, example: WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PED::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_PISTOL"), 1000, false)  ## Parameters * **ped**: * **weaponHash**: * **ammoCount**: * **bForceInHand**:

### Parameters
* Ped ped
* Hash weaponHash
* int ammoCount
* BOOL bForceInHand

### Return Value
* void

### Notes
* AP Hash: 0x0x5868D20D
* Build: 323
* Gives a weapon to PED with a delay, example:

WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PED::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_PISTOL"), 1000, false)
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

