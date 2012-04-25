#ifndef AsRangeError_h__
#define AsRangeError_h__
 
#include "AsBase.h"
 
#include "AsError.h"
 
ASTYPEREF(AsRangeError)
ASTYPEREF(AsString)
 
class AsRangeError : public AsError
{
public:
	ASOBJ(AsRangeError, AsError);
	
public:
	static AsRangeError_ref __createAsRangeError(const AsString_ref& message);
	static AsRangeError_ref __createAsRangeError();
	
private:
	void __internalConstructAsRangeError(const AsString_ref& message);
	void __internalConstructAsRangeError();
	
public:
	void __internalInitialiseAsRangeError();
	
private:
	static StaticInit __internalStaticInitializerAsRangeError;
	static BOOL __internalStaticInitializedAsRangeError;
	
public:
	static void __internalStaticInit();
	
protected:
	AsRangeError();
};
 
#endif // AsRangeError_h__
