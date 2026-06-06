# _GET_TATTOO_SHOP_DLC_ITEM_DATA

No description available.

### Parameters
* int characterType
* int decorationIndex
* Any* outComponent

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x2E9D628C
* Build: 323
* Character types:
0 = Michael, 
1 = Franklin, 
2 = Trevor, 
3 = MPMale, 
4 = MPFemale


enum TattooZoneData
{  
    ZONE_TORSO = 0,  
    ZONE_HEAD = 1,  
    ZONE_LEFT_ARM = 2,  
    ZONE_RIGHT_ARM = 3,  
    ZONE_LEFT_LEG = 4,  
    ZONE_RIGHT_LEG = 5,  
    ZONE_UNKNOWN = 6,
    ZONE_NONE = 7,  
};
struct outComponent
{
    // these vars are suffixed with 4 bytes of padding each.
    uint unk;
    int unk2;
    uint tattooCollectionHash;
    uint tattooNameHash;
    int unk3;
    TattooZoneData zoneId;
    uint unk4;
    uint unk5;
    // maybe more, not sure exactly, decompiled scripts are very vague around this part.
}

