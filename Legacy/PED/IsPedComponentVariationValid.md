# _IS_PED_COMPONENT_VARIATION_VALID

--- ns: PED --- ## IS_PED_COMPONENT_VARIATION_VALID  // 0xE825F6B6CEA7671D 0x952ABD9A BOOL IS_PED_COMPONENT_VARIATION_VALID(Ped ped, int componentId, int drawableId, int textureId);  Checks if the component variation is valid, this works great for randomizing components using loops.  ## Parameters * **ped**: The ped handle. * **componentId**: The component id to check the variation of. Refer to [SET_PED_COMPONENT_VARIATION](#_0x262B14F48D29DE80). * **drawableId**: The drawable id to get the component variation of. Refer to [GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS](#_0x5FAF9754E789FB47). * **textureId**: The texture id to get the component variation of. Refer to [GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS](#_0xA6E7F1CEB523E171).  ## Return value

### Parameters
* Ped ped
* int componentId
* int drawableId
* int textureId

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x952ABD9A
* Build: 323
* Checks if the component variation is valid, this works great for randomizing components using loops.

List of component/props ID
gtaxscripting.blogspot.com/2016/04/gta-v-peds-component-and-props.html

Full list of ped components by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/pedComponentVariations.json

