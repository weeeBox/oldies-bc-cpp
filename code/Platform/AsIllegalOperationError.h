#ifndef AsIllegalOperationError_h__
#define AsIllegalOperationError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsIllegalOperationError);
 
class AsIllegalOperationError : public AsError
{
public:
	AS_OBJ(AsIllegalOperationError, AsError);
	
	
public:
	static AsIllegalOperationError_ref _as_create_AsIllegalOperationError(const AsString_ref& message);
	static AsIllegalOperationError_ref _as_create_AsIllegalOperationError();
	
protected:
	void _as_construct_AsIllegalOperationError(const AsString_ref& message);
	void _as_construct_AsIllegalOperationError();
	
public:
	static void _as_static_init_AsIllegalOperationError();
	
private:
	static bool _as_static_initialized_AsIllegalOperationError;
	static AsStaticRefInitializer _as_static_initializer_AsIllegalOperationError;
};
 
#endif // AsIllegalOperationError_h__
