#include "AsError.h"
#include "AsString.h"
 
 
AsError_ref AsError::_as_create_AsError(const AsString_ref& message)
{
	AsError_ref __instance = new AsError();
	__instance->_as_construct_AsError(message);
	return __instance;
}
 
AsError_ref AsError::_as_create_AsError()
{
	AsError_ref __instance = new AsError();
	__instance->_as_construct_AsError();
	return __instance;
}
 
void AsError::_as_construct_AsError(const AsString_ref& message)
{
	this->message = message;
}
 
inline void AsError::_as_construct_AsError()
{
	_as_construct_AsError(ASL(""));
}
 
bool AsError::_as_static_initialized_AsError = false;
AsStaticRefInitializer AsError::_as_static_initializer_AsError(_as_static_init_AsError);
void AsError::_as_static_init_AsError()
{
	if (!_as_static_initialized_AsError)
	{
		_as_static_initialized_AsError = true;
	}
}
 
void AsError::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(message)
		AS_GC_MARK(name)
	}
}
 
AsError::AsError() : 
  message(false),
  name(false)
{
}
