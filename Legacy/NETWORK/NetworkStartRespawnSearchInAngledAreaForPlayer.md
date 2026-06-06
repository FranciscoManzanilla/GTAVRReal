# _NETWORK_START_RESPAWN_SEARCH_IN_ANGLED_AREA_FOR_PLAYER

--- ns: NETWORK aliases: ["0x4BA92A18502BCA61"] --- ## NETWORK_START_RESPAWN_SEARCH_IN_ANGLED_AREA_FOR_PLAYER  // 0x4BA92A18502BCA61 0x74D6B13C BOOL NETWORK_START_RESPAWN_SEARCH_IN_ANGLED_AREA_FOR_PLAYER(Player player, float x1, float y1, float z1, float x2, float y2, float z2, float width, float p8, float p9, float p10, int flags);  p8, p9, p10 is another coordinate, or zero, often related to ``GET_BLIP_COORDS`` in the decompiled scripts.  ## Parameters * **player**: * **x1**: X dimension of the angled area 'origin' * **y1**: Y dimension of the angled area 'origin' * **z1**: Z dimension of the angled area 'origin' * **x2**: X dimension of the angled area 'extent' * **y2**: Y dimension of the angled area 'extent' * **z2**: Z dimension of the angled area 'extent' * **width**: Width of the angled area * **p8**: * **p9**: * **p10**: * **flags**:  ## Return value

### Parameters
* Player player
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* float width
* float p8
* float p9
* float p10
* int flags

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x74D6B13C
* Build: 323
* p8, p9, p10 is another coordinate, or zero, often related to `GET_BLIP_COORDS in the decompiled scripts.

