# _GET_PLAYER_INVINCIBLE

--- ns: PLAYER --- ## GET_PLAYER_INVINCIBLE  // 0xB721981B2B939E07 0x680C90EE BOOL GET_PLAYER_INVINCIBLE(Player player);  This native will only return true if a player was made invincible with [`SET_PLAYER_INVINCIBLE`](#_0x239528EACDC3E7DE).  You should use [`GET_PLAYER_INVINCIBLE_2`](#_0xF2E3912B) to get both [`SET_PLAYER_INVINCIBLE`](#_0x239528EACDC3E7DE) and [`SET_PLAYER_INVINCIBLE_KEEP_RAGDOLL_ENABLED`](#_0x6BC97F4F4BB3C04B) invincibility state.  ## Parameters * **player**: The player index  ## Return value A boolean to tell if the player is invincible.

### Parameters
* Player player

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x680C90EE
* Build: 323
* Returns the Player's Invincible status.

This function will always return false if 0x733A643B5B0C53C1 is used to set the invincibility status. To always get the correct result, use this:

 bool IsPlayerInvincible(Player player)
    {
     auto addr = getScriptHandleBaseAddress(GET_PLAYER_PED(player)); 

        if (addr)
     {
         DWORD flag = *(DWORD *)(addr + 0x188);
            return ((flag & (1 << 8)) != 0) || ((flag & (1 << 9)) != 0);
      }

       return false;
 }



