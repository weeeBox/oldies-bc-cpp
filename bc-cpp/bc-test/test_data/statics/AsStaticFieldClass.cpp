#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
 
_V_AsString_ref AsStaticFieldClass::list(true);
 
AsStaticFieldClass_ref AsStaticFieldClass::_as_create_AsStaticFieldClass(const AsStaticDummy_ref& dummy)
{
	AsStaticFieldClass* __instance = new AsStaticFieldClass();
	__instance->_as_construct_AsStaticFieldClass(dummy);
	return __instance;
}
 
void AsStaticFieldClass::_as_construct_AsStaticFieldClass(const AsStaticDummy_ref& dummy)
{
	list->push(dummy->name);
}
 
bool AsStaticFieldClass::_as_static_initialized_AsStaticFieldClass = false;
AsStaticRefInitializer AsStaticFieldClass::_as_static_initializer_AsStaticFieldClass(_as_static_init_AsStaticFieldClass);
void AsStaticFieldClass::_as_static_init_AsStaticFieldClass()
{
	if (!_as_static_initialized_AsStaticFieldClass)
	{
		_as_static_initialized_AsStaticFieldClass = true;
		
		list = AS_NEW_VECTOR(AsString,());
	}
}
