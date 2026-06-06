# _NETWORK_JOIN_TRANSITION

--- ns: NETWORK --- ## NETWORK_JOIN_TRANSITION  // 0x9D060B08CD63321A 0xB054EC4B BOOL NETWORK_JOIN_TRANSITION(Player player);  int handle[76]; NETWORK_HANDLE_FROM_FRIEND(iSelectedPlayer, &handle[0], 13); Player uVar2 = NETWORK_GET_PLAYER_FROM_GAMER_HANDLE(&handle[0]); NETWORK_JOIN_TRANSITION(uVar2); nothing doin.  ## Parameters * **player**:  ## Return value

### Parameters
* Player player

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xB054EC4B
* Build: 323
* int handle[76];
          NETWORK_HANDLE_FROM_FRIEND(iSelectedPlayer, &handle[0], 13);
          Player uVar2 = NETWORK_GET_PLAYER_FROM_GAMER_HANDLE(&handle[0]);
          NETWORK_JOIN_TRANSITION(uVar2);
nothing doin.

