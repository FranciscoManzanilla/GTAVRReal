# _SET_PED_ENVEFF_CPV_ADD

No description available.

### Parameters
* Ped ped
* float p1

### Return Value
* void

### Notes
* AP Hash: 0x0x3B882533
* Build: 323
* In agency_heist3b.c4, its like this 90% of the time:

PED::SET_PED_ENVEFF_CPV_ADD(ped, 0.099);
PED::SET_PED_ENVEFF_SCALE(ped, 1.0);
PED::SET_PED_ENVEFF_CPV_ADD(ped, 87, 81, 68);
PED::SET_ENABLE_PED_ENVEFF_SCALE(ped, 1);

and its like this 10% of the time:

PED::SET_PED_ENVEFF_CPV_ADD(ped, 0.2);
PED::SET_PED_ENVEFF_SCALE(ped, 0.65);
PED::SET_PED_ENVEFF_COLOR_MODULATOR(ped, 74, 69, 60);
PED::SET_ENABLE_PED_ENVEFF_SCALE(ped, 1);

