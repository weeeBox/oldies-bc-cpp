#ifndef AsFunction_h__
#define AsFunction_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsFunction)
 
class AsFunction : public AsObject
{
public:
	ASOBJ(AsFunction, AsObject);
	
public:
	static AsFunction_ref __createAsFunction();
	void __internalInitialiseAsFunction();
	
private:
	static StaticInit __internalStaticInitializerAsFunction;
	static BOOL __internalStaticInitializedAsFunction;
	
public:
	static void __internalStaticInit();
	
protected:
	AsFunction();
};
 
#endif // AsFunction_h__
