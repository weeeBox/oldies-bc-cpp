#include "AsSoundChannel.h"
#include "AsSoundTransform.h"
#include "AsNotImplementedError.h"
 
 
float AsSoundChannel::getLeftPeak()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsSoundChannel::getPosition()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsSoundChannel::getRightPeak()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsSoundTransform_ref AsSoundChannel::getSoundTransform()
{
	return mSoundTransform;
}
 
void AsSoundChannel::setSoundTransform(const AsSoundTransform_ref& sndTransform)
{
	mSoundTransform = sndTransform;
}
 
void AsSoundChannel::stop()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsSoundChannel::_as_static_initialized_AsSoundChannel = false;
AsStaticRefInitializer AsSoundChannel::_as_static_initializer_AsSoundChannel(_as_static_init_AsSoundChannel);
void AsSoundChannel::_as_static_init_AsSoundChannel()
{
	if (!_as_static_initialized_AsSoundChannel)
	{
		_as_static_initialized_AsSoundChannel = true;
	}
}
 
void AsSoundChannel::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mSoundTransform)
	}
}
 
AsSoundChannel::AsSoundChannel() : 
  mSoundTransform(false)
{
}
