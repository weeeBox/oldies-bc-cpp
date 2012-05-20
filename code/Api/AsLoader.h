#ifndef AsLoader_h__
#define AsLoader_h__
 
#include "AsBc.h"
 
#include "AsDisplayObjectContainer.h"
 
AS_CLASS(AsDisplayObject);
AS_CLASS(AsLoaderInfo);
AS_CLASS(AsURLRequest);
AS_CLASS(AsLoaderContext);
AS_CLASS(AsByteArray);
 
AS_CLASS(AsLoader);
 
class AsLoader : public AsDisplayObjectContainer
{
public:
	AS_OBJ(AsLoader, AsDisplayObjectContainer);
	
private:
	AsDisplayObject_ref mContent;
	AsLoaderInfo_ref mContentLoaderInfo;
	
public:
	virtual void close();
	virtual AsDisplayObject_ref getContent();
	virtual AsLoaderInfo_ref getContentLoaderInfo();
	virtual void load(const AsURLRequest_ref& request, const AsLoaderContext_ref& context);
	virtual void load(const AsURLRequest_ref& request);
	virtual void loadBytes(const AsByteArray_ref& bytes, const AsLoaderContext_ref& context);
	virtual void loadBytes(const AsByteArray_ref& bytes);
	virtual void unload();
	virtual void addChild(const AsDisplayObject_ref& child);
	virtual void addChildAt(const AsDisplayObject_ref& child, int index);
	virtual void removeChild(const AsDisplayObject_ref& child, bool dispose);
	virtual void removeChild(const AsDisplayObject_ref& child);
	virtual void removeChildAt(int index, bool dispose);
	virtual void removeChildAt(int index);
	virtual void setChildIndex(const AsDisplayObject_ref& child, int index);
	
	
public:
	static AsLoader_ref _as_create_AsLoader();
	
protected:
	void _as_construct_AsLoader();
	
public:
	static void _as_static_init_AsLoader();
	
private:
	static bool _as_static_initialized_AsLoader;
	static AsStaticRefInitializer _as_static_initializer_AsLoader;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsLoader();
};
 
#endif // AsLoader_h__
