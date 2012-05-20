#include "AsAbstractClassError.h"
#include "AsString.h"
 
AsAbstractClassError_ref AsAbstractClassError::_as_create_AsAbstractClassError(const AsString_ref& message)
{
	AsAbstractClassError_ref __instance = new AsAbstractClassError();
	__instance->_as_construct_AsAbstractClassError(message);
	return __instance;
}
 
AsAbstractClassError_ref AsAbstractClassError::_as_create_AsAbstractClassError()
{
	AsAbstractClassError_ref __instance = new AsAbstractClassError();
	__instance->_as_construct_AsAbstractClassError();
	return __instance;
}
 
void AsAbstractClassError::_as_construct_AsAbstractClassError(const AsString_ref& message)
{
	_as_construct_AsError(message);
}
 
inline void AsAbstractClassError::_as_construct_AsAbstractClassError()
{
	_as_construct_AsAbstractClassError(ASL(""));
}
 
bool AsAbstractClassError::_as_static_initialized_AsAbstractClassError = false;
AsStaticRefInitializer AsAbstractClassError::_as_static_initializer_AsAbstractClassError(_as_static_init_AsAbstractClassError);
void AsAbstractClassError::_as_static_init_AsAbstractClassError()
{
	if (!_as_static_initialized_AsAbstractClassError)
	{
		_as_static_initialized_AsAbstractClassError = true;
		_as_static_init_AsError();
	}
}
