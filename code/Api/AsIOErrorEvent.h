#ifndef AsIOErrorEvent_h__
#define AsIOErrorEvent_h__
 
#include "AsBc.h"
 
#include "AsEvent.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsIOErrorEvent);
 
class AsIOErrorEvent : public AsEvent
{
public:
	AS_OBJ(AsIOErrorEvent, AsEvent);
	
public:
	static AsString_ref IO_ERROR;
	static AsString_ref NETWORK_ERROR;
	static AsString_ref DISK_ERROR;
	static AsString_ref VERIFY_ERROR;
	
	
public:
	static AsIOErrorEvent_ref _as_create_AsIOErrorEvent(const AsString_ref& type, bool bubbles);
	static AsIOErrorEvent_ref _as_create_AsIOErrorEvent(const AsString_ref& type);
	
protected:
	void _as_construct_AsIOErrorEvent(const AsString_ref& type, bool bubbles);
	void _as_construct_AsIOErrorEvent(const AsString_ref& type);
	
public:
	static void _as_static_init_AsIOErrorEvent();
	
private:
	static bool _as_static_initialized_AsIOErrorEvent;
	static AsStaticRefInitializer _as_static_initializer_AsIOErrorEvent;
};
 
#endif // AsIOErrorEvent_h__
