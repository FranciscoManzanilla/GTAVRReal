# _GET_ENTITY_HEADING

--- ns: ENTITY ---  ## GET_ENTITY_HEADING  // 0xE83D4F9BA2A38914 0x972CC383 float GET_ENTITY_HEADING(Entity entity);  Returns the heading of the entity in degrees. Also know as the "Yaw" of an entity.  ## Parameters  - **entity**: The entity to get the heading from.  ## Return value  The current entity heading.  ## Examples  local heading = GetEntityHeading(PlayerPedId()) print(heading)  const heading = GetEntityHeading(PlayerPedId()); console.log(`${heading}`);  using static CitizenFX.Core.Native.API; // ... float heading = GetEntityHeading(PlayerPedId());  // or the preferred use of C# wrapper float heading = Game.PlayerPed.Heading;  Debug.WriteLine($"{heading}");

### Parameters
* Entity entity

### Return Value
* float

### Notes
* AP Hash: 0x0x972CC383
* Build: 323
* Returns the heading of the entity in degrees. Also know as the "Yaw" of an entity.

