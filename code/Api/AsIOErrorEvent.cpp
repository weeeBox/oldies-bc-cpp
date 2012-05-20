#include "AsIOErrorEvent.h"
#include "AsString.h"
 
AsString_ref AsIOErrorEvent::IO_ERROR(true);
AsString_ref AsIOErrorEvent::NETWORK_ERROR(true);
AsString_ref AsIOErrorEvent::DISK_ERROR(true);
AsString_ref AsIOErrorEvent::VERIFY_ERROR(true);
 
AsIOErrorEvent_ref AsIOErrorEvent::_as_create_AsIOErrorEvent(const AsString_ref& type, bool bubbles)
{
	AsIOErrorEvent_ref __instance = new AsIOErrorEvent();
	__instance->_as_construct_AsIOErrorEvent(type, bubbles);
	return __instance;
}
 
AsIOErrorEvent_ref AsIOErrorEvent::_as_create_AsIOErrorEvent(const AsString_ref& type)
{
	AsIOErrorEvent_ref __instance = new AsIOErrorEvent();
	__instance->_as_construct_AsIOErrorEvent(type);
	return __instance;
}
 
void AsIOErrorEvent::_as_construct_AsIOErrorEvent(const AsString_ref& type, bool bubbles)
{
	_as_construct_AsEvent(type, bubbles);
}
 
inline void AsIOErrorEvent::_as_construct_AsIOErrorEvent(const AsString_ref& type)
{
	_as_construct_AsIOErrorEvent(type, false);
}
 
bool AsIOErrorEvent::_as_static_initialized_AsIOErrorEvent = false;
AsStaticRefInitializer AsIOErrorEvent::_as_static_initializer_AsIOErrorEvent(_as_static_init_AsIOErrorEvent);
void AsIOErrorEvent::_as_static_init_AsIOErrorEvent()
{
	if (!_as_static_initialized_AsIOErrorEvent)
	{
		_as_static_initialized_AsIOErrorEvent = true;
		_as_static_init_AsEvent();
		
		IO_ERROR = ASL("ioError");
		NETWORK_ERROR = ASL("networkError");
		DISK_ERROR = ASL("diskError");
		VERIFY_ERROR = ASL("verifyError");
	}
}
