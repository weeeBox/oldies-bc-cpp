#ifndef AsTouchData_h__
#define AsTouchData_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsTouch_h__
#include "AsTouch.h"
#else
AS_CLASS(AsTouch);
#endif // AsTouch_h__
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
 
AS_CLASS(AsTouchData);
 
class AsTouchData : public AsObject
{
public:
	AS_OBJ(AsTouchData, AsObject);
	
public:
	AsTouch_ref touch;
	AsDisplayObject_ref target;
	
	
public:
	static AsTouchData_ref _as_create_AsTouchData(const AsTouch_ref& touch, const AsDisplayObject_ref& target);
	
protected:
	void _as_construct_AsTouchData(const AsTouch_ref& touch, const AsDisplayObject_ref& target);
	
public:
	static void _as_static_init_AsTouchData();
	
private:
	static bool _as_static_initialized_AsTouchData;
	static AsStaticRefInitializer _as_static_initializer_AsTouchData;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsTouchData();
};
 
#endif // AsTouchData_h__
