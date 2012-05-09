#include "AsRangeError.h"
#include "AsString.h"
 
AsRangeError_ref AsRangeError::_as_create_AsRangeError(const AsString_ref& message)
{
	AsRangeError* __instance = new AsRangeError();
	__instance->_as_construct_AsRangeError(message);
	return __instance;
}
 
AsRangeError_ref AsRangeError::_as_create_AsRangeError()
{
	AsRangeError* __instance = new AsRangeError();
	__instance->_as_construct_AsRangeError();
	return __instance;
}
 
void AsRangeError::_as_construct_AsRangeError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsRangeError::_as_construct_AsRangeError()
{
	_as_construct_AsRangeError(ASL(""));
}
 
bool AsRangeError::_as_static_initialized_AsRangeError = false;
AsStaticRefInitializer AsRangeError::_as_static_initializer_AsRangeError(_as_static_init_AsRangeError);
void AsRangeError::_as_static_init_AsRangeError()
{
	if (!_as_static_initialized_AsRangeError)
	{
		_as_static_initialized_AsRangeError = true;
		_as_static_init_AsError();
	}
}
