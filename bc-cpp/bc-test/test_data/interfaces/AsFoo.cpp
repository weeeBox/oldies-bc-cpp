#include "AsFoo.h"
 
AsString_ref AsFoo::string1()
{
	return ASL("Foo.string1");
}
 
AsString_ref AsFoo::string2()
{
	return ASL("Foo.string2");
}
 
AsFoo_ref AsFoo::_as_create_AsFoo()
{
	AsFoo* __instance = new AsFoo();
	__instance->_as_construct_AsFoo();
	return __instance;
}
 
void AsFoo::_as_construct_AsFoo()
{
}
 
bool AsFoo::_as_static_initialized_AsFoo = false;
void AsFoo::_as_static_init_AsFoo()
{
	if (!_as_static_initialized_AsFoo)
	{
		_as_static_initialized_AsFoo = true;
	}
}
