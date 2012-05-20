#include "AsArgumentError.h"
#include "AsString.h"
 
AsArgumentError_ref AsArgumentError::_as_create_AsArgumentError(const AsString_ref& message)
{
	AsArgumentError_ref __instance = new AsArgumentError();
	__instance->_as_construct_AsArgumentError(message);
	return __instance;
}
 
AsArgumentError_ref AsArgumentError::_as_create_AsArgumentError()
{
	AsArgumentError_ref __instance = new AsArgumentError();
	__instance->_as_construct_AsArgumentError();
	return __instance;
}
 
void AsArgumentError::_as_construct_AsArgumentError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsArgumentError::_as_construct_AsArgumentError()
{
	_as_construct_AsArgumentError(ASL(""));
}
 
bool AsArgumentError::_as_static_initialized_AsArgumentError = false;
AsStaticRefInitializer AsArgumentError::_as_static_initializer_AsArgumentError(_as_static_init_AsArgumentError);
void AsArgumentError::_as_static_init_AsArgumentError()
{
	if (!_as_static_initialized_AsArgumentError)
	{
		_as_static_initialized_AsArgumentError = true;
		_as_static_init_AsError();
	}
}
