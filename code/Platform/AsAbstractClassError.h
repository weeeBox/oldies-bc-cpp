#ifndef AsAbstractClassError_h__
#define AsAbstractClassError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsAbstractClassError)
ASTYPEREF(AsString)
 
class AsAbstractClassError : public AsError
{
public:
	ASOBJ(AsAbstractClassError, AsError);
	
public:
	static AsAbstractClassError_ref __createAsAbstractClassError(const AsString_ref& message);
	static AsAbstractClassError_ref __createAsAbstractClassError();
	
private:
	void __internalConstructAsAbstractClassError(const AsString_ref& message);
	void __internalConstructAsAbstractClassError();
	
public:
	void __internalInitialiseAsAbstractClassError();
	
private:
	static StaticInit __internalStaticInitializerAsAbstractClassError;
	static BOOL __internalStaticInitializedAsAbstractClassError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsAbstractClassError();
};
 
#endif // AsAbstractClassError_h__
