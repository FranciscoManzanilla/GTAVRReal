# _SET_OBJECT_PHYSICS_PARAMS

--- ns: OBJECT --- ## SET_OBJECT_PHYSICS_PARAMS  // 0xF6DF6E90DE7DF90F 0xE8D11C58 void SET_OBJECT_PHYSICS_PARAMS(Object object, float mass, float gravityFactor, float linearC, float linearV, float linearV2, float angularC, float angularV, float angularV2, float p9, float maxAngSpeed, float buoyancyFactor);  rage::phArchetypeDamp p9: Some phBoundGeometry margin value, limited to (0.0, 0.1) exclusive.  ## Parameters * **object**: * **mass**: * **gravityFactor**: * **linearC**: * **linearV**: * **linearV2**: * **angularC**: * **angularV**: * **angularV2**: * **p9**: * **maxAngSpeed**: * **buoyancyFactor**:

### Parameters
* Object object
* float weight
* float p2
* float p3
* float p4
* float p5
* float gravity
* float p7
* float p8
* float p9
* float p10
* float buoyancy

### Return Value
* void

### Notes
* AP Hash: 0x0xE8D11C58
* Build: 323
* Adjust the physics parameters of a prop, or otherwise known as "object". This is useful for simulated gravity.

Other parameters seem to be unknown.

p2: seems to be weight and gravity related. Higher value makes the obj fall faster. Very sensitive?
p3: seems similar to p2
p4: makes obj fall slower the higher the value
p5: similar to p4

