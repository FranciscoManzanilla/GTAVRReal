# _START_PLAYER_SWITCH

--- ns: STREAMING --- ## START_PLAYER_SWITCH  // 0xFAA23F2CBA159D67 0x0829E975 void START_PLAYER_SWITCH(Ped from, Ped to, int flags, int switchType);  enum ePlayerSwitchType { SWITCH_TYPE_AUTO = 0, SWITCH_TYPE_LONG = 1, SWITCH_TYPE_MEDIUM = 2, SWITCH_TYPE_SHORT = 3 };   enum eSwitchFlags { SKIP_INTRO = 1, SKIP_OUTRO = 2, PAUSE_BEFORE_PAN = 4, PAUSE_BEFORE_OUTRO = 8, SKIP_PAN = 16, UNKNOWN_DEST = 32, DESCENT_ONLY = 64, START_FROM_CAMPOS = 128, PAUSE_BEFORE_ASCENT = 256, PAUSE_BEFORE_DESCENT = 512, ALLOW_SNIPER_AIM_INTRO = 1024, ALLOW_SNIPER_AIM_OUTRO = 2048, SKIP_TOP_DESCENT = 4096, SUPPRESS_OUTRO_FX = 8192, SUPPRESS_INTRO_FX = 16384, DELAY_ASCENT_FX = 32768 }  ## Parameters * **from**: * **to**: * **flags**: Refer to `eSwitchFlags` * **switchType**: Refer to `ePlayerSwitchType`

### Parameters
* Ped from
* Ped to
* int flags
* int switchType

### Return Value
* void

### Notes
* AP Hash: 0x0x0829E975
* Build: 323
* // this enum comes directly from R* so don't edit this
enum ePlayerSwitchTypes
{
  SWITCH_TYPE_AUTO,
 SWITCH_TYPE_LONG,
 SWITCH_TYPE_MEDIUM,
   SWITCH_TYPE_SHORT
};

Use GET_IDEAL_PLAYER_SWITCH_TYPE for the best switch type.

----------------------------------------------------

Examples from the decompiled scripts:

STREAMING::START_PLAYER_SWITCH(l_832._f3, PLAYER::PLAYER_PED_ID(), 0, 3);
STREAMING::START_PLAYER_SWITCH(l_832._f3, PLAYER::PLAYER_PED_ID(), 2050, 3);
STREAMING::START_PLAYER_SWITCH(PLAYER::PLAYER_PED_ID(), l_832._f3, 1024, 3);
STREAMING::START_PLAYER_SWITCH(g_141F27, PLAYER::PLAYER_PED_ID(), 513, v_14);

Note: DO NOT, use SWITCH_TYPE_LONG with flag 513. It leaves you stuck in the clouds. You'll have to call STOP_PLAYER_SWITCH() to return to your ped.

Flag 8 w/ SWITCH_TYPE_LONG will zoom out 3 steps, then zoom in 2/3 steps and stop on the 3rd and just hang there.
Flag 8 w/ SWITCH_TYPE_MEDIUM will zoom out 1 step, and just hang there.

