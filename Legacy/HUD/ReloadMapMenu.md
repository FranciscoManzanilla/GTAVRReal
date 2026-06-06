# _RELOAD_MAP_MENU

--- ns: HUD aliases: ["0x2916A928514C9827"] --- ## RELOAD_MAP_MENU  // 0x2916A928514C9827 void RELOAD_MAP_MENU();  Forces the map menu to reload.  ## Examples if GetNumberOfReferencesOfScriptWithNameHash(`pausemenu_map`) > 0 then -- Ensure we're on the map screen ReloadMapMenu() print('Reloaded map menu!') end

### Return Value
* void

### Notes
* Build: 573

