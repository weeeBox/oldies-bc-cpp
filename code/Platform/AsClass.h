#ifndef AsClass_h__
#define AsClass_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsClass)
ASTYPEREF(AsObject)
 
class AsClass : public AsObject
{
public:
	ASOBJ(AsClass, AsObject);
	
public:
	virtual AsObject_ref prototype();
	
public:
	static AsClass_ref __createAsClass();
	void __internalInitialiseAsClass();
	
private:
	static StaticInit __internalStaticInitializerAsClass;
	static BOOL __internalStaticInitializedAsClass;
	
public:
	static void __internalStaticInit();
	
protected:
	AsClass();
};
 
#endif // AsClass_h__
