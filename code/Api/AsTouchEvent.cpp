#include "AsTouchEvent.h"
#include "AsString.h"
#include "AsVector.h"
AS_VECTOR_REF(AsTouch);
#include "AsTouch.h"
#include "AsDisplayObject.h"
#include "AsDisplayObjectContainer.h"
#include "AsTouchPhase.h"
 
AsString_ref AsTouchEvent::TOUCH(true);
AsString_ref AsTouchEvent::TOUCH_BEGIN(true);
AsString_ref AsTouchEvent::TOUCH_END(true);
AsString_ref AsTouchEvent::TOUCH_MOVE(true);
AsString_ref AsTouchEvent::TOUCH_OVER(true);
AsString_ref AsTouchEvent::TOUCH_OUT(true);
AsString_ref AsTouchEvent::TOUCH_ROLL_OVER(true);
AsString_ref AsTouchEvent::TOUCH_ROLL_OUT(true);
AsString_ref AsTouchEvent::TOUCH_TAP(true);
AsString_ref AsTouchEvent::PROXIMITY_BEGIN(true);
AsString_ref AsTouchEvent::PROXIMITY_END(true);
AsString_ref AsTouchEvent::PROXIMITY_MOVE(true);
AsString_ref AsTouchEvent::PROXIMITY_OUT(true);
AsString_ref AsTouchEvent::PROXIMITY_OVER(true);
AsString_ref AsTouchEvent::PROXIMITY_ROLL_OUT(true);
AsString_ref AsTouchEvent::PROXIMITY_ROLL_OVER(true);
 
_V_AsTouch_ref AsTouchEvent::getTouches(const AsDisplayObject_ref& target, const AsString_ref& phase)
{
	_V_AsTouch_ref touchesFound = AS_NEW_VECTOR(AsTouch,());
	int numTouches = (int)(mTouches->getLength());
	int i = 0;
	for (; (i < numTouches); ++i)
	{
		AsTouch_ref touch = mTouches[i];
		bool correctTarget = ((touch->getTarget() == target) || (AS_IS(target, DisplayObjectContainer) && ((AS_IS(target, DisplayObjectContainer)) ? ((AsDisplayObjectContainer_ref)(target)) : AS_NULL)->contains(touch->getTarget())));
		bool correctPhase = ((phase == AS_NULL) || (phase == touch->getPhase()));
		if((correctTarget && correctPhase))
		{
			touchesFound->push(touch);
		}
	}
	return touchesFound;
}
 
_V_AsTouch_ref AsTouchEvent::getTouches(const AsDisplayObject_ref& target)
{
	return getTouches(target, AS_NULL);
}
 
AsTouch_ref AsTouchEvent::getTouch(const AsDisplayObject_ref& target, const AsString_ref& phase)
{
	_V_AsTouch_ref touchesFound = getTouches(target, phase);
	if((touchesFound->getLength() > 0))
	{
		return touchesFound[0];
	}
	else
	{
		return AS_NULL;
	}
}
 
AsTouch_ref AsTouchEvent::getTouch(const AsDisplayObject_ref& target)
{
	return getTouch(target, AS_NULL);
}
 
bool AsTouchEvent::interactsWith(const AsDisplayObject_ref& target)
{
	if((getTouch(target) == AS_NULL))
	{
		return false;
	}
	else
	{
		_V_AsTouch_ref touches = getTouches(target);
		int i = (int)((touches->getLength() - 1));
		for (; (i >= 0); --i)
		{
			if((touches[i]->getPhase() != AsTouchPhase::ENDED))
			{
				return true;
			}
		}
		return false;
	}
}
 
float AsTouchEvent::getTimestamp()
{
	return mTimestamp;
}
 
_V_AsTouch_ref AsTouchEvent::getTouches()
{
	return mTouches->concat();
}
 
bool AsTouchEvent::getShiftKey()
{
	return mShiftKey;
}
 
bool AsTouchEvent::getCtrlKey()
{
	return mCtrlKey;
}
 
