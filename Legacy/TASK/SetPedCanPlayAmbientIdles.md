# _SET_PED_CAN_PLAY_AMBIENT_IDLES

--- ns: TASK aliases: ["0x8FD89A6240813FD0"] --- ## SET_PED_CAN_PLAY_AMBIENT_IDLES  // 0x8FD89A6240813FD0 0xB5AD044E void SET_PED_CAN_PLAY_AMBIENT_IDLES(Ped ped, BOOL bBlockIdleClips, BOOL bRemoveIdleClipIfPlaying);  Prevents a ped from playing ambient idle animations.  **Note:** This native must be called every frame.  ## Parameters * **ped**: Ped index. * **bBlockIdleClips**: If true, prevents a ped from playing an idle animation this frame. * **bRemoveIdleClipIfPlaying**: If true and the ped is playing an idle animation, the clip is stopped.

### Parameters
* Ped ped
* BOOL blockIdleClips
* BOOL removeIdleClipIfPlaying

### Return Value
* void

### Notes
* AP Hash: 0x0xB5AD044E
* Build: 323
* Appears only in fm_mission_controller and used only 3 times.

ped was always PLAYER_PED_ID()
p1 was always true
p2 was always true

