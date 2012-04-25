#include "AsArgumentError.h"
#include "AsArgumentError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsArgumentError_ref AsArgumentError::__createAsArgumentError(const AsString_ref& message)
{
	AsArgumentError_ref __reference(new AsArgumentError());
	__reference->__internalConstructAsArgumentError(message);
	return __reference;
}
 
AsArgumentError_ref AsArgumentError::__createAsArgumentError()
{
	AsArgumentError_ref __reference(new AsArgumentError());
	__reference->__internalConstructAsArgumentError();
	return __reference;
}
 
void AsArgumentError::__internalConstructAsArgumentError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsArgumentError();
}
 
void AsArgumentError::__internalConstructAsArgumentError()
{
	__internalConstructAsError();
	__$base$__("");
}
 
void AsArgumentError::__internalInitialiseAsArgumentError()
{
}
 
StaticInit AsArgumentError::__internalStaticInitializerAsArgumentError(&AsArgumentError::__internalStaticInit);
BOOL AsArgumentError::__internalStaticInitializedAsArgumentError = false;
 
void AsArgumentError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsArgumentError)
	{
		__internalStaticInitializedAsArgumentError = true;
		AsError::__internalStaticInit();
	}
}
 
AsArgumentError::AsArgumentError()
{
}
 
