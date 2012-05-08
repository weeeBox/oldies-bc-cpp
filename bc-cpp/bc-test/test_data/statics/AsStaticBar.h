#ifndef AsStaticBar_h__
#define AsStaticBar_h__
 
#include "AsBc.h"
 
#include "AsBarBase.h"
 
AS_CLASS(AsStaticFieldClass);
 
AS_CLASS(AsStaticBar);
 
class AsStaticBar : public AsBarBase
{
public:
	AS_OBJ(AsStaticBar, AsBarBase);
	
private:
	static AsStaticFieldClass_ref staticField;
	
	
public:
	static AsStaticBar_ref _as_create_AsStaticBar();
	
protected:
	void _as_construct_AsStaticBar();
	
public:
	static void _as_static_init_AsStaticBar();
	
private:
	static bool _as_static_initialized_AsStaticBar;
	static AsStaticRefInitializer _as_static_initializer_AsStaticBar;
};
 
#endif // AsStaticBar_h__
