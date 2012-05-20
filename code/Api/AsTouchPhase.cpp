#include "AsTouchPhase.h"
#include "AsAbstractClassError.h"
 
AsString_ref AsTouchPhase::HOVER(true);
AsString_ref AsTouchPhase::BEGAN(true);
AsString_ref AsTouchPhase::MOVED(true);
AsString_ref AsTouchPhase::STATIONARY(true);
AsString_ref AsTouchPhase::ENDED(true);
 
AsTouchPhase_ref AsTouchPhase::_as_create_AsTouchPhase()
{
	AsTouchPhase_ref __instance = new AsTouchPhase();
	__instance->_as_construct_AsTouchPhase();
	return __instance;
}
 
void AsTouchPhase::_as_construct_AsTouchPhase()
{
	throw AS_NEW(AsAbstractClassError,());
}
 
bool AsTouchPhase::_as_static_initialized_AsTouchPhase = false;
AsStaticRefInitializer AsTouchPhase::_as_static_initializer_AsTouchPhase(_as_static_init_AsTouchPhase);
void AsTouchPhase::_as_static_init_AsTouchPhase()
{
	if (!_as_static_initialized_AsTouchPhase)
	{
		_as_static_initialized_AsTouchPhase = true;
		
		HOVER = ASL("hover");
		BEGAN = ASL("began");
		MOVED = ASL("moved");
		STATIONARY = ASL("stationary");
		ENDED = ASL("ended");
	}
}
