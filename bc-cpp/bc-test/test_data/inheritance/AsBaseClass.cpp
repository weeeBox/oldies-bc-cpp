#include "AsBaseClass.h"
#include "AsFieldClass.h"
 
 
AsBaseClass_ref AsBaseClass::_as_create_AsBaseClass()
{
	AsBaseClass* __instance = new AsBaseClass();
	__instance->_as_construct_AsBaseClass();
	return __instance;
}
 
void AsBaseClass::_as_construct_AsBaseClass()
{
	_as_init_fields_AsBaseClass();
	AsFieldClass::list->push(ASL("Base constructor"));
}
 
void AsBaseClass::_as_init_fields_AsBaseClass()
{
	field = AS_NEW(AsFieldClass,(ASL("Base field")));
}
 
bool AsBaseClass::_as_static_initialized_AsBaseClass = false;
AsStaticRefInitializer AsBaseClass::_as_static_initializer_AsBaseClass(_as_static_init_AsBaseClass);
void AsBaseClass::_as_static_init_AsBaseClass()
{
	if (!_as_static_initialized_AsBaseClass)
	{
		_as_static_initialized_AsBaseClass = true;
	}
}
 
void AsBaseClass::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(field)
	}
}
 
AsBaseClass::AsBaseClass() : 
  field(false)
{
}
