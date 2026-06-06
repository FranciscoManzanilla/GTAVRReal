# _HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON

--- ns: WEAPON --- ## HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON  // 0x131D401334815E94 0x6DAABB39 BOOL HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON(Entity entity, Hash weaponHash, int weaponType);  It determines what weapons caused damage: If you want to define only a specific weapon, second parameter=weapon hash code, third parameter=0 If you want to define any melee weapon, second parameter=0, third parameter=1. If you want to identify any weapon (firearms, melee, rockets, etc.), second parameter=0, third parameter=2.  ## Parameters * **entity**: * **weaponHash**: * **weaponType**:  ## Return value

### Parameters
* Entity entity
* Hash weaponHash
* int weaponType

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x6DAABB39
* Build: 323
* It determines what weapons caused damage:

If you want to define only a specific weapon, second parameter=weapon hash code, third parameter=0
If you want to define any melee weapon, second parameter=0, third parameter=1.
If you want to identify any weapon (firearms, melee, rockets, etc.), second parameter=0, third parameter=2.
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

