#ifndef AsTouchEvent_h__
#define AsTouchEvent_h__
 
#include "AsBc.h"
 
#include "AsEvent.h"
 
#include "AsString.h"
#include "AsVector.h"
 
#ifndef AsTouch_h__
#include "AsTouch.h"
#else
AS_CLASS(AsTouch);
#endif // AsTouch_h__
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
AS_VECTOR_REF(AsTouch);
 
AS_CLASS(AsTouchEvent);
 
class AsTouchEvent : public AsEvent
{
public:
	AS_OBJ(AsTouchEvent, AsEvent);
	
public:
	static AsString_ref TOUCH;
	static AsString_ref TOUCH_BEGIN;
	static AsString_ref TOUCH_END;
	static AsString_ref TOUCH_MOVE;
	static AsString_ref TOUCH_OVER;
	static AsString_ref TOUCH_OUT;
	static AsString_ref TOUCH_ROLL_OVER;
	static AsString_ref TOUCH_ROLL_OUT;
	static AsString_ref TOUCH_TAP;
	static AsString_ref PROXIMITY_BEGIN;
	static AsString_ref PROXIMITY_END;
	static AsString_ref PROXIMITY_MOVE;
	static AsString_ref PROXIMITY_OUT;
	static AsString_ref PROXIMITY_OVER;
	static AsString_ref PROXIMITY_ROLL_OUT;
	static AsString_ref PROXIMITY_ROLL_OVER;
	
private:
	_V_AsTouch_ref mTouches;
	bool mShiftKey;
	bool mCtrlKey;
	float mTimestamp;
	
public:
	virtual _V_AsTouch_ref getTouches(const AsDisplayObject_ref& target, const AsString_ref& phase);
	virtual _V_AsTouch_ref getTouches(const AsDisplayObject_ref& target);
	virtual AsTouch_ref getTouch(const AsDisplayObject_ref& target, const AsString_ref& phase);
	virtual AsTouch_ref getTouch(const AsDisplayObject_ref& target);
	virtual bool interactsWith(const AsDisplayObject_ref& target);
	virtual float getTimestamp();
	virtual _V_AsTouch_ref getTouches();
	virtual bool getShiftKey();
	virtual bool getCtrlKey();
	
	
public:
	static AsTouchEvent_ref _as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey, bool bubbles);
	static AsTouchEvent_ref _as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey);
	static AsTouchEvent_ref _as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey);
	static AsTouchEvent_ref _as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches);
	
protected:
	void _as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey, bool bubbles);
	void _as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey);
	void _as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey);
	void _as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches);
	
public:
	static void _as_static_init_AsTouchEvent();
	
private:
	static bool _as_static_initialized_AsTouchEvent;
	static AsStaticRefInitializer _as_static_initializer_AsTouchEvent;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsTouchEvent();
};
 
#endif // AsTouchEvent_h__
