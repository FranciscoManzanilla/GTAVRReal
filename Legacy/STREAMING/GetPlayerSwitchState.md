# _GET_PLAYER_SWITCH_STATE

--- ns: STREAMING --- ## GET_PLAYER_SWITCH_STATE  // 0x470555300D10B2A5 0x39A0E1F2 int GET_PLAYER_SWITCH_STATE();  ## Return value - Returns 5 if the player is in the air (in a state of switch). - Returns 12 if the player is either not in the air or if the switch is completed.  ## Examples local stateSwitch = GetPlayerSwitchState() if stateSwitch == 5 then -- Player is in the air elseif stateSwitch == 12 then -- Player is not in the air or switch is completed end  const stateSwitch = GetPlayerSwitchState(); if (stateSwitch == 5) { // Player is in the air } else if (stateSwitch == 12) { // Player is not in the air or switch is completed }  using static CitizenFX.Core.Native.API;  int stateSwitch = GetPlayerSwitchState(); if (stateSwitch == 5) { // Player is in the air } else if (stateSwitch == 12) { // Player is not in the air or switch is completed }

### Return Value
* int

### Notes
* AP Hash: 0x0x39A0E1F2
* Build: 323

