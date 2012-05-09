#include "AsFunction.h"
 
bool AsFunction::_as_static_initialized_AsFunction = false;
AsStaticRefInitializer AsFunction::_as_static_initializer_AsFunction(_as_static_init_AsFunction);
void AsFunction::_as_static_init_AsFunction()
{
	if (!_as_static_initialized_AsFunction)
	{
		_as_static_initialized_AsFunction = true;
	}
}
