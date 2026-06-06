# _BRING_VEHICLE_TO_HALT

--- ns: VEHICLE aliases: ["0x260BE8F09E326A20","_SET_VEHICLE_HALT"] --- ## BRING_VEHICLE_TO_HALT  // 0x260BE8F09E326A20 0xCBC7D3C8 void BRING_VEHICLE_TO_HALT(Vehicle vehicle, float distance, int duration, BOOL bControlVerticalVelocity);  This native makes the vehicle stop immediately, as it happens when we enter a multiplayer garage.  ## Parameters * **vehicle**: The vehicle to stop. * **distance**: The distance from the initial coords at which the vehicle should come to rest. * **duration**: The length of time in seconds to hold the car at rest after stopping. * **bControlVerticalVelocity**: `false` by default which allows gravity to act normally in the z direction. Enable this option to halt the vehicle's vertical velocity as well.

### Parameters
* Vehicle vehicle
* float distance
* int duration
* BOOL p3

### Return Value
* void

### Notes
* AP Hash: 0x0xCBC7D3C8
* Build: 323
* This native makes the vehicle stop immediately, as happens when we enter a MP garage.

. distance defines how far it will travel until stopping. Garage doors use 3.0.

. If killEngine is set to 1, you cannot resume driving the vehicle once it stops. This looks like is a bitmapped integer.

