#ifndef AsStageScaleMode_h__
#define AsStageScaleMode_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsStageScaleMode);
 
class AsStageScaleMode : public AsObject
{
public:
	AS_OBJ(AsStageScaleMode, AsObject);
	
public:
	static AsString_ref SHOW_ALL;
	static AsString_ref EXACT_FIT;
	static AsString_ref NO_BORDER;
	static AsString_ref NO_SCALE;
	
	static void _as_static_init_AsStageScaleMode();
	
private:
	static bool _as_static_initialized_AsStageScaleMode;
	static AsStaticRefInitializer _as_static_initializer_AsStageScaleMode;
};
 
#endif // AsStageScaleMode_h__
