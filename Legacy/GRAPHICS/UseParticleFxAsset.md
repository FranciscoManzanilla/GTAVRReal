# _USE_PARTICLE_FX_ASSET

--- ns: GRAPHICS aliases: ["_SET_PTFX_ASSET_NEXT_CALL","_USE_PARTICLE_FX_ASSET_NEXT_CALL"] --- ## USE_PARTICLE_FX_ASSET  // 0x6C38AF3693A69A91 0x9C720B61 void USE_PARTICLE_FX_ASSET(char* name);  From the b678d decompiled scripts: GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("FM_Mission_Controler"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_apartment_mp"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_indep_fireworks"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_mp_cig_plane"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_mp_creator"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_ornate_heist"); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_prison_break_heist_station");  ## Parameters * **name**:

### Parameters
* const char* name

### Return Value
* void

### Notes
* AP Hash: 0x0x9C720B61
* Build: 323
* From the b678d decompiled scripts:

 GRAPHICS::USE_PARTICLE_FX_ASSET("FM_Mission_Controler");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_apartment_mp");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_indep_fireworks");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_mp_cig_plane");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_mp_creator");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_ornate_heist");
 GRAPHICS::USE_PARTICLE_FX_ASSET("scr_prison_break_heist_station");

Full list of particle effect dictionaries and effects by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/particleEffectsCompact.json

