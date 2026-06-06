# _RESET_PED_MOVEMENT_CLIPSET

--- ns: PED --- ## RESET_PED_MOVEMENT_CLIPSET  // 0xAA74EC0CB0AAEA2C 0xB83CEE93 void RESET_PED_MOVEMENT_CLIPSET(Ped ped, float transitionSpeed);  ## Parameters * **ped**: * **transitionSpeed**:

### Parameters
* Ped ped
* float p1

### Return Value
* void

### Notes
* AP Hash: 0x0xB83CEE93
* Build: 323
* If p1 is 0.0, I believe you are back to normal. 
If p1 is 1.0, it looks like you can only rotate the ped, not walk.

Using the following code to reset back to normal
PED::RESET_PED_MOVEMENT_CLIPSET(PLAYER::PLAYER_PED_ID(), 0.0);

