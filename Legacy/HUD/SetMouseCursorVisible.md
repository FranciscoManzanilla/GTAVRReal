# _SET_MOUSE_CURSOR_VISIBLE

--- ns: HUD aliases: ["0x98215325A695E78A", "_SET_MOUSE_CURSOR_VISIBLE_IN_MENUS"] --- ## SET_MOUSE_CURSOR_VISIBLE  // 0x98215325A695E78A void SET_MOUSE_CURSOR_VISIBLE(BOOL isVisible);  Toggles the visibility of the cursor. Do note that if the game loses focus and then regains it, the cursor will become visible again.  ## Parameters * **isVisible**: If the mouse cursor is visible  ## Examples Citizen.CreateThread(function() local menuType = "FE_MENU_VERSION_CORONA_LOBBY" ActivateFrontendMenu(GetHashKey(menuType), false, -1) --100 works as well Citizen.Wait(1000) --Hide frontend cursor SetMouseCursorVisible(false) end)

### Parameters
* BOOL toggle

### Return Value
* void

### Notes
* Build: 323
* Shows/hides the frontend cursor on the pause menu or similar menus.
Clicking off and then on the game window will show it again.

