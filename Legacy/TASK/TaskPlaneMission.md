# _TASK_PLANE_MISSION

--- ns: TASK --- ## TASK_PLANE_MISSION  // 0x23703CD154E83B88 0x1D007E65 void TASK_PLANE_MISSION(Ped ped, Vehicle vehicle, Vehicle targetVehicle, Ped targetPed, float fTargetCoordX, float fTargetCoordY, float fTargetCoordZ, int iMissionIndex, float fCruiseSpeed, float fTargetReachedDist, float fOrientation, cs_type(float) int iFlightHeight, cs_type(float) int iMinHeightAboveTerrain, cs_split BOOL bPrecise);  Gives the plane a mission (purpose or objective), the mission is passed onto the `iMissionIndex` parameter.  enum eVehicleMission { MISSION_NONE = 0, MISSION_CRUISE, // 1 MISSION_RAM, // 2 MISSION_BLOCK, // 3 MISSION_GOTO, // 4 MISSION_STOP, // 5 MISSION_ATTACK, // 6 MISSION_FOLLOW, // 7 MISSION_FLEE, // 8 MISSION_CIRCLE, // 9 MISSION_ESCORT_LEFT, // 10 MISSION_ESCORT_RIGHT, // 11 MISSION_ESCORT_REAR, // 12 MISSION_ESCORT_FRONT, // 13 MISSION_GOTO_RACING, // 14 MISSION_FOLLOW_RECORDING, // 15 MISSION_POLICE_BEHAVIOUR, // 16 MISSION_PARK_PERPENDICULAR, // 17 MISSION_PARK_PARALLEL, // 18 MISSION_LAND, // 19 MISSION_LAND_AND_WAIT, // 20 MISSION_CRASH, // 21 MISSION_PULL_OVER, // 22 MISSION_PROTECT // 23 };  ## Parameters * **ped**: The `Ped` handle. * **vehicle**: The `Vehicle` handle for the actual plane that will be flown. * **targetVehicle**: The target `Vehicle` handle (in case `eVehicleMission` requires one). * **targetPed**: The target `Ped` (in case `eVehicleMission` requires one). * **fTargetCoordX**: * **fTargetCoordY**: * **fTargetCoordZ**: * **iMissionIndex**: The mission to be executed. See `eVehicleMission`. * **fCruiseSpeed**: The cruise speed (in m/s). * **fTargetReachedDist**: Distance (in meters) (at which the plane thinks it has arrived), this is also used as the hover distance for `MISSION_ATTACK` and `MISSION_CIRCLE`. * **fOrientation**: Used to specify the desired orientation of the plane in degrees (`0` to `360`). Use `-1` if no specific orientation is required. * **iFlightHeight**: The height above sea level the plane tries to maintain, i.e. `50` meters. * **iMinHeightAboveTerrain**: The minimum height above terrain, i.e. `30` meters. * **bPrecise**: A boolean value, defaults to `true`.

### Parameters
* Ped pilot
* Vehicle aircraft
* Vehicle targetVehicle
* Ped targetPed
* float destinationX
* float destinationY
* float destinationZ
* int missionFlag
* float angularDrag
* float targetReached
* float targetHeading
* float maxZ
* float minZ
* BOOL precise

### Return Value
* void

### Notes
* AP Hash: 0x0x1D007E65
* Build: 323
* EXAMPLE USAGE:

Fly around target (Precautiously, keeps high altitude):
Function.Call(Hash.TASK_PLANE_MISSION, pilot, selectedAirplane, 0, 0, Target.X, Target.Y, Target.Z, 4, 100f, 0f, 90f, 0, 200f);

Fly around target (Dangerously, keeps VERY low altitude):
Function.Call(Hash.TASK_PLANE_MISSION, pilot, selectedAirplane, 0, 0, Target.X, Target.Y, Target.Z, 4, 100f, 0f, 90f, 0, -500f);

Fly directly into target:
Function.Call(Hash.TASK_PLANE_MISSION, pilot, selectedAirplane, 0, 0, Target.X, Target.Y, Target.Z, 4, 100f, 0f, 90f, 0, -5000f);

EXPANDED INFORMATION FOR ADVANCED USAGE (custom pilot)

'physicsSpeed': (THIS IS NOT YOUR ORDINARY SPEED PARAMETER: READ!!)
Think of this -first- as a radius value, not a true speed value.  The ACTUAL effective speed of the plane will be that of the maximum speed permissible to successfully fly in a -circle- with a radius of 'physicsSpeed'.  This also means that the plane must complete a circle before it can begin its "bombing run", its straight line pass towards the target.  p9 appears to influence the angle at which a "bombing run" begins, although I can't confirm yet.

VERY IMPORTANT: A "bombing run" will only occur if a plane can successfully determine a possible navigable route (the slower the value of 'physicsSpeed', the more precise the pilot can be due to less influence of physics on flightpath).  Otherwise, the pilot will continue to patrol around Destination (be it a dynamic Entity position vector or a fixed world coordinate vector.)

0 = Plane's physics are almost entirely frozen, plane appears to "orbit" around precise destination point
1-299 = Blend of "frozen, small radius" vs. normal vs. "accelerated, hyperfast, large radius"
300+ =  Vehicle behaves entirely like a normal gameplay plane.

'patrolBlend' (The lower the value, the more the Destination is treated as a "fly AT" rather than a "fly AROUND point".)

Scenario: Destination is an Entity on ground level, wide open field
-5000 = Pilot kamikazes directly into Entity
-1000 = Pilot flies extremely low -around- Entity, very prone to crashing
-200 = Pilot flies lower than average around Entity.
0 = Pilot flies around Entity, normal altitude
200 = Pilot flies an extra eighty units or so higher than 0 while flying around Destination (this doesn't seem to correlate directly into distance units.)

-- Valid mission types found in the exe: --

0 = None
1 = Unk
2 = CTaskVehicleRam
3 = CTaskVehicleBlock
4 = CTaskVehicleGoToPlane
5 = CTaskVehicleStop
6 = CTaskVehicleAttack
7 = CTaskVehicleFollow
8 = CTaskVehicleFleeAirborne
9= CTaskVehicleCircle
10 = CTaskVehicleEscort
15 = CTaskVehicleFollowRecording
16 = CTaskVehiclePoliceBehaviour
17 = CTaskVehicleCrash

