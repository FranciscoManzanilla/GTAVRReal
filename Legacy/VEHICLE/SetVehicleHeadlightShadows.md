# _SET_VEHICLE_HEADLIGHT_SHADOWS

--- ns: VEHICLE aliases: ["0x1FD09E7390A74D54", "_SET_VEHICLE_LIGHTS_MODE"] --- ## SET_VEHICLE_HEADLIGHT_SHADOWS  // 0x1FD09E7390A74D54 void SET_VEHICLE_HEADLIGHT_SHADOWS(Vehicle vehicle, int flag);  Sets the vehicle headlight shadow flags.  NativeDB Introduced: v323  enum eVehicleHeadlightShadowFlags { // Default (Lights can be toggled between off, normal and high beams) NO_HEADLIGHT_SHADOWS = 0, // Lights Disabled (Lights are fully disabled, cannot be toggled) HEADLIGHTS_CAST_DYNAMIC_SHADOWS = 1, // Always On (Lights can be toggled between normal and high beams) HEADLIGHTS_CAST_STATIC_SHADOWS = 2, HEADLIGHTS_CAST_FULL_SHADOWS = 3 };  ## Parameters * **vehicle**: The target vehicle. * **flag**: A value from `eVehicleHeadlightShadowFlags` representing the desired headlight shadow flag.   ## Examples local vehicle = GetVehiclePedIsIn(PlayerPedId(), false) if not vehicle then return end  -- Set the vehicle headlight shadows to cast static shadows (always on) SetVehicleHeadlightShadows(vehicle, 2)  const vehicle = GetVehiclePedIsIn(PlayerPedId(), false); if (!vehicle) return;  // Set the vehicle headlight shadows to cast static shadows (always on) SetVehicleHeadlightShadows(vehicle, 2);  using static CitizenFX.Core.Native.API;  int vehicle = GetVehiclePedIsIn(PlayerPedId(), false); if (vehicle == 0) return;  // Set the vehicle headlight shadows to cast static shadows (always on) SetVehicleHeadlightShadows(vehicle, 2);

### Parameters
* Vehicle vehicle
* int p1

### Return Value
* void

### Notes
* Build: 323
* p1 can be either 0, 1 or 2.

Determines how vehicle lights behave when toggled.

0 = Default (Lights can be toggled between off, normal and high beams)
1 = Lights Disabled (Lights are fully disabled, cannot be toggled)
2 = Always On (Lights can be toggled between normal and high beams)

