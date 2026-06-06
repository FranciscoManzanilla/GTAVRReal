# _GET_PED_HEAD_BLEND_DATA

--- ns: PED aliases: ["_GET_PED_HEAD_BLEND_DATA"] --- ## GET_PED_HEAD_BLEND_DATA  // 0x2746BD9D88C5C5D0 0x44E1680C BOOL GET_PED_HEAD_BLEND_DATA(Ped ped, Any* headBlendData);  The pointer is to a padded struct that matches the arguments to SET_PED_HEAD_BLEND_DATA(...). There are 4 bytes of padding after each field. pass this struct in the second parameter typedef struct { int shapeFirst, shapeSecond, shapeThird; int skinFirst, skinSecond, skinThird; float shapeMix, skinMix, thirdMix; } headBlendData;  ## Parameters * **ped**: * **headBlendData**:  ## Return value

### Parameters
* Ped ped
* Any* headBlendData

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x44E1680C
* Build: 323
* The pointer is to a padded struct that matches the arguments to SET_PED_HEAD_BLEND_DATA(...). There are 4 bytes of padding after each field.
pass this struct in the second parameter 
struct headBlendData
{
    int shapeFirst;
    int padding1;
    int shapeSecond;
    int padding2;
    int shapeThird;
    int padding3;
    int skinFirst;
    int padding4;
    int skinSecond;
    int padding5;
    int skinThird;
    int padding6;
    float shapeMix;
    int padding7;
    float skinMix;
    int padding8;
    float thirdMix;
    int padding9;
    bool isParent;
};

