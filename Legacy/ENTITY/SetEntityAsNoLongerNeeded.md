# _SET_ENTITY_AS_NO_LONGER_NEEDED

--- ns: ENTITY --- ## SET_ENTITY_AS_NO_LONGER_NEEDED  // 0xB736A491E64A32CF 0xADF2267C void SET_ENTITY_AS_NO_LONGER_NEEDED(Entity* entity);  Marks the specified entity (ped, vehicle or object) as no longer needed. Entities marked as no longer needed, will be deleted as the engine sees fit.  ## Parameters * **entity**:

### Parameters
* Entity* entity

### Return Value
* void

### Notes
* AP Hash: 0x0xADF2267C
* Build: 323
* Marks the specified entity (ped, vehicle or object) as no longer needed if its population type is set to the mission type.
If the entity is ped, it will also clear their tasks immediately just like when CLEAR_PED_TASKS_IMMEDIATELY is called.
Entities marked as no longer needed, will be deleted as the engine sees fit.
Use this if you just want to just let the game delete the ped:
void MarkPedAsAmbientPed(Ped ped) {
  auto addr = getScriptHandleBaseAddress(ped);

  if (!addr) {
    return;
  }

  //the game uses only lower 4 bits as entity population type 
  BYTE origValue = *(BYTE *)(addr + 0xDA);
  *(BYTE *)(addr + 0xDA) = ((origValue & 0xF0) | ePopulationType::POPTYPE_RANDOM_AMBIENT);
}

