# _GET_SELECTED_PED_WEAPON

--- ns: WEAPON --- ## GET_SELECTED_PED_WEAPON  // 0x0A6DB4965674D243 0xD240123E Hash GET_SELECTED_PED_WEAPON(Ped ped);  ## Parameters * **ped**:  ## Return value

### Parameters
* Ped ped

### Return Value
* Hash

### Notes
* AP Hash: 0x0xD240123E
* Build: 323
* Returns the hash of the weapon. 

            var num7 = WEAPON::GET_SELECTED_PED_WEAPON(num4);
            sub_27D3(num7);
            switch (num7)
            {
                case 0x24B17070:

Also see WEAPON::GET_CURRENT_PED_WEAPON. Difference?

-------------------------------------------------------------------------

The difference is that GET_SELECTED_PED_WEAPON simply returns the ped's current weapon hash but GET_CURRENT_PED_WEAPON also checks the weapon object and returns true if the hash of the weapon object equals the weapon hash
Full list of weapons by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/weapons.json

