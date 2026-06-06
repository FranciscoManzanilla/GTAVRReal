# _TASK_HANDS_UP

--- ns: TASK --- ## TASK_HANDS_UP  // 0xF2EAB31979A7F910 0x8DCC19C5 void TASK_HANDS_UP(Ped ped, int duration, Ped facingPed, int p3, BOOL p4);  In the scripts, p3 was always -1. p3 seems to be duration or timeout of turn animation. Also facingPed can be 0 or -1 so ped will just raise hands up.  ## Parameters * **ped**: * **duration**: * **facingPed**: * **p3**: * **p4**:

### Parameters
* Ped ped
* int duration
* Ped facingPed
* int timeToFacePed
* int flags

### Return Value
* void

### Notes
* AP Hash: 0x0x8DCC19C5
* Build: 323
* In the scripts, p3 was always -1.

p3 seems to be duration or timeout of turn animation.
Also facingPed can be 0 or -1 so ped will just raise hands up.

