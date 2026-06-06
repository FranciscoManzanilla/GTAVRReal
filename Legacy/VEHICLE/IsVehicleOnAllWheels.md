# _IS_VEHICLE_ON_ALL_WHEELS

--- ns: VEHICLE --- ## IS_VEHICLE_ON_ALL_WHEELS  // 0xB104CD1BABF302E2 0x10089F8E BOOL IS_VEHICLE_ON_ALL_WHEELS(Vehicle vehicle);  Public Function isVehicleOnAllWheels(vh As Vehicle) As Boolean Return Native.Function.Call(Of Boolean)(Hash.IS_VEHICLE_ON_ALL_WHEELS, vh) End Function  ## Parameters * **vehicle**:  ## Return value

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x10089F8E
* Build: 323
*  Public Function isVehicleOnAllWheels(vh As Vehicle) As Boolean
        Return Native.Function.Call(Of Boolean)(Hash.IS_VEHICLE_ON_ALL_WHEELS, vh)
    End Function


