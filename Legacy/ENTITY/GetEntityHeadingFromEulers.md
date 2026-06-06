# _GET_ENTITY_HEADING_FROM_EULERS

--- ns: ENTITY aliases: ["0x846BF6291198A71E", "_GET_ENTITY_PHYSICS_HEADING"] --- ## GET_ENTITY_HEADING_FROM_EULERS  // 0x846BF6291198A71E 0x9320E642 float GET_ENTITY_HEADING_FROM_EULERS(Entity entity);  Gets the heading of the entity physics in degrees, which tends to be more accurate than just [`GET_ENTITY_HEADING`](#_0xE83D4F9BA2A38914). This can be clearly seen while, for example, ragdolling a ped/player.  ## Parameters * **entity**: The entity to get the heading from.  ## Return value Returns a float representing the entity's heading from eulers.

### Parameters
* Entity entity

### Return Value
* float

### Notes
* AP Hash: 0x0x9320E642
* Build: 323
* Gets the heading of the entity physics in degrees, which tends to be more accurate than just "GET_ENTITY_HEADING". This can be clearly seen while, for example, ragdolling a ped/player.

NOTE: The name and description of this native are based on independent research. If you find this native to be more suitable under a different name and/or described differently, please feel free to do so.

