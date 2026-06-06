# _SET_BLIP_SHOW_CONE

--- ns: HUD --- ## SET_BLIP_SHOW_CONE  // 0x13127EC3665E8EE1 0xFF545AD8 void SET_BLIP_SHOW_CONE(Blip blip, BOOL toggle);  NativeDB Added Parameter 3: Any p2  ## Parameters * **blip**: * **toggle**:

### Parameters
* Blip blip
* BOOL toggle
* int hudColorIndex

### Return Value
* void

### Notes
* AP Hash: 0x0xFF545AD8
* Build: 323
* As of b2189, the third parameter sets the color of the cone (before b2189 it was ignored). Note that it uses HUD colors, not blip colors.

