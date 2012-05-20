#include "AsSoundTransform.h"
 
 
float AsSoundTransform::getLeftToLeft()
{
	return mLeftToLeft;
}
 
void AsSoundTransform::setLeftToLeft(float leftToLeft)
{
	mLeftToLeft = leftToLeft;
}
 
float AsSoundTransform::getLeftToRight()
{
	return mLeftToRight;
}
 
void AsSoundTransform::setLeftToRight(float leftToRight)
{
	mLeftToRight = leftToRight;
}
 
float AsSoundTransform::getPan()
{
	return mPanning;
}
 
void AsSoundTransform::setPan(float panning)
{
	mPanning = panning;
}
 
float AsSoundTransform::getRightToLeft()
{
	return mRightToLeft;
}
 
void AsSoundTransform::setRightToLeft(float rightToLeft)
{
	mRightToLeft = rightToLeft;
}
 
float AsSoundTransform::getRightToRight()
{
	return mRightToRight;
}
 
void AsSoundTransform::setRightToRight(float rightToRight)
{
	mRightToRight = rightToRight;
}
 
float AsSoundTransform::getVolume()
{
	return mVolume;
}
 
void AsSoundTransform::setVolume(float volume)
{
	mVolume = volume;
}
 
AsSoundTransform_ref AsSoundTransform::_as_create_AsSoundTransform(float vol, float panning)
{
	AsSoundTransform_ref __instance = new AsSoundTransform();
	__instance->_as_construct_AsSoundTransform(vol, panning);
	return __instance;
}
 
AsSoundTransform_ref AsSoundTransform::_as_create_AsSoundTransform(float vol)
{
	AsSoundTransform_ref __instance = new AsSoundTransform();
	__instance->_as_construct_AsSoundTransform(vol);
	return __instance;
}
 
AsSoundTransform_ref AsSoundTransform::_as_create_AsSoundTransform()
{
	AsSoundTransform_ref __instance = new AsSoundTransform();
	__instance->_as_construct_AsSoundTransform();
	return __instance;
}
 
void AsSoundTransform::_as_construct_AsSoundTransform(float vol, float panning)
{
	mVolume = vol;
	mPanning = panning;
}
 
inline void AsSoundTransform::_as_construct_AsSoundTransform(float vol)
{
	_as_construct_AsSoundTransform(vol, 0);
}
 
inline void AsSoundTransform::_as_construct_AsSoundTransform()
{
	_as_construct_AsSoundTransform(1, 0);
}
 
bool AsSoundTransform::_as_static_initialized_AsSoundTransform = false;
AsStaticRefInitializer AsSoundTransform::_as_static_initializer_AsSoundTransform(_as_static_init_AsSoundTransform);
void AsSoundTransform::_as_static_init_AsSoundTransform()
{
	if (!_as_static_initialized_AsSoundTransform)
	{
		_as_static_initialized_AsSoundTransform = true;
	}
}
 
AsSoundTransform::AsSoundTransform() : 
  mVolume(0),
  mPanning(0),
  mLeftToLeft(0),
  mLeftToRight(0),
  mRightToLeft(0),
  mRightToRight(0)
{
}
