#ifndef AsChildClass_h__
#define AsChildClass_h__
 
#include "AsBc.h"
 
#include "AsBaseClass.h"
 
AS_CLASS(AsFieldClass);
 
AS_CLASS(AsChildClass);
 
class AsChildClass : public AsBaseClass
{
public:
	AS_OBJ(AsChildClass, AsBaseClass);
	
private:
	AsFieldClass_ref field;
	
	
public:
	static AsChildClass_ref _as_create_AsChildClass();
	
protected:
	void _as_construct_AsChildClass();
	void _as_init_fields_AsChildClass();
	
public:
	static void _as_static_init_AsChildClass();
	
private:
	static bool _as_static_initialized_AsChildClass;
	static AsStaticRefInitializer _as_static_initializer_AsChildClass;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsChildClass();
};
 
#endif // AsChildClass_h__
