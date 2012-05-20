#include "AsVector3D.h"
#include "AsVector3D.h"
#include "AsArgumentError.h"
#include "AsMath.h"
#include "AsIllegalOperationError.h"
#include "AsMathHelper.h"
 
AsVector3D_ref AsVector3D::X_AXIS(true);
AsVector3D_ref AsVector3D::Y_AXIS(true);
AsVector3D_ref AsVector3D::Z_AXIS(true);
 
AsVector3D_ref AsVector3D::add(const AsVector3D_ref& a)
{
	return AS_NEW(AsVector3D,((x + a->x), (y + a->y), (z + a->z)));
}
 
float AsVector3D::angleBetween(const AsVector3D_ref& a, const AsVector3D_ref& b)
{
	float aLen = a->getLength();
	if(epsilonEquals(aLen, 0))
	{
		throw AS_NEW(AsArgumentError,());
	}
	float bLen = b->getLength();
	if(epsilonEquals(bLen, 0))
	{
		throw AS_NEW(AsArgumentError,());
	}
	float dotProd = (((a->x * b->x) + (a->y * b->y)) + (a->z * b->z));
	if(epsilonEquals(dotProd, 0))
	{
		return (0.5f * AsMath::PI);
	}
	return AsMath::acos(((dotProd / aLen) / bLen));
}
 
AsVector3D_ref AsVector3D::clone()
{
	return AS_NEW(AsVector3D,(x, y, z, w));
}
 
void AsVector3D::copyFrom(const AsVector3D_ref& sourceVector3D)
{
	x = sourceVector3D->x;
	y = sourceVector3D->y;
	z = sourceVector3D->z;
	w = sourceVector3D->w;
}
 
AsVector3D_ref AsVector3D::crossProduct(const AsVector3D_ref& a)
{
	return AS_NEW(AsVector3D,(((y * a->z) - (z * a->y)), ((z * a->x) - (x * a->z)), ((x * a->y) - (y * a->x)), 1));
}
 
void AsVector3D::decrementBy(const AsVector3D_ref& a)
{
	x = (x - a->x);
	y = (y - a->y);
	z = (z - a->z);
}
 
float AsVector3D::distance(const AsVector3D_ref& pt1, const AsVector3D_ref& pt2)
{
	float dx = (pt1->x - pt2->x);
	float dy = (pt1->y - pt2->y);
	float dz = (pt1->z - pt2->z);
	return AsMath::sqrt((((dx * dx) + (dy * dy)) + (dz * dz)));
}
 
float AsVector3D::dotProduct(const AsVector3D_ref& a)
{
	return (((x * a->x) + (y * a->y)) + (z * a->z));
}
 
bool AsVector3D::equals(const AsVector3D_ref& toCompare, bool allFour)
{
	return ((((x == toCompare->x) && (y == toCompare->y)) && (z == toCompare->z)) && (!(allFour) || (w == toCompare->w)));
}
 
bool AsVector3D::equals(const AsVector3D_ref& toCompare)
{
	return equals(toCompare, false);
}
 
void AsVector3D::incrementBy(const AsVector3D_ref& a)
{
	x = (x + a->x);
	y = (y + a->y);
	z = (z + a->z);
}
 
float AsVector3D::getLength()
{
	return AsMath::sqrt((((x * x) + (y * y)) + (z * z)));
}
 
float AsVector3D::getLengthSquared()
{
	return (((x * x) + (y * y)) + (z * z));
}
 
bool AsVector3D::nearEquals(const AsVector3D_ref& toCompare, float tolerance, bool allFour)
{
	return ((((AsMath::abs((x - toCompare->x)) <= tolerance) && (AsMath::abs((y - toCompare->y)) <= tolerance)) && (AsMath::abs((z - toCompare->z)) <= tolerance)) && (!(allFour) || (AsMath::abs((w - toCompare->w)) <= tolerance)));
}
 
bool AsVector3D::nearEquals(const AsVector3D_ref& toCompare, float tolerance)
{
	return nearEquals(toCompare, tolerance, false);
}
 
void AsVector3D::negate()
{
	x = -x;
	y = -y;
	z = -z;
}
 
