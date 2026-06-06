# _CREATE_MODEL_HIDE

--- ns: ENTITY --- ## CREATE_MODEL_HIDE  // 0x8A97BCA30A0CE478 0x7BD5CF2F void CREATE_MODEL_HIDE(float x, float y, float z, float radius, Hash model, BOOL surviveMapReload);  Hides all objects of the specified model intersecting a sphere centered at (x, y, z) with the given radius. Network players do not see changes done with this. Use [`CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS`](#_0x3A52AE588830BF7F) if you only want to hide map objects and exclude those created by scripts. Use [`REMOVE_MODEL_HIDE`](#_0xD9E3006FB3CBD765) to make hidden objects visible again.  ## Parameters * **x**: X Coordinate of the hiding sphere center. * **y**: Y Coordinate of the hiding sphere center. * **z**: Z Coordinate of the hiding sphere center. * **radius**: Radius of the hiding sphere. * **model**: The object's model hash to hide. * **surviveMapReload**: If false, only currently loaded objects are hidden. If their map unloads (e.g. by moving away) and reloads, the objects will reappear.

### Parameters
* float x
* float y
* float z
* float radius
* Hash modelHash
* BOOL p5

### Return Value
* void

### Notes
* AP Hash: 0x0x7BD5CF2F
* Build: 323
* p5 = sets as true in scripts
Same as the comment for CREATE_MODEL_SWAP unless for some reason p5 affects it this only works with objects as well.

Network players do not see changes done with this.

