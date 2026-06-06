# _TASK_START_SCENARIO_IN_PLACE

--- ns: TASK --- ## TASK_START_SCENARIO_IN_PLACE  // 0x142A02425FF02BD9 0xE50D6DDE void TASK_START_SCENARIO_IN_PLACE(Ped ped, char* scenarioName, int timeToLeave, BOOL playIntroClip);  Puts the ped into the given scenario immediately at their current location. [List of scenario names](https://pastebin.com/6mrYTdQv) or in `update/update.rpf/common/data/ai/scenarios.meta`.  ## Parameters * **ped**: The ped handle. * **scenarioName**: The name of the scenario to start. * **timeToLeave**: Sets the timeout on the scenario point to the specified time in milliseconds. If less than 0, sets the `IdleForever` flag. * **playIntroClip**: If the ped should play the scenarios enter animation. Sets the `SkipEnterClip` flag.

### Parameters
* Ped ped
* const char* scenarioName
* int unkDelay
* BOOL playEnterAnim

### Return Value
* void

### Notes
* AP Hash: 0x0xE50D6DDE
* Build: 323
* Plays a scenario on a Ped at their current location.

unkDelay - Usually 0 or -1, doesn't seem to have any effect. Might be a delay between sequences.
playEnterAnim - Plays the "Enter" anim if true, otherwise plays the "Exit" anim. Scenarios that don't have any "Enter" anims won't play if this is set to true.

----

From "am_hold_up.ysc.c4" at line 339:

TASK::TASK_START_SCENARIO_IN_PLACE(NETWORK::NET_TO_PED(l_8D._f4), sub_adf(), 0, 1);

I'm unsure of what the last two parameters are, however sub_adf() randomly returns 1 of 3 scenarios, those being:
WORLD_HUMAN_SMOKING
WORLD_HUMAN_HANG_OUT_STREET
WORLD_HUMAN_STAND_MOBILE

This makes sense, as these are what I commonly see when going by a liquor store.
-------------------------
List of scenarioNames: https://pastebin.com/6mrYTdQv
(^ Thank you so fucking much for this)

Also these:
WORLD_FISH_FLEE
DRIVE
WORLD_HUMAN_HIKER
WORLD_VEHICLE_ATTRACTOR
WORLD_VEHICLE_BICYCLE_MOUNTAIN
WORLD_VEHICLE_BIKE_OFF_ROAD_RACE
WORLD_VEHICLE_BIKER
WORLD_VEHICLE_CONSTRUCTION_PASSENGERS
WORLD_VEHICLE_CONSTRUCTION_SOLO
WORLD_VEHICLE_DRIVE_PASSENGERS
WORLD_VEHICLE_DRIVE_SOLO
WORLD_VEHICLE_EMPTY
WORLD_VEHICLE_PARK_PARALLEL
WORLD_VEHICLE_PARK_PERPENDICULAR_NOSE_IN
WORLD_VEHICLE_POLICE_BIKE
WORLD_VEHICLE_POLICE_CAR
WORLD_VEHICLE_POLICE_NEXT_TO_CAR
WORLD_VEHICLE_SALTON_DIRT_BIKE
WORLD_VEHICLE_TRUCK_LOGS

Full list of ped scenarios by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/scenariosCompact.json

