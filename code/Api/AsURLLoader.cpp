#include "AsURLLoader.h"
#include "AsURLRequest.h"
#include "AsNotImplementedError.h"
 
 
void AsURLLoader::close()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsURLLoader::load(const AsURLRequest_ref& request)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsURLLoader_ref AsURLLoader::_as_create_AsURLLoader(const AsURLRequest_ref& request)
{
	AsURLLoader_ref __instance = new AsURLLoader();
	__instance->_as_construct_AsURLLoader(request);
	return __instance;
}
 
AsURLLoader_ref AsURLLoader::_as_create_AsURLLoader()
{
	AsURLLoader_ref __instance = new AsURLLoader();
	__instance->_as_construct_AsURLLoader();
	return __instance;
}
 
void AsURLLoader::_as_construct_AsURLLoader(const AsURLRequest_ref& request)
{
	_as_init_fields_AsURLLoader();
	_as_construct_AsEventDispatcher();
	throw AS_NEW(AsNotImplementedError,());
}
 
inline void AsURLLoader::_as_construct_AsURLLoader()
{
	_as_construct_AsURLLoader(AS_NULL);
}
 
void AsURLLoader::_as_init_fields_AsURLLoader()
{
	dataFormat = ASL("text");
	bytesLoaded = 0;
	bytesTotal = 0;
}
 
bool AsURLLoader::_as_static_initialized_AsURLLoader = false;
AsStaticRefInitializer AsURLLoader::_as_static_initializer_AsURLLoader(_as_static_init_AsURLLoader);
void AsURLLoader::_as_static_init_AsURLLoader()
{
	if (!_as_static_initialized_AsURLLoader)
	{
		_as_static_initialized_AsURLLoader = true;
		_as_static_init_AsEventDispatcher();
	}
}
 
void AsURLLoader::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsEventDispatcher::_as_gc_mark();
		AS_GC_MARK(data)
		AS_GC_MARK(dataFormat)
	}
}
 
AsURLLoader::AsURLLoader() : 
  data(false),
  dataFormat(false)
{
}
