#ifndef AsNotImplementedError_h__
#define AsNotImplementedError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsNotImplementedError)
ASTYPEREF(AsString)
 
class AsNotImplementedError : public AsError
{
public:
	ASOBJ(AsNotImplementedError, AsError);
	
public:
	static AsNotImplementedError_ref __createAsNotImplementedError(const AsString_ref& message);
	static AsNotImplementedError_ref __createAsNotImplementedError();
	
private:
	void __internalConstructAsNotImplementedError(const AsString_ref& message);
	void __internalConstructAsNotImplementedError();
	
public:
	void __internalInitialiseAsNotImplementedError();
	
private:
	static StaticInit __internalStaticInitializerAsNotImplementedError;
	static BOOL __internalStaticInitializedAsNotImplementedError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsNotImplementedError();
};
 
#endif // AsNotImplementedError_h__
