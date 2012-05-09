#ifndef AsNotImplementedError_h__
#define AsNotImplementedError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsNotImplementedError);
 
class AsNotImplementedError : public AsError
{
public:
	AS_OBJ(AsNotImplementedError, AsError);
	
	
public:
	static AsNotImplementedError_ref _as_create_AsNotImplementedError(const AsString_ref& message);
	static AsNotImplementedError_ref _as_create_AsNotImplementedError();
	
protected:
	void _as_construct_AsNotImplementedError(const AsString_ref& message);
	void _as_construct_AsNotImplementedError();
	
public:
	static void _as_static_init_AsNotImplementedError();
	
private:
	static bool _as_static_initialized_AsNotImplementedError;
	static AsStaticRefInitializer _as_static_initializer_AsNotImplementedError;
};
 
#endif // AsNotImplementedError_h__