AsTouchEvent_ref AsTouchEvent::_as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey, bool bubbles)
{
	AsTouchEvent_ref __instance = new AsTouchEvent();
	__instance->_as_construct_AsTouchEvent(type, touches, shiftKey, ctrlKey, bubbles);
	return __instance;
}
 
AsTouchEvent_ref AsTouchEvent::_as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey)
{
	AsTouchEvent_ref __instance = new AsTouchEvent();
	__instance->_as_construct_AsTouchEvent(type, touches, shiftKey, ctrlKey);
	return __instance;
}
 
AsTouchEvent_ref AsTouchEvent::_as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey)
{
	AsTouchEvent_ref __instance = new AsTouchEvent();
	__instance->_as_construct_AsTouchEvent(type, touches, shiftKey);
	return __instance;
}
 
AsTouchEvent_ref AsTouchEvent::_as_create_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches)
{
	AsTouchEvent_ref __instance = new AsTouchEvent();
	__instance->_as_construct_AsTouchEvent(type, touches);
	return __instance;
}
 
void AsTouchEvent::_as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey, bool bubbles)
{
	_as_construct_AsEvent(type, bubbles);
	mTouches = ((touches != AS_NULL) ? (touches) : (AS_NEW_VECTOR(AsTouch,())));
	mShiftKey = shiftKey;
	mCtrlKey = ctrlKey;
	mTimestamp = -1.0f;
	int numTouches = (int)(touches->getLength());
	int i = 0;
	for (; (i < numTouches); ++i)
	{
		if((touches[i]->getTimestamp() > mTimestamp))
		{
			mTimestamp = touches[i]->getTimestamp();
		}
	}
}
 
inline void AsTouchEvent::_as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey, bool ctrlKey)
{
	_as_construct_AsTouchEvent(type, touches, shiftKey, ctrlKey, true);
}
 
inline void AsTouchEvent::_as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches, bool shiftKey)
{
	_as_construct_AsTouchEvent(type, touches, shiftKey, false, true);
}
 
inline void AsTouchEvent::_as_construct_AsTouchEvent(const AsString_ref& type, const _V_AsTouch_ref& touches)
{
	_as_construct_AsTouchEvent(type, touches, false, false, true);
}
 
bool AsTouchEvent::_as_static_initialized_AsTouchEvent = false;
AsStaticRefInitializer AsTouchEvent::_as_static_initializer_AsTouchEvent(_as_static_init_AsTouchEvent);
void AsTouchEvent::_as_static_init_AsTouchEvent()
{
	if (!_as_static_initialized_AsTouchEvent)
	{
		_as_static_initialized_AsTouchEvent = true;
		_as_static_init_AsEvent();
		
		AsTouch::_as_static_init_AsTouch();
		AsDisplayObjectContainer::_as_static_init_AsDisplayObjectContainer();
		AsTouchPhase::_as_static_init_AsTouchPhase();
		
		TOUCH = ASL("touch");
		TOUCH_BEGIN = ASL("touchBegin");
		TOUCH_END = ASL("touchEnd");
		TOUCH_MOVE = ASL("touchMove");
		TOUCH_OVER = ASL("touchOver");
		TOUCH_OUT = ASL("touchOut");
		TOUCH_ROLL_OVER = ASL("touchRollOver");
		TOUCH_ROLL_OUT = ASL("touchRollOut");
		TOUCH_TAP = ASL("touchTap");
		PROXIMITY_BEGIN = ASL("proximityBegin");
		PROXIMITY_END = ASL("proximityEnd");
		PROXIMITY_MOVE = ASL("proximityMove");
		PROXIMITY_OUT = ASL("proximityOut");
		PROXIMITY_OVER = ASL("proximityOver");
		PROXIMITY_ROLL_OUT = ASL("proximityRollOut");
		PROXIMITY_ROLL_OVER = ASL("proximityRollOver");
	}
}
 
void AsTouchEvent::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsEvent::_as_gc_mark();
		AS_GC_MARK(mTouches)
	}
}
 
AsTouchEvent::AsTouchEvent() : 
  mTouches(false),
  mShiftKey(0),
  mCtrlKey(0),
  mTimestamp(0)
{
}
