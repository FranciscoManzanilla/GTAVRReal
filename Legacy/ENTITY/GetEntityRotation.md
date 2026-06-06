# _GET_ENTITY_ROTATION

--- ns: ENTITY --- ## GET_ENTITY_ROTATION  // 0xAFBD61CC738D9EB9 0x8FF45B04 Vector3 GET_ENTITY_ROTATION(Entity entity, int rotationOrder);  **NOTE**: What you use for rotationOrder when getting must be the same as rotationOrder when setting the rotation.   enum eRotationOrder { // Rotate around the z-axis, then the y-axis and finally the x-axis. ROT_ZYX = 0, // Rotate around the y-axis, then the z-axis and finally the x-axis. ROT_YZX = 1, // Rotate around the z-axis, then the x-axis and finally the y-axis. ROT_ZXY = 2, // Rotate around the x-axis, then the z-axis and finally the y-axis. ROT_XZY = 3, // Rotate around the y-axis, then the x-axis and finally the z-axis. ROT_YXZ = 4, // Rotate around the x-axis, then the y-axis and finally the z-axis. ROT_XYZ = 5, }  ## Parameters * **entity**: The entity to get the rotation for. * **rotationOrder**: The order yaw, pitch and roll is applied. Usually 2.  ## Return value A vector where the Z coordinate is the yaw.  ## Examples  local playerRotation = GetEntityRotation(PlayerPedId(), 2) print(playerRotation)  const [rotationX, rotationY, rotationZ] = GetEntityRotation(PlayerPedId(), 2); console.log(`${rotationX} ${rotationY} ${rotationZ}`);  using static CitizenFX.Core.Native.API; // ...  Vector3 playerRotation = GetEntityRotation(Game.PlayerPed.Handle, 2);  // or the preferred use of C# wrapper Vector3 playerRotation = Game.PlayerPed.Rotation;  Debug.WriteLine($"{playerRotation}");

### Parameters
* Entity entity
* int rotationOrder

### Return Value
* Vector3

### Notes
* AP Hash: 0x0x8FF45B04
* Build: 323
* rotationOrder is the order yaw, pitch and roll is applied. Usually 2. Returns a vector where the Z coordinate is the yaw.

rotationOrder refers to the order yaw pitch roll is applied; value ranges from 0 to 5 and is usually *2* in scripts.
What you use for rotationOrder when getting must be the same as rotationOrder when setting the rotation.

What it returns is the yaw on the z part of the vector, which makes sense considering R* considers z as vertical. Here's a picture for those of you who don't understand pitch, yaw, and roll: www.allstar.fiu.edu/aero/images/pic5-1.gif

Rotation Orders:
0: ZYX - Rotate around the z-axis, then the y-axis and finally the x-axis.
1: YZX - Rotate around the y-axis, then the z-axis and finally the x-axis.
2: ZXY - Rotate around the z-axis, then the x-axis and finally the y-axis.
3: XZY - Rotate around the x-axis, then the z-axis and finally the y-axis.
4: YXZ - Rotate around the y-axis, then the x-axis and finally the z-axis.
5: XYZ - Rotate around the x-axis, then the y-axis and finally the z-axis.

