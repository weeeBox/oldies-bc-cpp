#ifndef AsClass_h__
#define AsClass_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsObject.h"
 
 
AS_CLASS(AsClass);
 
class AsClass : public AsObject
{
public:
	AS_OBJ(AsClass, AsObject);
	
public:
	virtual AsObject_ref getPrototype();
	
	static void _as_static_init_AsClass();
	
private:
	static bool _as_static_initialized_AsClass;
	static AsStaticRefInitializer _as_static_initializer_AsClass;
};
 
#endif // AsClass_h__
