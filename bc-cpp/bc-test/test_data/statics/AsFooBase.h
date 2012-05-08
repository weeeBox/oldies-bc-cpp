#ifndef AsFooBase_h__
#define AsFooBase_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsStaticFieldClass);
 
AS_CLASS(AsFooBase);
 
class AsFooBase : public AsObject
{
public:
	AS_OBJ(AsFooBase, AsObject);
	
private:
	static AsStaticFieldClass_ref staticField;
	
	
public:
	static AsFooBase_ref _as_create_AsFooBase();
	
protected:
	void _as_construct_AsFooBase();
	
public:
	static void _as_static_init_AsFooBase();
	
private:
	static bool _as_static_initialized_AsFooBase;
	static AsStaticRefInitializer _as_static_initializer_AsFooBase;
};
 
#endif // AsFooBase_h__
