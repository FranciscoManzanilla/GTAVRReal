# _SET_PED_HEAD_BLEND_DATA

--- ns: PED --- ## SET_PED_HEAD_BLEND_DATA  // 0x9414E18B9434C2FE 0x60746B88 void SET_PED_HEAD_BLEND_DATA(Ped ped, int shapeFirstID, int shapeSecondID, int shapeThirdID, int skinFirstID, int skinSecondID, int skinThirdID, float shapeMix, float skinMix, float thirdMix, BOOL isParent);  For more info and the list of faceIDs please refer to [this](https://gtaforums.com/topic/858970-all-gtao-face-ids-pedset-ped-head-blend-data-explained) topic. Note that the Skin and Shape IDs are shared. This native will use this same list for both Skin and Shape IDs.  **Other information:**  IDs start at zero and go Male Non-DLC, Female Non-DLC, Male DLC, and Female DLC.  This native function is often called prior to calling natives such as: - [`SetPedHairColor`](#_0xA23FE32C) - [`SetPedHeadOverlayColor`](#_0x78935A27) - [`SetPedHeadOverlay`](#_0xD28DBA90) - [`SetPedFaceFeature`](#_0x6C8D4458)  ## Parameters * **ped**: The ped entity * **shapeFirstID**: Controls the shape of the first ped's face * **shapeSecondID**: Controls the shape of the second ped's face * **shapeThirdID**: Controls the shape of the third ped's face * **skinFirstID**: Controls the first id's skin tone * **skinSecondID**: Controls the second id's skin tone * **skinThirdID**: Controls the third id's skin tone * **shapeMix**: 0.0 - 1.0 Of whose characteristics to take Mother -> Father (shapeFirstID and shapeSecondID) * **skinMix**: 0.0 - 1.0 Of whose characteristics to take Mother -> Father (skinFirstID and skinSecondID) * **thirdMix**: Overrides the others in favor of the third IDs. * **isParent**: IsParent is set for "children" of the player character's grandparents during old-gen character creation. It has unknown effect otherwise.  ## Examples -- Unfortunately, there's no clear way of getting the head blend data in lua out of the box, but there are wrappers: -- https://forum.cfx.re/t/small-c-export-event-wrapper-for-getpedheadblenddata/214611 SetPedHeadBlendData(PlayerPedId(), 0, 0, 0, 0, 0, 0, 0, 0, 0, false)

### Parameters
* Ped ped
* int shapeFirstID
* int shapeSecondID
* int shapeThirdID
* int skinFirstID
* int skinSecondID
* int skinThirdID
* float shapeMix
* float skinMix
* float thirdMix
* BOOL isParent

### Return Value
* void

### Notes
* AP Hash: 0x0x60746B88
* Build: 323
* The "shape" parameters control the shape of the ped's face. The "skin" parameters control the skin tone. ShapeMix and skinMix control how much the first and second IDs contribute,(typically mother and father.) ThirdMix overrides the others in favor of the third IDs. IsParent is set for "children" of the player character's grandparents during old-gen character creation. It has unknown effect otherwise.

The IDs start at zero and go Male Non-DLC, Female Non-DLC, Male DLC, and Female DLC.

!!!Can someone add working example for this???

try this:
       headBlendData headData;
       GET_PED_HEAD_BLEND_DATA(PLAYER_PED_ID(), &headData);

       SET_PED_HEAD_BLEND_DATA(PLAYER_PED_ID(), headData.shapeFirst, headData.shapeSecond, headData.shapeThird, headData.skinFirst, headData.skinSecond
          , headData.skinThird, headData.shapeMix, headData.skinMix, headData.skinThird, 0);


For more info please refer to this topic. 
gtaforums.com/topic/858970-all-gtao-face-ids-pedset-ped-head-blend-data-explained

