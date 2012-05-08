#include "AsBarBase.h"
#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
 
AsStaticFieldClass_ref AsBarBase::staticField(true);
 
AsBarBase_ref AsBarBase::_as_create_AsBarBase()
{
	AsBarBase* __instance = new AsBarBase();
	__instance->_as_construct_AsBarBase();
	return __instance;
}
 
void AsBarBase::_as_construct_AsBarBase()
{
}
 
bool AsBarBase::_as_static_initialized_AsBarBase = false;
AsStaticRefInitializer AsBarBase::_as_static_initializer_AsBarBase(_as_static_init_AsBarBase);
void AsBarBase::_as_static_init_AsBarBase()
{
	if (!_as_static_initialized_AsBarBase)
	{
		_as_static_initialized_AsBarBase = true;
		
		AsStaticFieldClass::_as_static_init_AsStaticFieldClass();
		AsStaticDummy::_as_static_init_AsStaticDummy();
		
		staticField = AS_NEW(AsStaticFieldClass,(AS_NEW(AsStaticDummy,(ASL("BarBase")))));
	}
}
