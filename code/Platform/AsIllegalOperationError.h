#ifndef AsIllegalOperationError_h__
#define AsIllegalOperationError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsIllegalOperationError)
ASTYPEREF(AsString)
 
class AsIllegalOperationError : public AsError
{
public:
	ASOBJ(AsIllegalOperationError, AsError);
	
public:
	static AsIllegalOperationError_ref __createAsIllegalOperationError(const AsString_ref& message);
	static AsIllegalOperationError_ref __createAsIllegalOperationError();
	
private:
	void __internalConstructAsIllegalOperationError(const AsString_ref& message);
	void __internalConstructAsIllegalOperationError();
	
public:
	void __internalInitialiseAsIllegalOperationError();
	
private:
	static StaticInit __internalStaticInitializerAsIllegalOperationError;
	static BOOL __internalStaticInitializedAsIllegalOperationError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsIllegalOperationError();
};
 
#endif // AsIllegalOperationError_h__
