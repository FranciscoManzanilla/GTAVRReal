# _ADD_BLIP_FOR_ENTITY

--- ns: HUD --- ## ADD_BLIP_FOR_ENTITY  // 0x5CDE92C702A8FCE7 0x30822554 Blip ADD_BLIP_FOR_ENTITY(Entity entity);  Create a blip that by default is red (enemy), you can use [SET_BLIP_AS_FRIENDLY](#_0xC6F43D0E) to make it blue (friend). Can be used for objects, vehicles and peds.  Example of enemy: ![enemy](https://i.imgur.com/fl78svv.png) Example of friend: ![friend](https://i.imgur.com/Q16ho5d.png)  ## Parameters * **entity**: The entity handle to create the blip.  ## Return value A blip handle.  ## Examples local blip = AddBlipForEntity(PlayerPedId()) -- This adds an enemy blip to yourself  const blip = AddBlipForEntity(PlayerPedId()); // This adds an enemy blip to yourself

### Parameters
* Entity entity

### Return Value
* Blip

### Notes
* AP Hash: 0x0x30822554
* Build: 323
* Returns red ( default ) blip attached to entity.

Example:
Blip blip; //Put this outside your case or option
blip = HUD::ADD_BLIP_FOR_ENTITY(YourPedOrBodyguardName);
HUD::SET_BLIP_AS_FRIENDLY(blip, true);

