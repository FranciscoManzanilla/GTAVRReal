# _SET_PLANE_TURBULENCE_MULTIPLIER

--- ns: VEHICLE aliases: ["0xAD2D28A1AFDFF131"] --- ## SET_PLANE_TURBULENCE_MULTIPLIER  // 0xAD2D28A1AFDFF131 0xED159AE6 void SET_PLANE_TURBULENCE_MULTIPLIER(Vehicle vehicle, float multiplier);  This native sets the turbulence multiplier. It only works for planes. 0.0 = no turbulence at all. 1.0 = heavy turbulence.  Works by just calling it once, does not need to be called every tick.  ## Parameters * **vehicle**: The plane to set the multiplier for * **multiplier**: The turbulence multiplier. Value between 0.0 and 1.0  ## Examples local plane = GetVehiclePedIsIn(PlayerPedId(), false) if IsThisModelAPlane(GetEntityModel(plane)) then -- Goodbye turbulence! SetPlaneTurbulenceMultiplier(plane, 0.0) end

### Parameters
* Vehicle vehicle
* float multiplier

### Return Value
* void

### Notes
* AP Hash: 0x0xED159AE6
* Build: 323
* This native sets the turbulence multiplier. It only works for planes.
0.0 = no turbulence at all.
1.0 = heavy turbulence.
Works by just calling it once, does not need to be called every tick.

