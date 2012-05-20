#include "AsTouchProcessor.h"
#include "AsStage.h"
#include "AsTouch.h"
#include "AsTouchData.h"
#include "AsString.h"
#include "AsPoint.h"
#include "AsEvent.h"
#include "AsKeyboardEvent.h"
#include "AsVector.h"
AS_VECTOR_REF(AsTouch);
#include "AsTouchPhase.h"
AS_VECTOR_REF(AsTouchData);
#include "AsTouchEvent.h"
AS_VECTOR_PRIMITIVE_REF(int);
#include "AsMath.h"
 
const float AsTouchProcessor::MULTITAP_TIME = 0.3f;
const float AsTouchProcessor::MULTITAP_DISTANCE = 25;
_V_int_ref AsTouchProcessor::sProcessedTouchIDs(true);
_V_AsTouchData_ref AsTouchProcessor::sHoveringTouchData(true);
 
void AsTouchProcessor::dispose()
{
	mStage->removeEventListener(AsKeyboardEvent::KEY_DOWN, onKey);
	mStage->removeEventListener(AsKeyboardEvent::KEY_UP, onKey);
}
 
void AsTouchProcessor::advanceTime(float passedTime)
{
	int i = 0;
	AsTouch_ref touch = AS_NULL;
	mElapsedTime = (mElapsedTime + passedTime);
	mOffsetTime = 0.0f;
	if((mLastTaps->getLength() > 0))
	{
		for (i = (int)((mLastTaps->getLength() - 1)); (i >= 0); --i)
		{
			if(((mElapsedTime - mLastTaps[i]->getTimestamp()) > MULTITAP_TIME))
			{
				mLastTaps->splice(i, (uint)(1));
			}
		}
	}
	while((mQueue->getLength() > 0))
	{
		sProcessedTouchIDs->setLength(0);
		sHoveringTouchData->setLength(0);
		{ _V_AsTouch_ref __currentTouchs_ = mCurrentTouches; 
		if (__currentTouchs_ != AS_NULL) { for(_as_AsRefVector<AsTouch_ref>::Iterator it = (__currentTouchs_)->iterator(); it.hasNext();) { AsTouch_ref currentTouch = it.next();
		{
			if(((currentTouch->getPhase() == AsTouchPhase::BEGAN) || (currentTouch->getPhase() == AsTouchPhase::MOVED)))
			{
				currentTouch->setPhase(AsTouchPhase::STATIONARY);
			}
		}
		}}}
		{ _V_AsTouchData_ref __touchDatas_ = sHoveringTouchData; 
		if (__touchDatas_ != AS_NULL) { for(_as_AsRefVector<AsTouchData_ref>::Iterator it = (__touchDatas_)->iterator(); it.hasNext();) { AsTouchData_ref touchData = it.next();
		{
			if((touchData->touch->getTarget() != touchData->target))
			{
				touchData->target->dispatchEvent(AS_NEW(AsTouchEvent,(AsTouchEvent::TOUCH, mCurrentTouches, mShiftDown, mCtrlDown)));
			}
		}
		}}}
		{ _V_int_ref __touchIDs_ = sProcessedTouchIDs; 
		if (__touchIDs_ != AS_NULL) { for(AsVector<int>::Iterator it = (__touchIDs_)->iterator(); it.hasNext();) { int touchID = it.next();
		{
			touch = getCurrentTouch(touchID);
			if(touch->getTarget() != AS_NULL)
			{
				touch->getTarget()->dispatchEvent(AS_NEW(AsTouchEvent,(AsTouchEvent::TOUCH, mCurrentTouches, mShiftDown, mCtrlDown)));
			}
		}
		}}}
		for (i = (int)((mCurrentTouches->getLength() - 1)); (i >= 0); --i)
		{
			if((mCurrentTouches[i]->getPhase() == AsTouchPhase::ENDED))
			{
				mCurrentTouches->splice(i, (uint)(1));
			}
		}
		mOffsetTime = (mOffsetTime + 0.00001f);
	}
}
 
void AsTouchProcessor::enqueue(int touchID, const AsString_ref& phase, float globalX, float globalY)
{
}
 
void AsTouchProcessor::processTouch(int touchID, const AsString_ref& phase, float globalX, float globalY)
{
	AsPoint_ref position = AS_NEW(AsPoint,(globalX, globalY));
	AsTouch_ref touch = getCurrentTouch(touchID);
	if((touch == AS_NULL))
	{
		touch = AS_NEW(AsTouch,(touchID, globalX, globalY, phase, AS_NULL));
		addCurrentTouch(touch);
	}
	touch->setPosition(globalX, globalY);
	touch->setPhase(phase);
	touch->setTimestamp((mElapsedTime + mOffsetTime));
	if(((phase == AsTouchPhase::HOVER) || (phase == AsTouchPhase::BEGAN)))
	{
		touch->setTarget(mStage->hitTest(position, true));
	}
	if((phase == AsTouchPhase::BEGAN))
	{
		processTap(touch);
	}
}
 
