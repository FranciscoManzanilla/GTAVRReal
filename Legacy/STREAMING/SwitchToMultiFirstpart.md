# _SWITCH_TO_MULTI_FIRSTPART

--- ns: STREAMING aliases: ["0xAAB3200ED59016BC", "_SWITCH_OUT_PLAYER"] --- ## SWITCH_TO_MULTI_FIRSTPART  // 0xAAB3200ED59016BC 0xFB4D062D void SWITCH_TO_MULTI_FIRSTPART(Ped ped, int flags, int switchType);  You can check if the player is in a Switch state with [`IS_PLAYER_SWITCH_IN_PROGRESS`](#_0xD9D2CFFF49FAB35F).  _**Note:** Doesn't act normally when used on Mount Chiliad._  ## Parameters * **ped**: The Ped (player character) for which the switch is initiated. * **flags**: Flags control various functionalities: 0 for normal behavior, 1 for no transition, and 255 for Switch IN. * **switchType**: Specifies the type of switch (0 - 3): 0 for 1 step towards ped, 1 for 3 steps out from ped, 2 for 1 step out from ped, and 3 for 1 step towards ped.  ## Examples  -- Check if the player is in a Switch "state" if not IsPlayerSwitchInProgress() then -- If the player is not already in a Switch state, initiate a Switch SwitchToMultiFirstPart(PlayerPedId(), 0, 1) -- In this case, switchType is set to 1, which means "3 steps out from ped" end  // Check if the player is in a Switch "state" if (!IsPlayerSwitchInProgress()) { // If the player is not already in a Switch state, initiate a Switch SwitchToMultiFirstPart(PlayerPedId(), 0, 1); // In this case, switchType is set to 1, which means "3 steps out from ped" according to the documentation }  using static CitizenFX.Core.Native.API;  // Check if the player is in a Switch "state" if (!IsPlayerSwitchInProgress()) { // If the player is not already in a Switch state, initiate a Switch SwitchToMultiFirstPart(API.PlayerPedId(), 0, 1); // In this case, switchType is set to 1, which means "3 steps out from ped" according to the documentation }

### Parameters
* Ped ped
* int flags
* int switchType

### Return Value
* void

### Notes
* AP Hash: 0x0xFB4D062D
* Build: 323
* doesn't act normally when used on mount chilliad
Flags is a bitflag:
2^n - Enabled Functionality:
0 - Skip camera rotate up
3 - Wait for SET_PLAYER_SWITCH_ESTABLISHING_SHOT / hang at last step. You will still need to run 0x74DE2E8739086740 to exit "properly" and then STOP_PLAYER_SWITCH
6 - Invert Switch Direction (false = out, true = in)
8 - Hang above ped

switchType: 0 - 3
0: 1 step towards ped
1: 3 steps out from ped
2: 1 step out from ped
3: 1 step towards ped

