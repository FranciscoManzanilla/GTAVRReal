# _GET_DLC_WEAPON_COMPONENT_DATA

No description available.

### Parameters
* int dlcWeaponIndex
* int dlcWeapCompIndex
* Any* ComponentDataPtr

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x4B83FCAF
* Build: 323
* p0 seems to be the weapon index
p1 seems to be the weapon component index
struct DlcComponentData{
int attachBone;
int padding1;
int bActiveByDefault;
int padding2;
int unk;
int padding3;
int componentHash;
int padding4;
int unk2;
int padding5;
int componentCost;
int padding6;
char nameLabel[64];
char descLabel[64];
};


