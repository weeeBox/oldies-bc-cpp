#ifndef AsTouch_h__
#define AsTouch_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
#ifndef AsPoint_h__
#include "AsPoint.h"
#else
AS_CLASS(AsPoint);
#endif // AsPoint_h__
 
#ifndef AsTouch_h__
#include "AsTouch.h"
#else
AS_CLASS(AsTouch);
#endif // AsTouch_h__
 
 
AS_CLASS(AsTouch);
 
class AsTouch : public AsObject
{
public:
	AS_OBJ(AsTouch, AsObject);
	
private:
	int mID;
	float mGlobalX;
	float mGlobalY;
	float mPreviousGlobalX;
	float mPreviousGlobalY;
	int mTapCount;
	AsString_ref mPhase;
	AsDisplayObject_ref mTarget;
	float mTimestamp;
	
public:
	virtual AsPoint_ref getLocation(const AsDisplayObject_ref& space);
	virtual AsPoint_ref getPreviousLocation(const AsDisplayObject_ref& space);
	virtual AsTouch_ref clone();
	virtual int getId();
	virtual float getGlobalX();
	virtual float getGlobalY();
	virtual float getPreviousGlobalX();
	virtual float getPreviousGlobalY();
	virtual int getTapCount();
	virtual AsString_ref getPhase();
	virtual AsDisplayObject_ref getTarget();
	virtual float getTimestamp();
	virtual void setPosition(float globalX, float globalY);
	virtual void setPhase(const AsString_ref& value);
	virtual void setTapCount(int value);
	virtual void setTarget(const AsDisplayObject_ref& value);
	virtual void setTimestamp(float value);
	
	
public:
	static AsTouch_ref _as_create_AsTouch(int id, float globalX, float globalY, const AsString_ref& phase, const AsDisplayObject_ref& target);
	
protected:
	void _as_construct_AsTouch(int id, float globalX, float globalY, const AsString_ref& phase, const AsDisplayObject_ref& target);
	
public:
	static void _as_static_init_AsTouch();
	
private:
	static bool _as_static_initialized_AsTouch;
	static AsStaticRefInitializer _as_static_initializer_AsTouch;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsTouch();
};
 
#endif // AsTouch_h__
