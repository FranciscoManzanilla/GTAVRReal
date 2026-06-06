# _IS_COP_VEHICLE_IN_AREA_3D

No description available.

### Parameters
* float x1
* float x2
* float y1
* float y2
* float z1
* float z2

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xFB16C6D1
* Build: 323
* Usage:

public bool isCopInRange(Vector3 Location, float Range)
        {
            return Function.Call<bool>(Hash.IS_COP_PED_IN_AREA_3D, Location.X - Range, Location.Y - Range, Location.Z - Range, Location.X + Range, Location.Y + Range, Location.Z + Range);
        }

