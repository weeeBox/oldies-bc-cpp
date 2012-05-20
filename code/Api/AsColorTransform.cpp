#include "AsColorTransform.h"
#include "AsColorTransform.h"
#include "AsNotImplementedError.h"
 
 
uint AsColorTransform::getColor()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsColorTransform::setColor(uint newColor)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsColorTransform::concat(const AsColorTransform_ref& second)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset, float alphaOffset)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, greenOffset, blueOffset, alphaOffset);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, greenOffset, blueOffset);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, greenOffset);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier, float greenMultiplier)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier, greenMultiplier);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform(float redMultiplier)
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform(redMultiplier);
	return __instance;
}
 
AsColorTransform_ref AsColorTransform::_as_create_AsColorTransform()
{
	AsColorTransform_ref __instance = new AsColorTransform();
	__instance->_as_construct_AsColorTransform();
	return __instance;
}
 
void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset, float alphaOffset)
{
	this->redMultiplier = redMultiplier;
	this->greenMultiplier = greenMultiplier;
	this->blueMultiplier = blueMultiplier;
	this->alphaMultiplier = alphaMultiplier;
	this->redOffset = redOffset;
	this->greenOffset = greenOffset;
	this->blueOffset = blueOffset;
	this->alphaOffset = alphaOffset;
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, greenOffset, blueOffset, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, greenOffset, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, 0, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, 0, 0, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, blueMultiplier, 1.0f, 0, 0, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier, float greenMultiplier)
{
	_as_construct_AsColorTransform(redMultiplier, greenMultiplier, 1.0f, 1.0f, 0, 0, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform(float redMultiplier)
{
	_as_construct_AsColorTransform(redMultiplier, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0);
}
 
inline void AsColorTransform::_as_construct_AsColorTransform()
{
	_as_construct_AsColorTransform(1.0f, 1.0f, 1.0f, 1.0f, 0, 0, 0, 0);
}
 
bool AsColorTransform::_as_static_initialized_AsColorTransform = false;
AsStaticRefInitializer AsColorTransform::_as_static_initializer_AsColorTransform(_as_static_init_AsColorTransform);
void AsColorTransform::_as_static_init_AsColorTransform()
{
	if (!_as_static_initialized_AsColorTransform)
	{
		_as_static_initialized_AsColorTransform = true;
	}
}
 
AsColorTransform::AsColorTransform() : 
  redMultiplier(0),
  greenMultiplier(0),
  blueMultiplier(0),
  alphaMultiplier(0),
  redOffset(0),
  greenOffset(0),
  blueOffset(0),
  alphaOffset(0)
{
}
