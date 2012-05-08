#include "AsStaticDummy.h"
#include "AsString.h"
#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
 
AsStaticFieldClass_ref AsStaticDummy::staticField(true);
 
AsStaticDummy_ref AsStaticDummy::_as_create_AsStaticDummy(const AsString_ref& name)
{
	AsStaticDummy* __instance = new AsStaticDummy();
	__instance->_as_construct_AsStaticDummy(name);
	return __instance;
}
 
void AsStaticDummy::_as_construct_AsStaticDummy(const AsString_ref& name)
{
	this->name = name;
}
 
bool AsStaticDummy::_as_static_initialized_AsStaticDummy = false;
AsStaticRefInitializer AsStaticDummy::_as_static_initializer_AsStaticDummy(_as_static_init_AsStaticDummy);
void AsStaticDummy::_as_static_init_AsStaticDummy()
{
	if (!_as_static_initialized_AsStaticDummy)
	{
		_as_static_initialized_AsStaticDummy = true;
		
		AsStaticFieldClass::_as_static_init_AsStaticFieldClass();
		
		staticField = AS_NEW(AsStaticFieldClass,(AS_NEW(AsStaticDummy,(ASL("Dummy")))));
	}
}
 
void AsStaticDummy::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(name)
	}
}
 
AsStaticDummy::AsStaticDummy() : 
  name(false)
{
}
