#ifndef AsPixelSnapping_h__
#define AsPixelSnapping_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsPixelSnapping);
 
class AsPixelSnapping : public AsObject
{
public:
	AS_OBJ(AsPixelSnapping, AsObject);
	
public:
	static AsString_ref NEVER;
	static AsString_ref ALWAYS;
	static AsString_ref AUTO;
	
	static void _as_static_init_AsPixelSnapping();
	
private:
	static bool _as_static_initialized_AsPixelSnapping;
	static AsStaticRefInitializer _as_static_initializer_AsPixelSnapping;
};
 
#endif // AsPixelSnapping_h__
