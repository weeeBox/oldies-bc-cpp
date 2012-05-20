#include "AsStageDisplayState.h"
 
AsString_ref AsStageDisplayState::FULL_SCREEN(true);
AsString_ref AsStageDisplayState::FULL_SCREEN_INTERACTIVE(true);
AsString_ref AsStageDisplayState::NORMAL(true);
 
bool AsStageDisplayState::_as_static_initialized_AsStageDisplayState = false;
AsStaticRefInitializer AsStageDisplayState::_as_static_initializer_AsStageDisplayState(_as_static_init_AsStageDisplayState);
void AsStageDisplayState::_as_static_init_AsStageDisplayState()
{
	if (!_as_static_initialized_AsStageDisplayState)
	{
		_as_static_initialized_AsStageDisplayState = true;
		
		FULL_SCREEN = ASL("fullScreen");
		FULL_SCREEN_INTERACTIVE = ASL("fullScreenInteractive");
		NORMAL = ASL("normal");
	}
}
