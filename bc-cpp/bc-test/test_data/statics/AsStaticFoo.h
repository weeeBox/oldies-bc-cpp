#ifndef AsStaticFoo_h__
#define AsStaticFoo_h__
 
#include "AsBc.h"
 
#include "AsFooBase.h"
 
AS_CLASS(AsStaticFieldClass);
AS_CLASS(AsStaticBar);
 
AS_CLASS(AsStaticFoo);
 
class AsStaticFoo : public AsFooBase
{
public:
	AS_OBJ(AsStaticFoo, AsFooBase);
	
private:
	static AsStaticFieldClass_ref staticField;
	static AsStaticBar_ref staticBar;
	
	
public:
	static AsStaticFoo_ref _as_create_AsStaticFoo();
	
protected:
	void _as_construct_AsStaticFoo();
	
public:
	static void _as_static_init_AsStaticFoo();
	
private:
	static bool _as_static_initialized_AsStaticFoo;
	static AsStaticRefInitializer _as_static_initializer_AsStaticFoo;
};
 
#endif // AsStaticFoo_h__
