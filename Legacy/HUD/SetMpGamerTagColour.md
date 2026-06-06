# _SET_MP_GAMER_TAG_COLOUR

--- ns: HUD aliases: ["0x613ED644950626AE"] --- ## SET_MP_GAMER_TAG_COLOUR  // 0x613ED644950626AE 0x7E3AA40A void SET_MP_GAMER_TAG_COLOUR(int gamerTagId, int component, int hudColorIndex);  Sets a gamer tag's component colour  ## Parameters * **gamerTagId**: a gamerTagId obtained using  for example: [`CREATE_FAKE_MP_GAMER_TAG`](#_0xBFEFE3321A3F5015). * **component**: a component id, see the full list here: [link](https://docs.fivem.net/docs/game-references/gamer-tags/#components-list) * **hudColorIndex**: a hud color index, see the full list here: [link](https://docs.fivem.net/docs/game-references/hud-colors/)  ## Examples local playerPed = PlayerPedId() --get our players ped local playerName = GetPlayerName(PlayerId()) --get our players name local gamerTagId = CreateFakeMpGamerTag(playerPed, playerName, 0, 0, "", 0) --create a gamer tag SetMpGamerTagColour(gamerTagId, 0, 129) --set component 0(GAMER_NAME) color to 129(HUD_COLOUR_YOGA)  Player player = Game.Player; //get our player int gamerTagId = CreateFakeMpGamerTag(player.Character.Handle, player.Name, false, false, null, 0); //create a gamer tag SetMpGamerTagColour(gamerTagId, 0, 129); //set component 0(GAMER_NAME) color to 129(HUD_COLOUR_YOGA)

### Parameters
* int gamerTagId
* int component
* int hudColorIndex

### Return Value
* void

### Notes
* AP Hash: 0x0x7E3AA40A
* Build: 323
* Sets a gamer tag's component colour

gamerTagId is obtained using for example CREATE_FAKE_MP_GAMER_TAG
Ranges from 0 to 255. 0 is grey health bar, ~50 yellow, 200 purple.

