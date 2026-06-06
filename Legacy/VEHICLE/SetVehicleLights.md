# _SET_VEHICLE_LIGHTS

--- ns: VEHICLE --- ## SET_VEHICLE_LIGHTS  // 0x34E710FF01247C5A 0xE8930226 void SET_VEHICLE_LIGHTS(Vehicle vehicle, int state);  Sets the vehicle lights state. Allowing for different lighting modes.  NativeDB Introduced: v323  enum eVehicleLightSetting { // Normal light behavior. Lights cycle through off, then low beams, then high beams. // Note: It's affected by day or night; high beams don't exist in daytime. NO_VEHICLE_LIGHT_OVERRIDE = 0, // Vehicle doesn't have lights, always off. FORCE_VEHICLE_LIGHTS_OFF  = 1, // Vehicle has always-on lights. // During day: Cycles between low beams and high beams. // At night: Cycles between low beams, low beams, and high beams. FORCE_VEHICLE_LIGHTS_ON   = 2, // Sets vehicle lights on. Behaves like normal lights (same as 0). SET_VEHICLE_LIGHTS_ON     = 3, // Sets vehicle lights off. Behaves like normal lights (same as 0). SET_VEHICLE_LIGHTS_OFF    = 4 };   ## Parameters * **vehicle**: The target vehicle. * **state**: A value from `eVehicleLightSetting` representing the desired light setting.   ## Examples local vehicle = GetVehiclePedIsIn(PlayerPedId(), false) if not vehicle then return end  -- Set the vehicle lights to always on SetVehicleLights(vehicle, 2)  const vehicle = GetVehiclePedIsIn(PlayerPedId(), false); if (!vehicle) return;  // Set the vehicle lights to always on SetVehicleLights(vehicle, 2);  using static CitizenFX.Core.Native.API;  int vehicle = GetVehiclePedIsIn(PlayerPedId(), false); if (vehicle == 0) return;  // Set the vehicle lights to always on SetVehicleLights(vehicle, 2);

### Parameters
* Vehicle vehicle
* int state

### Return Value
* void

### Notes
* AP Hash: 0x0xE8930226
* Build: 323
* set's if the vehicle has lights or not.
not an on off toggle.
p1 = 0 ;vehicle normal lights, off then lowbeams, then highbeams
p1 = 1 ;vehicle doesn't have lights, always off
p1 = 2 ;vehicle has always on lights
p1 = 3 ;or even larger like 4,5,... normal lights like =1
note1: when using =2 on day it's lowbeam,highbeam
but at night it's lowbeam,lowbeam,highbeam
note2: when using =0 it's affected by day or night for highbeams don't exist in daytime.

