#ifndef AsAbstractMethodError_h__
#define AsAbstractMethodError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsAbstractMethodError);
 
class AsAbstractMethodError : public AsError
{
public:
	AS_OBJ(AsAbstractMethodError, AsError);
	
	
public:
	static AsAbstractMethodError_ref _as_create_AsAbstractMethodError(const AsString_ref& message);
	static AsAbstractMethodError_ref _as_create_AsAbstractMethodError();
	
protected:
	void _as_construct_AsAbstractMethodError(const AsString_ref& message);
	void _as_construct_AsAbstractMethodError();
	
public:
	static void _as_static_init_AsAbstractMethodError();
	
private:
	static bool _as_static_initialized_AsAbstractMethodError;
	static AsStaticRefInitializer _as_static_initializer_AsAbstractMethodError;
};
 
#endif // AsAbstractMethodError_h__
