# _HAS_ANIM_SET_LOADED

--- ns: STREAMING --- ## HAS_ANIM_SET_LOADED  // 0xC4EA073D86FB29B0 0x4FFF397D BOOL HAS_ANIM_SET_LOADED(char* animSet);  Gets whether the specified animation set has finished loading. An animation set provides movement animations for a ped.  Animation set and clip set are synonymous. See [`SET_PED_MOVEMENT_CLIPSET`](#_0xAF8A94EDE7712BEF).  ## Parameters * **animSet**:  ## Return value

### Parameters
* const char* animSet

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x4FFF397D
* Build: 323
* Gets whether the specified animation set has finished loading. An animation set provides movement animations for a ped. See SET_PED_MOVEMENT_CLIPSET.

Animation set and clip set are synonymous.

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

Full list of movement clipsets by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/movementClipsetsCompact.json

