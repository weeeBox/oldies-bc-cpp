#include "AsIllegalOperationError.h"
#include "AsString.h"
 
AsIllegalOperationError_ref AsIllegalOperationError::_as_create_AsIllegalOperationError(const AsString_ref& message)
{
	AsIllegalOperationError* __instance = new AsIllegalOperationError();
	__instance->_as_construct_AsIllegalOperationError(message);
	return __instance;
}
 
AsIllegalOperationError_ref AsIllegalOperationError::_as_create_AsIllegalOperationError()
{
	AsIllegalOperationError* __instance = new AsIllegalOperationError();
	__instance->_as_construct_AsIllegalOperationError();
	return __instance;
}
 
void AsIllegalOperationError::_as_construct_AsIllegalOperationError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsIllegalOperationError::_as_construct_AsIllegalOperationError()
{
	_as_construct_AsIllegalOperationError(AS_NULL);
}
 
bool AsIllegalOperationError::_as_static_initialized_AsIllegalOperationError = false;
AsStaticRefInitializer AsIllegalOperationError::_as_static_initializer_AsIllegalOperationError(_as_static_init_AsIllegalOperationError);
void AsIllegalOperationError::_as_static_init_AsIllegalOperationError()
{
	if (!_as_static_initialized_AsIllegalOperationError)
	{
		_as_static_initialized_AsIllegalOperationError = true;
		_as_static_init_AsError();
	}
}
