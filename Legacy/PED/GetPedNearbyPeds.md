# _GET_PED_NEARBY_PEDS

--- ns: PED --- ## GET_PED_NEARBY_PEDS  // 0x23F8F5FC7E8C4A6B 0x4D3325F4 int GET_PED_NEARBY_PEDS(Ped ped, int* sizeAndPeds, int ignore);  Console/PC structure definitions and example: pastebin.com/SsFej963  For FiveM/Cfx.Re use-cases refer to: [`GET_GAME_POOL`](#_0x2B9D4F50).  ## Parameters * **ped**: * **sizeAndPeds**: * **ignore**: Ped type to ignore  ## Return value

### Parameters
* Ped ped
* Any* sizeAndPeds
* int ignore

### Return Value
* int

### Notes
* AP Hash: 0x0x4D3325F4
* Build: 323
* sizeAndPeds - is a pointer to an array. The array is filled with peds found nearby the ped supplied to the first argument.
ignore - ped type to ignore

Return value is the number of peds found and added to the array passed.

-----------------------------------

To make this work in most menu bases at least in C++ do it like so,

 Formatted Example: https://pastebin.com/D8an9wwp

-----------------------------------

Example: gtaforums.com/topic/789788-function-args-to-pedget-ped-nearby-peds/?p=1067386687

