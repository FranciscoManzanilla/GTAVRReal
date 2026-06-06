# _SET_ENTITY_TRAFFICLIGHT_OVERRIDE

--- ns: ENTITY --- ## SET_ENTITY_TRAFFICLIGHT_OVERRIDE  // 0x57C5DB656185EAC4 0xC47F5B91 void SET_ENTITY_TRAFFICLIGHT_OVERRIDE(Entity entity, int state);  Changing traffic-lights will not change the behavior of NPCs.  Example: [here](https://www.gtaforums.com/topic/830463-help-with-turning-lights-green-and-causing-peds-to-crash-into-each-other/#entry1068211340)  enum eTrafficlightOverrideMode { TLO_RED = 0, TLO_AMBER = 1, TLO_GREEN = 2, TLO_NONE = 3 }  ## Parameters * **entity**: * **state**:

### Parameters
* Entity entity
* int state

### Return Value
* void

### Notes
* AP Hash: 0x0xC47F5B91
* Build: 323
* Example here: www.gtaforums.com/topic/830463-help-with-turning-lights-green-and-causing-peds-to-crash-into-each-other/#entry1068211340

0 = green
1 = red
2 = yellow
3 = reset changes
changing lights may not change the behavior of vehicles

