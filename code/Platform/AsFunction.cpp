#include "AsFunction.h"
#include "AsFunction.h"
 
 
AsFunction_ref AsFunction::__createAsFunction()
{
	AsFunction_ref __reference(new AsFunction());
	return __reference;
}
 
void AsFunction::__internalInitialiseAsFunction()
{
}
 
StaticInit AsFunction::__internalStaticInitializerAsFunction(&AsFunction::__internalStaticInit);
BOOL AsFunction::__internalStaticInitializedAsFunction = false;
 
void AsFunction::__internalStaticInit()
{
	if (!__internalStaticInitializedAsFunction)
	{
		__internalStaticInitializedAsFunction = true;
		AsObject::__internalStaticInit();
	}
}
 
AsFunction::AsFunction()
{
}
 
