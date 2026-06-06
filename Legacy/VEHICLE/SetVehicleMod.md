# _SET_VEHICLE_MOD

--- ns: VEHICLE --- ## SET_VEHICLE_MOD  // 0x6AF0636DDEDCB6DD 0xB52E5ED5 void SET_VEHICLE_MOD(Vehicle vehicle, int modType, int modIndex, BOOL customTires);  // eVehicleModType values modified to conform to script native reorganization (see 0x140D25327 in 1604). enum eVehicleModType { VMT_SPOILER = 0, VMT_BUMPER_F = 1, VMT_BUMPER_R = 2, VMT_SKIRT = 3, VMT_EXHAUST = 4, VMT_CHASSIS = 5, VMT_GRILL = 6, VMT_BONNET = 7, VMT_WING_L = 8, VMT_WING_R = 9, VMT_ROOF = 10, VMT_ENGINE = 11, VMT_BRAKES = 12, VMT_GEARBOX = 13, VMT_HORN = 14, VMT_SUSPENSION = 15, VMT_ARMOUR = 16, VMT_NITROUS = 17, VMT_TURBO = 18, VMT_SUBWOOFER = 19, VMT_TYRE_SMOKE = 20, VMT_HYDRAULICS = 21, VMT_XENON_LIGHTS = 22, VMT_WHEELS = 23, VMT_WHEELS_REAR_OR_HYDRAULICS = 24, VMT_PLTHOLDER = 25, VMT_PLTVANITY = 26, VMT_INTERIOR1 = 27, VMT_INTERIOR2 = 28, VMT_INTERIOR3 = 29, VMT_INTERIOR4 = 30, VMT_INTERIOR5 = 31, VMT_SEATS = 32, VMT_STEERING = 33, VMT_KNOB = 34, VMT_PLAQUE = 35, VMT_ICE = 36, VMT_TRUNK = 37, VMT_HYDRO = 38, VMT_ENGINEBAY1 = 39, VMT_ENGINEBAY2 = 40, VMT_ENGINEBAY3 = 41, VMT_CHASSIS2 = 42, VMT_CHASSIS3 = 43, VMT_CHASSIS4 = 44, VMT_CHASSIS5 = 45, VMT_DOOR_L = 46, VMT_DOOR_R = 47, VMT_LIVERY_MOD = 48, VMT_LIGHTBAR = 49, };  ## Parameters * **vehicle**: * **modType**: * **modIndex**: * **customTires**:

### Parameters
* Vehicle vehicle
* int modType
* int modIndex
* BOOL customTires

### Return Value
* void

### Notes
* AP Hash: 0x0xB52E5ED5
* Build: 323
* In b944, there are 50 (0 - 49) mod types.

Sets the vehicle mod.
The vehicle must have a mod kit first.

Any out of range ModIndex is stock.

#Mod Type
Spoilers - 0
Front Bumper - 1
Rear Bumper - 2
Side Skirt - 3
Exhaust - 4
Frame - 5
Grille - 6
Hood - 7
Fender - 8
Right Fender - 9
Roof - 10
Engine - 11
Brakes - 12
Transmission - 13
Horns - 14 (modIndex from 0 to 51)
Suspension - 15
Armor - 16
Front Wheels - 23
Back Wheels - 24 //only for motocycles
Plate holders - 25
Trim Design - 27
Ornaments - 28
Dial Design - 30
Steering Wheel - 33
Shifter Leavers - 34
Plaques - 35
Hydraulics - 38
Livery - 48

ENUMS: https://pastebin.com/QzEAn02v

