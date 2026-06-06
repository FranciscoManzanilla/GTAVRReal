# _IS_VEHICLE_WINDOW_INTACT

--- ns: VEHICLE --- ## IS_VEHICLE_WINDOW_INTACT  // 0x46E571A0E20D01F1 0xAC4EF23D BOOL IS_VEHICLE_WINDOW_INTACT(Vehicle vehicle, int windowIndex);  enum eWindowId { VEH_EXT_WINDOW_LF = 0, VEH_EXT_WINDOW_RF = 1, VEH_EXT_WINDOW_LR = 2, VEH_EXT_WINDOW_RR = 3, VEH_EXT_WINDOW_LM = 4, VEH_EXT_WINDOW_RM = 5, VEH_EXT_WINDSCREEN = 6, VEH_EXT_WINDSCREEN_R = 7, }  ## Parameters * **vehicle**: The vehicle handle * **windowIndex**: The index of the window  ## Return value

### Parameters
* Vehicle vehicle
* int windowIndex

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xAC4EF23D
* Build: 323
* This will return false if the window is broken, or rolled down.
Window indexes:
0 = Front Right Window
1 = Front Left Window
2 = Back Right Window
3 = Back Left Window


Those numbers go on for vehicles that have more than 4 doors with windows.

