# _GET_RANDOM_VEHICLE_IN_SPHERE

--- ns: VEHICLE --- ## GET_RANDOM_VEHICLE_IN_SPHERE  // 0x386F6CE5BAF6091C 0x57216D03 Vehicle GET_RANDOM_VEHICLE_IN_SPHERE(float x, float y, float z, float radius, Hash modelHash, int flags);  Gets a random vehicle in a sphere at the specified position, of the specified radius. x: The X-component of the position of the sphere. y: The Y-component of the position of the sphere. z: The Z-component of the position of the sphere. radius: The radius of the sphere. Max is 9999.9004. modelHash: The vehicle model to limit the selection to. Pass 0 for any model. flags: The bitwise flags that modifies the behaviour of this function.  ## Parameters * **x**: * **y**: * **z**: * **radius**: * **modelHash**: * **flags**:  ## Return value

### Parameters
* float x
* float y
* float z
* float radius
* Hash modelHash
* int flags

### Return Value
* Vehicle

### Notes
* AP Hash: 0x0x57216D03
* Build: 323
* Gets a random vehicle in a sphere at the specified position, of the specified radius.

x: The X-component of the position of the sphere.
y: The Y-component of the position of the sphere.
z: The Z-component of the position of the sphere.
radius: The radius of the sphere. Max is 9999.9004.
modelHash: The vehicle model to limit the selection to. Pass 0 for any model.
flags: The bitwise flags that modifies the behaviour of this function.

Full list of vehicles by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/vehicles.json

