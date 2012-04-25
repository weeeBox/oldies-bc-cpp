#include "AsAbstractClassError.h"
#include "AsAbstractClassError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsAbstractClassError_ref AsAbstractClassError::__createAsAbstractClassError(const AsString_ref& message)
{
	AsAbstractClassError_ref __reference(new AsAbstractClassError());
	__reference->__internalConstructAsAbstractClassError(message);
	return __reference;
}
 
AsAbstractClassError_ref AsAbstractClassError::__createAsAbstractClassError()
{
	AsAbstractClassError_ref __reference(new AsAbstractClassError());
	__reference->__internalConstructAsAbstractClassError();
	return __reference;
}
 
void AsAbstractClassError::__internalConstructAsAbstractClassError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsAbstractClassError();
}
 
void AsAbstractClassError::__internalConstructAsAbstractClassError()
{
	__internalConstructAsError();
	__$base$__("");
}
 
void AsAbstractClassError::__internalInitialiseAsAbstractClassError()
{
}
 
StaticInit AsAbstractClassError::__internalStaticInitializerAsAbstractClassError(&AsAbstractClassError::__internalStaticInit);
BOOL AsAbstractClassError::__internalStaticInitializedAsAbstractClassError = false;
 
void AsAbstractClassError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsAbstractClassError)
	{
		__internalStaticInitializedAsAbstractClassError = true;
		AsError::__internalStaticInit();
	}
}
 
AsAbstractClassError::AsAbstractClassError()
{
}
 
