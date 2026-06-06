# _SET_RAGDOLL_BLOCKING_FLAGS

--- ns: PED aliases: ["0x26695EC767728D84","_SET_PED_RAGDOLL_BLOCKING_FLAGS"] --- ## SET_RAGDOLL_BLOCKING_FLAGS  // 0x26695EC767728D84 0x9C8F830D void SET_RAGDOLL_BLOCKING_FLAGS(Ped ped, int flags);  Works for both player and peds, but some flags don't seem to work for the player (1, for example) 1 - Blocks ragdolling when shot. 2 - Blocks ragdolling when hit by a vehicle. The ped still might play a falling animation. 4 - Blocks ragdolling when set on fire. ----------------------------------------------------------------------- There seem to be 26 flags  ## Parameters * **ped**: * **flags**:

### Parameters
* Ped ped
* int blockingFlag

### Return Value
* void

### Notes
* AP Hash: 0x0x9C8F830D
* Build: 323
* Works for both player and peds,

enum eRagdollBlockingFlags
{
 RBF_BULLET_IMPACT = 0,
 RBF_VEHICLE_IMPACT = 1,
 RBF_FIRE = 2,
 RBF_ELECTROCUTION = 3,
 RBF_PLAYER_IMPACT = 4,
 RBF_EXPLOSION = 5,0
 RBF_IMPACT_OBJECT = 6,
 RBF_MELEE = 7,
 RBF_RUBBER_BULLET = 8,
 RBF_FALLING = 9,
 RBF_WATER_JET = 10,
 RBF_DROWNING = 11,
 _0x9F52E2C4 = 12,
 RBF_PLAYER_BUMP = 13,
 RBF_PLAYER_RAGDOLL_BUMP = 14,
 RBF_PED_RAGDOLL_BUMP = 15,
 RBF_VEHICLE_GRAB = 16,
 RBF_SMOKE_GRENADE = 17,
};



