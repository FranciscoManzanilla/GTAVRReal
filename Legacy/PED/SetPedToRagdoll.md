# _SET_PED_TO_RAGDOLL

--- ns: PED --- ## SET_PED_TO_RAGDOLL  // 0xAE99FB955581844A 0x83CB5052 BOOL SET_PED_TO_RAGDOLL(Ped ped, int minTime, int maxTime, int ragdollType, BOOL bAbortIfInjured, BOOL bAbortIfDead, BOOL bForceScriptControl);  p4/p5: Unusued in TU27  ### Ragdoll Types **0**: CTaskNMRelax **1**: CTaskNMScriptControl: Hardcoded not to work in networked environments. **Else**: CTaskNMBalance  ## Parameters * **ped**: The ped to ragdoll. * **minTime**: Time(ms) Ped is in ragdoll mode; only applies to ragdoll types 0 and not 1. * **maxTime**: * **ragdollType**: * **bAbortIfInjured**: unused * **bAbortIfDead**: unused * **bForceScriptControl**:  ## Return value

### Parameters
* Ped ped
* int time1
* int time2
* int ragdollType
* BOOL p4
* BOOL p5
* BOOL p6

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x83CB5052
* Build: 323
* p4/p5: Unused in TU27
Ragdoll Types:
**0**: CTaskNMRelax
**1**: CTaskNMScriptControl: Hardcoded not to work in networked environments.
**Else**: CTaskNMBalance
time1- Time(ms) Ped is in ragdoll mode; only applies to ragdoll types 0 and not 1.

time2- Unknown time, in milliseconds

ragdollType-
0 : Normal ragdoll
1 : Falls with stiff legs/body
2 : Narrow leg stumble(may not fall)
3 : Wide leg stumble(may not fall)

p4, p5, p6- No idea. In R*'s scripts they are usually either "true, true, false" or "false, false, false".




EDIT 3/11/16: unclear what 'mircoseconds' mean-- a microsecond is 1000x a ms, so time2 must be 1000x time1?  more testing needed.  -sob

Edit Mar 21, 2017: removed part about time2 being the microseconds version of time1. this just isn't correct. time2 is in milliseconds, and time1 and time2 don't seem to be connected in any way.

