#include "AsStage.h"
#include "AsPoint.h"
#include "AsDisplayObject.h"
#include "AsString.h"
#include "AsRectangle.h"
#include "AsEnterFrameEvent.h"
#include "AsEvent.h"
#include "AsIllegalOperationError.h"
#include "AsKeyboardEvent.h"
#include "AsMouseEvent.h"
 
AsStage_ref AsStage::mCurrentStage(true);
 
AsStage_ref AsStage::getInstance()
{
	return mCurrentStage;
}
 
void AsStage::tick(float dt)
{
	dispatchEventOnChildren(AS_NEW(AsEnterFrameEvent,(AsEvent::ENTER_FRAME, dt)));
}
 
AsDisplayObject_ref AsStage::hitTest(const AsPoint_ref& localPoint, bool forTouch)
{
	if((forTouch && (!(getVisible()) || !(getTouchable()))))
	{
		return AS_NULL;
	}
	AsDisplayObject_ref target = AsDisplayObjectContainer::hitTest(localPoint, forTouch);
	if((target == AS_NULL))
	{
		target = this;
	}
	return target;
}
 
AsDisplayObject_ref AsStage::hitTest(const AsPoint_ref& localPoint)
{
	return hitTest(localPoint, false);
}
 
void AsStage::setWidth(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot set width of stage")));
}
 
void AsStage::setHeight(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot set height of stage")));
}
 
void AsStage::setX(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot set x-coordinate of stage")));
}
 
void AsStage::setY(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot set y-coordinate of stage")));
}
 
void AsStage::setScaleX(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot scale stage")));
}
 
void AsStage::setScaleY(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot scale stage")));
}
 
void AsStage::setRotation(float value)
{
	throw AS_NEW(AsIllegalOperationError,(ASL("Cannot rotate stage")));
}
 
uint AsStage::getColor()
{
	return mColor;
}
 
void AsStage::setColor(uint value)
{
	mColor = value;
}
 
int AsStage::getStageWidth()
{
	return mWidth;
}
 
void AsStage::setStageWidth(int value)
{
	mWidth = value;
}
 
int AsStage::getStageHeight()
{
	return mHeight;
}
 
void AsStage::setStageHeight(int value)
{
	mHeight = value;
}
 
AsString_ref AsStage::getQuality()
{
	return mStageQuality;
}
 
void AsStage::setQuality(const AsString_ref& value)
{
	mStageQuality = value;
}
 
float AsStage::getFrameRate()
{
	return mFrameRate;
}
 
void AsStage::setFrameRate(float value)
{
	mFrameRate = value;
}
 
AsString_ref AsStage::getAlign()
{
	return mAlign;
}
 
void AsStage::setAlign(const AsString_ref& value)
{
	mAlign = value;
}
 
AsString_ref AsStage::getScaleMode()
{
	return mScaleMode;
}
 
void AsStage::setScaleMode(const AsString_ref& value)
{
	mScaleMode = value;
}
 
AsRectangle_ref AsStage::getFullScreenSourceRect()
{
	return mFullScreenSourceRect;
}
 
void AsStage::setFullScreenSourceRect(const AsRectangle_ref& value)
{
	mFullScreenSourceRect = value;
}
 
bool AsStage::getStageFocusRect()
{
	return mStageFocusRect;
}
 
void AsStage::setStageFocusRect(bool on)
{
	mStageFocusRect = on;
}
 
bool AsStage::getTabChildren()
{
	return mTabChildren;
}
 
void AsStage::setTabChildren(bool value)
{
	mTabChildren = value;
}
 
void AsStage::keyPressed(uint code)
{
	dispatchEvent(AS_NEW(AsKeyboardEvent,(AsKeyboardEvent::KEY_DOWN, code)));
}
 
void AsStage::keyReleased(uint code)
{
	dispatchEvent(AS_NEW(AsKeyboardEvent,(AsKeyboardEvent::KEY_UP, code)));
}
 
void AsStage::touchDown(float x, float y, int touchId)
{
	dispatchEvent(AS_NEW(AsMouseEvent,(AsMouseEvent::MOUSE_DOWN, x, y)));
}
 
void AsStage::touchMove(float x, float y, int touchId)
{
	dispatchEvent(AS_NEW(AsMouseEvent,(AsMouseEvent::MOUSE_MOVE, x, y)));
}
 
void AsStage::touchDragged(float x, float y, int touchId)
{
	dispatchEvent(AS_NEW(AsMouseEvent,(AsMouseEvent::MOUSE_MOVE, x, y)));
}
 
void AsStage::touchUp(float x, float y, int touchId)
{
	dispatchEvent(AS_NEW(AsMouseEvent,(AsMouseEvent::MOUSE_UP, x, y)));
}
 
AsStage_ref AsStage::_as_create_AsStage(int width, int height, uint color)
{
	AsStage_ref __instance = new AsStage();
	__instance->_as_construct_AsStage(width, height, color);
	return __instance;
}
 
AsStage_ref AsStage::_as_create_AsStage(int width, int height)
{
	AsStage_ref __instance = new AsStage();
	__instance->_as_construct_AsStage(width, height);
	return __instance;
}
 
void AsStage::_as_construct_AsStage(int width, int height, uint color)
{
	_as_construct_AsDisplayObjectContainer();
	mWidth = width;
	mHeight = height;
	mColor = color;
	mCurrentStage = this;
}
 
inline void AsStage::_as_construct_AsStage(int width, int height)
{
	_as_construct_AsStage(width, height, 0);
}
 
bool AsStage::_as_static_initialized_AsStage = false;
AsStaticRefInitializer AsStage::_as_static_initializer_AsStage(_as_static_init_AsStage);
void AsStage::_as_static_init_AsStage()
{
	if (!_as_static_initialized_AsStage)
	{
		_as_static_initialized_AsStage = true;
		_as_static_init_AsDisplayObjectContainer();
		
		AsEnterFrameEvent::_as_static_init_AsEnterFrameEvent();
		AsEvent::_as_static_init_AsEvent();
		AsDisplayObject::_as_static_init_AsDisplayObject();
		AsKeyboardEvent::_as_static_init_AsKeyboardEvent();
		AsMouseEvent::_as_static_init_AsMouseEvent();
		
		mCurrentStage = AS_NULL;
	}
}
 
void AsStage::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsDisplayObjectContainer::_as_gc_mark();
		AS_GC_MARK(mStageQuality)
		AS_GC_MARK(mAlign)
		AS_GC_MARK(mScaleMode)
		AS_GC_MARK(mFullScreenSourceRect)
	}
}
 
AsStage::AsStage() : 
  mWidth(0),
  mHeight(0),
  mColor(0),
  mStageQuality(false),
  mFrameRate(0),
  mAlign(false),
  mScaleMode(false),
  mFullScreenSourceRect(false),
  mStageFocusRect(0),
  mTabChildren(0)
{
}
