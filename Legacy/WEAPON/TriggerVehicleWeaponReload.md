# __TRIGGER_VEHICLE_WEAPON_RELOAD

--- ns: WEAPON --- ## _TRIGGER_VEHICLE_WEAPON_RELOAD  // 0x5B1513F27F279A44 BOOL _TRIGGER_VEHICLE_WEAPON_RELOAD(Vehicle vehicle, int seat, Ped ped);  Start a reload for a vehicle's weapon.  NativeDB Introduced: v3407  ## Parameters * **vehicle**: The vehicle containing the weapon to reload. * **seat**: The seat/weapon index. * **ped**: The ped initiating the reload (the one using the weapon).  ## Return value Return `true` if reload was triggered successfully, `false` otherwise.

### Parameters
* Vehicle vehicle
* int seat
* Ped ped

### Return Value
* BOOL

### Notes
* Build: 3407

