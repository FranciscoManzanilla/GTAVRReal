# _SET_BLIP_FLASH_TIMER

--- ns: HUD --- ## SET_BLIP_FLASH_TIMER  // 0xD3CD6FD297AE87CC 0x8D5DF611 void SET_BLIP_FLASH_TIMER(Blip blip, int duration);  Flashes blip for time in milliseconds before stopping.  ## Parameters * **blip**: The blip to start flashing * **duration**: Time in milliseconds to flash the blip before stopping  ## Examples local blip = AddBlipForCoord(0, 0, 0)  -- flash blip for seven seconds then stop SetBlipFlashTimer(blip, 7000)  const blip = AddBlipForCoord(0, 0, 0)  //flash blip for seven seconds then stop SetBlipFlashTimer(blip, 7000)

### Parameters
* Blip blip
* int duration

### Return Value
* void

### Notes
* AP Hash: 0x0x8D5DF611
* Build: 323
* Adds up after viewing multiple R* scripts. I believe that the duration is in miliseconds.

