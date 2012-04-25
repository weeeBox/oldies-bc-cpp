#ifndef AsError_h__
#define AsError_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsError)
ASTYPEREF(AsString)
 
class AsError : public AsObject
{
public:
	ASOBJ(AsError, AsObject);
	
public:
	AsString_ref message;
	AsString_ref name;
	
public:
	static AsError_ref __createAsError(const AsString_ref& message);
	static AsError_ref __createAsError();
	
private:
	void __internalConstructAsError(const AsString_ref& message);
	void __internalConstructAsError();
	
public:
	void __internalInitialiseAsError();
	
private:
	static StaticInit __internalStaticInitializerAsError;
	static BOOL __internalStaticInitializedAsError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsError();
	
public:
	void __internalGc();
};
 
#endif // AsError_h__
