#include "AsLoader.h"
#include "AsURLRequest.h"
#include "AsLoaderContext.h"
#include "AsByteArray.h"
#include "AsDisplayObject.h"
#include "AsLoaderInfo.h"
#include "AsNotImplementedError.h"
#include "AsIllegalOperationError.h"
 
 
void AsLoader::close()
{
}
 
AsDisplayObject_ref AsLoader::getContent()
{
	return mContent;
}
 
AsLoaderInfo_ref AsLoader::getContentLoaderInfo()
{
	return mContentLoaderInfo;
}
 
void AsLoader::load(const AsURLRequest_ref& request, const AsLoaderContext_ref& context)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsLoader::load(const AsURLRequest_ref& request)
{
	load(request, AS_NULL);
}
 
void AsLoader::loadBytes(const AsByteArray_ref& bytes, const AsLoaderContext_ref& context)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsLoader::loadBytes(const AsByteArray_ref& bytes)
{
	loadBytes(bytes, AS_NULL);
}
 
void AsLoader::unload()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsLoader::addChild(const AsDisplayObject_ref& child)
{
	throw AS_NEW(AsIllegalOperationError,());
}
 
void AsLoader::addChildAt(const AsDisplayObject_ref& child, int index)
{
	throw AS_NEW(AsIllegalOperationError,());
}
 
void AsLoader::removeChild(const AsDisplayObject_ref& child, bool dispose)
{
	throw AS_NEW(AsIllegalOperationError,());
}
 
void AsLoader::removeChild(const AsDisplayObject_ref& child)
{
	removeChild(child, false);
}
 
void AsLoader::removeChildAt(int index, bool dispose)
{
	throw AS_NEW(AsIllegalOperationError,());
}
 
void AsLoader::removeChildAt(int index)
{
	removeChildAt(index, false);
}
 
void AsLoader::setChildIndex(const AsDisplayObject_ref& child, int index)
{
	throw AS_NEW(AsIllegalOperationError,());
}
 
AsLoader_ref AsLoader::_as_create_AsLoader()
{
	AsLoader_ref __instance = new AsLoader();
	__instance->_as_construct_AsLoader();
	return __instance;
}
 
void AsLoader::_as_construct_AsLoader()
{
	_as_construct_AsDisplayObjectContainer();
	mContentLoaderInfo = AS_NEW(AsLoaderInfo,());
}
 
bool AsLoader::_as_static_initialized_AsLoader = false;
AsStaticRefInitializer AsLoader::_as_static_initializer_AsLoader(_as_static_init_AsLoader);
void AsLoader::_as_static_init_AsLoader()
{
	if (!_as_static_initialized_AsLoader)
	{
		_as_static_initialized_AsLoader = true;
		_as_static_init_AsDisplayObjectContainer();
	}
}
 
void AsLoader::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsDisplayObjectContainer::_as_gc_mark();
		AS_GC_MARK(mContent)
		AS_GC_MARK(mContentLoaderInfo)
	}
}
 
AsLoader::AsLoader() : 
  mContent(false),
  mContentLoaderInfo(false)
{
}
