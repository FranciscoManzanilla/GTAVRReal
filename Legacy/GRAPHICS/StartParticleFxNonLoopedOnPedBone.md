# _START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE

--- ns: GRAPHICS --- ## START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE  // 0x0E7E72961BA18619 0x53DAEF4E BOOL START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE(char* effectName, Ped ped, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, int boneIndex, float scale, BOOL axisX, BOOL axisY, BOOL axisZ);  GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_sh_bong_smoke", PLAYER::PLAYER_PED_ID(), -0.025f, 0.13f, 0f, 0f, 0f, 0f, 31086, 0x3F800000, 0, 0, 0); Axis - Invert Axis Flags list: pastebin.com/N9unUFWY  ## Parameters * **effectName**: * **ped**: * **offsetX**: * **offsetY**: * **offsetZ**: * **rotX**: * **rotY**: * **rotZ**: * **boneIndex**: * **scale**: * **axisX**: * **axisY**: * **axisZ**:  ## Return value

### Parameters
* const char* effectName
* Ped ped
* float offsetX
* float offsetY
* float offsetZ
* float rotX
* float rotY
* float rotZ
* int boneIndex
* float scale
* BOOL axisX
* BOOL axisY
* BOOL axisZ

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x53DAEF4E
* Build: 323
* GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_sh_bong_smoke", PLAYER::PLAYER_PED_ID(), -0.025f, 0.13f, 0f, 0f, 0f, 0f, 31086, 0x3F800000, 0, 0, 0);

Axis - Invert Axis Flags

Full list of particle effect dictionaries and effects by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/particleEffectsCompact.json

