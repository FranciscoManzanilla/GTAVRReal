# _APPLY_PED_DAMAGE_DECAL

--- ns: PED --- ## APPLY_PED_DAMAGE_DECAL  // 0x397C38AA7B4A5F83 0x8A13A41F void APPLY_PED_DAMAGE_DECAL(Ped ped, int damageZone, float xOffset, float yOffset, float heading, float scale, float alpha, int variation, BOOL fadeIn, char* decalName);  scar blushing cs_flush_anger cs_flush_anger_face bruise bruise_large herpes ArmorBullet basic_dirt_cloth basic_dirt_skin cs_trev1_dirt  ## Parameters * **ped**: * **damageZone**: Refer to `ePedDecorationZone` in [GET_PED_DECORATION_ZONE_FROM_HASHES](#_0x9FD452BFBE7A7A8B) * **xOffset**: * **yOffset**: * **heading**: * **scale**: * **alpha**: * **variation**: * **fadeIn**: * **decalName**:

### Parameters
* Ped ped
* int damageZone
* float xOffset
* float yOffset
* float heading
* float scale
* float alpha
* int variation
* BOOL fadeIn
* const char* decalName

### Return Value
* void

### Notes
* AP Hash: 0x0x8A13A41F
* Build: 323
* enum eDamageZone
{
	DZ_Torso = 0,
	DZ_Head,
	DZ_LeftArm,
	DZ_RightArm,
	DZ_LeftLeg,
	DZ_RightLeg,
};

Decal Names:
scar
blushing
cs_flush_anger
cs_flush_anger_face
bruise
bruise_large
herpes
ArmorBullet
basic_dirt_cloth
basic_dirt_skin
cs_trev1_dirt

APPLY_PED_DAMAGE_DECAL(ped, 1, 0.5f, 0.513f, 0f, 1f, unk, 0, 0, "blushing");

