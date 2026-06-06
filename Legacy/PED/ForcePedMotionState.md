# _FORCE_PED_MOTION_STATE

--- ns: PED --- ## FORCE_PED_MOTION_STATE  // 0xF28965D04F570DCA 0x164DDEFF BOOL FORCE_PED_MOTION_STATE(Ped ped, Hash motionStateHash, BOOL shouldReset, cs_type(BOOL) int updateState, BOOL forceAIPreCameraUpdate);  enum ePedMotionState { MOTIONSTATE_NONE = -294553821, // MotionState_None MOTIONSTATE_IDLE = -1871534317, // MotionState_Idle MOTIONSTATE_WALK = -668482597, // MotionState_Walk MOTIONSTATE_RUN = -530524, // MotionState_Run MOTIONSTATE_SPRINT = -1115154469, // MotionState_Sprint MOTIONSTATE_CROUCH_IDLE = 1140525470, // MotionState_Crouch_Idle MOTIONSTATE_CROUCH_WALK = 147004056, // MotionState_Crouch_Walk MOTIONSTATE_CROUCH_RUN = 898879241, // MotionState_Crouch_Run MOTIONSTATE_DONOTHING = 247561816, // MotionState_DoNothing MOTIONSTATE_ANIMATEDVELOCITY = 1427811395, // MotionState_AnimatedVelocity MOTIONSTATE_INVEHICLE = -1797663347, // MotionState_InVehicle MOTIONSTATE_AIMING = 1063765679, // MotionState_Aiming MOTIONSTATE_DIVING_IDLE = 1212730861, // MotionState_Diving_Idle MOTIONSTATE_DIVING_SWIM = -1855028596, // MotionState_Diving_Swim MOTIONSTATE_SWIMMING_TREADWATER = -776007225, // MotionState_Swimming_TreadWater MOTIONSTATE_DEAD = 230360860, // MotionState_Dead MOTIONSTATE_STEALTH_IDLE = 1110276645, // MotionState_Stealth_Idle MOTIONSTATE_STEALTH_WALK = 69908130, // MotionState_Stealth_Walk MOTIONSTATE_STEALTH_RUN = -83133983, // MotionState_Stealth_Run MOTIONSTATE_PARACHUTING = -1161760501, // MotionState_Parachuting MOTIONSTATE_ACTIONMODE_IDLE = -633298724, // MotionState_ActionMode_Idle MOTIONSTATE_ACTIONMODE_WALK = -762290521, // MotionState_ActionMode_Walk MOTIONSTATE_ACTIONMODE_RUN = 834330132, // MotionState_ActionMode_Run MOTIONSTATE_JETPACK = 1398696542 // MotionState_Jetpack }  ## Parameters * **ped**: The ped handle. * **motionStateHash**: The motion state hash. * **shouldReset**: If the motion state should be set even if the ped is already in the specified motion state. * **updateState**: Integer but treated as a boolean (only allows 1 or 0). Sets ped reset flags `CPED_RESET_FLAG_ForcePreCameraAiAnimUpdateIfFirstPerson` and `CPED_RESET_FLAG_ForcePostCameraAnimUpdate`. * **forceAIPreCameraUpdate**: If `updateState` is 1, will set either `CPED_RESET_FLAG_ForcePreCameraAIUpdate` (if true) or `CPED_RESET_FLAG_ForcePostCameraAIUpdate` (if false) ped reset flags.  ## Return value Whether or not the motion state was forced on the ped successfully.

### Parameters
* Ped ped
* Hash motionStateHash
* BOOL p2
* int p3
* BOOL p4

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x164DDEFF
* Build: 323
* Regarding p2, p3 and p4: Most common is 0, 0, 0); followed by 0, 1, 0); and 1, 1, 0); in R* scripts. p4 is very rarely something other than 0.

enum eMotionState // 0x92A659FE
{
	MotionState_None = 0xEE717723,
	MotionState_Idle = 0x9072A713,
	MotionState_Walk = 0xD827C3DB,
	MotionState_Run = 0xFFF7E7A4,
	MotionState_Sprint = 0xBD8817DB,
	MotionState_Crouch_Idle = 0x43FB099E,
	MotionState_Crouch_Walk = 0x08C31A98,
	MotionState_Crouch_Run = 0x3593CF09,
	MotionState_DoNothing = 0x0EC17E58,
	MotionState_AnimatedVelocity = 0x551AAC43,
	MotionState_InVehicle = 0x94D9D58D,
	MotionState_Aiming = 0x3F67C6AF,
	MotionState_Diving_Idle = 0x4848CDED,
	MotionState_Diving_Swim = 0x916E828C,
	MotionState_Swimming_TreadWater = 0xD1BF11C7,
	MotionState_Dead = 0x0DBB071C,
	MotionState_Stealth_Idle = 0x422D7A25,
	MotionState_Stealth_Walk = 0x042AB6A2,
	MotionState_Stealth_Run = 0xFB0B79E1,
	MotionState_Parachuting = 0xBAC0F10B,
	MotionState_ActionMode_Idle = 0xDA40A0DC,
	MotionState_ActionMode_Walk = 0xD2905EA7,
	MotionState_ActionMode_Run = 0x31BADE14,
	MotionState_Jetpack = 0x535E6A5E
};

