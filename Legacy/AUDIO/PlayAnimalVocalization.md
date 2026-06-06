# _PLAY_ANIMAL_VOCALIZATION

--- ns: AUDIO aliases: ["0xEE066C7006C49C0A"] --- ## PLAY_ANIMAL_VOCALIZATION  // 0xEE066C7006C49C0A 0x498849F3 void PLAY_ANIMAL_VOCALIZATION(Ped pedHandle, int animalType, char* speechName);  enum eAudAnimalType { AUD_ANIMAL_NONE = -1, AUD_ANIMAL_BOAR = 0, AUD_ANIMAL_CHICKEN = 1, AUD_ANIMAL_DOG = 2, AUD_ANIMAL_DOG_ROTTWEILER = 3, AUD_ANIMAL_HORSE = 4, AUD_NUM_ANIMALS = 5 }  ## Parameters * **pedHandle**: * **animalType**: * **speechName**:

### Parameters
* Ped pedHandle
* int p1
* const char* speechName

### Return Value
* void

### Notes
* AP Hash: 0x0x498849F3
* Build: 323
* Plays sounds from a ped with chop model. For example it used to play bark or sniff sounds. p1 is always 3 or 4294967295 in decompiled scripts. By a quick disassembling I can assume that this arg is unused.
This native is works only when you call it on the ped with right model (ac_chop only ?)
Speech Name can be: CHOP_SNIFF_SEQ CHOP_WHINE CHOP_LICKS_MOUTH CHOP_PANT bark GROWL SNARL BARK_SEQ

