# _GET_DLC_VEHICLE_DATA

No description available.

### Parameters
* int dlcVehicleIndex
* Any* outData

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xCF428FA4
* Build: 323
* dlcVehicleIndex takes a number from 0 - GET_NUM_DLC_VEHICLES() - 1.
outData is a struct of 3 8-byte items.
The Second item in the struct *(Hash *)(outData + 1) is the vehicle hash.

