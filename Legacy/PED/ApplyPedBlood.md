# _APPLY_PED_BLOOD

--- ns: PED --- ## APPLY_PED_BLOOD  // 0x83F7E01C7B769A26 0x376CE3C0 void APPLY_PED_BLOOD(Ped ped, int boneIndex, float xRot, float yRot, float zRot, char* woundType);  Found one occurence in re_crashrescue.c4 PED::APPLY_PED_BLOOD(l_4B, 3, 0.0, 0.0, 0.0, "wound_sheet");  ## Parameters * **ped**: * **boneIndex**: * **xRot**: * **yRot**: * **zRot**: * **woundType**:

### Parameters
* Ped ped
* int boneIndex
* float xRot
* float yRot
* float zRot
* const char* woundType

### Return Value
* void

### Notes
* AP Hash: 0x0x376CE3C0
* Build: 323
* woundTypes:
- soak_splat
- wound_sheet
- BulletSmall
- BulletLarge
- ShotgunSmall
- ShotgunSmallMonolithic
- ShotgunLarge
- ShotgunLargeMonolithic
- NonFatalHeadshot
- stab
- BasicSlash
- Scripted_Ped_Splash_Back
- BackSplash

