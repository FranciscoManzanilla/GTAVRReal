# _TASK_VEHICLE_TEMP_ACTION

--- ns: TASK --- ## TASK_VEHICLE_TEMP_ACTION  // 0xC429DCEEB339E129 0x0679DFB8 void TASK_VEHICLE_TEMP_ACTION(Ped driver, Vehicle vehicle, int action, int time);  Gives the vehicle a temporary action.  **Note**: For migrating objects, a `CScriptEntityStateChangeEvent` will be sent over the network to let other clients know that this object is being given a temporary action. At the same time, temporary actions cannot be applied to clones/remote objects.  enum eTempAction { TA_NONE = 0, TA_WAIT = 1, TA_UNUSED = 2, TA_BRAKE_REVERSE = 3, TA_HANDBRAKE_TURN_LEFT = 4, TA_HANDBRAKE_TURN_RIGHT = 5, TA_HANDBRAKE_UNTIL_TIME_ENDS = 6, TA_TURN_LEFT = 7, TA_TURN_RIGHT = 8, TA_ACCELERATE = 9, TA_TURN_LEFT = 10, TA_TURN_RIGHT = 11, TA_UNUSED_12 = 12, TA_TURN_LEFT_GO_REVERSE = 13, TA_TURN_RIGHT_GO_REVERSE = 14, TA_PLANE_FLY_UP = 15, // (crashes game if not in plane) TA_PLANE_FLY_STRAIGHT = 16, // (crashes game if not in plane) TA_PLANE_SHARP_LEFT = 17, // (crashes game if not in plane) TA_PLANE_SHARP_RIGHT = 18, // (crashes game if not in plane) TA_STRONG_BRAKE = 19, TA_TURN_LEFT_AND_STOP = 20, TA_TURN_RIGHT_AND_STOP = 21, TA_GO_IN_REVERSE = 22, TA_ACCELERATE_FAST = 23, TA_BRAKE_ACTION = 24, TA_HANDBRAKE_TURN_LEFT_MORE = 25, TA_HANDBRAKE_TURN_RIGHT_MORE = 26, TA_HANDBRAKE_BRAKE_STRAIGHT = 27, TA_BRAKE_STRONG_REVERSE_ACCELERATION = 28, TA_UNUSED_29 = 29, TA_PERFORMS_BURNOUT = 30, TA_REV_ENGINE = 31, TA_ACCELERATE_VERY_STRONG = 32, TA_SURFACE_IN_SUBMARINE = 33 };  ## Parameters * **driver**: The vehicle driver (`Ped`). * **vehicle**: The vehicle handle. * **action**: The temporary action, see `eTempAction`. * **time**: The time to run this temp action for, use `-1` for infinite. Time is in milliseconds.

### Parameters
* Ped driver
* Vehicle vehicle
* int action
* int time

### Return Value
* void

### Notes
* AP Hash: 0x0x0679DFB8
* Build: 323
* '1 - brake
'3 - brake + reverse
'4 - turn left 90 + braking
'5 - turn right 90 + braking
'6 - brake strong (handbrake?) until time ends
'7 - turn left + accelerate
'8 - turn right + accelerate
'9 - weak acceleration
'10 - turn left + restore wheel pos to center in the end
'11 - turn right + restore wheel pos to center in the end
'13 - turn left + go reverse
'14 - turn left + go reverse
'16 - crash the game after like 2 seconds :)
'17 - keep actual state, game crashed after few tries
'18 - game crash
'19 - strong brake + turn left/right
'20 - weak brake + turn left then turn right
'21 - weak brake + turn right then turn left
'22 - brake + reverse
'23 - accelerate fast
'24 - brake
'25 - brake turning left then when almost stopping it turns left more
'26 - brake turning right then when almost stopping it turns right more
'27 - brake until car stop or until time ends
'28 - brake + strong reverse acceleration
'30 - performs a burnout (brake until stop + brake and accelerate)
'31 - accelerate + handbrake
'32 - accelerate very strong

Seems to be this:
Works on NPCs, but overrides their current task. If inside a task sequence (and not being the last task), "time" will work, otherwise the task will be performed forever until tasked with something else

