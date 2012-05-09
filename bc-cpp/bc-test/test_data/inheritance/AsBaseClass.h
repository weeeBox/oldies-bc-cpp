#ifndef AsBaseClass_h__
#define AsBaseClass_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsFieldClass);
 
AS_CLASS(AsBaseClass);
 
class AsBaseClass : public AsObject
{
public:
	AS_OBJ(AsBaseClass, AsObject);
	
private:
	AsFieldClass_ref field;
	
	
public:
	static AsBaseClass_ref _as_create_AsBaseClass();
	
protected:
	void _as_construct_AsBaseClass();
	void _as_init_fields_AsBaseClass();
	
public:
	static void _as_static_init_AsBaseClass();
	
private:
	static bool _as_static_initialized_AsBaseClass;
	static AsStaticRefInitializer _as_static_initializer_AsBaseClass;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsBaseClass();
};
 
#endif // AsBaseClass_h__
