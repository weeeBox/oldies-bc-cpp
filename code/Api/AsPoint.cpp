#include "AsPoint.h"
#include "AsPoint.h"
#include "AsMath.h"
 
 
AsPoint_ref AsPoint::add(const AsPoint_ref& v)
{
	return AS_NEW(AsPoint,((x + v->x), (y + v->y)));
}
 
AsPoint_ref AsPoint::clone()
{
	return AS_NEW(AsPoint,(x, y));
}
 
float AsPoint::distance(const AsPoint_ref& pt1, const AsPoint_ref& pt2)
{
	float dx = (pt1->x - pt2->x);
	float dy = (pt1->y - pt2->y);
	return AsMath::sqrt(((dx * dx) + (dy * dy)));
}
 
bool AsPoint::equals(const AsPoint_ref& toCompare)
{
	return (((toCompare != AS_NULL) && (toCompare->x == x)) && (toCompare->y == y));
}
 
AsPoint_ref AsPoint::interpolate(const AsPoint_ref& pt1, const AsPoint_ref& pt2, float ratio)
{
	float invRatio = (1.0f - ratio);
	return AS_NEW(AsPoint,(((invRatio * pt1->x) + (ratio * pt2->x)), ((invRatio * pt1->y) + (ratio * pt2->y))));
}
 
float AsPoint::getLength()
{
	return AsMath::sqrt(((x * x) + (y * y)));
}
 
void AsPoint::normalize(float thickness)
{
	float inverseLength = (thickness / getLength());
	x = (x * inverseLength);
	y = (y * inverseLength);
}
 
void AsPoint::offset(float dx, float dy)
{
	x = (x + dx);
	y = (y + dy);
}
 
AsPoint_ref AsPoint::polar(float len, float angle)
{
	return AS_NEW(AsPoint,((AsMath::cos(angle) * len), (AsMath::sin(angle) * len)));
}
 
AsPoint_ref AsPoint::subtract(const AsPoint_ref& v)
{
	return AS_NEW(AsPoint,((x - v->x), (y - v->y)));
}
 
AsPoint_ref AsPoint::_as_create_AsPoint(float x, float y)
{
	AsPoint_ref __instance = new AsPoint();
	__instance->_as_construct_AsPoint(x, y);
	return __instance;
}
 
AsPoint_ref AsPoint::_as_create_AsPoint(float x)
{
	AsPoint_ref __instance = new AsPoint();
	__instance->_as_construct_AsPoint(x);
	return __instance;
}
 
AsPoint_ref AsPoint::_as_create_AsPoint()
{
	AsPoint_ref __instance = new AsPoint();
	__instance->_as_construct_AsPoint();
	return __instance;
}
 
void AsPoint::_as_construct_AsPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}
 
inline void AsPoint::_as_construct_AsPoint(float x)
{
	_as_construct_AsPoint(x, 0);
}
 
inline void AsPoint::_as_construct_AsPoint()
{
	_as_construct_AsPoint(0, 0);
}
 
bool AsPoint::_as_static_initialized_AsPoint = false;
AsStaticRefInitializer AsPoint::_as_static_initializer_AsPoint(_as_static_init_AsPoint);
void AsPoint::_as_static_init_AsPoint()
{
	if (!_as_static_initialized_AsPoint)
	{
		_as_static_initialized_AsPoint = true;
	}
}
 
AsPoint::AsPoint() : 
  x(0),
  y(0)
{
}
