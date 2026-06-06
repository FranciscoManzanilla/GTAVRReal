# _RESTORE_PLAYER_STAMINA

--- ns: PLAYER --- ## RESTORE_PLAYER_STAMINA  // 0xA352C1B864CAFD33 0x62A93608 void RESTORE_PLAYER_STAMINA(Player player, float percentage); Adds a percentage to a players stamina  ## Parameters * **player**: player to restore the stamina for * **percentage**: seems to be a percentage that ranges from 0.0 to 1.0 (1.0 being 100%)  ## Examples Citizen.CreateThread(function() while true do RestorePlayerStamina(PlayerId(), 0.3) Citizen.Wait(15000) -- 15 seconds end end)

### Parameters
* Player player
* float p1

### Return Value
* void

### Notes
* AP Hash: 0x0x62A93608
* Build: 323

