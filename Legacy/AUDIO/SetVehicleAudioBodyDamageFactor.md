# _SET_VEHICLE_AUDIO_BODY_DAMAGE_FACTOR

--- ns: AUDIO aliases: ["0x01BB4D577D38BD9E"] --- ## SET_VEHICLE_AUDIO_BODY_DAMAGE_FACTOR  // 0x01BB4D577D38BD9E 0xE81FAC68 void SET_VEHICLE_AUDIO_BODY_DAMAGE_FACTOR(Vehicle vehicle, float intensity);  Vehicle will make a 'rattling' noise when decelerating  ## Parameters * **vehicle**: Vehicle to modify * **intensity**: A value 0.0 - 1.0. Higher the value, the more likely the vehicle is to make the sound while decelerating

### Parameters
* Vehicle vehicle
* float intensity

### Return Value
* void

### Notes
* AP Hash: 0x0xE81FAC68
* Build: 323
* intensity: 0.0f - 1.0f, only used once with 1.0f in R* Scripts (nigel2)
Makes an engine rattling noise when you decelerate, you need to be going faster to hear lower values

