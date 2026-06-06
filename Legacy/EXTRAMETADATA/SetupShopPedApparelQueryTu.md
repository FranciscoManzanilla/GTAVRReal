# _SETUP_SHOP_PED_APPAREL_QUERY_TU

No description available.

### Parameters
* int character
* int p1
* int p2
* BOOL p3
* int p4
* int componentId

### Return Value
* int

### Notes
* AP Hash: 0x0x594E862C
* Build: 323
* character is 0 for Michael, 1 for Franklin, 2 for Trevor, 3 for freemode male, and 4 for freemode female.

componentId is between 0 and 11 and corresponds to the usual component slots.

p1 could be the outfit number; unsure.

p2 is usually -1; unknown function.

p3 appears to be for selecting between clothes and props; false is used with components/clothes, true is used with props.

p4 is usually -1; unknown function.

componentId is -1 when p3 is true in decompiled scripts.

