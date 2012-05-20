#ifndef AsTouchProcessor_h__
#define AsTouchProcessor_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsStage_h__
#include "AsStage.h"
#else
AS_CLASS(AsStage);
#endif // AsStage_h__
#include "AsVector.h"
 
#ifndef AsTouch_h__
#include "AsTouch.h"
#else
AS_CLASS(AsTouch);
#endif // AsTouch_h__
#include "AsArray.h"
 
#ifndef AsTouchData_h__
#include "AsTouchData.h"
#else
AS_CLASS(AsTouchData);
#endif // AsTouchData_h__
#include "AsString.h"
 
#ifndef AsEvent_h__
#include "AsEvent.h"
#else
AS_CLASS(AsEvent);
#endif // AsEvent_h__
 
AS_VECTOR_REF(AsTouch);
AS_VECTOR_REF(AsArray);
AS_VECTOR_PRIMITIVE_REF(int);
AS_VECTOR_REF(AsTouchData);
 
AS_CLASS(AsTouchProcessor);
 
class AsTouchProcessor : public AsObject
{
public:
	AS_OBJ(AsTouchProcessor, AsObject);
	
private:
	static const float MULTITAP_TIME;
	static const float MULTITAP_DISTANCE;
	AsStage_ref mStage;
	float mElapsedTime;
	float mOffsetTime;
	_V_AsTouch_ref mCurrentTouches;
	_V_AsArray_ref mQueue;
	_V_AsTouch_ref mLastTaps;
	bool mShiftDown;
	bool mCtrlDown;
	static _V_int_ref sProcessedTouchIDs;
	static _V_AsTouchData_ref sHoveringTouchData;
	
public:
	virtual void dispose();
	virtual void advanceTime(float passedTime);
	virtual void enqueue(int touchID, const AsString_ref& phase, float globalX, float globalY);
	
private:
	virtual void processTouch(int touchID, const AsString_ref& phase, float globalX, float globalY);
	virtual void onKey(const AsEvent_ref& evt);
	virtual void processTap(const AsTouch_ref& touch);
	virtual void addCurrentTouch(const AsTouch_ref& touch);
	virtual AsTouch_ref getCurrentTouch(int touchID);
	
	
public:
	static AsTouchProcessor_ref _as_create_AsTouchProcessor(const AsStage_ref& stage);
	
protected:
	void _as_construct_AsTouchProcessor(const AsStage_ref& stage);
	void _as_init_fields_AsTouchProcessor();
	
public:
	static void _as_static_init_AsTouchProcessor();
	
private:
	static bool _as_static_initialized_AsTouchProcessor;
	static AsStaticRefInitializer _as_static_initializer_AsTouchProcessor;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsTouchProcessor();
};
 
#endif // AsTouchProcessor_h__
