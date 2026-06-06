# _SET_ANIMAL_MOOD

--- ns: AUDIO --- ## SET_ANIMAL_MOOD  // 0xCC97B29285B1DC3B 0x3EA7C6CB void SET_ANIMAL_MOOD(Ped animal, int mood);  enum eAudAnimalMood { AUD_ANIMAL_MOOD_ANGRY = 0, AUD_ANIMAL_MOOD_PLAYFUL = 1,  AUD_ANIMAL_MOOD_NUM_MOODS = 2 }   ## Parameters * **animal**: * **mood**: Refer to `eAudAnimalMood`

### Parameters
* Ped animal
* int mood

### Return Value
* void

### Notes
* AP Hash: 0x0x3EA7C6CB
* Build: 323
* mood can be 0 or 1 (it's not a boolean value!). Effects audio of the animal.

