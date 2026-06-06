# _SET_VEHICLE_DAMAGE

--- ns: VEHICLE --- ## SET_VEHICLE_DAMAGE  // 0xA1DD317EA8FD4F29 0x21B458B2 void SET_VEHICLE_DAMAGE(Vehicle vehicle, float xOffset, float yOffset, float zOffset, float damage, float radius, BOOL focusOnModel);  Apply damage to vehicle at a location. Location is relative to vehicle model (not world). Radius of effect damage applied in a sphere at impact location When `focusOnModel` set to `true`, the damage sphere will travel towards the vehicle from the given point, thus guaranteeing an impact  ## Parameters * **vehicle**: * **xOffset**: * **yOffset**: * **zOffset**: * **damage**: * **radius**: the size of the damage sphere to apply * **focusOnModel**: when set to `true`, the damage sphere will travel towards the vehicle from the given point, thus guaranteeing an impact  ## Examples  -- Both of these are for an average sized car  -- nothing will be hit SetVehicleDamage(vehicle, 0.0, 0.0, 0.33, 200.0, 100.0, false)  -- will hit the first hitbox on your Z index line SetVehicleDamage(vehicle, 0.0, 0.0, 0.33, 200.0, 100.0, true)

### Parameters
* Vehicle vehicle
* float xOffset
* float yOffset
* float zOffset
* float damage
* float radius
* BOOL focusOnModel

### Return Value
* void

### Notes
* AP Hash: 0x0x21B458B2
* Build: 323
* Apply damage to vehicle at a location. Location is relative to vehicle model (not world).

Radius of effect damage applied in a sphere at impact location
When `focusOnModel` set to `true`, the damage sphere will travel towards the vehicle from the given point, thus guaranteeing an impact

