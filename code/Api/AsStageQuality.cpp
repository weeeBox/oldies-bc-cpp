#include "AsStageQuality.h"
 
AsString_ref AsStageQuality::LOW(true);
AsString_ref AsStageQuality::MEDIUM(true);
AsString_ref AsStageQuality::HIGH(true);
AsString_ref AsStageQuality::BEST(true);
 
bool AsStageQuality::_as_static_initialized_AsStageQuality = false;
AsStaticRefInitializer AsStageQuality::_as_static_initializer_AsStageQuality(_as_static_init_AsStageQuality);
void AsStageQuality::_as_static_init_AsStageQuality()
{
	if (!_as_static_initialized_AsStageQuality)
	{
		_as_static_initialized_AsStageQuality = true;
		
		LOW = ASL("low");
		MEDIUM = ASL("medium");
		HIGH = ASL("high");
		BEST = ASL("best");
	}
}
