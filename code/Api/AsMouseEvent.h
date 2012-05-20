#ifndef AsMouseEvent_h__
#define AsMouseEvent_h__
 
#include "AsBc.h"
 
#include "AsEvent.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsMouseEvent);
 
class AsMouseEvent : public AsEvent
{
public:
	AS_OBJ(AsMouseEvent, AsEvent);
	
public:
	static AsString_ref CLICK;
	static AsString_ref DOUBLE_CLICK;
	static AsString_ref MOUSE_DOWN;
	static AsString_ref MOUSE_MOVE;
	static AsString_ref MOUSE_OUT;
	static AsString_ref MOUSE_OVER;
	static AsString_ref MOUSE_UP;
	static AsString_ref MOUSE_WHEEL;
	static AsString_ref ROLL_OUT;
	static AsString_ref ROLL_OVER;
	
private:
	float mX;
	float mY;
	
public:
	virtual float getStageX();
	virtual float getStageY();
	
	
public:
	static AsMouseEvent_ref _as_create_AsMouseEvent(const AsString_ref& type, float x, float y, bool bubbles);
	static AsMouseEvent_ref _as_create_AsMouseEvent(const AsString_ref& type, float x, float y);
	
protected:
	void _as_construct_AsMouseEvent(const AsString_ref& type, float x, float y, bool bubbles);
	void _as_construct_AsMouseEvent(const AsString_ref& type, float x, float y);
	
public:
	static void _as_static_init_AsMouseEvent();
	
private:
	static bool _as_static_initialized_AsMouseEvent;
	static AsStaticRefInitializer _as_static_initializer_AsMouseEvent;
	
	
protected:
	AsMouseEvent();
};
 
#endif // AsMouseEvent_h__
