# _SET_PLAYER_INVINCIBLE

--- ns: PLAYER --- ## SET_PLAYER_INVINCIBLE  // 0x239528EACDC3E7DE 0xDFB9A2A2 void SET_PLAYER_INVINCIBLE(Player player, BOOL bInvincible);  Make the player impervious to all forms of damage.  ## Parameters * **player**: The player index. * **bInvincible**:

### Parameters
* Player player
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0xDFB9A2A2
* Build: 323
* Simply sets you as invincible (Health will not deplete).

Use 0x733A643B5B0C53C1 instead if you want Ragdoll enabled, which is equal to:
*(DWORD *)(playerPedAddress + 0x188) |= (1 << 9);

