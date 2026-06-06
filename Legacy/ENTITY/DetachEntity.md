# _DETACH_ENTITY

--- ns: ENTITY --- ## DETACH_ENTITY  // 0x961AC54BF0613F5D 0xC8EFCB41 void DETACH_ENTITY(Entity entity, BOOL dynamic, BOOL collision);  ## Parameters * **entity**: * **dynamic**: Set to `true` to keep velocity after detaching * **collision**:

### Parameters
* Entity entity
* BOOL dynamic
* BOOL collision

### Return Value
* void

### Notes
* AP Hash: 0x0xC8EFCB41
* Build: 323
* If `collision` is set to true, both entities won't collide with the other until the distance between them is above 4 meters.
Set `dynamic` to true to keep velocity after dettaching

