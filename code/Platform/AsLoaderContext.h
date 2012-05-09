#ifndef AsLoaderContext_h__
#define AsLoaderContext_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
AS_CLASS(AsLoaderContext);
 
class AsLoaderContext : public AsObject
{
public:
	AS_OBJ(AsLoaderContext, AsObject);
	
	static void _as_static_init_AsLoaderContext();
	
private:
	static bool _as_static_initialized_AsLoaderContext;
	static AsStaticRefInitializer _as_static_initializer_AsLoaderContext;
};
 
#endif // AsLoaderContext_h__
