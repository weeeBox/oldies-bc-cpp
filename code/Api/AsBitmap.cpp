#include "AsBitmap.h"
#include "AsBitmapData.h"
#include "AsString.h"
#include "AsRenderSupport.h"
#include "AsDisplayObject.h"
#include "AsRectangle.h"
#include "AsPoint.h"
#include "AsMatrix.h"
#include "AsMathHelper.h"
 
AsPoint_ref AsBitmap::sHelperPoint(true);
AsMatrix_ref AsBitmap::sHelperMatrix(true);
AsPoint_ref AsBitmap::sPosition(true);
 
void AsBitmap::render(const AsRenderSupport_ref& support, float alpha)
{
}
 
AsRectangle_ref AsBitmap::getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect)
{
	if((resultRect == AS_NULL))
	{
		resultRect = AS_NEW(AsRectangle,());
	}
	if((targetSpace == this))
	{
		resultRect->x = getX();
		resultRect->y = getY();
		resultRect->width = mBitmapData->getWidth();
		resultRect->height = mBitmapData->getHeight();
		return resultRect;
	}
	float minX = AsMathHelper::MAX_NUMBER;
	float maxX = -AsMathHelper::MAX_NUMBER;
	float minY = AsMathHelper::MAX_NUMBER;
	float maxY = -AsMathHelper::MAX_NUMBER;
	getTransformationMatrix(targetSpace, sHelperMatrix);
	sPosition->x = getX();
	sPosition->y = getY();
	AsGlobal::transformCoords(sHelperMatrix, sPosition->x, sPosition->y, sHelperPoint);
	minX = (((minX < sHelperPoint->x)) ? (minX) : (sHelperPoint->x));
	maxX = (((maxX > sHelperPoint->x)) ? (maxX) : (sHelperPoint->x));
	minY = (((minY < sHelperPoint->y)) ? (minY) : (sHelperPoint->y));
	maxY = (((maxY > sHelperPoint->y)) ? (maxY) : (sHelperPoint->y));
	sPosition->x = (sPosition->x + getBitmapData()->getWidth());
	AsGlobal::transformCoords(sHelperMatrix, sPosition->x, sPosition->y, sHelperPoint);
	minX = (((minX < sHelperPoint->x)) ? (minX) : (sHelperPoint->x));
	maxX = (((maxX > sHelperPoint->x)) ? (maxX) : (sHelperPoint->x));
	minY = (((minY < sHelperPoint->y)) ? (minY) : (sHelperPoint->y));
	maxY = (((maxY > sHelperPoint->y)) ? (maxY) : (sHelperPoint->y));
	sPosition->y = (sPosition->y + getBitmapData()->getHeight());
	AsGlobal::transformCoords(sHelperMatrix, sPosition->x, sPosition->y, sHelperPoint);
	minX = (((minX < sHelperPoint->x)) ? (minX) : (sHelperPoint->x));
	maxX = (((maxX > sHelperPoint->x)) ? (maxX) : (sHelperPoint->x));
	minY = (((minY < sHelperPoint->y)) ? (minY) : (sHelperPoint->y));
	maxY = (((maxY > sHelperPoint->y)) ? (maxY) : (sHelperPoint->y));
	sPosition->x = getX();
	AsGlobal::transformCoords(sHelperMatrix, sPosition->x, sPosition->y, sHelperPoint);
	minX = (((minX < sHelperPoint->x)) ? (minX) : (sHelperPoint->x));
	maxX = (((maxX > sHelperPoint->x)) ? (maxX) : (sHelperPoint->x));
	minY = (((minY < sHelperPoint->y)) ? (minY) : (sHelperPoint->y));
	maxY = (((maxY > sHelperPoint->y)) ? (maxY) : (sHelperPoint->y));
	resultRect->x = minX;
	resultRect->y = minY;
	resultRect->width = (maxX - minX);
	resultRect->height = (maxY - minY);
	return resultRect;
}
 
AsRectangle_ref AsBitmap::getBounds(const AsDisplayObject_ref& targetSpace)
{
	return getBounds(targetSpace, AS_NULL);
}
 
AsBitmapData_ref AsBitmap::getBitmapData()
{
	return mBitmapData;
}
 
void AsBitmap::setBitmapData(const AsBitmapData_ref& value)
{
	mBitmapData = value;
}
 
AsString_ref AsBitmap::getPixelSnapping()
{
	return mPixelSnapping;
}
 
void AsBitmap::setPixelSnapping(const AsString_ref& value)
{
	mPixelSnapping = value;
}
 
bool AsBitmap::getSmoothing()
{
	return mSmoothing;
}
 
void AsBitmap::setSmoothing(bool value)
{
	mSmoothing = value;
}
 
AsBitmap_ref AsBitmap::_as_create_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping, bool smoothing)
{
	AsBitmap_ref __instance = new AsBitmap();
	__instance->_as_construct_AsBitmap(bitmapData, pixelSnapping, smoothing);
	return __instance;
}
 
AsBitmap_ref AsBitmap::_as_create_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping)
{
	AsBitmap_ref __instance = new AsBitmap();
	__instance->_as_construct_AsBitmap(bitmapData, pixelSnapping);
	return __instance;
}
 
AsBitmap_ref AsBitmap::_as_create_AsBitmap(const AsBitmapData_ref& bitmapData)
{
	AsBitmap_ref __instance = new AsBitmap();
	__instance->_as_construct_AsBitmap(bitmapData);
	return __instance;
}
 
AsBitmap_ref AsBitmap::_as_create_AsBitmap()
{
	AsBitmap_ref __instance = new AsBitmap();
	__instance->_as_construct_AsBitmap();
	return __instance;
}
 
void AsBitmap::_as_construct_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping, bool smoothing)
{
	_as_construct_AsDisplayObject();
	mBitmapData = bitmapData;
	mPixelSnapping = pixelSnapping;
	mSmoothing = smoothing;
}
 
inline void AsBitmap::_as_construct_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping)
{
	_as_construct_AsBitmap(bitmapData, pixelSnapping, false);
}
 
inline void AsBitmap::_as_construct_AsBitmap(const AsBitmapData_ref& bitmapData)
{
	_as_construct_AsBitmap(bitmapData, ASL("auto"), false);
}
 
inline void AsBitmap::_as_construct_AsBitmap()
{
	_as_construct_AsBitmap(AS_NULL, ASL("auto"), false);
}
 
bool AsBitmap::_as_static_initialized_AsBitmap = false;
AsStaticRefInitializer AsBitmap::_as_static_initializer_AsBitmap(_as_static_init_AsBitmap);
void AsBitmap::_as_static_init_AsBitmap()
{
	if (!_as_static_initialized_AsBitmap)
	{
		_as_static_initialized_AsBitmap = true;
		_as_static_init_AsDisplayObject();
		
		AsPoint::_as_static_init_AsPoint();
		AsMatrix::_as_static_init_AsMatrix();
		AsRectangle::_as_static_init_AsRectangle();
		
		sHelperPoint = AS_NEW(AsPoint,());
		sHelperMatrix = AS_NEW(AsMatrix,());
		sPosition = AS_NEW(AsPoint,());
	}
}
 
void AsBitmap::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsDisplayObject::_as_gc_mark();
		AS_GC_MARK(mBitmapData)
		AS_GC_MARK(mPixelSnapping)
	}
}
 
AsBitmap::AsBitmap() : 
  mBitmapData(false),
  mPixelSnapping(false),
  mSmoothing(0)
{
}
