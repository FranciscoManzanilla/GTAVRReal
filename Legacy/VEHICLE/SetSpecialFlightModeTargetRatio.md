# _SET_SPECIAL_FLIGHT_MODE_TARGET_RATIO

--- ns: VEHICLE aliases: ["0x438B3D7CA026FE91","_SET_VEHICLE_TRANSFORM_STATE", "_SET_VEHICLE_HOVER_TRANSFORM_PERCENTAGE"] --- ## SET_SPECIAL_FLIGHT_MODE_TARGET_RATIO  // 0x438B3D7CA026FE91 void SET_SPECIAL_FLIGHT_MODE_TARGET_RATIO(Vehicle vehicle, float state);  According to decompiled scripts this should work with the `deluxo` and `oppressor2` vehicles. Does nothing when used on `oppressor2`.  For the deluxo: - Set `state` to `0.0`: Fully transform to a 'road' vehicle (non-hover mode). - Set `state` to `1.0`: Fully transform to a 'flying' vehicle (hover mode).  If you set it to something like 0.5, then something [weird happens](https://streamable.com/p6wmr), you end up in some 50% hover mode, 50% not hover mode.  This doesn't need to be called every tick, just once and the vehicle will transform to that state at the usual transform speed. It'll just stop transforming when it reaches the state you provided.  Once this native is used then players will just be able to hit the vehicle transform key to toggle the transformation cycle; it won't block users from using the key.   ## Parameters * **vehicle**: The vehicle (a deluxo or oppressor2). * **state**: The transform state (value between 0.0 and 1.0).  ## Examples -- In this case we are enabling the hover mode for the deluxo (fyling mode) local vehicle = GetVehiclePedIsIn(PlayerPedId(), false) SetSpecialFlightModeTargetRatio(vehicle, 1.0)  // In this case we are enabling the hover mode for the deluxo (fyling mode) const vehicle = GetVehiclePedIsIn(PlayerPedId(), false); SetSpecialFlightModeTargetRatio(vehicle, 1.0);  // In this case we are enabling the hover mode for the deluxo (fyling mode) using static CitizenFX.Core.Native.API; Vehicle vehicle = GetVehiclePedIsIn(PlayerPedId(), false); SetSpecialFlightModeTargetRatio(vehicle, 1f);

### Parameters
* Vehicle vehicle
* float targetRatio

### Return Value
* void

### Notes
* Build: 1290
* Used in conjunction with SET_SPECIAL_FLIGHT_MODE_RATIO, in Rockstar's scripts. The vehicle will transform into the given targetRatio, starting from the vehicle's current hover mode transform ratio (which can also be manually set by SET_SPECIAL_FLIGHT_MODE_RATIO,) i.e. setting targetRatio to 0.0 while the vehicle is in hover mode will transform the vehicle into car mode, likewise setting targetRatio to 1.0 while the vehicle is in car mode will transform the vehicle into hover mode, and if the current transform ratio is set to 0.7 while targetRatio is 1.0 the vehicle will transform into hover mode starting from being already partially transformed.

targetRatio is recommended to always be 0.0 or 1.0, otherwise the vehicle will transform into a glitched state.

Usable only with the deluxo and other vehicles with deluxo-like hover mode toggle, modded or otherwise. Does nothing when used on oppressor2.

Example:
Ped playerPed = PLAYER::PLAYER_PED_ID();
Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
VEHICLE::SET_SPECIAL_FLIGHT_MODE_RATIO(veh, 0.7f);
VEHICLE::SET_SPECIAL_FLIGHT_MODE_TARGET_RATIO(veh, 1.0f);

