# _SET_PED_POPULATION_BUDGET

--- ns: STREAMING --- ## SET_PED_POPULATION_BUDGET  // 0x8C95333CFC3340F3 0xD2D026CD void SET_PED_POPULATION_BUDGET(int budgetLevel);  Sets the memory budget level for ped population.  ## Parameters * **budgetLevel**: Ranges from `0` to `3`, where `0` is lowest (no peds) and `3` is the full budget level.

### Parameters
* int p0

### Return Value
* void

### Notes
* AP Hash: 0x0xD2D026CD
* Build: 323
* Control how many new (ambient?) peds will spawn in the game world.
Range for p0 seems to be 0-3, where 0 is none and 3 is the normal level.

