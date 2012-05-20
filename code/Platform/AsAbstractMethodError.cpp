#include "AsAbstractMethodError.h"
#include "AsString.h"
 
AsAbstractMethodError_ref AsAbstractMethodError::_as_create_AsAbstractMethodError(const AsString_ref& message)
{
	AsAbstractMethodError_ref __instance = new AsAbstractMethodError();
	__instance->_as_construct_AsAbstractMethodError(message);
	return __instance;
}
 
AsAbstractMethodError_ref AsAbstractMethodError::_as_create_AsAbstractMethodError()
{
	AsAbstractMethodError_ref __instance = new AsAbstractMethodError();
	__instance->_as_construct_AsAbstractMethodError();
	return __instance;
}
 
void AsAbstractMethodError::_as_construct_AsAbstractMethodError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsAbstractMethodError::_as_construct_AsAbstractMethodError()
{
	_as_construct_AsAbstractMethodError(ASL(""));
}
 
bool AsAbstractMethodError::_as_static_initialized_AsAbstractMethodError = false;
AsStaticRefInitializer AsAbstractMethodError::_as_static_initializer_AsAbstractMethodError(_as_static_init_AsAbstractMethodError);
void AsAbstractMethodError::_as_static_init_AsAbstractMethodError()
{
	if (!_as_static_initialized_AsAbstractMethodError)
	{
		_as_static_initialized_AsAbstractMethodError = true;
		_as_static_init_AsError();
	}
}
