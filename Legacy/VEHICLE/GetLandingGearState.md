# _GET_LANDING_GEAR_STATE

--- ns: VEHICLE aliases: ["_GET_VEHICLE_LANDING_GEAR"] --- ## GET_LANDING_GEAR_STATE  // 0x9B0F3DCA3DB0F4CD 0xA6F02670 int GET_LANDING_GEAR_STATE(Vehicle vehicle);  Landing gear states: 0: Deployed 1: Closing (Retracting) 3: Opening (Deploying) 4: Retracted 5: Broken  Landing gear state 2 is never used.  ## Parameters * **vehicle**: The vehicle to check.  ## Return value The current state of the vehicles landing gear.

### Parameters
* Vehicle vehicle

### Return Value
* int

### Notes
* AP Hash: 0x0xA6F02670
* Build: 323
* Landing gear states:

0: Deployed
1: Closing (Retracting)
2: (Landing gear state 2 is never used.)
3: Opening (Deploying)
4: Retracted

Returns the current state of the vehicles landing gear.

