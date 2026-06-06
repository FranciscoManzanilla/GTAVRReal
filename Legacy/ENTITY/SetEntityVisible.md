# _SET_ENTITY_VISIBLE

--- ns: ENTITY --- ## SET_ENTITY_VISIBLE  // 0xEA1C610A04DB6BBB 0xD043E8E1 void SET_ENTITY_VISIBLE(Entity entity, BOOL toggle, BOOL unk);  Toggle the visibility of a given entity.  ## Parameters * **entity**: The entity to change the visibility of * **toggle**: Whether or not the entity will be visible * **unk**: Always 0 in scripts  ## Examples SetEntityVisible(PlayerPedId(), false, 0)

### Parameters
* Entity entity
* BOOL toggle
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0xD043E8E1
* Build: 323
* p2 is always 0.

