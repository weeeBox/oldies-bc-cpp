#include "AsKeyboardEvent.h"
#include "AsString.h"
 
AsString_ref AsKeyboardEvent::KEY_UP(true);
AsString_ref AsKeyboardEvent::KEY_DOWN(true);
 
uint AsKeyboardEvent::getCharCode()
{
	return mCharCode;
}
 
uint AsKeyboardEvent::getKeyCode()
{
	return mKeyCode;
}
 
uint AsKeyboardEvent::getKeyLocation()
{
	return mKeyLocation;
}
 
bool AsKeyboardEvent::getAltKey()
{
	return mAltKey;
}
 
bool AsKeyboardEvent::getCtrlKey()
{
	return mCtrlKey;
}
 
bool AsKeyboardEvent::getShiftKey()
{
	return mShiftKey;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey, bool shiftKey)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, ctrlKey, altKey, shiftKey);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, ctrlKey, altKey);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, ctrlKey);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode, keyCode);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type, charCode);
	return __instance;
}
 
AsKeyboardEvent_ref AsKeyboardEvent::_as_create_AsKeyboardEvent(const AsString_ref& type)
{
	AsKeyboardEvent_ref __instance = new AsKeyboardEvent();
	__instance->_as_construct_AsKeyboardEvent(type);
	return __instance;
}
 
void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey, bool shiftKey)
{
	_as_construct_AsEvent(type, false);
	mCharCode = charCode;
	mKeyCode = keyCode;
	mKeyLocation = keyLocation;
	mCtrlKey = ctrlKey;
	mAltKey = altKey;
	mShiftKey = shiftKey;
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey)
{
	_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, ctrlKey, altKey, false);
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey)
{
	_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, ctrlKey, false, false);
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation)
{
	_as_construct_AsKeyboardEvent(type, charCode, keyCode, keyLocation, false, false, false);
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode)
{
	_as_construct_AsKeyboardEvent(type, charCode, keyCode, 0, false, false, false);
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode)
{
	_as_construct_AsKeyboardEvent(type, charCode, 0, 0, false, false, false);
}
 
inline void AsKeyboardEvent::_as_construct_AsKeyboardEvent(const AsString_ref& type)
{
	_as_construct_AsKeyboardEvent(type, 0, 0, 0, false, false, false);
}
 
bool AsKeyboardEvent::_as_static_initialized_AsKeyboardEvent = false;
AsStaticRefInitializer AsKeyboardEvent::_as_static_initializer_AsKeyboardEvent(_as_static_init_AsKeyboardEvent);
void AsKeyboardEvent::_as_static_init_AsKeyboardEvent()
{
	if (!_as_static_initialized_AsKeyboardEvent)
	{
		_as_static_initialized_AsKeyboardEvent = true;
		_as_static_init_AsEvent();
		
		KEY_UP = ASL("keyUp");
		KEY_DOWN = ASL("keyDown");
	}
}
 
AsKeyboardEvent::AsKeyboardEvent() : 
  mCharCode(0),
  mKeyCode(0),
  mKeyLocation(0),
  mAltKey(0),
  mCtrlKey(0),
  mShiftKey(0)
{
}
