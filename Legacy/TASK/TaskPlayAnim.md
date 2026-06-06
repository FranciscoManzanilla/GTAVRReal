# _TASK_PLAY_ANIM

--- ns: TASK --- ## TASK_PLAY_ANIM  // 0xEA47FE3719165B94 0x5AB552C6 void TASK_PLAY_ANIM(Ped ped, char* animDictionary, char* animationName, float blendInSpeed, float blendOutSpeed, int duration, int flag, float playbackRate, BOOL lockX, BOOL lockY, BOOL lockZ);  [Animations list](https://alexguirre.github.io/animations-list/)  enum eScriptedAnimFlags { AF_LOOPING = 1, AF_HOLD_LAST_FRAME = 2, AF_REPOSITION_WHEN_FINISHED = 4, AF_NOT_INTERRUPTABLE = 8, AF_UPPERBODY = 16, AF_SECONDARY = 32, AF_REORIENT_WHEN_FINISHED = 64, AF_ABORT_ON_PED_MOVEMENT = 128, AF_ADDITIVE = 256, AF_TURN_OFF_COLLISION = 512, AF_OVERRIDE_PHYSICS = 1024, AF_IGNORE_GRAVITY = 2048, AF_EXTRACT_INITIAL_OFFSET = 4096, AF_EXIT_AFTER_INTERRUPTED = 8192, AF_TAG_SYNC_IN = 16384, AF_TAG_SYNC_OUT = 32768, AF_TAG_SYNC_CONTINUOUS = 65536, AF_FORCE_START = 131072, AF_USE_KINEMATIC_PHYSICS = 262144, AF_USE_MOVER_EXTRACTION = 524288, AF_HIDE_WEAPON = 1048576, AF_ENDS_IN_DEAD_POSE = 2097152, AF_ACTIVATE_RAGDOLL_ON_COLLISION = 4194304, AF_DONT_EXIT_ON_DEATH = 8388608, AF_ABORT_ON_WEAPON_DAMAGE = 16777216, AF_DISABLE_FORCED_PHYSICS_UPDATE = 33554432, AF_PROCESS_ATTACHMENTS_ON_START = 67108864, AF_EXPAND_PED_CAPSULE_FROM_SKELETON = 134217728, AF_USE_ALTERNATIVE_FP_ANIM = 268435456, AF_BLENDOUT_WRT_LAST_FRAME = 536870912, AF_USE_FULL_BLENDING = 1073741824 }  ## Parameters * **ped**: The ped you want to play the animation * **animDictionary**: The animation dictionary * **animationName**: The animation name * **blendInSpeed**: The speed at which the animation blends in. Lower is slower and higher is faster, 1.0 is normal, 8.0 is basically instant * **blendOutSpeed**: The speed at which the animation blends out. Lower is slower and higher is faster, 1.0 is normal, 8.0 is basically instant * **duration**: The duration of the animation in milliseconds. -1 will play the animation until canceled * **flag**: The animation flags (see enum) * **playbackRate**: The playback rate (between 0.0 and 1.0) * **lockX**: * **lockY**: * **lockZ**:

### Parameters
* Ped ped
* const char* animDictionary
* const char* animationName
* float blendInSpeed
* float blendOutSpeed
* int duration
* int flag
* float playbackRate
* BOOL lockX
* BOOL lockY
* BOOL lockZ

### Return Value
* void

### Notes
* AP Hash: 0x0x5AB552C6
* Build: 323
* Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

float speed > normal speed is 8.0f
----------------------

float speedMultiplier > multiply the playback speed
----------------------

int duration: time in millisecond
----------------------
-1 _ _ _ _ _ _ _> Default (see flag)
0 _ _ _ _ _ _ _ > Not play at all
Small value _ _ > Slow down animation speed
Other _ _ _ _ _ > freeze player control until specific time (ms) has 
_ _ _ _ _ _ _ _ _ passed. (No effect if flag is set to be 
_ _ _ _ _ _ _ _ _ controllable.)

int flag:
----------------------
enum eAnimationFlags
{
 ANIM_FLAG_NORMAL = 0,
   ANIM_FLAG_REPEAT = 1,
   ANIM_FLAG_STOP_LAST_FRAME = 2,
   ANIM_FLAG_UPPERBODY = 16,
   ANIM_FLAG_ENABLE_PLAYER_CONTROL = 32,
   ANIM_FLAG_CANCELABLE = 120,
};
Odd number : loop infinitely
Even number : Freeze at last frame
Multiple of 4: Freeze at last frame but controllable

01 to 15 > Full body
10 to 31 > Upper body
32 to 47 > Full body > Controllable
48 to 63 > Upper body > Controllable
...
001 to 255 > Normal
256 to 511 > Garbled
...

playbackRate:

values are between 0.0 and 1.0


lockX:  

0 in most cases 1 for rcmepsilonism8 and rcmpaparazzo_3
> 1 for mini@sprunk
 

lockY:

0 in most cases 
1 for missfam5_yoga, missfra1mcs_2_crew_react


lockZ: 

    0 for single player 
    Can be 1 but only for MP 

