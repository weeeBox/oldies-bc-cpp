#include "AsSound.h"
#include "AsURLRequest.h"
#include "AsSoundLoaderContext.h"
#include "AsSoundTransform.h"
#include "AsNotImplementedError.h"
 
 
uint AsSound::getBytesLoaded()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsSound::getBytesTotal()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsSound::close()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsSound::getLength()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsSound::load(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context)
{
	mRequest = request;
	mContext = context;
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsSound::load(const AsURLRequest_ref& request)
{
	load(request, AS_NULL);
}
 
AsSoundChannel_ref AsSound::play(float startTime, int loops, const AsSoundTransform_ref& sndTransform)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsSoundChannel_ref AsSound::play(float startTime, int loops)
{
	return play(startTime, loops, AS_NULL);
}
 
AsSoundChannel_ref AsSound::play(float startTime)
{
	return play(startTime, 0, AS_NULL);
}
 
AsSoundChannel_ref AsSound::play()
{
	return play(0, 0, AS_NULL);
}
 
AsString_ref AsSound::getUrl()
{
	return mRequest->getUrl();
}
 
AsSound_ref AsSound::_as_create_AsSound(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context)
{
	AsSound_ref __instance = new AsSound();
	__instance->_as_construct_AsSound(request, context);
	return __instance;
}
 
AsSound_ref AsSound::_as_create_AsSound(const AsURLRequest_ref& request)
{
	AsSound_ref __instance = new AsSound();
	__instance->_as_construct_AsSound(request);
	return __instance;
}
 
AsSound_ref AsSound::_as_create_AsSound()
{
	AsSound_ref __instance = new AsSound();
	__instance->_as_construct_AsSound();
	return __instance;
}
 
void AsSound::_as_construct_AsSound(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context)
{
	_as_construct_AsEventDispatcher();
	mRequest = request;
	mContext = context;
}
 
inline void AsSound::_as_construct_AsSound(const AsURLRequest_ref& request)
{
	_as_construct_AsSound(request, AS_NULL);
}
 
inline void AsSound::_as_construct_AsSound()
{
	_as_construct_AsSound(AS_NULL, AS_NULL);
}
 
bool AsSound::_as_static_initialized_AsSound = false;
AsStaticRefInitializer AsSound::_as_static_initializer_AsSound(_as_static_init_AsSound);
void AsSound::_as_static_init_AsSound()
{
	if (!_as_static_initialized_AsSound)
	{
		_as_static_initialized_AsSound = true;
		_as_static_init_AsEventDispatcher();
	}
}
 
void AsSound::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsEventDispatcher::_as_gc_mark();
		AS_GC_MARK(mRequest)
		AS_GC_MARK(mContext)
	}
}
 
AsSound::AsSound() : 
  mRequest(false),
  mContext(false)
{
}
