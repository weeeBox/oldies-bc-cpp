#ifndef AsAbstractClassError_h__
#define AsAbstractClassError_h__
 
#include "AsBc.h"
 
#include "AsError.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsAbstractClassError);
 
class AsAbstractClassError : public AsError
{
public:
	AS_OBJ(AsAbstractClassError, AsError);
	
	
public:
	static AsAbstractClassError_ref _as_create_AsAbstractClassError(const AsString_ref& message);
	static AsAbstractClassError_ref _as_create_AsAbstractClassError();
	
protected:
	void _as_construct_AsAbstractClassError(const AsString_ref& message);
	void _as_construct_AsAbstractClassError();
	
public:
	static void _as_static_init_AsAbstractClassError();
	
private:
	static bool _as_static_initialized_AsAbstractClassError;
	static AsStaticRefInitializer _as_static_initializer_AsAbstractClassError;
};
 
#endif // AsAbstractClassError_h__
