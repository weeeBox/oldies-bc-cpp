#include "AsStageAlign.h"
 
AsString_ref AsStageAlign::TOP(true);
AsString_ref AsStageAlign::LEFT(true);
AsString_ref AsStageAlign::BOTTOM(true);
AsString_ref AsStageAlign::RIGHT(true);
AsString_ref AsStageAlign::TOP_LEFT(true);
AsString_ref AsStageAlign::TOP_RIGHT(true);
AsString_ref AsStageAlign::BOTTOM_LEFT(true);
AsString_ref AsStageAlign::BOTTOM_RIGHT(true);
 
bool AsStageAlign::_as_static_initialized_AsStageAlign = false;
AsStaticRefInitializer AsStageAlign::_as_static_initializer_AsStageAlign(_as_static_init_AsStageAlign);
void AsStageAlign::_as_static_init_AsStageAlign()
{
	if (!_as_static_initialized_AsStageAlign)
	{
		_as_static_initialized_AsStageAlign = true;
		
		TOP = ASL("T");
		LEFT = ASL("L");
		BOTTOM = ASL("B");
		RIGHT = ASL("R");
		TOP_LEFT = ASL("TL");
		TOP_RIGHT = ASL("TR");
		BOTTOM_LEFT = ASL("BL");
		BOTTOM_RIGHT = ASL("BR");
	}
}
