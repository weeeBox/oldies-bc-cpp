#ifndef AsError_h__
#define AsError_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsError);
 
class AsError : public AsObject
{
public:
	AS_OBJ(AsError, AsObject);
	
public:
	AsString_ref message;
	AsString_ref name;
	
	
public:
	static AsError_ref _as_create_AsError(const AsString_ref& message);
	static AsError_ref _as_create_AsError();
	
protected:
	void _as_construct_AsError(const AsString_ref& message);
	void _as_construct_AsError();
	
public:
	static void _as_static_init_AsError();
	
private:
	static bool _as_static_initialized_AsError;
	static AsStaticRefInitializer _as_static_initializer_AsError;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsError();
};
 
#endif // AsError_h__
