#include "AsTouch.h"
#include "AsString.h"
#include "AsDisplayObject.h"
#include "AsTouch.h"
#include "AsNotImplementedError.h"
 
 
AsPoint_ref AsTouch::getLocation(const AsDisplayObject_ref& space)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsPoint_ref AsTouch::getPreviousLocation(const AsDisplayObject_ref& space)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsTouch_ref AsTouch::clone()
{
	AsTouch_ref clone = AS_NEW(AsTouch,(mID, mGlobalX, mGlobalY, mPhase, mTarget));
	clone->mPreviousGlobalX = mPreviousGlobalX;
	clone->mPreviousGlobalY = mPreviousGlobalY;
	clone->mTapCount = mTapCount;
	clone->mTimestamp = mTimestamp;
	return clone;
}
 
int AsTouch::getId()
{
	return mID;
}
 
float AsTouch::getGlobalX()
{
	return mGlobalX;
}
 
float AsTouch::getGlobalY()
{
	return mGlobalY;
}
 
float AsTouch::getPreviousGlobalX()
{
	return mPreviousGlobalX;
}
 
float AsTouch::getPreviousGlobalY()
{
	return mPreviousGlobalY;
}
 
int AsTouch::getTapCount()
{
	return mTapCount;
}
 
AsString_ref AsTouch::getPhase()
{
	return mPhase;
}
 
AsDisplayObject_ref AsTouch::getTarget()
{
	return mTarget;
}
 
float AsTouch::getTimestamp()
{
	return mTimestamp;
}
 
void AsTouch::setPosition(float globalX, float globalY)
{
	mPreviousGlobalX = mGlobalX;
	mPreviousGlobalY = mGlobalY;
	mGlobalX = globalX;
	mGlobalY = globalY;
}
 
void AsTouch::setPhase(const AsString_ref& value)
{
	mPhase = value;
}
 
void AsTouch::setTapCount(int value)
{
	mTapCount = value;
}
 
void AsTouch::setTarget(const AsDisplayObject_ref& value)
{
	mTarget = value;
}
 
void AsTouch::setTimestamp(float value)
{
	mTimestamp = value;
}
 
AsTouch_ref AsTouch::_as_create_AsTouch(int id, float globalX, float globalY, const AsString_ref& phase, const AsDisplayObject_ref& target)
{
	AsTouch_ref __instance = new AsTouch();
	__instance->_as_construct_AsTouch(id, globalX, globalY, phase, target);
	return __instance;
}
 
void AsTouch::_as_construct_AsTouch(int id, float globalX, float globalY, const AsString_ref& phase, const AsDisplayObject_ref& target)
{
	mID = id;
	mGlobalX = mPreviousGlobalX = globalX;
	mGlobalY = mPreviousGlobalY = globalY;
	mTapCount = 0;
	mPhase = phase;
	mTarget = target;
}
 
bool AsTouch::_as_static_initialized_AsTouch = false;
AsStaticRefInitializer AsTouch::_as_static_initializer_AsTouch(_as_static_init_AsTouch);
void AsTouch::_as_static_init_AsTouch()
{
	if (!_as_static_initialized_AsTouch)
	{
		_as_static_initialized_AsTouch = true;
	}
}
 
void AsTouch::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mPhase)
		AS_GC_MARK(mTarget)
	}
}
 
AsTouch::AsTouch() : 
  mID(0),
  mGlobalX(0),
  mGlobalY(0),
  mPreviousGlobalX(0),
  mPreviousGlobalY(0),
  mTapCount(0),
  mPhase(false),
  mTarget(false),
  mTimestamp(0)
{
}