void AsTouchProcessor::onKey(const AsEvent_ref& evt)
{
	AsKeyboardEvent_ref event = ((AsKeyboardEvent_ref)(evt));
	if(((event->getKeyCode() == 17) || (event->getKeyCode() == 15)))
	{
		bool wasCtrlDown = mCtrlDown;
		mCtrlDown = (event->getType() == AsKeyboardEvent::KEY_DOWN);
	}
	else
	{
		if((event->getKeyCode() == 16))
		{
			mShiftDown = (event->getType() == AsKeyboardEvent::KEY_DOWN);
		}
	}
}
 
void AsTouchProcessor::processTap(const AsTouch_ref& touch)
{
	AsTouch_ref nearbyTap = AS_NULL;
	float minSqDist = (MULTITAP_DISTANCE * MULTITAP_DISTANCE);
	{ _V_AsTouch_ref __taps_ = mLastTaps; 
	if (__taps_ != AS_NULL) { for(_as_AsRefVector<AsTouch_ref>::Iterator it = (__taps_)->iterator(); it.hasNext();) { AsTouch_ref tap = it.next();
	{
		float sqDist = (AsMath::pow((tap->getGlobalX() - touch->getGlobalX()), 2) + AsMath::pow((tap->getGlobalY() - touch->getGlobalY()), 2));
		if((sqDist <= minSqDist))
		{
			nearbyTap = tap;
			break;
		}
	}
	}}}
	if(nearbyTap != AS_NULL)
	{
		touch->setTapCount((nearbyTap->getTapCount() + 1));
		mLastTaps->splice(mLastTaps->indexOf(nearbyTap), (uint)(1));
	}
	else
	{
		touch->setTapCount(1);
	}
	mLastTaps->push(touch->clone());
}
 
void AsTouchProcessor::addCurrentTouch(const AsTouch_ref& touch)
{
	int i = (int)((mCurrentTouches->getLength() - 1));
	for (; (i >= 0); --i)
	{
		if((mCurrentTouches[i]->getId() == touch->getId()))
		{
			mCurrentTouches->splice(i, (uint)(1));
		}
	}
	mCurrentTouches->push(touch);
}
 
AsTouch_ref AsTouchProcessor::getCurrentTouch(int touchID)
{
	{ _V_AsTouch_ref __touchs_ = mCurrentTouches; 
	if (__touchs_ != AS_NULL) { for(_as_AsRefVector<AsTouch_ref>::Iterator it = (__touchs_)->iterator(); it.hasNext();) { AsTouch_ref touch = it.next();
	{
		if((touch->getId() == touchID))
		{
			return touch;
		}
	}
	}}}
	return AS_NULL;
}
 
AsTouchProcessor_ref AsTouchProcessor::_as_create_AsTouchProcessor(const AsStage_ref& stage)
{
	AsTouchProcessor_ref __instance = new AsTouchProcessor();
	__instance->_as_construct_AsTouchProcessor(stage);
	return __instance;
}
 
void AsTouchProcessor::_as_construct_AsTouchProcessor(const AsStage_ref& stage)
{
	_as_init_fields_AsTouchProcessor();
	mStage = stage;
	mElapsedTime = mOffsetTime = 0.0f;
	mCurrentTouches = AS_NEW_VECTOR(AsTouch,());
	mQueue = AS_NEW_VECTOR(AsArray,());
	mLastTaps = AS_NEW_VECTOR(AsTouch,());
	mStage->addEventListener(AsKeyboardEvent::KEY_DOWN, onKey);
	mStage->addEventListener(AsKeyboardEvent::KEY_UP, onKey);
}
 
void AsTouchProcessor::_as_init_fields_AsTouchProcessor()
{
	mShiftDown = false;
	mCtrlDown = false;
}
 
bool AsTouchProcessor::_as_static_initialized_AsTouchProcessor = false;
AsStaticRefInitializer AsTouchProcessor::_as_static_initializer_AsTouchProcessor(_as_static_init_AsTouchProcessor);
void AsTouchProcessor::_as_static_init_AsTouchProcessor()
{
	if (!_as_static_initialized_AsTouchProcessor)
	{
		_as_static_initialized_AsTouchProcessor = true;
		
		AsKeyboardEvent::_as_static_init_AsKeyboardEvent();
		AsTouch::_as_static_init_AsTouch();
		AsTouchPhase::_as_static_init_AsTouchPhase();
		AsTouchData::_as_static_init_AsTouchData();
		AsTouchEvent::_as_static_init_AsTouchEvent();
		AsPoint::_as_static_init_AsPoint();
		
		sProcessedTouchIDs = AS_NEW_PRIMITIVES_VECTOR(int,());
		sHoveringTouchData = AS_NEW_VECTOR(AsTouchData,());
	}
}
 
void AsTouchProcessor::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mStage)
		AS_GC_MARK(mCurrentTouches)
		AS_GC_MARK(mQueue)
		AS_GC_MARK(mLastTaps)
	}
}
 
AsTouchProcessor::AsTouchProcessor() : 
  mStage(false),
  mElapsedTime(0),
  mOffsetTime(0),
  mCurrentTouches(false),
  mQueue(false),
  mLastTaps(false)
{
}
