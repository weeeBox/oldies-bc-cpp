#include "AsMultitouchInputMode.h"
 
AsString_ref AsMultitouchInputMode::NONE(true);
AsString_ref AsMultitouchInputMode::GESTURE(true);
AsString_ref AsMultitouchInputMode::TOUCH_POINT(true);
 
bool AsMultitouchInputMode::_as_static_initialized_AsMultitouchInputMode = false;
AsStaticRefInitializer AsMultitouchInputMode::_as_static_initializer_AsMultitouchInputMode(_as_static_init_AsMultitouchInputMode);
void AsMultitouchInputMode::_as_static_init_AsMultitouchInputMode()
{
	if (!_as_static_initialized_AsMultitouchInputMode)
	{
		_as_static_initialized_AsMultitouchInputMode = true;
		
		NONE = ASL("none");
		GESTURE = ASL("gesture");
		TOUCH_POINT = ASL("touchPoint");
	}
}
