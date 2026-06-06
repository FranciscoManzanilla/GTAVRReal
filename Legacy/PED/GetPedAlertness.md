# _GET_PED_ALERTNESS

--- ns: PED --- ## GET_PED_ALERTNESS  // 0xF6AA118530443FD2 0xF83E4DAF int GET_PED_ALERTNESS(Ped ped);  Returns the ped's alertness (0-3). Values : 0 : Neutral 1 : Heard something (gun shot, hit, etc) 2 : Knows (the origin of the event) 3 : Fully alerted (is facing the event?) If the Ped does not exist, returns -1.  ## Parameters * **ped**:  ## Return value

### Parameters
* Ped ped

### Return Value
* int

### Notes
* AP Hash: 0x0xF83E4DAF
* Build: 323
* Returns the ped's alertness (0-3).

Values : 

0 : Neutral
1 : Heard something (gun shot, hit, etc)
2 : Knows (the origin of the event)
3 : Fully alerted (is facing the event?)

If the Ped does not exist, returns -1.

