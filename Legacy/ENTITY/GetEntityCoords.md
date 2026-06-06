# _GET_ENTITY_COORDS

--- ns: ENTITY apiset: client --- ## GET_ENTITY_COORDS  // 0x3FEF770D40960D5A 0x1647F1CB Vector3 GET_ENTITY_COORDS(Entity entity, BOOL alive);  Gets the current coordinates (world position) for a specified entity.  ## Parameters * **entity**: The entity to get the coordinates from. * **alive**: Unused by the game, potentially used by debug builds of GTA in order to assert whether or not an entity was alive.  ## Return value  The current entity coordinates.  ## Examples  local playerCoords = GetEntityCoords(PlayerPedId()) print(playerCoords) -- vector3(...)  const [playerX, playerY, playerZ] = GetEntityCoords(PlayerPedId(), false); console.log(`${playerX}, ${playerY}, ${playerZ}`);  using static CitizenFX.Core.Native.API; // ... Vector3 playerCoords = GetEntityCoords(PlayerPedId(), false);  // or the preferred use of C# wrapper Vector3 playerCoords = Game.PlayerPed.Position;  Debug.WriteLine($"{playerCoords}");

### Parameters
* Entity entity
* BOOL alive

### Return Value
* Vector3

### Notes
* AP Hash: 0x0x1647F1CB
* Build: 323
* Gets the current coordinates for a specified entity.
`entity` = The entity to get the coordinates from.
`alive` = Unused by the game, potentially used by debug builds of GTA in order to assert whether or not an entity was alive.

