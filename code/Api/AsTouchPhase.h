#ifndef AsTouchPhase_h__
#define AsTouchPhase_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsTouchPhase);
 
class AsTouchPhase : public AsObject
{
public:
	AS_OBJ(AsTouchPhase, AsObject);
	
public:
	static AsString_ref HOVER;
	static AsString_ref BEGAN;
	static AsString_ref MOVED;
	static AsString_ref STATIONARY;
	static AsString_ref ENDED;
	
	
public:
	static AsTouchPhase_ref _as_create_AsTouchPhase();
	
protected:
	void _as_construct_AsTouchPhase();
	
public:
	static void _as_static_init_AsTouchPhase();
	
private:
	static bool _as_static_initialized_AsTouchPhase;
	static AsStaticRefInitializer _as_static_initializer_AsTouchPhase;
};
 
#endif // AsTouchPhase_h__
