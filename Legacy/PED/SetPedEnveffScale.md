# _SET_PED_ENVEFF_SCALE

--- ns: PED --- ## SET_PED_ENVEFF_SCALE  // 0xBF29516833893561 0xFC1CFC27 void SET_PED_ENVEFF_SCALE(Ped ped, float value);  Values look to be between 0.0 and 1.0 From decompiled scripts: 0.0, 0.6, 0.65, 0.8, 1.0 You are correct, just looked in IDA it breaks from the function if it's less than 0.0f or greater than 1.0f.  ## Parameters * **ped**: * **value**:

### Parameters
* Ped ped
* float value

### Return Value
* void

### Notes
* AP Hash: 0x0xFC1CFC27
* Build: 323
* Values look to be between 0.0 and 1.0
From decompiled scripts: 0.0, 0.6, 0.65, 0.8, 1.0

You are correct, just looked in IDA it breaks from the function if it's less than 0.0f or greater than 1.0f.

