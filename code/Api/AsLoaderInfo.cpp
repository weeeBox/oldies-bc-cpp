#include "AsLoaderInfo.h"
#include "AsNotImplementedError.h"
 
uint AsLoaderInfo::getActionScriptVersion()
{
	return (uint)(3);
}
 
AsByteArray_ref AsLoaderInfo::getBytes()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsLoaderInfo::getBytesLoaded()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsLoaderInfo::getBytesTotal()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsLoaderInfo::getChildAllowsParent()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsDisplayObject_ref AsLoaderInfo::getContent()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsLoaderInfo::getContentType()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsLoaderInfo::getFrameRate()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsLoaderInfo::getHeight()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsLoaderInfo::getIsURLInaccessible()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsLoader_ref AsLoaderInfo::getLoader()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsLoaderInfo::getLoaderURL()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsObject_ref AsLoaderInfo::getParameters()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsLoaderInfo::getParentAllowsChild()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsLoaderInfo::getSameDomain()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsEventDispatcher_ref AsLoaderInfo::getSharedEvents()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsLoaderInfo::getSwfVersion()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsLoaderInfo::getUrl()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsLoaderInfo::getWidth()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsLoaderInfo::_as_static_initialized_AsLoaderInfo = false;
AsStaticRefInitializer AsLoaderInfo::_as_static_initializer_AsLoaderInfo(_as_static_init_AsLoaderInfo);
void AsLoaderInfo::_as_static_init_AsLoaderInfo()
{
	if (!_as_static_initialized_AsLoaderInfo)
	{
		_as_static_initialized_AsLoaderInfo = true;
		_as_static_init_AsEventDispatcher();
	}
}
