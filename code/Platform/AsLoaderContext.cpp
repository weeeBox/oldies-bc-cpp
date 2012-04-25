#include "AsLoaderContext.h"
#include "AsLoaderContext.h"
 
 
AsLoaderContext_ref AsLoaderContext::__createAsLoaderContext()
{
	AsLoaderContext_ref __reference(new AsLoaderContext());
	return __reference;
}
 
void AsLoaderContext::__internalInitialiseAsLoaderContext()
{
}
 
StaticInit AsLoaderContext::__internalStaticInitializerAsLoaderContext(&AsLoaderContext::__internalStaticInit);
BOOL AsLoaderContext::__internalStaticInitializedAsLoaderContext = false;
 
void AsLoaderContext::__internalStaticInit()
{
	if (!__internalStaticInitializedAsLoaderContext)
	{
		__internalStaticInitializedAsLoaderContext = true;
		AsObject::__internalStaticInit();
	}
}
 
AsLoaderContext::AsLoaderContext()
{
}
 
