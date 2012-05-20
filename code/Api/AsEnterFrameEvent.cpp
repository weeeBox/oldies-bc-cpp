#include "AsEnterFrameEvent.h"
#include "AsString.h"
 
 
float AsEnterFrameEvent::getPassedTime()
{
	return mPassedTime;
}
 
void AsEnterFrameEvent::setPassedTime(float value)
{
	mPassedTime = value;
}
 
AsEnterFrameEvent_ref AsEnterFrameEvent::_as_create_AsEnterFrameEvent(const AsString_ref& type, float passedTime, bool bubbles)
{
	AsEnterFrameEvent_ref __instance = new AsEnterFrameEvent();
	__instance->_as_construct_AsEnterFrameEvent(type, passedTime, bubbles);
	return __instance;
}
 
AsEnterFrameEvent_ref AsEnterFrameEvent::_as_create_AsEnterFrameEvent(const AsString_ref& type, float passedTime)
{
	AsEnterFrameEvent_ref __instance = new AsEnterFrameEvent();
	__instance->_as_construct_AsEnterFrameEvent(type, passedTime);
	return __instance;
}
 
void AsEnterFrameEvent::_as_construct_AsEnterFrameEvent(const AsString_ref& type, float passedTime, bool bubbles)
{
	_as_construct_AsEvent(type, bubbles);
	mPassedTime = passedTime;
}
 
inline void AsEnterFrameEvent::_as_construct_AsEnterFrameEvent(const AsString_ref& type, float passedTime)
{
	_as_construct_AsEnterFrameEvent(type, passedTime, false);
}
 
bool AsEnterFrameEvent::_as_static_initialized_AsEnterFrameEvent = false;
AsStaticRefInitializer AsEnterFrameEvent::_as_static_initializer_AsEnterFrameEvent(_as_static_init_AsEnterFrameEvent);
void AsEnterFrameEvent::_as_static_init_AsEnterFrameEvent()
{
	if (!_as_static_initialized_AsEnterFrameEvent)
	{
		_as_static_initialized_AsEnterFrameEvent = true;
		_as_static_init_AsEvent();
	}
}
 
AsEnterFrameEvent::AsEnterFrameEvent() : 
  mPassedTime(0)
{
}
