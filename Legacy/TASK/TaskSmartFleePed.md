# _TASK_SMART_FLEE_PED

--- ns: TASK --- ## TASK_SMART_FLEE_PED  // 0x22B0D0E37CCB840D 0xE52EB560 void TASK_SMART_FLEE_PED(Ped ped, Ped fleeTarget, float distance, Any fleeTime, BOOL p4, BOOL p5);  Makes a ped run away from another ped (fleeTarget). distance = ped will flee this distance. fleeTime = ped will flee for this amount of time, set to "-1" to flee forever  ## Parameters * **ped**: * **fleeTarget**: * **distance**: * **fleeTime**: * **p4**: * **p5**:

### Parameters
* Ped ped
* Ped fleeTarget
* float safeDistance
* int fleeTime
* BOOL preferPavements
* BOOL updateToNearestHatedPed

### Return Value
* void

### Notes
* AP Hash: 0x0xE52EB560
* Build: 323
* Makes a ped run away from another ped (fleeTarget).

distance = ped will flee this distance.
fleeTime = ped will flee for this amount of time, set to "-1" to flee forever

