#ifndef AsBlendMode_h__
#define AsBlendMode_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsBlendMode);
 
class AsBlendMode : public AsObject
{
public:
	AS_OBJ(AsBlendMode, AsObject);
	
public:
	static AsString_ref NORMAL;
	static AsString_ref LAYER;
	static AsString_ref MULTIPLY;
	static AsString_ref SCREEN;
	static AsString_ref LIGHTEN;
	static AsString_ref DARKEN;
	static AsString_ref ADD;
	static AsString_ref SUBTRACT;
	static AsString_ref DIFFERENCE;
	static AsString_ref INVERT;
	static AsString_ref OVERLAY;
	static AsString_ref HARDLIGHT;
	static AsString_ref ALPHA;
	static AsString_ref ERASE;
	static AsString_ref SHADER;
	
	static void _as_static_init_AsBlendMode();
	
private:
	static bool _as_static_initialized_AsBlendMode;
	static AsStaticRefInitializer _as_static_initializer_AsBlendMode;
};
 
#endif // AsBlendMode_h__
