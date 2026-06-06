# _SET_PLAYER_CAN_DO_DRIVE_BY

--- ns: PLAYER --- ## SET_PLAYER_CAN_DO_DRIVE_BY  // 0x6E8834B52EC20C77 0xF4D99685 void SET_PLAYER_CAN_DO_DRIVE_BY(Player player, BOOL toggle);  Sets whether the player is able to do drive-bys in vehicle (shooting & aiming in vehicles), this also includes middle finger taunts.  This is a toggle, it does not have to be ran every frame.  ## Parameters * **player**: The player to target. * **toggle**: If set to false, disables the players ability to do drive bys.  ## Example SetPlayerCanDoDriveBy(PlayerId(), false)

### Parameters
* Player player
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0xF4D99685
* Build: 323
* Set whether this player should be able to do drive-bys.

"A drive-by is when a ped is aiming/shooting from vehicle. This includes middle finger taunts. By setting this value to false I confirm the player is unable to do all that. Tested on tick."


