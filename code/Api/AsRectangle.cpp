#include "AsRectangle.h"
#include "AsPoint.h"
#include "AsRectangle.h"
#include "AsNotImplementedError.h"
 
 
float AsRectangle::getBottom()
{
	return (y + height);
}
 
void AsRectangle::setBottom(float value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsPoint_ref AsRectangle::getBottomRight()
{
	return AS_NEW(AsPoint,((x + width), (y + height)));
}
 
void AsRectangle::setBottomRight(const AsPoint_ref& value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsRectangle_ref AsRectangle::clone()
{
	return AS_NEW(AsRectangle,(x, y, width, height));
}
 
bool AsRectangle::contains(float x, float y)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsRectangle::containsPoint(const AsPoint_ref& point)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsRectangle::containsRect(const AsRectangle_ref& rect)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsRectangle::equals(const AsRectangle_ref& toCompare)
{
	return ((((x == toCompare->x) && (y == toCompare->y)) && (width == toCompare->width)) && (height == toCompare->height));
}
 
void AsRectangle::inflate(float dx, float dy)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsRectangle::inflatePoint(const AsPoint_ref& point)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsRectangle_ref AsRectangle::intersection(const AsRectangle_ref& toIntersect)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsRectangle::intersects(const AsRectangle_ref& toIntersect)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsRectangle::isEmpty()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsRectangle::getLeft()
{
	return x;
}
 
void AsRectangle::setLeft(float value)
{
	x = value;
}
 
void AsRectangle::offset(float dx, float dy)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsRectangle::offsetPoint(const AsPoint_ref& point)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsRectangle::getRight()
{
	return (x + width);
}
 
void AsRectangle::setRight(float value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsRectangle::setEmpty()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsPoint_ref AsRectangle::getSize()
{
	return AS_NEW(AsPoint,(width, height));
}
 
void AsRectangle::setSize(const AsPoint_ref& value)
{
	width = value->x;
	height = value->y;
}
 
float AsRectangle::getTop()
{
	return y;
}
 
void AsRectangle::setTop(float value)
{
	y = value;
}
 
AsPoint_ref AsRectangle::getTopLeft()
{
	return AS_NEW(AsPoint,(x, y));
}
 
void AsRectangle::setTopLeft(const AsPoint_ref& value)
{
	x = value->x;
	y = value->y;
}
 
AsRectangle_ref AsRectangle::_union(const AsRectangle_ref& toUnion)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsRectangle::toString()
{
	return ((((((((ASL("(x=") + x) + ASL(", y=")) + y) + ASL(", w=")) + width) + ASL(", h=")) + height) + ASL(")"));
}
 
AsRectangle_ref AsRectangle::_as_create_AsRectangle(float x, float y, float width, float height)
{
	AsRectangle_ref __instance = new AsRectangle();
	__instance->_as_construct_AsRectangle(x, y, width, height);
	return __instance;
}
 
AsRectangle_ref AsRectangle::_as_create_AsRectangle(float x, float y, float width)
{
	AsRectangle_ref __instance = new AsRectangle();
	__instance->_as_construct_AsRectangle(x, y, width);
	return __instance;
}
 
AsRectangle_ref AsRectangle::_as_create_AsRectangle(float x, float y)
{
	AsRectangle_ref __instance = new AsRectangle();
	__instance->_as_construct_AsRectangle(x, y);
	return __instance;
}
 
AsRectangle_ref AsRectangle::_as_create_AsRectangle(float x)
{
	AsRectangle_ref __instance = new AsRectangle();
	__instance->_as_construct_AsRectangle(x);
	return __instance;
}
 
AsRectangle_ref AsRectangle::_as_create_AsRectangle()
{
	AsRectangle_ref __instance = new AsRectangle();
	__instance->_as_construct_AsRectangle();
	return __instance;
}
 
void AsRectangle::_as_construct_AsRectangle(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
 
inline void AsRectangle::_as_construct_AsRectangle(float x, float y, float width)
{
	_as_construct_AsRectangle(x, y, width, 0);
}
 
inline void AsRectangle::_as_construct_AsRectangle(float x, float y)
{
	_as_construct_AsRectangle(x, y, 0, 0);
}
 
inline void AsRectangle::_as_construct_AsRectangle(float x)
{
	_as_construct_AsRectangle(x, 0, 0, 0);
}
 
inline void AsRectangle::_as_construct_AsRectangle()
{
	_as_construct_AsRectangle(0, 0, 0, 0);
}
 
bool AsRectangle::_as_static_initialized_AsRectangle = false;
AsStaticRefInitializer AsRectangle::_as_static_initializer_AsRectangle(_as_static_init_AsRectangle);
void AsRectangle::_as_static_init_AsRectangle()
{
	if (!_as_static_initialized_AsRectangle)
	{
		_as_static_initialized_AsRectangle = true;
	}
}
 
AsRectangle::AsRectangle() : 
  x(0),
  y(0),
  width(0),
  height(0)
{
}
