#include "AsFooBase.h"
#include "AsStaticFieldClass.h"
#include "AsStaticDummy.h"
 
AsStaticFieldClass_ref AsFooBase::staticField(true);
 
AsFooBase_ref AsFooBase::_as_create_AsFooBase()
{
	AsFooBase* __instance = new AsFooBase();
	__instance->_as_construct_AsFooBase();
	return __instance;
}
 
void AsFooBase::_as_construct_AsFooBase()
{
}
 
bool AsFooBase::_as_static_initialized_AsFooBase = false;
AsStaticRefInitializer AsFooBase::_as_static_initializer_AsFooBase(_as_static_init_AsFooBase);
void AsFooBase::_as_static_init_AsFooBase()
{
	if (!_as_static_initialized_AsFooBase)
	{
		_as_static_initialized_AsFooBase = true;
		
		AsStaticFieldClass::_as_static_init_AsStaticFieldClass();
		AsStaticDummy::_as_static_init_AsStaticDummy();
		
		staticField = AS_NEW(AsStaticFieldClass,(AS_NEW(AsStaticDummy,(ASL("FooBase")))));
	}
}
