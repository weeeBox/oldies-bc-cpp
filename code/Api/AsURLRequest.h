#ifndef AsURLRequest_h__
#define AsURLRequest_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
#include "AsObject.h"
 
 
AS_CLASS(AsURLRequest);
 
class AsURLRequest : public AsObject
{
public:
	AS_OBJ(AsURLRequest, AsObject);
	
private:
	AsString_ref mUrl;
	AsString_ref mContentType;
	AsObject_ref mData;
	AsString_ref mDigest;
	AsString_ref mMethod;
	
public:
	virtual AsString_ref getContentType();
	virtual void setContentType(const AsString_ref& value);
	virtual AsObject_ref getData();
	virtual void setData(const AsObject_ref& value);
	virtual AsString_ref getDigest();
	virtual void setDigest(const AsString_ref& value);
	virtual AsString_ref getMethod();
	virtual void setMethod(const AsString_ref& value);
	virtual AsString_ref getUrl();
	virtual void setUrl(const AsString_ref& value);
	
	
public:
	static AsURLRequest_ref _as_create_AsURLRequest(const AsString_ref& url);
	static AsURLRequest_ref _as_create_AsURLRequest();
	
protected:
	void _as_construct_AsURLRequest(const AsString_ref& url);
	void _as_construct_AsURLRequest();
	
public:
	static void _as_static_init_AsURLRequest();
	
private:
	static bool _as_static_initialized_AsURLRequest;
	static AsStaticRefInitializer _as_static_initializer_AsURLRequest;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsURLRequest();
};
 
#endif // AsURLRequest_h__
