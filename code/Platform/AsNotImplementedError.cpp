#include "AsNotImplementedError.h"
#include "AsNotImplementedError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsNotImplementedError_ref AsNotImplementedError::__createAsNotImplementedError(const AsString_ref& message)
{
	AsNotImplementedError_ref __reference(new AsNotImplementedError());
	__reference->__internalConstructAsNotImplementedError(message);
	return __reference;
}
 
AsNotImplementedError_ref AsNotImplementedError::__createAsNotImplementedError()
{
	AsNotImplementedError_ref __reference(new AsNotImplementedError());
	__reference->__internalConstructAsNotImplementedError();
	return __reference;
}
 
void AsNotImplementedError::__internalConstructAsNotImplementedError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsNotImplementedError();
}
 
void AsNotImplementedError::__internalConstructAsNotImplementedError()
{
	__internalConstructAsError();
	__$base$__("");
}
 
void AsNotImplementedError::__internalInitialiseAsNotImplementedError()
{
}
 
StaticInit AsNotImplementedError::__internalStaticInitializerAsNotImplementedError(&AsNotImplementedError::__internalStaticInit);
BOOL AsNotImplementedError::__internalStaticInitializedAsNotImplementedError = false;
 
void AsNotImplementedError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsNotImplementedError)
	{
		__internalStaticInitializedAsNotImplementedError = true;
		AsError::__internalStaticInit();
	}
}
 
AsNotImplementedError::AsNotImplementedError()
{
}
 
