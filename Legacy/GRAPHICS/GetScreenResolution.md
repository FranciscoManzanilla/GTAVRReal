# _GET_SCREEN_RESOLUTION

--- ns: GRAPHICS --- ## GET_SCREEN_RESOLUTION  // 0x888D57E407E63624 0x29F3572F void GET_SCREEN_RESOLUTION(int* x, int* y);  Hardcoded to always return 1280x720. Use [`_GET_ACTIVE_SCREEN_RESOLUTION`](#_0x873C9F3104101DD3) to retrieve the correct screen resolution.  ## Parameters * **x**: * **y**:

### Parameters
* int* x
* int* y

### Return Value
* void

### Notes
* AP Hash: 0x0x29F3572F
* Build: 323
* int screenresx,screenresy;
GET_SCREEN_RESOLUTION(&screenresx,&screenresy);

