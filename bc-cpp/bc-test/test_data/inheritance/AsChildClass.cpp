#include "AsChildClass.h"
#include "AsFieldClass.h"
 
 
AsChildClass_ref AsChildClass::_as_create_AsChildClass()
{
	AsChildClass* __instance = new AsChildClass();
	__instance->_as_construct_AsChildClass();
	return __instance;
}
 
void AsChildClass::_as_construct_AsChildClass()
{
	_as_init_fields_AsChildClass();
	_as_construct_AsBaseClass();
	AsFieldClass::list->push(ASL("Child constructor"));
}
 
void AsChildClass::_as_init_fields_AsChildClass()
{
	field = AS_NEW(AsFieldClass,(ASL("Child field")));
}
 
bool AsChildClass::_as_static_initialized_AsChildClass = false;
AsStaticRefInitializer AsChildClass::_as_static_initializer_AsChildClass(_as_static_init_AsChildClass);
void AsChildClass::_as_static_init_AsChildClass()
{
	if (!_as_static_initialized_AsChildClass)
	{
		_as_static_initialized_AsChildClass = true;
		_as_static_init_AsBaseClass();
	}
}
 
void AsChildClass::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsBaseClass::_as_gc_mark();
		AS_GC_MARK(field)
	}
}
 
AsChildClass::AsChildClass() : 
  field(false)
{
}
