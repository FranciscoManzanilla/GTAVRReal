# _CONTROL_LANDING_GEAR

--- ns: VEHICLE aliases: ["_SET_VEHICLE_LANDING_GEAR"] --- ## CONTROL_LANDING_GEAR  // 0xCFC8BE9A5E1FE575 0x24F873FB void CONTROL_LANDING_GEAR(Vehicle vehicle, int state);  Works for vehicles with a retractable landing gear landing gear states: 0: Deployed 1: Closing 2: Opening 3: Retracted  ## Parameters * **vehicle**: * **state**:

### Parameters
* Vehicle vehicle
* int state

### Return Value
* void

### Notes
* AP Hash: 0x0x24F873FB
* Build: 323
* Works for vehicles with a retractable landing gear

Landing gear states:

0: Deployed
1: Closing
2: Opening
3: Retracted

