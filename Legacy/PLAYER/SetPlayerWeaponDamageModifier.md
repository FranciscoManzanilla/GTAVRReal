# _SET_PLAYER_WEAPON_DAMAGE_MODIFIER

--- ns: PLAYER --- ## SET_PLAYER_WEAPON_DAMAGE_MODIFIER  // 0xCE07B9F7817AADA3 0xB02C2F39 void SET_PLAYER_WEAPON_DAMAGE_MODIFIER(Player player, float modifier);  The native ensures the 'modifier' parameter is 0.1 or greater.  ## Parameters * **player**: * **modifier**:

### Parameters
* Player player
* float modifier

### Return Value
* void

### Notes
* AP Hash: 0x0xB02C2F39
* Build: 323
* This modifies the damage value of your weapon. Whether it is a multiplier or base damage is unknown. 

Based on tests, it is unlikely to be a multiplier.

modifier's min value is 0.1

