#include "AsMovieClip.h"
#include "AsObject.h"
#include "AsString.h"
#include "AsNotImplementedError.h"
 
int AsMovieClip::getCurrentFrame()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsMovieClip::getCurrentFrameLabel()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsMovieClip::getCurrentLabel()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsArray_ref AsMovieClip::getCurrentLabels()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsMovieClip::getEnabled()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::setEnabled(bool value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsMovieClip::getFramesLoaded()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::gotoAndPlay(const AsObject_ref& frame, const AsString_ref& scene)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::gotoAndPlay(const AsObject_ref& frame)
{
	gotoAndPlay((AsObject_ref)(frame), AS_NULL);
}
 
void AsMovieClip::gotoAndStop(const AsObject_ref& frame, const AsString_ref& scene)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::gotoAndStop(const AsObject_ref& frame)
{
	gotoAndStop((AsObject_ref)(frame), AS_NULL);
}
 
void AsMovieClip::nextFrame()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::play()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::prevFrame()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::prevScene()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMovieClip::stop()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsMovieClip::getTotalFrames()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsMovieClip::_as_static_initialized_AsMovieClip = false;
AsStaticRefInitializer AsMovieClip::_as_static_initializer_AsMovieClip(_as_static_init_AsMovieClip);
void AsMovieClip::_as_static_init_AsMovieClip()
{
	if (!_as_static_initialized_AsMovieClip)
	{
		_as_static_initialized_AsMovieClip = true;
		_as_static_init_AsSprite();
	}
}
