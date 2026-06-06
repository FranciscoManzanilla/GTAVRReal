# _SET_PED_VISUAL_FIELD_MIN_ELEVATION_ANGLE

--- ns: PED --- ## SET_PED_VISUAL_FIELD_MIN_ELEVATION_ANGLE  // 0x7A276EB2C224D70F 0x5CC2F1B8 void SET_PED_VISUAL_FIELD_MIN_ELEVATION_ANGLE(Ped ped, float angle);  This native refers to the field of vision the ped has below them, starting at 0 degrees. The angle value should be negative.  ## Parameters * **ped**: * **angle**:

### Parameters
* Ped ped
* float angle

### Return Value
* void

### Notes
* AP Hash: 0x0x5CC2F1B8
* Build: 323
* This native refers to the field of vision the ped has below them, starting at 0 degrees. The angle value should be negative.
-90f should let the ped see 90 degrees below them, for example.

