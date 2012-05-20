#include "AsMouse.h"
#include "AsString.h"
 
AsString_ref AsMouse::mCursor(true);
bool AsMouse::mHidden(0);
 
AsString_ref AsMouse::getCursor()
{
	return mCursor;
}
 
void AsMouse::setCursor(const AsString_ref& value)
{
	mCursor = value;
}
 
void AsMouse::hide()
{
	mHidden = true;
}
 
void AsMouse::show()
{
	mHidden = false;
}
 
bool AsMouse::_as_static_initialized_AsMouse = false;
AsStaticRefInitializer AsMouse::_as_static_initializer_AsMouse(_as_static_init_AsMouse);
void AsMouse::_as_static_init_AsMouse()
{
	if (!_as_static_initialized_AsMouse)
	{
		_as_static_initialized_AsMouse = true;
		
		mCursor = AS_NULL;
		mHidden = false;
	}
}
