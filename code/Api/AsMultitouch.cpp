#include "AsMultitouch.h"
#include "AsString.h"
#include "AsMultitouchInputMode.h"
 
AsString_ref AsMultitouch::mInputMode(true);
 
AsString_ref AsMultitouch::getInputMode()
{
	return mInputMode;
}
 
void AsMultitouch::setInputMode(const AsString_ref& value)
{
	mInputMode = value;
}
 
bool AsMultitouch::_as_static_initialized_AsMultitouch = false;
AsStaticRefInitializer AsMultitouch::_as_static_initializer_AsMultitouch(_as_static_init_AsMultitouch);
void AsMultitouch::_as_static_init_AsMultitouch()
{
	if (!_as_static_initialized_AsMultitouch)
	{
		_as_static_initialized_AsMultitouch = true;
		
		AsMultitouchInputMode::_as_static_init_AsMultitouchInputMode();
		
		mInputMode = AsMultitouchInputMode::NONE;
	}
}
