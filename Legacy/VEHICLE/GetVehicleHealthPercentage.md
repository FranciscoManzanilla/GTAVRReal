# _GET_VEHICLE_HEALTH_PERCENTAGE

--- ns: VEHICLE aliases: ["_GET_VEHICLE_BODY_HEALTH_2"] --- ## GET_VEHICLE_HEALTH_PERCENTAGE  // 0xB8EF61207C2393A9 0x196BA503 float GET_VEHICLE_HEALTH_PERCENTAGE(Vehicle vehicle);  NativeDB Added Parameter 2: float maxEngineHealth NativeDB Added Parameter 3: float maxPetrolTankHealth NativeDB Added Parameter 4: float maxBodyHealth NativeDB Added Parameter 5: float maxMainRotorHealth NativeDB Added Parameter 6: float maxTailRotorHealth NativeDB Added Parameter 7: float maxUnkHealth  ## Parameters * **vehicle**:  ## Return value

### Parameters
* Vehicle vehicle
* float maxEngineHealth
* float maxPetrolTankHealth
* float maxBodyHealth
* float maxMainRotorHealth
* float maxTailRotorHealth
* float maxUnkHealth

### Return Value
* float

### Notes
* AP Hash: 0x0x196BA503
* Build: 323
* 0 min 100 max
starts at 100
Seams to have health zones
Front of vehicle when damaged goes from 100-50 and stops at 50.
Rear can be damaged from 100-0
Only tested with two cars.

any idea how this differs from the first one?

--
May return the vehicle health on a scale of 0.0 - 100.0 (needs to be confirmed)

example:

v_F = ENTITY::GET_ENTITY_MODEL(v_3);
if (((v_F == ${tanker}) || (v_F == ${armytanker})) || (v_F == ${tanker2})) {
    if (VEHICLE::GET_VEHICLE_HEALTH_PERCENTAGE(v_3) <= 1.0) {
        NETWORK::NETWORK_EXPLODE_VEHICLE(v_3, 1, 1, -1);
    }
}

