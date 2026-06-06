# _SET_ENTITY_LOCALLY_INVISIBLE

--- ns: NETWORK --- ## SET_ENTITY_LOCALLY_INVISIBLE  // 0xE135A9FF3F5D05D8 0x51ADCC5F void SET_ENTITY_LOCALLY_INVISIBLE(Entity entity);  Sets the provided entity not visible for yourself for the current frame.  ## Parameters * **entity**:  ## Examples  CreateThread(function() -- Any random entity should work local entity = PlayerPedId() -- Make the entity visible for all players SetEntityVisible(entity, true) while true do Wait(0) -- Make the entity invisible for the current player only. SetEntityLocallyInvisible(entity) end end)

### Parameters
* Entity entity

### Return Value
* void

### Notes
* AP Hash: 0x0x51ADCC5F
* Build: 323
* Makes the provided entity visible for yourself for the current frame.

