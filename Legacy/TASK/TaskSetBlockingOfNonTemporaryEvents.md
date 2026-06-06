# _TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS

--- ns: TASK --- ## TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS  // 0x90D2156198831D69 0x1B54FB6B void TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped ped, BOOL toggle);  I cant believe I have to define this, this is one of the best natives. It makes the ped ignore basically all shocking events around it. Occasionally the ped may comment or gesture, but other than that they just continue their daily activities. This includes shooting and wounding the ped. And - most importantly - they do not flee. Since it is a task, every time the native is called the ped will stop for a moment.  ## Parameters * **ped**: * **toggle**:

### Parameters
* Ped ped
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x1B54FB6B
* Build: 323
* I cant believe I have to define this, this is one of the best natives.

It makes the ped ignore basically all shocking events around it. Occasionally the ped may comment or gesture, but other than that they just continue their daily activities. This includes shooting and wounding the ped. And - most importantly - they do not flee.

Since it is a task, every time the native is called the ped will stop for a moment. 

