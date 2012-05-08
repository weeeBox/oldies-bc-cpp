#include "AsStaticFoo.h"
#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
#include "AsStaticBar.h"
 
AsStaticFieldClass_ref AsStaticFoo::staticField(true);
AsStaticBar_ref AsStaticFoo::staticBar(true);
 
AsStaticFoo_ref AsStaticFoo::_as_create_AsStaticFoo()
{
	AsStaticFoo* __instance = new AsStaticFoo();
	__instance->_as_construct_AsStaticFoo();
	return __instance;
}
 
void AsStaticFoo::_as_construct_AsStaticFoo()
{
	_as_construct_AsFooBase();
}
 
bool AsStaticFoo::_as_static_initialized_AsStaticFoo = false;
AsStaticRefInitializer AsStaticFoo::_as_static_initializer_AsStaticFoo(_as_static_init_AsStaticFoo);
void AsStaticFoo::_as_static_init_AsStaticFoo()
{
	if (!_as_static_initialized_AsStaticFoo)
	{
		_as_static_initialized_AsStaticFoo = true;
		_as_static_init_AsFooBase();
		
		AsStaticFieldClass::_as_static_init_AsStaticFieldClass();
		AsStaticDummy::_as_static_init_AsStaticDummy();
		AsStaticBar::_as_static_init_AsStaticBar();
		
		staticField = AS_NEW(AsStaticFieldClass,(AS_NEW(AsStaticDummy,(ASL("Foo")))));
		staticBar = AS_NEW(AsStaticBar,());
	}
}
