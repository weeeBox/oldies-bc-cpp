#ifndef AsMultitouch_h__
#define AsMultitouch_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsMultitouch);
 
class AsMultitouch : public AsObject
{
public:
	AS_OBJ(AsMultitouch, AsObject);
	
private:
	static AsString_ref mInputMode;
	
public:
	static AsString_ref getInputMode();
	static void setInputMode(const AsString_ref& value);
	
	static void _as_static_init_AsMultitouch();
	
private:
	static bool _as_static_initialized_AsMultitouch;
	static AsStaticRefInitializer _as_static_initializer_AsMultitouch;
};
 
#endif // AsMultitouch_h__
