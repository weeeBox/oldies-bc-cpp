#include "AsBitmapData.h"
#include "AsIBitmapDrawable.h"
#include "AsMatrix.h"
#include "AsColorTransform.h"
#include "AsString.h"
#include "AsRectangle.h"
#include "AsAbstractClassError.h"
 
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode, const AsRectangle_ref& clipRect, bool smoothing)
{
	throw AS_NEW(AsAbstractClassError,());
}
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode, const AsRectangle_ref& clipRect)
{
	draw(source, matrix, colorTransform, blendMode, clipRect, false);
}
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode)
{
	draw(source, matrix, colorTransform, blendMode, AS_NULL, false);
}
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform)
{
	draw(source, matrix, colorTransform, AS_NULL, AS_NULL, false);
}
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix)
{
	draw(source, matrix, AS_NULL, AS_NULL, AS_NULL, false);
}
 
void AsBitmapData::draw(const AsIBitmapDrawable_ref& source)
{
	draw(source, AS_NULL, AS_NULL, AS_NULL, AS_NULL, false);
}
 
void AsBitmapData::dispose()
{
	throw AS_NEW(AsAbstractClassError,());
}
 
int AsBitmapData::getWidth()
{
	return mWidth;
}
 
int AsBitmapData::getHeight()
{
	return mHeight;
}
 
AsBitmapData_ref AsBitmapData::_as_create_AsBitmapData(int width, int height, bool transparent, uint fillColor)
{
	AsBitmapData_ref __instance = new AsBitmapData();
	__instance->_as_construct_AsBitmapData(width, height, transparent, fillColor);
	return __instance;
}
 
AsBitmapData_ref AsBitmapData::_as_create_AsBitmapData(int width, int height, bool transparent)
{
	AsBitmapData_ref __instance = new AsBitmapData();
	__instance->_as_construct_AsBitmapData(width, height, transparent);
	return __instance;
}
 
AsBitmapData_ref AsBitmapData::_as_create_AsBitmapData(int width, int height)
{
	AsBitmapData_ref __instance = new AsBitmapData();
	__instance->_as_construct_AsBitmapData(width, height);
	return __instance;
}
 
void AsBitmapData::_as_construct_AsBitmapData(int width, int height, bool transparent, uint fillColor)
{
	mWidth = width;
	mHeight = height;
	mTransparent = transparent;
	mFillColor = fillColor;
}
 
inline void AsBitmapData::_as_construct_AsBitmapData(int width, int height, bool transparent)
{
	_as_construct_AsBitmapData(width, height, transparent, 0xffffffff);
}
 
inline void AsBitmapData::_as_construct_AsBitmapData(int width, int height)
{
	_as_construct_AsBitmapData(width, height, true, 0xffffffff);
}
 
bool AsBitmapData::_as_static_initialized_AsBitmapData = false;
AsStaticRefInitializer AsBitmapData::_as_static_initializer_AsBitmapData(_as_static_init_AsBitmapData);
void AsBitmapData::_as_static_init_AsBitmapData()
{
	if (!_as_static_initialized_AsBitmapData)
	{
		_as_static_initialized_AsBitmapData = true;
	}
}
 
AsBitmapData::AsBitmapData() : 
  mWidth(0),
  mHeight(0),
  mTransparent(0),
  mFillColor(0)
{
}
