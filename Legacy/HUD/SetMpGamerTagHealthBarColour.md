# _SET_MP_GAMER_TAG_HEALTH_BAR_COLOUR

--- ns: HUD aliases: ["0x3158C77A7E888AB4","_SET_MP_GAMER_TAG_HEALTH_BAR_COLOR"] --- ## SET_MP_GAMER_TAG_HEALTH_BAR_COLOUR  // 0x3158C77A7E888AB4 0x5777EC77 void SET_MP_GAMER_TAG_HEALTH_BAR_COLOUR(int gamerTagId, int hudColorIndex);  Should be enabled as component (2). Has 0 alpha by default.  ## Parameters * **gamerTagId**: a gamerTagId obtained using  for example: [CREATE_FAKE_MP_GAMER_TAG](#_0xBFEFE3321A3F5015) * **hudColorIndex**: a hud color index, see the full list here: [link](https://docs.fivem.net/docs/game-references/hud-colors/)  ## Examples local playerPed = PlayerPedId() --get our players ped local playerName = GetPlayerName(PlayerId()) --get our players name local gamerTagId = CreateFakeMpGamerTag(playerPed, playerName, 0, 0, "", 0) --create a gamer tag SetMpGamerTagVisibility(gamerTagId, 2, 1)  --set the visibility of component 2(healthArmour) to true SetMpGamerTagAlpha(gamerTagId, 2, 255) --set the alpha of component 2(healthArmour) to 255 SetMpGamerTagHealthBarColor(gamerTagId, 129) --set component 2(healthArmour) color to 129(HUD_COLOUR_YOGA)  Player player = Game.Player; //get our player int gamerTagId = CreateFakeMpGamerTag(player.Character.Handle, player.Name, false, false, null, 0); //create a gamer tag SetMpGamerTagVisibility(gamerTagId, 2, true); //set the visibility of component 2(healthArmour) to true SetMpGamerTagAlpha(gamerTagId, 2, 255); //set the alpha of component 2(healthArmour) to 255 SetMpGamerTagHealthBarColor(gamerTagId, 129); //set component 2(healthArmour) color to 129(HUD_COLOUR_YOGA)

### Parameters
* int gamerTagId
* int hudColorIndex

### Return Value
* void

### Notes
* AP Hash: 0x0x5777EC77
* Build: 323
* Ranges from 0 to 255. 0 is grey health bar, ~50 yellow, 200 purple.
Should be enabled as flag (2). Has 0 opacity by default.

- This was _SET_MP_GAMER_TAG_HEALTH_BAR_COLOR,
-> Rockstar use the EU spelling of 'color' so I hashed the same name with COLOUR and it came back as the correct hash, so it has been corrected above.

