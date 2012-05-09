#include "AsNotImplementedError.h"
#include "AsString.h"
 
AsNotImplementedError_ref AsNotImplementedError::_as_create_AsNotImplementedError(const AsString_ref& message)
{
	AsNotImplementedError* __instance = new AsNotImplementedError();
	__instance->_as_construct_AsNotImplementedError(message);
	return __instance;
}
 
AsNotImplementedError_ref AsNotImplementedError::_as_create_AsNotImplementedError()
{
	AsNotImplementedError* __instance = new AsNotImplementedError();
	__instance->_as_construct_AsNotImplementedError();
	return __instance;
}
 
void AsNotImplementedError::_as_construct_AsNotImplementedError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsNotImplementedError::_as_construct_AsNotImplementedError()
{
	_as_construct_AsNotImplementedError(ASL(""));
}
 
bool AsNotImplementedError::_as_static_initialized_AsNotImplementedError = false;
AsStaticRefInitializer AsNotImplementedError::_as_static_initializer_AsNotImplementedError(_as_static_init_AsNotImplementedError);
void AsNotImplementedError::_as_static_init_AsNotImplementedError()
{
	if (!_as_static_initialized_AsNotImplementedError)
	{
		_as_static_initialized_AsNotImplementedError = true;
		_as_static_init_AsError();
	}
}
