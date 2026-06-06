# _SET_ENTITY_PROOFS

--- ns: ENTITY --- ## SET_ENTITY_PROOFS  // 0xFAEE099C6F890BB8 0x7E9EAB66 void SET_ENTITY_PROOFS(Entity entity, BOOL bulletProof, BOOL fireProof, BOOL explosionProof, BOOL collisionProof, BOOL meleeProof, BOOL steamProof, BOOL p7, BOOL drownProof);  Enable / disable each type of damage. -------------- p7 is to to '1' in am_mp_property_ext/int: entity::set_entity_proofs(uParam0->f_19, true, true, true, true, true, true, 1, true);  ## Parameters * **entity**: * **bulletProof**: * **fireProof**: * **explosionProof**: * **collisionProof**: * **meleeProof**: * **steamProof**: * **p7**: * **drownProof**:

### Parameters
* Entity entity
* BOOL bulletProof
* BOOL fireProof
* BOOL explosionProof
* BOOL collisionProof
* BOOL meleeProof
* BOOL steamProof
* BOOL dontResetOnCleanup
* BOOL waterProof

### Return Value
* void

### Notes
* AP Hash: 0x0x7E9EAB66
* Build: 323
* Enable / disable each type of damage.

waterProof is damage related to water not drowning
--------------
p7 is to to '1' in am_mp_property_ext/int: ENTITY::SET_ENTITY_PROOFS(uParam0->f_19, true, true, true, true, true, true, 1, true);


