#include "AsLoaderContext.h"
 
bool AsLoaderContext::_as_static_initialized_AsLoaderContext = false;
AsStaticRefInitializer AsLoaderContext::_as_static_initializer_AsLoaderContext(_as_static_init_AsLoaderContext);
void AsLoaderContext::_as_static_init_AsLoaderContext()
{
	if (!_as_static_initialized_AsLoaderContext)
	{
		_as_static_initialized_AsLoaderContext = true;
	}
}
