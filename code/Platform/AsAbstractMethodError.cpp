#include "AsAbstractMethodError.h"
#include "AsAbstractMethodError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsAbstractMethodError_ref AsAbstractMethodError::__createAsAbstractMethodError(const AsString_ref& message)
{
	AsAbstractMethodError_ref __reference(new AsAbstractMethodError());
	__reference->__internalConstructAsAbstractMethodError(message);
	return __reference;
}
 
AsAbstractMethodError_ref AsAbstractMethodError::__createAsAbstractMethodError()
{
	AsAbstractMethodError_ref __reference(new AsAbstractMethodError());
	__reference->__internalConstructAsAbstractMethodError();
	return __reference;
}
 
void AsAbstractMethodError::__internalConstructAsAbstractMethodError(const AsString_ref& message)
{
	__internalConstructAsError(message);
	__internalInitialiseAsAbstractMethodError();
}
 
void AsAbstractMethodError::__internalConstructAsAbstractMethodError()
{
	__internalConstructAsError();
	__$base$__("");
}
 
void AsAbstractMethodError::__internalInitialiseAsAbstractMethodError()
{
}
 
StaticInit AsAbstractMethodError::__internalStaticInitializerAsAbstractMethodError(&AsAbstractMethodError::__internalStaticInit);
BOOL AsAbstractMethodError::__internalStaticInitializedAsAbstractMethodError = false;
 
void AsAbstractMethodError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsAbstractMethodError)
	{
		__internalStaticInitializedAsAbstractMethodError = true;
		AsError::__internalStaticInit();
	}
}
 
AsAbstractMethodError::AsAbstractMethodError()
{
}
 
