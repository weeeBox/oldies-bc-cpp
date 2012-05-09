#include "AsClass.h"
#include "AsNotImplementedError.h"
 
AsObject_ref AsClass::getPrototype()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsClass::_as_static_initialized_AsClass = false;
AsStaticRefInitializer AsClass::_as_static_initializer_AsClass(_as_static_init_AsClass);
void AsClass::_as_static_init_AsClass()
{
	if (!_as_static_initialized_AsClass)
	{
		_as_static_initialized_AsClass = true;
	}
}
