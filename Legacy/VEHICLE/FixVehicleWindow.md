# _FIX_VEHICLE_WINDOW

--- ns: VEHICLE --- ## FIX_VEHICLE_WINDOW  // 0x772282EBEB95E682 0x6B8E990D cs_type(Any) void FIX_VEHICLE_WINDOW(Vehicle vehicle, int windowIndex);  See eWindowId declared in [`IS_VEHICLE_WINDOW_INTACT`](#_0x46E571A0E20D01F1).  This function is coded to not work on vehicles of type: `CBike`, `Bmx`, `CBoat`, `CTrain`, and `CSubmarine`.  ## Parameters * **vehicle**: * **windowIndex**:  ## Return value

### Parameters
* Vehicle vehicle
* int windowIndex

### Return Value
* void

### Notes
* AP Hash: 0x0x6B8E990D
* Build: 323
* windowIndex:
0 = Front Left Window
1 = Front Right Window
2 = Rear Left Window
3 = Rear Right Window
4 = Front Windscreen
5 = Rear Windscreen
6 = Mid Left
7 = Mid Right
8 = Invalid

Additional information: FIX_VEHICLE_WINDOW (0x140D0BB88) references an array of bone vehicle indices (0x141D4B3E0) { 2Ah, 2Bh, 2Ch, 2Dh, 2Eh, 2Fh, 28h, 29h } that correspond to: window_lf, window_rf, window_lr, window_rr, window_lm, window_rm, windscreen, windscreen_r. This array is used by most vehwindow natives.

Also, this function is coded to not work on vehicles of type: CBike, Bmx, CBoat, CTrain, and CSubmarine.

