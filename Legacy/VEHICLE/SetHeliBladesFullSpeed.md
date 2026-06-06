# _SET_HELI_BLADES_FULL_SPEED

--- ns: VEHICLE --- ## SET_HELI_BLADES_FULL_SPEED  // 0xA178472EBB8AE60D 0x033A9408 void SET_HELI_BLADES_FULL_SPEED(Vehicle vehicle);  Despite its name, this works on Helicopters and Planes.  Sets the speed of the helicopter blades to full speed.  This is equivalent to calling `SetHeliBladesSpeed(vehicleHandle, 1.0);`  ## Parameters * **vehicle**: The helicopter or the plane

### Parameters
* Vehicle vehicle

### Return Value
* void

### Notes
* AP Hash: 0x0x033A9408
* Build: 323
* Equivalent of SET_HELI_BLADES_SPEED(vehicleHandle, 1.0f);

