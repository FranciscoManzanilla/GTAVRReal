# _CREATE_WEAPON_OBJECT

--- ns: WEAPON --- ## CREATE_WEAPON_OBJECT  // 0x9541D3CF0D398F36 0x62F5987F Object CREATE_WEAPON_OBJECT(Hash weaponHash, int ammoCount, float x, float y, float z, BOOL bCreateDefaultComponents, float scale, int customModelHash);  Create a weapon object that cannot be attached to a ped. If you want to create a weapon object that can be attached to a ped, use [`CREATE_OBJECT`](#_0x509D5878EB39E842) instead.  NativeDB Added Parameter 9: BOOL bRegisterAsNetworkObject NativeDB Added Parameter 10: BOOL bScriptHostObject  ## Parameters * **weaponHash**: The hash of the weapon to create. * **ammoCount**: The amount of ammo for the weapon. * **x**: X coordinate for the weapon's position. * **y**: Y coordinate for the weapon's position. * **z**: Z coordinate for the weapon's position. * **bCreateDefaultComponents**: Boolean that indicates whether the default components should be created for that weapon (`true`/`false`). * **scale**: The size of the object, to increase it, set the scale to a value greater than `1.0`. * **customModelHash**: The hash of the custom model to use for the weapon object. Set to `0` if you do not intend to use a custom model hash.

### Parameters
* Hash weaponHash
* int ammoCount
* float x
* float y
* float z
* BOOL showWorldModel
* float scale
* Any p7
* Any p8
* Any p9

### Return Value
* Object

### Notes
* AP Hash: 0x0x62F5987F
* Build: 323
* Now has 8 params.

