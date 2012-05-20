#ifndef AsStageAlign_h__
#define AsStageAlign_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsStageAlign);
 
class AsStageAlign : public AsObject
{
public:
	AS_OBJ(AsStageAlign, AsObject);
	
public:
	static AsString_ref TOP;
	static AsString_ref LEFT;
	static AsString_ref BOTTOM;
	static AsString_ref RIGHT;
	static AsString_ref TOP_LEFT;
	static AsString_ref TOP_RIGHT;
	static AsString_ref BOTTOM_LEFT;
	static AsString_ref BOTTOM_RIGHT;
	
	static void _as_static_init_AsStageAlign();
	
private:
	static bool _as_static_initialized_AsStageAlign;
	static AsStaticRefInitializer _as_static_initializer_AsStageAlign;
};
 
#endif // AsStageAlign_h__
