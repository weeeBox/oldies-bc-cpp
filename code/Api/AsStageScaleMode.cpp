#include "AsStageScaleMode.h"
 
AsString_ref AsStageScaleMode::SHOW_ALL(true);
AsString_ref AsStageScaleMode::EXACT_FIT(true);
AsString_ref AsStageScaleMode::NO_BORDER(true);
AsString_ref AsStageScaleMode::NO_SCALE(true);
 
bool AsStageScaleMode::_as_static_initialized_AsStageScaleMode = false;
AsStaticRefInitializer AsStageScaleMode::_as_static_initializer_AsStageScaleMode(_as_static_init_AsStageScaleMode);
void AsStageScaleMode::_as_static_init_AsStageScaleMode()
{
	if (!_as_static_initialized_AsStageScaleMode)
	{
		_as_static_initialized_AsStageScaleMode = true;
		
		SHOW_ALL = ASL("showAll");
		EXACT_FIT = ASL("exactFit");
		NO_BORDER = ASL("noBorder");
		NO_SCALE = ASL("noScale");
	}
}
