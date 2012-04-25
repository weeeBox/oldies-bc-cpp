#ifndef AsLoaderContext_h__
#define AsLoaderContext_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsLoaderContext)
 
class AsLoaderContext : public AsObject
{
public:
	ASOBJ(AsLoaderContext, AsObject);
	
public:
	static AsLoaderContext_ref __createAsLoaderContext();
	void __internalInitialiseAsLoaderContext();
	
private:
	static StaticInit __internalStaticInitializerAsLoaderContext;
	static BOOL __internalStaticInitializedAsLoaderContext;
	
public:
	static void __internalStaticInit();
	
protected:
	AsLoaderContext();
};
 
#endif // AsLoaderContext_h__
