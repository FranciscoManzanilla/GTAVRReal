# _DOOR_SYSTEM_SET_AUTOMATIC_RATE

--- ns: OBJECT aliases: ["0x03C27E13B42A0E82"] --- ## DOOR_SYSTEM_SET_AUTOMATIC_RATE  // 0x03C27E13B42A0E82 0x4F44AF21 void DOOR_SYSTEM_SET_AUTOMATIC_RATE(Hash doorHash, float rate, BOOL requestDoor, BOOL forceUpdate);  Includes networking check: ownership vs. or the door itself **isn't** networked.  ## Parameters * **doorHash**: Door system identifier * **rate**: * **requestDoor**: * **forceUpdate**: On true invokes [DOOR_SYSTEM_SET_DOOR_STATE](#_0x6BAB9442830C7F53); otherwise requestDoor is unused.

### Parameters
* Hash doorHash
* float rate
* BOOL requestDoor
* BOOL forceUpdate

### Return Value
* void

### Notes
* AP Hash: 0x0x4F44AF21
* Build: 323
* Includes networking check: ownership vs. or the door itself **isn't** networked.
`forceUpdate` on true invokes DOOR_SYSTEM_SET_DOOR_STATE otherwise requestDoor is unused.

