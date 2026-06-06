# _SET_BLIP_COLOUR

--- ns: HUD --- ## SET_BLIP_COLOUR  // 0x03D7FB09E75D6B7E 0xBB3C5A41 void SET_BLIP_COLOUR(Blip blip, int color);  ## Parameters * **blip**: The blip handle to set the color of * **color**: This can be a hex color code, or a [blip color](https://docs.fivem.net/docs/game-references/blips/#blip-colors).  ## Examples local coords = GetEntityCoords(PlayerPedId()) local blip = AddBlipForCoord(coords.x, coords.y, coords.z)  SetBlipColour(blip, 1) -- Sets the color to red (see list above)  -- You can also use a hex like so: SetBlipColour(blip, 0x3A7F3AFF) -- Our custom green

### Parameters
* Blip blip
* int color

### Return Value
* void

### Notes
* AP Hash: 0x0xBB3C5A41
* Build: 323
* https://gtaforums.com/topic/864881-all-blip-color-ids-pictured/

