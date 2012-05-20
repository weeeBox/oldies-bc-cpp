#include "AsMouseEvent.h"
#include "AsString.h"
 
AsString_ref AsMouseEvent::CLICK(true);
AsString_ref AsMouseEvent::DOUBLE_CLICK(true);
AsString_ref AsMouseEvent::MOUSE_DOWN(true);
AsString_ref AsMouseEvent::MOUSE_MOVE(true);
AsString_ref AsMouseEvent::MOUSE_OUT(true);
AsString_ref AsMouseEvent::MOUSE_OVER(true);
AsString_ref AsMouseEvent::MOUSE_UP(true);
AsString_ref AsMouseEvent::MOUSE_WHEEL(true);
AsString_ref AsMouseEvent::ROLL_OUT(true);
AsString_ref AsMouseEvent::ROLL_OVER(true);
 
float AsMouseEvent::getStageX()
{
	return mX;
}
 
float AsMouseEvent::getStageY()
{
	return mY;
}
 
AsMouseEvent_ref AsMouseEvent::_as_create_AsMouseEvent(const AsString_ref& type, float x, float y, bool bubbles)
{
	AsMouseEvent_ref __instance = new AsMouseEvent();
	__instance->_as_construct_AsMouseEvent(type, x, y, bubbles);
	return __instance;
}
 
AsMouseEvent_ref AsMouseEvent::_as_create_AsMouseEvent(const AsString_ref& type, float x, float y)
{
	AsMouseEvent_ref __instance = new AsMouseEvent();
	__instance->_as_construct_AsMouseEvent(type, x, y);
	return __instance;
}
 
void AsMouseEvent::_as_construct_AsMouseEvent(const AsString_ref& type, float x, float y, bool bubbles)
{
	_as_construct_AsEvent(type, bubbles);
	mX = x;
	mY = y;
}
 
inline void AsMouseEvent::_as_construct_AsMouseEvent(const AsString_ref& type, float x, float y)
{
	_as_construct_AsMouseEvent(type, x, y, false);
}
 
bool AsMouseEvent::_as_static_initialized_AsMouseEvent = false;
AsStaticRefInitializer AsMouseEvent::_as_static_initializer_AsMouseEvent(_as_static_init_AsMouseEvent);
void AsMouseEvent::_as_static_init_AsMouseEvent()
{
	if (!_as_static_initialized_AsMouseEvent)
	{
		_as_static_initialized_AsMouseEvent = true;
		_as_static_init_AsEvent();
		
		CLICK = ASL("click");
		DOUBLE_CLICK = ASL("doubleClick");
		MOUSE_DOWN = ASL("mouseDown");
		MOUSE_MOVE = ASL("mouseMove");
		MOUSE_OUT = ASL("mouseOut");
		MOUSE_OVER = ASL("mouseOver");
		MOUSE_UP = ASL("mouseUp");
		MOUSE_WHEEL = ASL("mouseWheel");
		ROLL_OUT = ASL("rollOut");
		ROLL_OVER = ASL("rollOver");
	}
}
 
AsMouseEvent::AsMouseEvent() : 
  mX(0),
  mY(0)
{
}
