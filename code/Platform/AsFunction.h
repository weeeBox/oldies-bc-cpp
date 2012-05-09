#ifndef AsFunction_h__
#define AsFunction_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
AS_CLASS(AsFunction);
 
class AsFunction : public AsObject
{
public:
	AS_OBJ(AsFunction, AsObject);
	
	static void _as_static_init_AsFunction();
	
private:
	static bool _as_static_initialized_AsFunction;
	static AsStaticRefInitializer _as_static_initializer_AsFunction;
};
 
#endif // AsFunction_h__
