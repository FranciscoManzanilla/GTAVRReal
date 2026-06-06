# _GET_VEHICLE_HAS_KERS

--- ns: VEHICLE aliases: ["0x50634E348C8D44EF", "_HAS_VEHICLE_KERS_BOOST"] --- ## GET_VEHICLE_HAS_KERS  // 0x50634E348C8D44EF 0x0761E635 BOOL GET_VEHICLE_HAS_KERS(Vehicle vehicle);   ## Parameters * **vehicle**: The vehicle handle.  ## Return value Returns true if the vehicle has a kers boost (for instance the lectro or the vindicator)

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x0761E635
* Build: 372
* Returns true if the vehicle has a HF_HAS_KERS (strHandlingFlags 0x4) handing flag set, for instance the lectro/vindicator bikes or the open wheelers.

