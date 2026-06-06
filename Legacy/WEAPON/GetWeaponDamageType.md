# _GET_WEAPON_DAMAGE_TYPE

--- ns: WEAPON --- ## GET_WEAPON_DAMAGE_TYPE  // 0x3BE0BB12D25FB305 0x013AFC13 int GET_WEAPON_DAMAGE_TYPE(Hash weaponHash);  0=unknown (or incorrect weaponHash) 1= no damage (flare,snowball, petrolcan) 2=melee 3=bullet 4=force ragdoll fall 5=explosive (RPG, Railgun, grenade) 6=fire(molotov) 8=fall(WEAPON_HELI_CRASH) 10=electric 11=barbed wire 12=extinguisher 13=gas 14=water cannon(WEAPON_HIT_BY_WATER_CANNON)  ## Parameters * **weaponHash**:  ## Return value

### Parameters
* Hash weaponHash

### Return Value
* int

### Notes
* AP Hash: 0x0x013AFC13
* Build: 323
* enum class eDamageType
{
	UNKNOWN = 0,
	NONE = 1,
	MELEE = 2,
	BULLET = 3,
	BULLET_RUBBER = 4,
	EXPLOSIVE = 5,
	FIRE = 6,
	COLLISION = 7,
	FALL = 8,
	DROWN = 9,
	ELECTRIC = 10,
	BARBED_WIRE = 11,
	FIRE_EXTINGUISHER = 12,
	SMOKE = 13,
	WATER_CANNON = 14,
	TRANQUILIZER = 15,
};

Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

