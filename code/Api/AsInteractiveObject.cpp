#include "AsInteractiveObject.h"
 
 
bool AsInteractiveObject::getDoubleClickEnabled()
{
	return m_doubleClickEnabled;
}
 
void AsInteractiveObject::setDoubleClickEnabled(bool enabled)
{
	m_doubleClickEnabled = enabled;
}
 
bool AsInteractiveObject::getFocusRect()
{
	return mFocusRect;
}
 
void AsInteractiveObject::setFocusRect(bool focusRect)
{
	mFocusRect = focusRect;
}
 
bool AsInteractiveObject::getMouseEnabled()
{
	return m_mouseEnabled;
}
 
void AsInteractiveObject::setMouseEnabled(bool enabled)
{
	m_mouseEnabled = enabled;
}
 
bool AsInteractiveObject::_as_static_initialized_AsInteractiveObject = false;
AsStaticRefInitializer AsInteractiveObject::_as_static_initializer_AsInteractiveObject(_as_static_init_AsInteractiveObject);
void AsInteractiveObject::_as_static_init_AsInteractiveObject()
{
	if (!_as_static_initialized_AsInteractiveObject)
	{
		_as_static_initialized_AsInteractiveObject = true;
		_as_static_init_AsDisplayObject();
	}
}
 
AsInteractiveObject::AsInteractiveObject() : 
  m_mouseEnabled(0),
  m_doubleClickEnabled(0),
  mFocusRect(0)
{
}
