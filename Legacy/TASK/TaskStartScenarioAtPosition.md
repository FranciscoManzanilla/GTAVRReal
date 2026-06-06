# _TASK_START_SCENARIO_AT_POSITION

--- ns: TASK --- ## TASK_START_SCENARIO_AT_POSITION  // 0xFA4EFC79F69D4F07 0xAA2C4AC2 void TASK_START_SCENARIO_AT_POSITION(Ped ped, char* scenarioName, float x, float y, float z, float heading, int timeToLeave, BOOL playIntro, BOOL warp);  The ped will move or warp to the position and heading given, then start the scenario passed. See [`TASK_START_SCENARIO_IN_PLACE`](#_0x142A02425FF02BD9) for a list of scenarios.  ## Parameters * **ped**: The ped handle. * **scenarioName**: The name of the scenario to start. * **x**: The x coordinate to start at. * **y**: The y coordinate to start at. * **z**: The z coordinate to start at. Should be the ground position plus the ped's ground to root offset. * **heading**: The heading to start at. * **timeToLeave**: Sets the timeout on the scenario point to the specified time in milliseconds. If less than 0, sets the `IdleForever` flag. * **playIntro**: If the ped should play the scenarios enter animation. Sets the `SkipEnterClip` flag. * **warp**: If the ped should be warped to the position. Sets the `Warp` flag.

### Parameters
* Ped ped
* const char* scenarioName
* float x
* float y
* float z
* float heading
* int duration
* BOOL sittingScenario
* BOOL teleport

### Return Value
* void

### Notes
* AP Hash: 0x0xAA2C4AC2
* Build: 323
* Full list of ped scenarios by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/scenariosCompact.json

Also a few more listed at TASK::TASK_START_SCENARIO_IN_PLACE just above.
---------------
The first parameter in every scenario has always been a Ped of some sort. The second like TASK_START_SCENARIO_IN_PLACE is the name of the scenario. 

The next 4 parameters were harder to decipher. After viewing "hairdo_shop_mp.ysc.c4", and being confused from seeing the case in other scripts, they passed the first three of the arguments as one array from a function, and it looked like it was obviously x, y, and z.

I haven't seen the sixth parameter go to or over 360, making me believe that it is rotation, but I really can't confirm anything.

I have no idea what the last 3 parameters are, but I'll try to find out.

-going on the last 3 parameters, they appear to always be "0, 0, 1"

p6 -1 also used in scrips

p7 used for sitting scenarios

p8 teleports ped to position

