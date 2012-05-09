#ifndef AsRangeError_h__
#define AsRangeError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsRangeError);
 
class AsRangeError : public AsError
{
public:
	AS_OBJ(AsRangeError, AsError);
	
	
public:
	static AsRangeError_ref _as_create_AsRangeError(const AsString_ref& message);
	static AsRangeError_ref _as_create_AsRangeError();
	
protected:
	void _as_construct_AsRangeError(const AsString_ref& message);
	void _as_construct_AsRangeError();
	
public:
	static void _as_static_init_AsRangeError();
	
private:
	static bool _as_static_initialized_AsRangeError;
	static AsStaticRefInitializer _as_static_initializer_AsRangeError;
};
 
#endif // AsRangeError_h__
