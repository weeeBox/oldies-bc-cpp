#ifndef AsURLLoader_h__
#define AsURLLoader_h__
 
#include "AsBc.h"
 
#include "AsEventDispatcher.h"
 
#include "AsObject.h"
#include "AsString.h"
 
AS_CLASS(AsURLRequest);
 
AS_CLASS(AsURLLoader);
 
class AsURLLoader : public AsEventDispatcher
{
public:
	AS_OBJ(AsURLLoader, AsEventDispatcher);
	
public:
	AsObject_ref data;
	AsString_ref dataFormat;
	uint bytesLoaded;
	uint bytesTotal;
	
public:
	virtual void close();
	virtual void load(const AsURLRequest_ref& request);
	
	
public:
	static AsURLLoader_ref _as_create_AsURLLoader(const AsURLRequest_ref& request);
	static AsURLLoader_ref _as_create_AsURLLoader();
	
protected:
	void _as_construct_AsURLLoader(const AsURLRequest_ref& request);
	void _as_construct_AsURLLoader();
	void _as_init_fields_AsURLLoader();
	
public:
	static void _as_static_init_AsURLLoader();
	
private:
	static bool _as_static_initialized_AsURLLoader;
	static AsStaticRefInitializer _as_static_initializer_AsURLLoader;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsURLLoader();
};
 
#endif // AsURLLoader_h__
