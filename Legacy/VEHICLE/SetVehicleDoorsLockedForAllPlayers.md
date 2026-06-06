# _SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS

--- ns: VEHICLE --- ## SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS  // 0xA2F80B8D040727CC 0x891BA8A4 void SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(Vehicle vehicle, BOOL toggle);  ## Parameters * **vehicle**: * **toggle**:

### Parameters
* Vehicle vehicle
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x891BA8A4
* Build: 323
* After some analysis, I've decided that these are what the parameters are.

We can see this being used in R* scripts such as "am_mp_property_int.ysc.c4":
l_11A1 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1);
...
VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(l_11A1, 1);

