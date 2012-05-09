#ifndef AsArgumentError_h__
#define AsArgumentError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsArgumentError);
 
class AsArgumentError : public AsError
{
public:
	AS_OBJ(AsArgumentError, AsError);
	
	
public:
	static AsArgumentError_ref _as_create_AsArgumentError(const AsString_ref& message);
	static AsArgumentError_ref _as_create_AsArgumentError();
	
protected:
	void _as_construct_AsArgumentError(const AsString_ref& message);
	void _as_construct_AsArgumentError();
	
public:
	static void _as_static_init_AsArgumentError();
	
private:
	static bool _as_static_initialized_AsArgumentError;
	static AsStaticRefInitializer _as_static_initializer_AsArgumentError;
};
 
#endif // AsArgumentError_h__
