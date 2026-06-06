# _PLAY_CAM_ANIM

--- ns: CAM --- ## PLAY_CAM_ANIM  // 0x9A2D0FB2E7852392 0xBCEFB87E BOOL PLAY_CAM_ANIM(Cam cam, char* animName, char* animDictionary, float x, float y, float z, float xRot, float yRot, float zRot, BOOL p9, int p10);  Atleast one time in a script for the zRot Rockstar uses GET_ENTITY_HEADING to help fill the parameter. p9 is unknown at this time. p10 throughout all the X360 Scripts is always 2.  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **cam**: * **animName**: * **animDictionary**: * **x**: * **y**: * **z**: * **xRot**: * **yRot**: * **zRot**: * **p9**: * **p10**:  ## Return value

### Parameters
* Cam cam
* const char* animName
* const char* animDictionary
* float x
* float y
* float z
* float xRot
* float yRot
* float zRot
* BOOL p9
* int p10

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xBCEFB87E
* Build: 323
* Atleast one time in a script for the zRot Rockstar uses GET_ENTITY_HEADING to help fill the parameter.

p9 is unknown at this time.
p10 throughout all the X360 Scripts is always 2.

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

