#ifndef AsLoaderInfo_h__
#define AsLoaderInfo_h__
 
#include "AsBc.h"
 
#include "AsEventDispatcher.h"
 
#include "AsByteArray.h"
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
#include "AsString.h"
 
#ifndef AsLoader_h__
#include "AsLoader.h"
#else
AS_CLASS(AsLoader);
#endif // AsLoader_h__
#include "AsObject.h"
 
#ifndef AsEventDispatcher_h__
#include "AsEventDispatcher.h"
#else
AS_CLASS(AsEventDispatcher);
#endif // AsEventDispatcher_h__
 
 
AS_CLASS(AsLoaderInfo);
 
class AsLoaderInfo : public AsEventDispatcher
{
public:
	AS_OBJ(AsLoaderInfo, AsEventDispatcher);
	
public:
	virtual uint getActionScriptVersion();
	virtual AsByteArray_ref getBytes();
	virtual uint getBytesLoaded();
	virtual uint getBytesTotal();
	virtual bool getChildAllowsParent();
	virtual AsDisplayObject_ref getContent();
	virtual AsString_ref getContentType();
	virtual float getFrameRate();
	virtual int getHeight();
	virtual bool getIsURLInaccessible();
	virtual AsLoader_ref getLoader();
	virtual AsString_ref getLoaderURL();
	virtual AsObject_ref getParameters();
	virtual bool getParentAllowsChild();
	virtual bool getSameDomain();
	virtual AsEventDispatcher_ref getSharedEvents();
	virtual uint getSwfVersion();
	virtual AsString_ref getUrl();
	virtual int getWidth();
	
	static void _as_static_init_AsLoaderInfo();
	
private:
	static bool _as_static_initialized_AsLoaderInfo;
	static AsStaticRefInitializer _as_static_initializer_AsLoaderInfo;
};
 
#endif // AsLoaderInfo_h__
