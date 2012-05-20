#include "AsURLRequest.h"
#include "AsString.h"
#include "AsObject.h"
 
 
AsString_ref AsURLRequest::getContentType()
{
	return mContentType;
}
 
void AsURLRequest::setContentType(const AsString_ref& value)
{
	mContentType = value;
}
 
AsObject_ref AsURLRequest::getData()
{
	return (AsObject_ref)(mData);
}
 
void AsURLRequest::setData(const AsObject_ref& value)
{
	mData = (AsObject_ref)(value);
}
 
AsString_ref AsURLRequest::getDigest()
{
	return mDigest;
}
 
void AsURLRequest::setDigest(const AsString_ref& value)
{
	mDigest = value;
}
 
AsString_ref AsURLRequest::getMethod()
{
	return mMethod;
}
 
void AsURLRequest::setMethod(const AsString_ref& value)
{
	mMethod = value;
}
 
AsString_ref AsURLRequest::getUrl()
{
	return mUrl;
}
 
void AsURLRequest::setUrl(const AsString_ref& value)
{
	mUrl = value;
}
 
AsURLRequest_ref AsURLRequest::_as_create_AsURLRequest(const AsString_ref& url)
{
	AsURLRequest_ref __instance = new AsURLRequest();
	__instance->_as_construct_AsURLRequest(url);
	return __instance;
}
 
AsURLRequest_ref AsURLRequest::_as_create_AsURLRequest()
{
	AsURLRequest_ref __instance = new AsURLRequest();
	__instance->_as_construct_AsURLRequest();
	return __instance;
}
 
void AsURLRequest::_as_construct_AsURLRequest(const AsString_ref& url)
{
	mUrl = url;
}
 
inline void AsURLRequest::_as_construct_AsURLRequest()
{
	_as_construct_AsURLRequest(AS_NULL);
}
 
bool AsURLRequest::_as_static_initialized_AsURLRequest = false;
AsStaticRefInitializer AsURLRequest::_as_static_initializer_AsURLRequest(_as_static_init_AsURLRequest);
void AsURLRequest::_as_static_init_AsURLRequest()
{
	if (!_as_static_initialized_AsURLRequest)
	{
		_as_static_initialized_AsURLRequest = true;
	}
}
 
void AsURLRequest::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mUrl)
		AS_GC_MARK(mContentType)
		AS_GC_MARK(mData)
		AS_GC_MARK(mDigest)
		AS_GC_MARK(mMethod)
	}
}
 
AsURLRequest::AsURLRequest() : 
  mUrl(false),
  mContentType(false),
  mData(false),
  mDigest(false),
  mMethod(false)
{
}
