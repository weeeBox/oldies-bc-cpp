#ifndef AsStageQuality_h__
#define AsStageQuality_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsStageQuality);
 
class AsStageQuality : public AsObject
{
public:
	AS_OBJ(AsStageQuality, AsObject);
	
public:
	static AsString_ref LOW;
	static AsString_ref MEDIUM;
	static AsString_ref HIGH;
	static AsString_ref BEST;
	
	static void _as_static_init_AsStageQuality();
	
private:
	static bool _as_static_initialized_AsStageQuality;
	static AsStaticRefInitializer _as_static_initializer_AsStageQuality;
};
 
#endif // AsStageQuality_h__
