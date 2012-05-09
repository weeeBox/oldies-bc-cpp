#include "AsFieldClass.h"
#include "AsString.h"
 
_V_AsString_ref AsFieldClass::list(true);
 
AsFieldClass_ref AsFieldClass::_as_create_AsFieldClass(const AsString_ref& name)
{
	AsFieldClass* __instance = new AsFieldClass();
	__instance->_as_construct_AsFieldClass(name);
	return __instance;
}
 
void AsFieldClass::_as_construct_AsFieldClass(const AsString_ref& name)
{
	if((list == AS_NULL))
	{
		list = AS_NEW_VECTOR(AsString,());
	}
	list->push(name);
}
 
bool AsFieldClass::_as_static_initialized_AsFieldClass = false;
AsStaticRefInitializer AsFieldClass::_as_static_initializer_AsFieldClass(_as_static_init_AsFieldClass);
void AsFieldClass::_as_static_init_AsFieldClass()
{
	if (!_as_static_initialized_AsFieldClass)
	{
		_as_static_initialized_AsFieldClass = true;
		
		list = AS_NULL;
	}
}
