# _GET_GAMEPLAY_CAM_ROT

--- ns: CAM --- ## GET_GAMEPLAY_CAM_ROT  // 0x837765A25378F0BB 0x13A010B5 Vector3 GET_GAMEPLAY_CAM_ROT(int rotationOrder);  This function takes a rotation order and outputs a `Vector3` in degrees.  It first calls a game function to calculate these values given the rotation order and effectively multiplies those values by `180/PI`, hence degrees since the function it calls outputs radians which are then converted to degrees.  ## Parameters * **rotationOrder**: The order of rotation, see [`GET_ENTITY_ROTATION`](#_0xAFBD61CC738D9EB9)  ## Return value A `Vector3` representing the gameplay camera rotation in degrees.  ## Examples local camRot = GetGameplayCamRot(0) -- vector3(-14.74518, 0.05254443, 95.24616) Citizen.Trace(string.format("Cam Rotation is x: %f, y: %f, z: %f", camRot.x, camRot.y, camRot.z))

### Parameters
* int rotationOrder

### Return Value
* Vector3

### Notes
* AP Hash: 0x0x13A010B5
* Build: 323
* p0 dosen't seem to change much, I tried it with 0, 1, 2:
0-Pitch(X): -70.000092
0-Roll(Y): -0.000001
0-Yaw(Z): -43.886459
1-Pitch(X): -70.000092
1-Roll(Y): -0.000001
1-Yaw(Z): -43.886463
2-Pitch(X): -70.000092
2-Roll(Y): -0.000002
2-Yaw(Z): -43.886467

