#ifndef AsMouseCursor_h__
#define AsMouseCursor_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsMouseCursor);
 
class AsMouseCursor : public AsObject
{
public:
	AS_OBJ(AsMouseCursor, AsObject);
	
public:
	static AsString_ref AUTO;
	static AsString_ref ARROW;
	static AsString_ref BUTTON;
	static AsString_ref HAND;
	static AsString_ref IBEAM;
	
	static void _as_static_init_AsMouseCursor();
	
private:
	static bool _as_static_initialized_AsMouseCursor;
	static AsStaticRefInitializer _as_static_initializer_AsMouseCursor;
};
 
#endif // AsMouseCursor_h__
