#ifndef AsEnterFrameEvent_h__
#define AsEnterFrameEvent_h__
 
#include "AsBc.h"
 
#include "AsEvent.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsEnterFrameEvent);
 
class AsEnterFrameEvent : public AsEvent
{
public:
	AS_OBJ(AsEnterFrameEvent, AsEvent);
	
private:
	float mPassedTime;
	
public:
	virtual float getPassedTime();
	virtual void setPassedTime(float value);
	
	
public:
	static AsEnterFrameEvent_ref _as_create_AsEnterFrameEvent(const AsString_ref& type, float passedTime, bool bubbles);
	static AsEnterFrameEvent_ref _as_create_AsEnterFrameEvent(const AsString_ref& type, float passedTime);
	
protected:
	void _as_construct_AsEnterFrameEvent(const AsString_ref& type, float passedTime, bool bubbles);
	void _as_construct_AsEnterFrameEvent(const AsString_ref& type, float passedTime);
	
public:
	static void _as_static_init_AsEnterFrameEvent();
	
private:
	static bool _as_static_initialized_AsEnterFrameEvent;
	static AsStaticRefInitializer _as_static_initializer_AsEnterFrameEvent;
	
	
protected:
	AsEnterFrameEvent();
};
 
#endif // AsEnterFrameEvent_h__
