#include "AsError.h"
#include "AsError.h"
#include "AsString.h"
#include "AsString.h"
 
 
AsError_ref AsError::__createAsError(const AsString_ref& message)
{
	AsError_ref __reference(new AsError());
	__reference->__internalConstructAsError(message);
	return __reference;
}
 
AsError_ref AsError::__createAsError()
{
	AsError_ref __reference(new AsError());
	__reference->__internalConstructAsError();
	return __reference;
}
 
void AsError::__internalConstructAsError(const AsString_ref& message)
{
	__internalConstructAsObject();
	__internalInitialiseAsError();
	this.message = message;
}
 
void AsError::__internalConstructAsError()
{
	__internalConstructAsObject();
	__$base$__("");
}
 
void AsError::__internalInitialiseAsError()
{
}
 
StaticInit AsError::__internalStaticInitializerAsError(&AsError::__internalStaticInit);
BOOL AsError::__internalStaticInitializedAsError = false;
 
void AsError::__internalStaticInit()
{
	if (!__internalStaticInitializedAsError)
	{
		__internalStaticInitializedAsError = true;
		AsObject::__internalStaticInit();
	}
}
 
AsError::AsError() :
  message(false),
  name(false)
{
}
 
void AsError::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsObject::__internalGc();
		if (message != __NULL) message->__internalGc();
		if (name != __NULL) name->__internalGc();
	}
}
 
