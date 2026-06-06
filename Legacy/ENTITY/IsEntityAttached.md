# _IS_ENTITY_ATTACHED

--- ns: ENTITY --- ## IS_ENTITY_ATTACHED  // 0xB346476EF1A64897 0xEC1479D5 BOOL IS_ENTITY_ATTACHED(Entity entity);  ## Parameters * **entity**: The entity to check if it is attached to another entity.  ## Return value Whether the entity is attached to another entity.  ## Examples  local ped = PlayerPedId()  if IsEntityAttached(ped) then DetachEntity(ped, true, true) end  int ped = PlayerPedId();  if(IsEntityAttached(ped)) { DetachEntity(ped, true, true); }  using static CitizenFX.Core.Native.API; // ...  int ped = PlayerPedId();  if(IsEntityAttached(ped)) { DetachEntity(ped, true, true); }  // or the preferred use of C# wrapper if(Game.PlayerPed.IsAttached()) { Game.PlayerPed.Detach(); }

### Parameters
* Entity entity

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xEC1479D5
* Build: 323
* Whether the entity is attached to any other entity.

