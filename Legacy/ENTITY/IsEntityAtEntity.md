# _IS_ENTITY_AT_ENTITY

--- ns: ENTITY --- ## IS_ENTITY_AT_ENTITY  // 0x751B70C3D034E187 0xDABDCB52 BOOL IS_ENTITY_AT_ENTITY(Entity entity, Entity target, float xSize, float ySize, float zSize, BOOL highlightArea, BOOL do3dCheck, int transportMode);  Checks if entity is within the specified axis aligned box around the target entity.  enum eTransportMode { SCRIPT_TM_ANY = 0, SCRIPT_TM_ON_FOOT = 1, SCRIPT_TM_IN_VEHICLE = 2 };  ## Parameters * **entity**: The source entity handle. * **target**: The target entity handle. * **xSize**: The x size of the axis aligned box around the target entity to check. * **ySize**: The y size of the axis aligned box around the target entity to check. * **zSize**: The z size of the axis aligned box around the target entity to check. * **highlightArea**: * **do3dCheck**: If the check should be 2d or 3d. * **transportMode**: The transport mode. Returns early if the entity is not in that mode of transportation.  ## Return value

### Parameters
* Entity entity1
* Entity entity2
* float xSize
* float ySize
* float zSize
* BOOL p5
* BOOL p6
* int p7

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xDABDCB52
* Build: 323
* Checks if entity1 is within the box defined by x/y/zSize of entity2.

Last three parameters are almost alwasy p5 = 0, p6 = 1, p7 = 0

