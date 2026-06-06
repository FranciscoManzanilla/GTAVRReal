# _REMOVE_ALL_PED_WEAPONS

--- ns: WEAPON --- ## REMOVE_ALL_PED_WEAPONS  // 0xF25DF915FA38C5F3 0xA44CE817 void REMOVE_ALL_PED_WEAPONS(Ped ped, BOOL p1);  Parameter `p1` does not seem to be used or referenced in game binaries. **Note:** When called for networked entities, a `CRemoveAllWeaponsEvent` will be created per request.  ## Parameters * **ped**: The ped entity * **p1**:

### Parameters
* Ped ped
* BOOL p1

### Return Value
* void

### Notes
* AP Hash: 0x0xA44CE817
* Build: 323
* setting the last params to false it does that same so I would suggest its not a toggle

