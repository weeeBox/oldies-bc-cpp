#include "AsBar.h"
 
AsString_ref AsBar::string1()
{
	return ASL("Bar.string1");
}
 
AsString_ref AsBar::string2()
{
	return ASL("Bar.string2");
}
 
AsBar_ref AsBar::_as_create_AsBar()
{
	AsBar* __instance = new AsBar();
	__instance->_as_construct_AsBar();
	return __instance;
}
 
void AsBar::_as_construct_AsBar()
{
}
 
bool AsBar::_as_static_initialized_AsBar = false;
void AsBar::_as_static_init_AsBar()
{
	if (!_as_static_initialized_AsBar)
	{
		_as_static_initialized_AsBar = true;
	}
}
