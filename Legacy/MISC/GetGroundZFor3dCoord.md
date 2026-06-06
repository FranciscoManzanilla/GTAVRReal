# _GET_GROUND_Z_FOR_3D_COORD

No description available.

### Parameters
* float x
* float y
* float z
* float* groundZ
* BOOL ignoreWater
* BOOL p5

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xA1BFD5E0
* Build: 323
* Gets the ground elevation at the specified position. Note that if the specified position is below ground level, the function will output zero!

x: Position on the X-axis to get ground elevation at.
y: Position on the Y-axis to get ground elevation at.
z: Position on the Z-axis to get ground elevation at.
groundZ: The ground elevation at the specified position.
ignoreWater: Nearly always 0, very rarely 1 in the scripts: https://gfycat.com/NiftyTatteredCricket

Bear in mind this native can only calculate the elevation when the coordinates are within the client's render distance.

