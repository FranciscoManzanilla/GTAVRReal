# _RESTART_FRONTEND_MENU

--- ns: HUD --- ## RESTART_FRONTEND_MENU  // 0x10706DC6AD2D49C0 0xB07DAF98 void RESTART_FRONTEND_MENU(Hash menuHash, int highlightedTab);  Changes the current frontend menu to the desired frontend menu version.  ## Parameters * **menuHash**: Hash of the frontend menu. See [`ACTIVATE_FRONTEND_MENU`](#_0xEF01D36B9C9D0C7B) for the list of available menus. * **highlightedTab**: Menu ID (from PauseMenuLUT (in pause_menu_sp_content.gfx files), but the value - 1000) of which tab to have highlighted on the header, or -1.

### Parameters
* Hash menuHash
* int p1

### Return Value
* void

### Notes
* AP Hash: 0x0xB07DAF98
* Build: 323
* Before using this native click the native above and look at the decription.

Example:
int GetHash = Function.Call<int>(Hash.GET_HASH_KEY, "fe_menu_version_corona_lobby");
Function.Call(Hash.ACTIVATE_FRONTEND_MENU, GetHash, 0, -1);
Function.Call(Hash.RESTART_FRONTEND_MENU(GetHash, -1);

This native refreshes the frontend menu.

p1 = Hash of Menu
p2 = Unknown but always works with -1.

