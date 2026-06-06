# _GET_WATER_HEIGHT

--- ns: WATER --- ## GET_WATER_HEIGHT  // 0xF6829842C06AE524 0xD864E17C BOOL GET_WATER_HEIGHT(float x, float y, float z, float* height);  Retrieves the depth of the water beneath the specified position, accounting for the waves.  **Note:** The result might vary depending on the specific frame when this command is executed due to wave fluctuations.  ## Parameters * **x**: The coordinate at which to test at for water. * **y**: The coordinate at which to test at for water. * **z**: The coordinate at which to test at for water. * **height**: The height at which to test at for water.  ## Return value Returns `false` when land at the tested coordinates is higher than water, `true` otherwise.

### Parameters
* float x
* float y
* float z
* float* height

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xD864E17C
* Build: 323
* This function set height to the value of z-axis of the water surface.

This function works with sea and lake. However it does not work with shallow rivers (e.g. raton canyon will return -100000.0f)

note: seems to return true when you are in water

