# _DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE

--- ns: OBJECT aliases: ["0x9BA001CB45CBF627"] --- ## DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE  // 0x9BA001CB45CBF627 0x47531446 void DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(Hash doorHash, float distance, BOOL requestDoor, BOOL forceUpdate);  ## Parameters * **doorHash**: Door system identifier * **distance**: * **requestDoor**: * **forceUpdate**: On true invokes [DOOR_SYSTEM_SET_DOOR_STATE](#_0x6BAB9442830C7F53); otherwise requestDoor is unused.

### Parameters
* Hash doorHash
* float distance
* BOOL requestDoor
* BOOL forceUpdate

### Return Value
* void

### Notes
* AP Hash: 0x0x47531446
* Build: 323
* `forceUpdate` on true invokes DOOR_SYSTEM_SET_DOOR_STATE otherwise requestDoor is unused.

