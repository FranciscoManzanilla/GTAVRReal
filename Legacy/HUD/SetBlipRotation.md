# _SET_BLIP_ROTATION

--- ns: HUD --- ## SET_BLIP_ROTATION  // 0xF87683CDF73C3F6E 0x6B8F44FE void SET_BLIP_ROTATION(Blip blip, int rotation);  After some testing, looks like you need to use CEIL() on the rotation (vehicle/ped heading) before using it there.  ## Parameters * **blip**: * **rotation**:

### Parameters
* Blip blip
* int rotation

### Return Value
* void

### Notes
* AP Hash: 0x0x6B8F44FE
* Build: 323
* After some testing, looks like you need to use CEIL() on the rotation (vehicle/ped heading) before using it there.

