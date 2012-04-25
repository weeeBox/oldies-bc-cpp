#include "AsRangeError.h"
#include "AsRangeError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsRangeError_ref AsRangeError::__createAsRangeError(const AsString_ref& message)
{
	AsRangeError_ref __reference(new AsRangeError());
	__reference->__internalConstructAsRangeError(message);
	return __reference;
}
 
AsRangeError_ref AsRangeError::__createAsRangeError()
{
	AsRangeError_ref __reference(new AsRangeError());
	__reference->__internalConstructAsRangeError();
	return __reference;
}
 
void AsRangeError::__internalConstructAsRangeError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsRangeError();
}
 
void AsRangeError::__internalConstructAsRangeError()
{
	__internalConstructAsError();
	__$base$__("");
}
 
void AsRangeError::__internalInitialiseAsRangeError()
{
}
 
StaticInit AsRangeError::__internalStaticInitializerAsRangeError(&AsRangeError::__internalStaticInit);
BOOL AsRangeError::__internalStaticInitializedAsRangeError = false;
 
void AsRangeError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsRangeError)
	{
		__internalStaticInitializedAsRangeError = true;
		AsError::__internalStaticInit();
	}
}
 
AsRangeError::AsRangeError()
{
}
 
