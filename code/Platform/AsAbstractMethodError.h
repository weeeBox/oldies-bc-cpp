#ifndef AsAbstractMethodError_h__
#define AsAbstractMethodError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsAbstractMethodError)
ASTYPEREF(AsString)
 
class AsAbstractMethodError : public AsError
{
public:
	ASOBJ(AsAbstractMethodError, AsError);
	
public:
	static AsAbstractMethodError_ref __createAsAbstractMethodError(const AsString_ref& message);
	static AsAbstractMethodError_ref __createAsAbstractMethodError();
	
private:
	void __internalConstructAsAbstractMethodError(const AsString_ref& message);
	void __internalConstructAsAbstractMethodError();
	
public:
	void __internalInitialiseAsAbstractMethodError();
	
private:
	static StaticInit __internalStaticInitializerAsAbstractMethodError;
	static BOOL __internalStaticInitializedAsAbstractMethodError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsAbstractMethodError();
};
 
#endif // AsAbstractMethodError_h__
