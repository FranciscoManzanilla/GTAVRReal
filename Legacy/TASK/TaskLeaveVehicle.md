# _TASK_LEAVE_VEHICLE

--- ns: TASK --- ## TASK_LEAVE_VEHICLE  // 0xD3DBCE61A490BE02 0x7B1141C6 void TASK_LEAVE_VEHICLE(Ped ped, Vehicle vehicle, int flags);  Flags from decompiled scripts: 0 = normal exit and closes door. 1 = normal exit and closes door. 16 = teleports outside, door kept closed.  (This flag does not seem to work for the front seats in buses, NPCs continue to exit normally) 64 = normal exit and closes door, maybe a bit slower animation than 0. 256 = normal exit but does not close the door. 4160 = ped is throwing himself out, even when the vehicle is still. 262144 = ped moves to passenger seat first, then exits normally Others to be tried out: 320, 512, 131072.  ## Parameters * **ped**: * **vehicle**: * **flags**:

### Parameters
* Ped ped
* Vehicle vehicle
* int flags

### Return Value
* void

### Notes
* AP Hash: 0x0x7B1141C6
* Build: 323
* Flags from decompiled scripts:
0 = normal exit and closes door.
1 = normal exit and closes door.
16 = teleports outside, door kept closed.
64 = normal exit and closes door, maybe a bit slower animation than 0.
256 = normal exit but does not close the door.
4160 = ped is throwing himself out, even when the vehicle is still.
262144 = ped moves to passenger seat first, then exits normally

Others to be tried out: 320, 512, 131072.

