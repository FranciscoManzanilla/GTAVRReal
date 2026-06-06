# _APPLY_DAMAGE_TO_PED

--- ns: PED --- ## APPLY_DAMAGE_TO_PED  // 0x697157CED63F18D4 0x4DC27FCF void APPLY_DAMAGE_TO_PED(Ped ped, int damageAmount, BOOL armorFirst);  damages a ped with the given amount ---- armorFirst means it will damage/lower the armor first before damaging the player. setting damageAmount to a negative amount will cause the player or the armor (depending on armorFirst) to be healed by damageAmount instead.  NativeDB Added Parameter 4: Any p3  ## Parameters * **ped**: * **damageAmount**: * **armorFirst**:

### Parameters
* Ped ped
* int damageAmount
* BOOL p2
* Any p3
* Hash weaponType

### Return Value
* void

### Notes
* AP Hash: 0x0x4DC27FCF
* Build: 323
* damages a ped with the given amount

