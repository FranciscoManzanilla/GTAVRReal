# _PLAY_SYNCHRONIZED_MAP_ENTITY_ANIM

--- ns: ENTITY --- ## PLAY_SYNCHRONIZED_MAP_ENTITY_ANIM  // 0xB9C54555ED30FBC4 0xEB4CBA74 BOOL PLAY_SYNCHRONIZED_MAP_ENTITY_ANIM(float x, float y, float z, float radius, cs_type(Any) Hash objectModelHash, int sceneId, cs_type(AnyPtr) char* pAnimName, cs_type(AnyPtr) char* pAnimDictName, float fBlendDelta, float fBlendOutDelta, int flags, float fMoverBlendInDelta);  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **x**: * **y**: * **z**: * **radius**: * **objectModelHash**: * **sceneId**: * **pAnimName**: The name of the animation to play. * **pAnimDictName**: The name of the animation dictionary to use. * **fBlendDelta**: Blend in time. * **fBlendOutDelta**: Blend out time. * **flags**: The flags to use when playing the animation. See [`TASK_PLAY_ANIM`](#_0xEA47FE3719165B94). * **fMoverBlendInDelta**:  ## Return value

### Parameters
* float x1
* float y1
* float z1
* float x2
* Any y2
* float z2
* const char* p6
* const char* p7
* float p8
* float p9
* Any p10
* float p11

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xEB4CBA74
* Build: 323
* p6,p7 probably animname and animdict

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

