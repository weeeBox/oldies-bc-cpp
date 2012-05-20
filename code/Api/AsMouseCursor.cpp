#include "AsMouseCursor.h"
 
AsString_ref AsMouseCursor::AUTO(true);
AsString_ref AsMouseCursor::ARROW(true);
AsString_ref AsMouseCursor::BUTTON(true);
AsString_ref AsMouseCursor::HAND(true);
AsString_ref AsMouseCursor::IBEAM(true);
 
bool AsMouseCursor::_as_static_initialized_AsMouseCursor = false;
AsStaticRefInitializer AsMouseCursor::_as_static_initializer_AsMouseCursor(_as_static_init_AsMouseCursor);
void AsMouseCursor::_as_static_init_AsMouseCursor()
{
	if (!_as_static_initialized_AsMouseCursor)
	{
		_as_static_initialized_AsMouseCursor = true;
		
		AUTO = ASL("auto");
		ARROW = ASL("arrow");
		BUTTON = ASL("button");
		HAND = ASL("hand");
		IBEAM = ASL("ibeam");
	}
}
