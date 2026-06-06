# _SPECIAL_FUNCTION_DO_NOT_USE

--- ns: PED aliases: ["0xF9ACF4A08098EA25"] --- ## SPECIAL_FUNCTION_DO_NOT_USE  // 0xF9ACF4A08098EA25 0x141CC936 void SPECIAL_FUNCTION_DO_NOT_USE(Ped ped, BOOL noCollisionUntilClear);  Kicks the ped from the current vehicle and keeps the rendering-focus on this ped (also disables its collision). If doing this for your player ped, you'll still be able to drive the vehicle. Only to be used in very specific situations where the ped needs to be inside the car still but not attached.  ## Parameters * **ped**: * **noCollisionUntilClear**:

### Parameters
* Ped ped
* BOOL p1

### Return Value
* void

### Notes
* AP Hash: 0x0x141CC936
* Build: 323
* p1 was always 1 (true).

Kicks the ped from the current vehicle and keeps the rendering-focus on this ped (also disables its collision). If doing this for your player ped, you'll still be able to drive the vehicle.

