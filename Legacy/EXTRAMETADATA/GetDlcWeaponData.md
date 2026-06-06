# _GET_DLC_WEAPON_DATA

No description available.

### Parameters
* int dlcWeaponIndex
* Any* outData

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xD88EC8EA
* Build: 323
* 
dlcWeaponIndex takes a number from 0 - GET_NUM_DLC_WEAPONS() - 1.
struct DlcWeaponData
{
int emptyCheck; //use DLC1::IS_CONTENT_ITEM_LOCKED on this
int padding1;
int weaponHash;
int padding2;
int unk;
int padding3;
int weaponCost;
int padding4;
int ammoCost;
int padding5;
int ammoType;
int padding6;
int defaultClipSize;
int padding7;
char nameLabel[64];
char descLabel[64];
char desc2Label[64]; // usually "the" + name
char upperCaseNameLabel[64];
};

