# _SET_WEAPON_DAMAGE_MODIFIER

--- ns: WEAPON aliases: ["0x4757F00BC6323CFE", "_SET_WEAPON_DAMAGE_MODIFIER_THIS_FRAME"] --- ## _SET_WEAPON_DAMAGE_MODIFIER  // 0x4757F00BC6323CFE void _SET_WEAPON_DAMAGE_MODIFIER(Hash weaponHash, float damageMultiplier);  Changes the weapon damage output by the given multiplier value. Does NOT need to be called every frame.  ## Parameters * **weaponHash**: Hash of the weapon * **damageMultiplier**: Damage Multiplier  ## Examples SetWeaponDamageModifier(`WEAPON_CARBINERIFLE`, 0.8)

### Parameters
* Hash weaponHash
* float damageMultiplier

### Return Value
* void

### Notes
* Build: 505
* Changes the weapon damage output by the given multiplier value. Must be run every frame.
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

