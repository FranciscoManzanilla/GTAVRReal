# _SET_HOVER_MODE_WING_RATIO

--- ns: VEHICLE aliases: ["_SET_SPECIALFLIGHT_WING_RATIO"] --- ## SET_HOVER_MODE_WING_RATIO  // 0x70A252F60A3E036B void SET_HOVER_MODE_WING_RATIO(Vehicle vehicle, float ratio);  This native allows opening or closing the wings of the Deluxo/Oppressor. For the Deluxo, wing deployment depends on sufficient altitude.   ## Parameters * **vehicle**: The vehicle to which the ratio will be applied. * **ratio**: Between 0.0 and 1.0. 0.0 is wings closed, 1.0 is wings open.   ## Examples  -- In this case we are opening the wings of the vehicle local vehicle = GetVehiclePedIsIn(PlayerPedId(), false) SetHoverModeWingRatio(vehicle, 1.0)  // In this case we are opening the wings of the vehicle const vehicle = GetVehiclePedIsIn(PlayerPedId(), false); SetHoverModeWingRatio(vehicle, 1.0);  // In this case we are opening the wings of the vehicle using static CitizenFX.Core.Native.API; Vehicle vehicle = GetVehiclePedIsIn(PlayerPedId(), false); SetHoverModeWingRatio(vehicle, 1f);

### Parameters
* Vehicle vehicle
* float ratio

### Return Value
* void

### Notes
* Build: 1365

