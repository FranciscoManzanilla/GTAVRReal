# _TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD

--- ns: TASK --- ## TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD  // 0x11315AB3385B8AC0 0x1552DC91 void TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD(Ped ped, float x, float y, float z, float aimAtX, float aimAtY, float aimAtZ, float moveSpeed, BOOL shoot, float p9, float p10, BOOL p11, Any flags, BOOL p13, Hash firingPattern);  Will make the ped move to a coordinate while aiming (and optionally shooting) at given coordinates.  ## Parameters * **ped**: Ped to task * **x**: Destination X position * **y**: Destination Y position * **z**: Destination Z position * **aimAtX**: Aim at target x position * **aimAtY**: Aim at target Y position * **aimAtZ**: Aim at target Z position * **moveSpeed**: mostly 2f, but also 1/1.2f, etc. * **shoot**: If true ped will shoot; false - will not * **p9**: Usually 2.0f * **p10**: Usually 0.5f * **p11**: If true ped will stay still; false - will not * **flags**: 0 / 512 / 513, etc * **p13**: * **firingPattern**: ${firing_pattern_full_auto}, 0xC6EE6B4C

### Parameters
* Ped ped
* float x
* float y
* float z
* float aimAtX
* float aimAtY
* float aimAtZ
* float moveBlendRatio
* BOOL shoot
* float targetRadius
* float slowDistance
* BOOL useNavMesh
* int navFlags
* BOOL instantBlendToAim
* Hash firingPattern

### Return Value
* void

### Notes
* AP Hash: 0x0x1552DC91
* Build: 323
* movement_speed: mostly 2f, but also 1/1.2f, etc.
p8: always false
p9: 2f
p10: 0.5f
p11: true
p12: 0 / 512 / 513, etc.
p13: 0
firing_pattern: ${firing_pattern_full_auto}, 0xC6EE6B4C

