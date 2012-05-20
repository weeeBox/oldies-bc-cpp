#include "AsPixelSnapping.h"
 
AsString_ref AsPixelSnapping::NEVER(true);
AsString_ref AsPixelSnapping::ALWAYS(true);
AsString_ref AsPixelSnapping::AUTO(true);
 
bool AsPixelSnapping::_as_static_initialized_AsPixelSnapping = false;
AsStaticRefInitializer AsPixelSnapping::_as_static_initializer_AsPixelSnapping(_as_static_init_AsPixelSnapping);
void AsPixelSnapping::_as_static_init_AsPixelSnapping()
{
	if (!_as_static_initialized_AsPixelSnapping)
	{
		_as_static_initialized_AsPixelSnapping = true;
		
		NEVER = ASL("never");
		ALWAYS = ASL("always");
		AUTO = ASL("auto");
	}
}
