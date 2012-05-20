#ifndef AsSoundTransform_h__
#define AsSoundTransform_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
AS_CLASS(AsSoundTransform);
 
class AsSoundTransform : public AsObject
{
public:
	AS_OBJ(AsSoundTransform, AsObject);
	
private:
	float mVolume;
	float mPanning;
	float mLeftToLeft;
	float mLeftToRight;
	float mRightToLeft;
	float mRightToRight;
	
public:
	virtual float getLeftToLeft();
	virtual void setLeftToLeft(float leftToLeft);
	virtual float getLeftToRight();
	virtual void setLeftToRight(float leftToRight);
	virtual float getPan();
	virtual void setPan(float panning);
	virtual float getRightToLeft();
	virtual void setRightToLeft(float rightToLeft);
	virtual float getRightToRight();
	virtual void setRightToRight(float rightToRight);
	virtual float getVolume();
	virtual void setVolume(float volume);
	
	
public:
	static AsSoundTransform_ref _as_create_AsSoundTransform(float vol, float panning);
	static AsSoundTransform_ref _as_create_AsSoundTransform(float vol);
	static AsSoundTransform_ref _as_create_AsSoundTransform();
	
protected:
	void _as_construct_AsSoundTransform(float vol, float panning);
	void _as_construct_AsSoundTransform(float vol);
	void _as_construct_AsSoundTransform();
	
public:
	static void _as_static_init_AsSoundTransform();
	
private:
	static bool _as_static_initialized_AsSoundTransform;
	static AsStaticRefInitializer _as_static_initializer_AsSoundTransform;
	
	
protected:
	AsSoundTransform();
};
 
#endif // AsSoundTransform_h__
