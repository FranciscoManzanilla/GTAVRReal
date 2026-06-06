# _SET_CUTSCENE_PED_PROP_VARIATION

--- ns: CUTSCENE aliases: ["0x0546524ADE2E9723"] --- ## SET_CUTSCENE_PED_PROP_VARIATION  // 0x0546524ADE2E9723 0x22E9A9DE void SET_CUTSCENE_PED_PROP_VARIATION(char* cutsceneEntName, int componentId, int drawableId, int textureId, Hash modelHash);  See [`SET_PED_PROP_INDEX`](#_0x93376B65A266EB5F)  ## Parameters * **cutsceneEntName**: i.e Michael, Trevor, MP_1, MP_4 * **componentId**: * **drawableId**: * **textureId**: * **modelHash**:

### Parameters
* const char* cutsceneEntName
* int componentId
* int drawableId
* int textureId
* Hash modelHash

### Return Value
* void

### Notes
* AP Hash: 0x0x22E9A9DE
* Build: 323
* Thanks R*! ;)

if ((l_161 == 0) || (l_161 == 2)) {
    sub_2ea27("Trying to set Jimmy prop variation");
    CUTSCENE::SET_CUTSCENE_PED_PROP_VARIATION("Jimmy_Boston", 1, 0, 0, 0);
}

Full list of ped components by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/pedComponentVariations.json

