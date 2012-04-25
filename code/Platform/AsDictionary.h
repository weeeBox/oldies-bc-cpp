#ifndef AsDictionary_h__
#define AsDictionary_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsDictionary)
 
class AsDictionary : public AsObject
{
public:
	ASOBJ(AsDictionary, AsObject);
	
public:
	static AsDictionary_ref __createAsDictionary();
	void __internalInitialiseAsDictionary();
	
private:
	static StaticInit __internalStaticInitializerAsDictionary;
	static BOOL __internalStaticInitializedAsDictionary;
	
public:
	static void __internalStaticInit();
	
protected:
	AsDictionary();
};
 
#endif // AsDictionary_h__
