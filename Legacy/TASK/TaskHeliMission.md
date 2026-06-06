# _TASK_HELI_MISSION

--- ns: TASK --- ## TASK_HELI_MISSION  // 0xDAD029E187A2BEB4 0x0C143E97 void TASK_HELI_MISSION(Ped ped, Vehicle heli, Vehicle vehicleTarget, Ped pedTarget, float x, float y, float z, int missionType, float speed, float radius, float heading, cs_type(int) float height, float minHeight, cs_type(Hash) float slowDist, int missionFlags);  All parameters except ped, heli and speed are optional, with `pedTarget`, `vehicleTarget`, `x`, `y`, `z` being dependent on `missionType` (ie. Attack/Flee mission types require a target ped/vehicle, whereas GoTo mission types require either `x`, `y`, `z` or a target ped/vehicle).  If you don't want to use a parameter; pass `0.0f` for `x`, `y` and `z`, `0` for `pedTarget`, `vehicleTarget`, `0` for other int parameters, and `-1.0f` for the remaining float parameters.  enum eHeliMissionFlags { None = 0, AttainRequestedOrientation = 1, DontModifyOrientation = 2, DontModifyPitch = 4, DontModifyThrottle = 8, DontModifyRoll = 16, LandOnArrival = 32, DontDoAvoidance = 64, StartEngineImmediately = 128, ForceHeightMapAvoidance = 256, DontClampProbesToDestination = 512, EnableTimeslicingWhenPossible = 1024, CircleOppositeDirection = 2048, MaintainHeightAboveTerrain = 4096, IgnoreHiddenEntitiesDuringLand = 8192, DisableAllHeightMapAvoidance = 16384, // ForceHeightMapAvoidance | DontDoAvoidance HeightMapOnlyAvoidance = 320, }  ## Parameters * **ped**: The ped to be tasked. * **heli**: The helicopters' entity handle. * **vehicleTarget**: The target vehicle (default is 0). * **pedTarget**: The target ped (default is 0). * **x**: The x coordinate of the target (default is 0.0f). * **y**: The y coordinate of the target (default is 0.0f). * **z**: The z coordinate of the target (default is 0.0f). * **missionType**: The mission type (default is 0) (see [TaskVehicleMission](#_0x659427E0EF36BCDE)). * **speed**: The speed in m/s. * **radius**: The radius of when the task will be completed (default is -1.0f). * **heading**:  The heading the helicopter will face at task completion (default is -1.0f). * **height**: The height the helicopter will fly at (default is -1.0f). * **minHeight**: The height the helicopter will not fly below (default is -1.0f). * **slowDist**: The distance to the target at which the helicopter will slow down (default is -1.0f). * **missionFlags**: The mission flags (default is 0) (see `eHeliMissionFlags`).  ## Examples  local heli_model = `akula` RequestModel(heli_model) repeat Wait(0) until HasModelLoaded(heli_model)  -- Player needs to be outside for this to work local ped = PlayerPedId() local coords = GetEntityCoords(ped) + GetEntityForwardVector(ped) * 100.0 local heli = CreateVehicle(heli_model, coords.x, coords.y, coords.z + 50.0, GetEntityHeading(ped) - 180.0, true, false) -- Allow the game engine to clear the model from memory SetModelAsNoLongerNeeded(heli_model) SetHeliBladesFullSpeed(heli)  local ped_model = `a_m_m_skater_01` RequestModel(ped_model) repeat Wait(0) until HasModelLoaded(ped_model)  local pilot = CreatePedInsideVehicle(heli, 0, ped_model, -1, true, false) -- Allow the game engine to clear the model from memory SetModelAsNoLongerNeeded(ped_model)  TaskHeliMission(pilot, heli, 0, 0, coords.x, coords.y, coords.z, 19, 10.0, -1.0, -1.0, -1.0, -1.0, -1.0, 96) -- Mission Type: Land | Mission Flags: LandOnArrival | DontDoAvoidance SetPedKeepTask(pilot, true)

