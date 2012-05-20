#ifndef AsMultitouchInputMode_h__
#define AsMultitouchInputMode_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsMultitouchInputMode);
 
class AsMultitouchInputMode : public AsObject
{
public:
	AS_OBJ(AsMultitouchInputMode, AsObject);
	
public:
	static AsString_ref NONE;
	static AsString_ref GESTURE;
	static AsString_ref TOUCH_POINT;
	
	static void _as_static_init_AsMultitouchInputMode();
	
private:
	static bool _as_static_initialized_AsMultitouchInputMode;
	static AsStaticRefInitializer _as_static_initializer_AsMultitouchInputMode;
};
 
#endif // AsMultitouchInputMode_h__
