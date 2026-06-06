# _START_PLAYER_TELEPORT

--- ns: PLAYER --- ## START_PLAYER_TELEPORT  // 0xAD15F075A4DA0FDE 0xC552E06C void START_PLAYER_TELEPORT(Player player, float x, float y, float z, float heading, BOOL teleportWithVehicle, BOOL findCollisionLand, BOOL p7);  Teleports the player to the given coordinates.  If findCollisionLand is true it will try to find the Z value for you, this however has a timeout of 100 frames.  When trying to find the Z value the native will take longer the higher the difference from the given Z to the ground, this combined with the timeout can cause the teleport to just teleport to the given Z value, so try to estimate the z value, so don't just pass in 1000.0.  Also if you're in a vehicle and teleportWithVehicle is true it will not find the Z value for you.  ## Parameters * **player**: * **x**: * **y**: * **z**: * **heading**: * **teleportWithVehicle**: Teleports the player along with the vehicle they are in. * **findCollisionLand**: Attempt to find a ground coordinate at the given XY location; overriding the Z value. * **p7**:  ## Examples  local coords = vector3(100.0, 100.0, 50.0) StartPlayerTeleport(PlayerId(), coords.x, coords.y, coords.z, 0.0, false, true, true)  while IsPlayerTeleportActive() do Citizen.Wait(0) end  --- If you would want to make 100% sure the ped is on the ground here you would have to do some additional checks here --- Easiest would be a simple: GetEntityHeightAboveGround(PlayerPedId())

### Parameters
* Player player
* float x
* float y
* float z
* float heading
* BOOL p5
* BOOL findCollisionLand
* BOOL p7

### Return Value
* void

### Notes
* AP Hash: 0x0xC552E06C
* Build: 323
* `findCollisionLand`: This teleports the player to land when set to true and will not consider the Z coordinate parameter provided by you. It will automatically put the Z coordinate so that you don't fall from sky.

