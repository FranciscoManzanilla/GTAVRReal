# _SET_ENTITY_ALPHA

--- ns: ENTITY --- ## SET_ENTITY_ALPHA  // 0x44A0870B7E92D7C0 0xAE667CB0 void SET_ENTITY_ALPHA(Entity entity, int alphaLevel, cs_type(int) BOOL skin);  This native sets the entity's alpha level.  ## Parameters * **entity**: The entity to change the alpha for. * **alphaLevel**: The alpha level ranges from 0 to 255, but changes occur every 20% (every 51). * **skin**: Whether or not to change the alpha of the entity's skin.  ## Examples  SetEntityAlpha(PlayerPedId(), 51, false)  SetEntityAlpha(PlayerPedId(), 51, false);  using static CitizenFX.Core.Native.API; // ...  SetEntityAlpha(PlayerPedId(), 51, 0);  // or the preferred use of C# wrapper Game.PlayerPed.Opacity = 51;

### Parameters
* Entity entity
* int alphaLevel
* BOOL skin

### Return Value
* void

### Notes
* AP Hash: 0x0xAE667CB0
* Build: 323
* skin - everything alpha except skin
Set entity alpha level. Ranging from 0 to 255 but chnages occur after every 20 percent (after every 51).

