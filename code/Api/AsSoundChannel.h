#ifndef AsSoundChannel_h__
#define AsSoundChannel_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsSoundTransform);
 
AS_CLASS(AsSoundChannel);
 
class AsSoundChannel : public AsObject
{
public:
	AS_OBJ(AsSoundChannel, AsObject);
	
private:
	AsSoundTransform_ref mSoundTransform;
	
public:
	virtual float getLeftPeak();
	virtual float getPosition();
	virtual float getRightPeak();
	virtual AsSoundTransform_ref getSoundTransform();
	virtual void setSoundTransform(const AsSoundTransform_ref& sndTransform);
	virtual void stop();
	
	static void _as_static_init_AsSoundChannel();
	
private:
	static bool _as_static_initialized_AsSoundChannel;
	static AsStaticRefInitializer _as_static_initializer_AsSoundChannel;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsSoundChannel();
};
 
#endif // AsSoundChannel_h__
