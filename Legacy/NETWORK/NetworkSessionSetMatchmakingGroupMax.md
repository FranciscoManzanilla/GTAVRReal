# _NETWORK_SESSION_SET_MATCHMAKING_GROUP_MAX

--- ns: NETWORK aliases: ["0x8B6A4DD0AF9CE215","_NETWORK_SESSION_SET_MAX_PLAYERS"] --- ## NETWORK_SESSION_SET_MATCHMAKING_GROUP_MAX  // 0x8B6A4DD0AF9CE215 0x5F29A7E0 void NETWORK_SESSION_SET_MATCHMAKING_GROUP_MAX(int playerType, int playerCount);  playerTypes: 0 = regular joiner 4 = spectator 8 = unknown  ## Parameters * **playerType**: * **playerCount**:

### Parameters
* int playerType
* int playerCount

### Return Value
* void

### Notes
* AP Hash: 0x0x5F29A7E0
* Build: 323
* playerType is an unsigned int from 0 to 4
0 = regular joiner
4 = spectator

