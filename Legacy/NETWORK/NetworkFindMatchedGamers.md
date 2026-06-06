# _NETWORK_FIND_MATCHED_GAMERS

--- ns: NETWORK aliases: ["0xF7B2CFDE5C9F700D"] --- ## NETWORK_FIND_MATCHED_GAMERS  // 0xF7B2CFDE5C9F700D 0xA13045D4 BOOL NETWORK_FIND_MATCHED_GAMERS(Any p0, float p1, float p2, float p3);   ## Parameters * **p0**: * **p1**: * **p2**: * **p3**:  ## Return value

### Parameters
* int attribute
* float fallbackLimit
* float lowerLimit
* float upperLimit

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xA13045D4
* Build: 323
* Uses attributes to find players with similar stats. Upper/Lower limit must be above zero or the fallback limit +/-0.1 is used.
There can be up to 15 attributes, they are as follows:

0 = Races
1 = Parachuting
2 = Horde
3 = Darts
4 = Arm Wrestling
5 = Tennis
6 = Golf
7 = Shooting Range
8 = Deathmatch
9 = MPPLY_MCMWIN/MPPLY_CRMISSION

