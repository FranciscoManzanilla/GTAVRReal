# _GET_WEAPON_HUD_STATS

--- ns: WEAPON --- ## GET_WEAPON_HUD_STATS  // 0xD92C739EE34C9EBA 0xA9AD3D98 BOOL GET_WEAPON_HUD_STATS(Hash weaponHash, Any* outData);  // members should be aligned to 8 bytes by default but it's best to use alignas here, just to be sure struct WeaponHudStatsData { alignas(8) uint8_t hudDamage; // 0x0000 alignas(8) uint8_t hudSpeed; // 0x0008 alignas(8) uint8_t hudCapacity; // 0x0010 alignas(8) uint8_t hudAccuracy; // 0x0018 alignas(8) uint8_t hudRange; // 0x0020 }; Usage: WeaponHudStatsData data; if (GET_WEAPON_HUD_STATS(weaponHash, (Any*)&data)) { // uint8_t damagePercentage = data.hudDamage etc... }  ## Parameters * **weaponHash**: * **outData**:  ## Return value

### Parameters
* Hash weaponHash
* Any* outData

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xA9AD3D98
* Build: 323
* struct WeaponHudStatsData
{
    BYTE hudDamage; // 0x0000
    char _0x0001[0x7]; // 0x0001
    BYTE hudSpeed; // 0x0008
    char _0x0009[0x7]; // 0x0009
    BYTE hudCapacity; // 0x0010
    char _0x0011[0x7]; // 0x0011
    BYTE hudAccuracy; // 0x0018
    char _0x0019[0x7]; // 0x0019
    BYTE hudRange; // 0x0020
};

Usage:

WeaponHudStatsData data;
if (GET_WEAPON_HUD_STATS(weaponHash, (int *)&data))
{
    // BYTE damagePercentage = data.hudDamage and so on
}
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