### Parameters
* Ped pilot
* Vehicle aircraft
* Vehicle targetVehicle
* Ped targetPed
* float destinationX
* float destinationY
* float destinationZ
* int missionFlag
* float maxSpeed
* float radius
* float targetHeading
* int maxHeight
* int minHeight
* float slowDownDistance
* int behaviorFlags

### Return Value
* void

### Notes
* AP Hash: 0x0x0C143E97
* Build: 323
* Must have targetVehicle, targetPed, OR destination X/Y/Z set
Will follow targeted vehicle/ped, or fly to destination
Set whichever is not being used to 0


Mission mode type:
 - 4, 7: Forces heli to snap to the heading if set, flies to destination or tracks specified entity (mode 4 only works for coordinates, 7 works for coordinates OR ped/vehicle)
 - 6: Attacks the target ped/vehicle with mounted weapons. If radius is set, will maintain that distance from target.
 - 8: Makes the heli flee from the ped/vehicle/coordinate
 - 9: Circles around target ped/vehicle, snaps to angle if set. Behavior flag (last parameter) of 2048 switches from counter-clockwise to clockwise circling. Does not work with coordinate destination.
 - 10, 11: Follows ped/vehicle target and imitates target heading. Only works with ped/vehicle target, not coord target
 - 19: Heli lands at specified coordinate, ignores heading (lands facing whatever direction it is facing when the task is started)
 - 20: Makes the heli land when near target ped. It won't resume chasing.
 - 21: Emulates a helicopter crash
 - 23: makes the heli circle erratically around ped


Heli will fly at maxSpeed (up to actual maximum speed defined by the model's handling config)
You can use SET_DRIVE_TASK_CRUISE_SPEED to modulate the speed based on distance to the target without having to re-invoke the task native. Setting to 8.0 when close to the destination results in a much smoother approach.

If minHeight and maxHeight are set, heli will fly between those specified elevations, relative to ground level and any obstructions/buildings below. You can specify -1 for either if you only want to specify one. Usually it is easiest to leave maxHeight at -1, and specify a reasonable minHeight to ensure clearance over any obstacles. Note this MUST be passed as an INT, not a FLOAT. 

Radius affects how closely the heli will follow tracked ped/vehicle, and when circling (mission type 9) sets the radius (in meters) that it will circle the target from

Heading is -1.0 for default behavior, which will point the nose of the helicopter towards the destination. Set a heading and the heli will lock to that direction when near its destination/target, but may still turn towards the destination when flying at higher speed from a further distance.

Behavior Flags is a bitwise value that modifies the AI behavior. Not clear what all flags do, but here are some guesses/notes:
   1: Forces heading to face E
   2: Unknown
   4: Tight circles around coordinate destination
   8: Unknown
  16: Circles around coordinate destination facing towards destination
  32: Flys to normally, then lands at coordinate destination and stays on the ground (using mission type 4)
  64: Ignores obstacles when flying, will follow at specified minHeight above ground level but will not avoid buildings, vehicles, etc.
 128: Unknown
 256: Unknown
 512: Unknown
1024: Unknown 
2048: Reverses direction of circling (mission type 9) to clockwise
4096: Hugs closer to the ground, maintains minHeight from ground generally, but barely clears buildings and dips down more between buildings instead of taking a more efficient/safe route
8192: Unknown

Unk3 is a float value, you may see -1082130432 for this value in decompiled native scripts, this is the equivalent to -1.0f. Seems to affect acceleration/aggressiveness, but not sure exactly how it works. Higher value seems to result in lower acceleration/less aggressive flying. Almost always -1.0 in native scripts, occasionally 20.0 or 50.0. Setting to 400.0 seems to work well for making the pilot not overshoot the destination when using coordinate destination.

Notes updated by PNWParksFan, May 2021


