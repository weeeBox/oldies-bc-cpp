#ifndef AsMouse_h__
#define AsMouse_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsMouse);
 
class AsMouse : public AsObject
{
public:
	AS_OBJ(AsMouse, AsObject);
	
private:
	static AsString_ref mCursor;
	static bool mHidden;
	
public:
	static AsString_ref getCursor();
	static void setCursor(const AsString_ref& value);
	static void hide();
	static void show();
	
	static void _as_static_init_AsMouse();
	
private:
	static bool _as_static_initialized_AsMouse;
	static AsStaticRefInitializer _as_static_initializer_AsMouse;
};
 
#endif // AsMouse_h__
