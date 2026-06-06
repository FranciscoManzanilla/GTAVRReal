# _GET_DOES_VEHICLE_HAVE_TOMBSTONE

--- ns: VEHICLE --- ## _GET_DOES_VEHICLE_HAVE_TOMBSTONE  // 0x71AFB258CCED3A27 BOOL _GET_DOES_VEHICLE_HAVE_TOMBSTONE(Vehicle vehicle);  NativeDB Introduced: v1604  ## Parameters * **vehicle**:

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* Build: 1604
* Returns true only if the "tombstone" bone is attached to the vehicle, irrespective of "FLAG_HAS_TOMBSTONE" being present or not. Detaching the tombstone will return false.

