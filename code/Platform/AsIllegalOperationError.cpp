#include "AsIllegalOperationError.h"
#include "AsIllegalOperationError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsIllegalOperationError_ref AsIllegalOperationError::__createAsIllegalOperationError(const AsString_ref& message)
{
	AsIllegalOperationError_ref __reference(new AsIllegalOperationError());
	__reference->__internalConstructAsIllegalOperationError(message);
	return __reference;
}
 
AsIllegalOperationError_ref AsIllegalOperationError::__createAsIllegalOperationError()
{
	AsIllegalOperationError_ref __reference(new AsIllegalOperationError());
	__reference->__internalConstructAsIllegalOperationError();
	return __reference;
}
 
void AsIllegalOperationError::__internalConstructAsIllegalOperationError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsIllegalOperationError();
}
 
void AsIllegalOperationError::__internalConstructAsIllegalOperationError()
{
	__internalConstructAsError();
	__$base$__(null);
}
 
void AsIllegalOperationError::__internalInitialiseAsIllegalOperationError()
{
}
 
StaticInit AsIllegalOperationError::__internalStaticInitializerAsIllegalOperationError(&AsIllegalOperationError::__internalStaticInit);
BOOL AsIllegalOperationError::__internalStaticInitializedAsIllegalOperationError = false;
 
void AsIllegalOperationError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsIllegalOperationError)
	{
		__internalStaticInitializedAsIllegalOperationError = true;
		AsError::__internalStaticInit();
	}
}
 
AsIllegalOperationError::AsIllegalOperationError()
{
}
 
