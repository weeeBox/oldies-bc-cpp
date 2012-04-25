#ifndef AsArgumentError_h__
#define AsArgumentError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsArgumentError)
ASTYPEREF(AsString)
 
class AsArgumentError : public AsError
{
public:
	ASOBJ(AsArgumentError, AsError);
	
public:
	static AsArgumentError_ref __createAsArgumentError(const AsString_ref& message);
	static AsArgumentError_ref __createAsArgumentError();
	
private:
	void __internalConstructAsArgumentError(const AsString_ref& message);
	void __internalConstructAsArgumentError();
	
public:
	void __internalInitialiseAsArgumentError();
	
private:
	static StaticInit __internalStaticInitializerAsArgumentError;
	static BOOL __internalStaticInitializedAsArgumentError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsArgumentError();
};
 
#endif // AsArgumentError_h__
