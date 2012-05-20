#ifndef AsStageDisplayState_h__
#define AsStageDisplayState_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsStageDisplayState);
 
class AsStageDisplayState : public AsObject
{
public:
	AS_OBJ(AsStageDisplayState, AsObject);
	
public:
	static AsString_ref FULL_SCREEN;
	static AsString_ref FULL_SCREEN_INTERACTIVE;
	static AsString_ref NORMAL;
	
	static void _as_static_init_AsStageDisplayState();
	
private:
	static bool _as_static_initialized_AsStageDisplayState;
	static AsStaticRefInitializer _as_static_initializer_AsStageDisplayState;
};
 
#endif // AsStageDisplayState_h__
