#include "AsStaticBar.h"
#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
 
AsStaticFieldClass_ref AsStaticBar::staticField(true);
 
AsStaticBar_ref AsStaticBar::_as_create_AsStaticBar()
{
	AsStaticBar* __instance = new AsStaticBar();
	__instance->_as_construct_AsStaticBar();
	return __instance;
}
 
void AsStaticBar::_as_construct_AsStaticBar()
{
	_as_construct_AsBarBase();
}
 
bool AsStaticBar::_as_static_initialized_AsStaticBar = false;
AsStaticRefInitializer AsStaticBar::_as_static_initializer_AsStaticBar(_as_static_init_AsStaticBar);
void AsStaticBar::_as_static_init_AsStaticBar()
{
	if (!_as_static_initialized_AsStaticBar)
	{
		_as_static_initialized_AsStaticBar = true;
		_as_static_init_AsBarBase();
		
		AsStaticFieldClass::_as_static_init_AsStaticFieldClass();
		AsStaticDummy::_as_static_init_AsStaticDummy();
		
		staticField = AS_NEW(AsStaticFieldClass,(AS_NEW(AsStaticDummy,(ASL("Bar")))));
	}
}
