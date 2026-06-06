# _TASK_RELOAD_WEAPON

--- ns: TASK --- ## TASK_RELOAD_WEAPON  // 0x62D2916F56B9CD2D 0xCA6E91FD void TASK_RELOAD_WEAPON(Ped ped, BOOL unused);  The 2nd param (unused) is not implemented. ----------------------------------------------------------------------- The only occurrence I found in a R* script ("assassin_construction.ysc.c4"): if (((v_3 < v_4) && (TASK::GET_SCRIPT_TASK_STATUS(PLAYER::PLAYER_PED_ID(), 0x6a67a5cc) != 1)) && (v_5 > v_3)) { TASK::TASK_RELOAD_WEAPON(PLAYER::PLAYER_PED_ID(), 1); }  ## Parameters * **ped**: * **unused**:

### Parameters
* Ped ped
* BOOL drawWeapon

### Return Value
* void

### Notes
* AP Hash: 0x0xCA6E91FD
* Build: 323
* The 2nd param (drawWeapon) is not implemented.

-----------------------------------------------------------------------

The only occurrence I found in a R* script ("assassin_construction.ysc.c4"):

            if (((v_3 < v_4) && (TASK::GET_SCRIPT_TASK_STATUS(PLAYER::PLAYER_PED_ID(), 0x6a67a5cc) != 1)) && (v_5 > v_3)) {
                TASK::TASK_RELOAD_WEAPON(PLAYER::PLAYER_PED_ID(), 1);
            }

