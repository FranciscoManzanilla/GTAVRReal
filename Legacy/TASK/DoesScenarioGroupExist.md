# _DOES_SCENARIO_GROUP_EXIST

--- ns: TASK --- ## DOES_SCENARIO_GROUP_EXIST  // 0xF9034C136C9E00D3 0x5F072EB9 BOOL DOES_SCENARIO_GROUP_EXIST(char* scenarioGroup);  Occurrences in the b617d scripts: "ARMY_GUARD", "ARMY_HELI", "Cinema_Downtown", "Cinema_Morningwood", "Cinema_Textile", "City_Banks", "Countryside_Banks", "DEALERSHIP", "GRAPESEED_PLANES", "KORTZ_SECURITY", "LOST_BIKERS", "LSA_Planes", "LSA_Planes", "MP_POLICE", "Observatory_Bikers", "POLICE_POUND1", "POLICE_POUND2", "POLICE_POUND3", "POLICE_POUND4", "POLICE_POUND5" "QUARRY", "SANDY_PLANES", "SCRAP_SECURITY", "SEW_MACHINE", "SOLOMON_GATE", "Triathlon_1_Start", "Triathlon_2_Start", "Triathlon_3_Start" Sometimes used with IS_SCENARIO_GROUP_ENABLED: if (TASK::DOES_SCENARIO_GROUP_EXIST("Observatory_Bikers") && (!TASK::IS_SCENARIO_GROUP_ENABLED("Observatory_Bikers"))) { else if (TASK::IS_SCENARIO_GROUP_ENABLED("BLIMP")) {  ## Parameters * **scenarioGroup**:  ## Return value

### Parameters
* const char* scenarioGroup

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x5F072EB9
* Build: 323
* Full list of scenario groups used in scripts by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/scenarioGroupNames.json
Occurrences in the b617d scripts:

"ARMY_GUARD",
"ARMY_HELI",
"Cinema_Downtown",
"Cinema_Morningwood",
"Cinema_Textile",
"City_Banks",
"Countryside_Banks",
"DEALERSHIP",
"GRAPESEED_PLANES",
"KORTZ_SECURITY",
"LOST_BIKERS",
"LSA_Planes",
"LSA_Planes",
"MP_POLICE",
"Observatory_Bikers", 
"POLICE_POUND1",
"POLICE_POUND2",
"POLICE_POUND3",
"POLICE_POUND4",
"POLICE_POUND5"
"QUARRY",
"SANDY_PLANES",
"SCRAP_SECURITY",
"SEW_MACHINE",
"SOLOMON_GATE",
"Triathlon_1_Start", 
"Triathlon_2_Start", 
"Triathlon_3_Start"

Sometimes used with IS_SCENARIO_GROUP_ENABLED:
if (TASK::DOES_SCENARIO_GROUP_EXIST("Observatory_Bikers") && (!TASK::IS_SCENARIO_GROUP_ENABLED("Observatory_Bikers"))) {
else if (TASK::IS_SCENARIO_GROUP_ENABLED("BLIMP")) {


