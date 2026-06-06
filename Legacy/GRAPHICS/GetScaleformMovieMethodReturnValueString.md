# _GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_STRING

--- ns: GRAPHICS aliases: ["SITTING_TV", "_GET_SCALEFORM_MOVIE_FUNCTION_RETURN_STRING"] --- ## GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_STRING  // 0xE1E258829A885245 0x516862EB char* GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_STRING(int method_return);  Used to get a return value from a scaleform function. Returns a string in the same way GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT returns an int.  ## Parameters * **method_return**: The return value of this native: `EndScaleformMovieMethodReturn`  ## Return value Returns a string in the same way `GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT` returns an int.  ## Examples  local a = RequestScaleformMovie("translate") --scaleform gfx while not HasScaleformMovieLoaded(a) do Citizen.Wait(0) end BeginScaleformMovieMethod(a,"EnglishToChinese") --call function ScaleformMovieMethodAddParamPlayerNameString("Good") --input local b = EndScaleformMovieMethodReturnValue() while true do if IsScaleformMovieMethodReturnValueReady(b) then local c = GetScaleformMovieMethodReturnValueString(b) --output print(c) break end Citizen.Wait(0) end

### Parameters
* int methodReturn

### Return Value
* const char*

### Notes
* AP Hash: 0x0x516862EB
* Build: 323
* methodReturn: The return value of this native: END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE
Used to get a return value from a scaleform function. Returns a string in the same way GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT returns an int.

