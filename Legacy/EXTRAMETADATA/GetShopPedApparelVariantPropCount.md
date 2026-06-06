# _GET_SHOP_PED_APPAREL_VARIANT_PROP_COUNT

No description available.

### Parameters
* Hash propHash

### Return Value
* int

### Notes
* Build: 791
* `propHash`: Ped helmet prop hash?
This native returns 1 when the player helmet has a visor (there is another prop index for the same helmet with closed/opened visor variant) that can be toggled. 0 if there's no alternative version with a visor for this helmet prop.

