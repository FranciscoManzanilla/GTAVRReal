# _SET_ENTITY_NO_COLLISION_ENTITY

--- ns: ENTITY --- ## SET_ENTITY_NO_COLLISION_ENTITY  // 0xA53ED5520C07654A 0x1E11BFE9 void SET_ENTITY_NO_COLLISION_ENTITY(Entity entity1, Entity entity2, BOOL thisFrameOnly);  Calling this function disables collision between two entities. The importance of the order for entity1 and entity2 is unclear. The third parameter, `thisFrame`, decides whether the collision is to be disabled until it is turned back on, or if it's just this frame.  ## Parameters * **entity1**: * **entity2**: * **thisFrameOnly**:

### Parameters
* Entity entity1
* Entity entity2
* BOOL thisFrameOnly

### Return Value
* void

### Notes
* AP Hash: 0x0x1E11BFE9
* Build: 323
* Calling this function disables collision between two entities.
The importance of the order for entity1 and entity2 is unclear.
The third parameter, `thisFrame`, decides whether the collision is to be disabled until it is turned back on, or if it's just this frame.

