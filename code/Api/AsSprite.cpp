#include "AsSprite.h"
#include "AsEvent.h"
#include "AsTouchEvent.h"
#include "AsGraphics.h"
#include "AsMouse.h"
#include "AsMouseCursor.h"
 
 
void AsSprite::dispose()
{
	AsDisplayObjectContainer::dispose();
}
 
bool AsSprite::getUseHandCursor()
{
	return mUseHandCursor;
}
 
void AsSprite::setUseHandCursor(bool value)
{
	if((value == mUseHandCursor))
	{
		return;
	}
	mUseHandCursor = value;
	if(mUseHandCursor)
	{
		addEventListener(AsTouchEvent::TOUCH, onTouch);
	}
	else
	{
		removeEventListener(AsTouchEvent::TOUCH, onTouch);
	}
}
 
AsGraphics_ref AsSprite::getGraphics()
{
	return mGraphics;
}
 
void AsSprite::onTouch(const AsEvent_ref& evt)
{
	AsTouchEvent_ref event = ((AsTouchEvent_ref)(evt));
	AsMouse::setCursor(((event->interactsWith(this)) ? (AsMouseCursor::BUTTON) : (AsMouseCursor::AUTO)));
}
 
bool AsSprite::getMouseChildren()
{
	return mMouseChildren;
}
 
void AsSprite::setMouseChildren(bool enable)
{
	mMouseChildren = enable;
}
 
bool AsSprite::getTabChildren()
{
	return false;
}
 
void AsSprite::setTabChildren(bool enable)
{
}
 
AsSprite_ref AsSprite::_as_create_AsSprite()
{
	AsSprite_ref __instance = new AsSprite();
	__instance->_as_construct_AsSprite();
	return __instance;
}
 
void AsSprite::_as_construct_AsSprite()
{
	_as_construct_AsDisplayObjectContainer();
	mGraphics = AS_NEW(AsGraphics,());
}
 
bool AsSprite::_as_static_initialized_AsSprite = false;
AsStaticRefInitializer AsSprite::_as_static_initializer_AsSprite(_as_static_init_AsSprite);
void AsSprite::_as_static_init_AsSprite()
{
	if (!_as_static_initialized_AsSprite)
	{
		_as_static_initialized_AsSprite = true;
		_as_static_init_AsDisplayObjectContainer();
	}
}
 
void AsSprite::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsDisplayObjectContainer::_as_gc_mark();
		AS_GC_MARK(mGraphics)
	}
}
 
AsSprite::AsSprite() : 
  mGraphics(false),
  mUseHandCursor(0),
  mMouseChildren(0)
{
}
