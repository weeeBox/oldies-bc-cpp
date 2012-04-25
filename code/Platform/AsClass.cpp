#include "AsClass.h"
#include "AsClass.h"
#include "AsObject.h"
 
 
AsObject_ref AsClass::prototype()
{
	throw new AsNotImplementedError();
}
 
AsClass_ref AsClass::__createAsClass()
{
	AsClass_ref __reference(new AsClass());
	return __reference;
}
 
void AsClass::__internalInitialiseAsClass()
{
}
 
StaticInit AsClass::__internalStaticInitializerAsClass(&AsClass::__internalStaticInit);
BOOL AsClass::__internalStaticInitializedAsClass = false;
 
void AsClass::__internalStaticInit()
{
	if (!__internalStaticInitializedAsClass)
	{
		__internalStaticInitializedAsClass = true;
		AsObject::__internalStaticInit();
	}
}
 
AsClass::AsClass()
{
}
 
