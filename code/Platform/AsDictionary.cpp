#include "AsDictionary.h"
#include "AsDictionary.h"
 
 
AsDictionary_ref AsDictionary::__createAsDictionary()
{
	AsDictionary_ref __reference(new AsDictionary());
	return __reference;
}
 
void AsDictionary::__internalInitialiseAsDictionary()
{
}
 
StaticInit AsDictionary::__internalStaticInitializerAsDictionary(&AsDictionary::__internalStaticInit);
BOOL AsDictionary::__internalStaticInitializedAsDictionary = false;
 
void AsDictionary::__internalStaticInit()
{
	if (!__internalStaticInitializedAsDictionary)
	{
		__internalStaticInitializedAsDictionary = true;
		AsObject::__internalStaticInit();
	}
}
 
AsDictionary::AsDictionary()
{
}
 
