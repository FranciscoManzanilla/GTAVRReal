# _GET_ENTITY_OF_TYPE_ATTACHED_TO_ENTITY

No description available.

### Parameters
* Entity entity
* Hash modelHash

### Return Value
* Entity

### Notes
* Build: 1180
* Gets the handle of an entity with a specific model hash attached to another entity, such as an object attached to a ped.
 This native does not appear to have anything to do with pickups as in scripts it is used with objects.

Example from fm_mission_controller_2020.c:

iVar8 = ENTITY::GET_ENTITY_OF_TYPE_ATTACHED_TO_ENTITY(bParam0->f_9, joaat("p_cs_clipboard"));