float AsVector3D::normalize()
{
	float len = getLength();
	if(epsilonEquals(len, 0.0f))
	{
		throw AS_NEW(AsIllegalOperationError,(ASL("Unable to normalize vector with zero lenght")));
	}
	float lenInv = (1.0f / getLength());
	x = (x * lenInv);
	y = (y * lenInv);
	z = (z * lenInv);
	return getLength();
}
 
void AsVector3D::project()
{
	if(((w != 0) && (w != 1)))
	{
		float invW = (1.0f / w);
		x = (x * invW);
		y = (y * invW);
		z = (z * invW);
	}
}
 
void AsVector3D::scaleBy(float s)
{
	x = (x * s);
	y = (y * s);
	z = (z * s);
}
 
void AsVector3D::setTo(float xa, float ya, float za)
{
	x = xa;
	y = ya;
	z = za;
}
 
AsVector3D_ref AsVector3D::subtract(const AsVector3D_ref& a)
{
	return AS_NEW(AsVector3D,((x - a->x), (y - a->y), (z - a->z)));
}
 
AsString_ref AsVector3D::toString()
{
	return ((((((ASL("[") + x) + ASL(", ")) + y) + ASL(", ")) + z) + ASL("]"));
}
 
bool AsVector3D::epsilonEquals(float a, float b)
{
	return AsMathHelper::epsilonEquals(a, b);
}
 
AsVector3D_ref AsVector3D::_as_create_AsVector3D(float x, float y, float z, float w)
{
	AsVector3D_ref __instance = new AsVector3D();
	__instance->_as_construct_AsVector3D(x, y, z, w);
	return __instance;
}
 
AsVector3D_ref AsVector3D::_as_create_AsVector3D(float x, float y, float z)
{
	AsVector3D_ref __instance = new AsVector3D();
	__instance->_as_construct_AsVector3D(x, y, z);
	return __instance;
}
 
AsVector3D_ref AsVector3D::_as_create_AsVector3D(float x, float y)
{
	AsVector3D_ref __instance = new AsVector3D();
	__instance->_as_construct_AsVector3D(x, y);
	return __instance;
}
 
AsVector3D_ref AsVector3D::_as_create_AsVector3D(float x)
{
	AsVector3D_ref __instance = new AsVector3D();
	__instance->_as_construct_AsVector3D(x);
	return __instance;
}
 
AsVector3D_ref AsVector3D::_as_create_AsVector3D()
{
	AsVector3D_ref __instance = new AsVector3D();
	__instance->_as_construct_AsVector3D();
	return __instance;
}
 
void AsVector3D::_as_construct_AsVector3D(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
 
inline void AsVector3D::_as_construct_AsVector3D(float x, float y, float z)
{
	_as_construct_AsVector3D(x, y, z, 0.0f);
}
 
inline void AsVector3D::_as_construct_AsVector3D(float x, float y)
{
	_as_construct_AsVector3D(x, y, 0.0f, 0.0f);
}
 
inline void AsVector3D::_as_construct_AsVector3D(float x)
{
	_as_construct_AsVector3D(x, 0.0f, 0.0f, 0.0f);
}
 
inline void AsVector3D::_as_construct_AsVector3D()
{
	_as_construct_AsVector3D(0.0f, 0.0f, 0.0f, 0.0f);
}
 
bool AsVector3D::_as_static_initialized_AsVector3D = false;
AsStaticRefInitializer AsVector3D::_as_static_initializer_AsVector3D(_as_static_init_AsVector3D);
void AsVector3D::_as_static_init_AsVector3D()
{
	if (!_as_static_initialized_AsVector3D)
	{
		_as_static_initialized_AsVector3D = true;
		
		X_AXIS = AS_NEW(AsVector3D,(1, 0, 0));
		Y_AXIS = AS_NEW(AsVector3D,(0, 1, 0));
		Z_AXIS = AS_NEW(AsVector3D,(0, 0, 1));
	}
}
 
AsVector3D::AsVector3D() : 
  x(0),
  y(0),
  z(0),
  w(0)
{
}
