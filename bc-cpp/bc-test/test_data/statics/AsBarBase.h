#ifndef AsBarBase_h__
#define AsBarBase_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsStaticFieldClass);
 
AS_CLASS(AsBarBase);
 
class AsBarBase : public AsObject
{
public:
	AS_OBJ(AsBarBase, AsObject);
	
private:
	static AsStaticFieldClass_ref staticField;
	
	
public:
	static AsBarBase_ref _as_create_AsBarBase();
	
protected:
	void _as_construct_AsBarBase();
	
public:
	static void _as_static_init_AsBarBase();
	
private:
	static bool _as_static_initialized_AsBarBase;
	static AsStaticRefInitializer _as_static_initializer_AsBarBase;
};
 
#endif // AsBarBase_h__
