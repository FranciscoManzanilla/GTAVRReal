# _SET_BLIP_FLASH_INTERVAL

--- ns: HUD --- ## SET_BLIP_FLASH_INTERVAL  // 0xAA51DB313C010A7E 0xEAF67377 void SET_BLIP_FLASH_INTERVAL(Blip blip, int interval);  Sets the interval in milliseconds before flashing the blip.  ## Parameters * **blip**: The blip to change flashing interval * **interval**: Interval in milliseconds before flashing the blip  ## Examples local blip = AddBlipForCoord(0, 0, 0)  SetBlipFlashes(blip, true)  -- flash the blip every 50ms SetBlipFlashInterval(blip, 50) const blip = AddBlipForCoord(0, 0, 0)  SetBlipFlashes(blip, true)  // flash the blip every 50ms SetBlipFlashInterval(blip, 50)

### Parameters
* Blip blip
* Any p1

### Return Value
* void

### Notes
* AP Hash: 0x0xEAF67377
* Build: 323

