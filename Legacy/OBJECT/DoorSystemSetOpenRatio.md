# _DOOR_SYSTEM_SET_OPEN_RATIO

--- ns: OBJECT aliases: ["0xB6E6FBA95C7324AC","_SET_DOOR_AJAR_ANGLE"] --- ## DOOR_SYSTEM_SET_OPEN_RATIO  // 0xB6E6FBA95C7324AC 0x34883DE3 void DOOR_SYSTEM_SET_OPEN_RATIO(Hash doorHash, float ajar, BOOL requestDoor, BOOL forceUpdate);  Sets the ajar angle of a door. Ranges from -1.0 to 1.0, and 0.0 is closed / default.  ## Parameters * **doorHash**: Door system identifier * **ajar**: * **requestDoor**: * **forceUpdate**: On true invokes [DOOR_SYSTEM_SET_DOOR_STATE](#_0x6BAB9442830C7F53); otherwise requestDoor is unused.

### Parameters
* Hash doorHash
* float ajar
* BOOL requestDoor
* BOOL forceUpdate

### Return Value
* void

### Notes
* AP Hash: 0x0x34883DE3
* Build: 323
* Sets the ajar angle of a door.
Ranges from -1.0 to 1.0, and 0.0 is closed / default.
`forceUpdate` on true invokes DOOR_SYSTEM_SET_DOOR_STATE otherwise requestDoor is unused.

