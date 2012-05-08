#ifndef AsStaticDummy_h__
#define AsStaticDummy_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
AS_CLASS(AsStaticFieldClass);
 
AS_CLASS(AsStaticDummy);
 
class AsStaticDummy : public AsObject
{
public:
	AS_OBJ(AsStaticDummy, AsObject);
	
private:
	static AsStaticFieldClass_ref staticField;
	
public:
	AsString_ref name;
	
	
public:
	static AsStaticDummy_ref _as_create_AsStaticDummy(const AsString_ref& name);
	
protected:
	void _as_construct_AsStaticDummy(const AsString_ref& name);
	
public:
	static void _as_static_init_AsStaticDummy();
	
private:
	static bool _as_static_initialized_AsStaticDummy;
	static AsStaticRefInitializer _as_static_initializer_AsStaticDummy;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsStaticDummy();
};
 
#endif // AsStaticDummy_h__
