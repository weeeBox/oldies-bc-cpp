#ifndef AsKeyboardEvent_h__
#define AsKeyboardEvent_h__
 
#include "AsBc.h"
 
#include "AsEvent.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsKeyboardEvent);
 
class AsKeyboardEvent : public AsEvent
{
public:
	AS_OBJ(AsKeyboardEvent, AsEvent);
	
public:
	static AsString_ref KEY_UP;
	static AsString_ref KEY_DOWN;
	
private:
	uint mCharCode;
	uint mKeyCode;
	uint mKeyLocation;
	bool mAltKey;
	bool mCtrlKey;
	bool mShiftKey;
	
public:
	virtual uint getCharCode();
	virtual uint getKeyCode();
	virtual uint getKeyLocation();
	virtual bool getAltKey();
	virtual bool getCtrlKey();
	virtual bool getShiftKey();
	
	
public:
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey, bool shiftKey);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type, uint charCode);
	static AsKeyboardEvent_ref _as_create_AsKeyboardEvent(const AsString_ref& type);
	
protected:
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey, bool shiftKey);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey, bool altKey);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation, bool ctrlKey);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode, uint keyLocation);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode, uint keyCode);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type, uint charCode);
	void _as_construct_AsKeyboardEvent(const AsString_ref& type);
	
public:
	static void _as_static_init_AsKeyboardEvent();
	
private:
	static bool _as_static_initialized_AsKeyboardEvent;
	static AsStaticRefInitializer _as_static_initializer_AsKeyboardEvent;
	
	
protected:
	AsKeyboardEvent();
};
 
#endif // AsKeyboardEvent_h__
