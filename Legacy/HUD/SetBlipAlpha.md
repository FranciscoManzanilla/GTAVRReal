# _SET_BLIP_ALPHA

--- ns: HUD --- ## SET_BLIP_ALPHA  // 0x45FF974EEE1C8734 0xA791FCCD void SET_BLIP_ALPHA(Blip blip, int alpha);  Sets alpha-channel for blip color. Example: Blip blip = HUD::ADD_BLIP_FOR_ENTITY(entity); HUD::SET_BLIP_COLOUR(blip , 3); HUD::SET_BLIP_ALPHA(blip , 64);  ## Parameters * **blip**: * **alpha**:

### Parameters
* Blip blip
* int alpha

### Return Value
* void

### Notes
* AP Hash: 0x0xA791FCCD
* Build: 323
* Sets alpha-channel for blip color.

Example:

Blip blip = HUD::ADD_BLIP_FOR_ENTITY(entity);
HUD::SET_BLIP_COLOUR(blip , 3);
HUD::SET_BLIP_ALPHA(blip , 64);


