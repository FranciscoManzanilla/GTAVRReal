# _SET_ENTITY_COORDS

--- ns: ENTITY --- ## SET_ENTITY_COORDS  // 0x06843DA7060A026B 0xDF70B41B void SET_ENTITY_COORDS(Entity entity, float xPos, float yPos, float zPos, BOOL alive, BOOL deadFlag, BOOL ragdollFlag, BOOL clearArea);  Sets the coordinates (world position) for a specified entity, offset by the radius of the entity on the Z axis.  ## Parameters * **entity**: The entity to change coordinates for. * **xPos**: The X coordinate. * **yPos**: The Y coordinate. * **zPos**: The Z coordinate, ground level. * **alive**: Unused by the game, potentially used by debug builds of GTA in order to assert whether or not an entity was alive. * **deadFlag**: Whether to disable physics for dead peds, too, and not just living peds. * **ragdollFlag**: A special flag used for ragdolling peds. * **clearArea**: Whether to clear any entities in the target area.  ## Examples  local ped = PlayerPedId() local currentPos = GetEntityCoords(ped) print(currentPos)  SetEntityCoords(ped, 674.883, 548.269, 133.94, false, false, false, true)  currentPos = GetEntityCoords(ped) print(currentPos) -- changed!  const ped = PlayerPedId(); let currentPos = GetEntityCoords(ped, false); console.log(`${currentPos[0]} ${currentPos[1]} ${currentPos[2]}`);  SetEntityCoords(ped, 674.883, 548.269, 133.94, false, false, false, true);  currentPos = GetEntityCoords(ped, false); console.log(`${currentPos[0]} ${currentPos[1]} ${currentPos[2]}`); // changed!  using static CitizenFX.Core.Native.API; // ...  int ped = PlayerPedId(); Vector3 currentPos = GetEntityCoords(ped, false); Debug.WriteLine($"{currentPos}");  SetEntityCoords(ped, 674.883f, 548.269f, 133.94f, false, false, false, true);  currentPos = GetEntityCoords(ped, false); Debug.WriteLine($"{currentPos}"); // changed!  // or the preferred use of C# wrapper Debug.WriteLine($"{Game.PlayerPed.Position}");  Game.PlayerPed.Position = new Vector3(674.883f, 548.269f, 133.94f);  Debug.WriteLine($"{Game.PlayerPed.Position}"); // changed!

### Parameters
* Entity entity
* float xPos
* float yPos
* float zPos
* BOOL xAxis
* BOOL yAxis
* BOOL zAxis
* BOOL clearArea

### Return Value
* void

### Notes
* AP Hash: 0x0xDF70B41B
* Build: 323
* p7 is always 1 in the scripts. Set to 1, an area around the destination coords for the moved entity is cleared from other entities. 
 
Often ends with 1, 0, 0, 1); in the scripts. It works. 

Axis - Invert Axis Flags

