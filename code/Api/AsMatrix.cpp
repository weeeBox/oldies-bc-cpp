#include "AsMatrix.h"
#include "AsMatrix.h"
#include "AsVector3D.h"
#include "AsPoint.h"
#include "AsNotImplementedError.h"
#include "AsMathHelper.h"
#include "AsIllegalOperationError.h"
#include "AsMath.h"
 
 
AsMatrix_ref AsMatrix::clone()
{
	return AS_NEW(AsMatrix,(a, b, c, d, tx, ty));
}
 
void AsMatrix::concat(const AsMatrix_ref& m)
{
	concatValues(m->a, m->b, m->c, m->d, m->tx, m->ty);
}
 
void AsMatrix::concatValues(float a, float b, float c, float d, float tx, float ty)
{
	setTo(((this->a * a) + (this->b * c)), ((this->a * b) + (this->b * d)), ((this->c * a) + (this->d * c)), ((this->c * b) + (this->d * d)), (((this->tx * a) + (this->ty * c)) + tx), (((this->tx * b) + (this->ty * d)) + ty));
}
 
void AsMatrix::copyColumnFrom(uint column, const AsVector3D_ref& vector3D)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix::copyColumnTo(uint column, const AsVector3D_ref& vector3D)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix::copyFrom(const AsMatrix_ref& sourceMatrix)
{
	setTo(sourceMatrix->a, sourceMatrix->b, sourceMatrix->c, sourceMatrix->d, sourceMatrix->tx, sourceMatrix->ty);
}
 
void AsMatrix::copyRowFrom(uint row, const AsVector3D_ref& vector3D)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix::copyRowTo(uint row, const AsVector3D_ref& vector3D)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix::createBox(float scaleX, float scaleY, float rotation, float tx, float ty)
{
	identity();
	rotate(rotation);
	scale(scaleX, scaleY);
	translate(tx, ty);
}
 
void AsMatrix::createBox(float scaleX, float scaleY, float rotation, float tx)
{
	createBox(scaleX, scaleY, rotation, tx, 0);
}
 
void AsMatrix::createBox(float scaleX, float scaleY, float rotation)
{
	createBox(scaleX, scaleY, rotation, 0, 0);
}
 
void AsMatrix::createBox(float scaleX, float scaleY)
{
	createBox(scaleX, scaleY, 0, 0, 0);
}
 
void AsMatrix::createGradientBox(float width, float height, float rotation, float tx, float ty)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix::createGradientBox(float width, float height, float rotation, float tx)
{
	createGradientBox(width, height, rotation, tx, 0);
}
 
void AsMatrix::createGradientBox(float width, float height, float rotation)
{
	createGradientBox(width, height, rotation, 0, 0);
}
 
void AsMatrix::createGradientBox(float width, float height)
{
	createGradientBox(width, height, 0, 0, 0);
}
 
AsPoint_ref AsMatrix::deltaTransformPoint(const AsPoint_ref& point)
{
	return AS_NEW(AsPoint,(((a * point->x) + (c * point->y)), ((b * point->x) + (d * point->y))));
}
 
void AsMatrix::identity()
{
	setTo(1, 0, 0, 1, 0, 0);
}
 
void AsMatrix::invert()
{
	float det = ((a * d) - (c * b));
	if(AsMathHelper::epsilonZero(det))
	{
		throw AS_NEW(AsIllegalOperationError,());
	}
	float detInv = (1.0f / det);
	setTo((detInv * d), (-detInv * b), (-detInv * c), (detInv * a), (detInv * ((c * ty) - (d * tx))), (-detInv * ((a * ty) - (b * tx))));
}
 
void AsMatrix::rotate(float angle)
{
	float cosA = AsMath::cos(angle);
	float sinA = AsMath::sin(angle);
	concatValues(cosA, sinA, -sinA, cosA, 0, 0);
}
 
void AsMatrix::scale(float sx, float sy)
{
	concatValues(sx, 0, 0, sy, 0, 0);
}
 
void AsMatrix::setTo(float a, float b, float c, float d, float tx, float ty)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->tx = tx;
	this->ty = ty;
}
 
AsPoint_ref AsMatrix::transformPoint(const AsPoint_ref& point)
{
	return AS_NEW(AsPoint,((((a * point->x) + (c * point->y)) + tx), (((b * point->x) + (d * point->y)) + ty)));
}
 
void AsMatrix::transformPointCords(float x, float y, const AsPoint_ref& point)
{
	point->x = (((a * x) + (c * y)) + tx);
	point->y = (((b * x) + (d * y)) + ty);
}
 
void AsMatrix::translate(float dx, float dy)
{
	concatValues(1, 0, 0, 1, dx, dy);
}
 
AsString_ref AsMatrix::toString()
{
	return ((((((((((((ASL("(a=") + a) + ASL(", b=")) + b) + ASL(", c=")) + c) + ASL(", d=")) + d) + ASL(", tx=")) + tx) + ASL(", ty=")) + ty) + ASL(")"));
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a, float b, float c, float d, float tx, float ty)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a, b, c, d, tx, ty);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a, float b, float c, float d, float tx)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a, b, c, d, tx);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a, float b, float c, float d)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a, b, c, d);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a, float b, float c)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a, b, c);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a, float b)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a, b);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix(float a)
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix(a);
	return __instance;
}
 
AsMatrix_ref AsMatrix::_as_create_AsMatrix()
{
	AsMatrix_ref __instance = new AsMatrix();
	__instance->_as_construct_AsMatrix();
	return __instance;
}
 
void AsMatrix::_as_construct_AsMatrix(float a, float b, float c, float d, float tx, float ty)
{
	setTo(a, b, c, d, tx, ty);
}
 
inline void AsMatrix::_as_construct_AsMatrix(float a, float b, float c, float d, float tx)
{
	_as_construct_AsMatrix(a, b, c, d, tx, 0);
}
 
inline void AsMatrix::_as_construct_AsMatrix(float a, float b, float c, float d)
{
	_as_construct_AsMatrix(a, b, c, d, 0, 0);
}
 
inline void AsMatrix::_as_construct_AsMatrix(float a, float b, float c)
{
	_as_construct_AsMatrix(a, b, c, 1, 0, 0);
}
 
inline void AsMatrix::_as_construct_AsMatrix(float a, float b)
{
	_as_construct_AsMatrix(a, b, 0, 1, 0, 0);
}
 
inline void AsMatrix::_as_construct_AsMatrix(float a)
{
	_as_construct_AsMatrix(a, 0, 0, 1, 0, 0);
}
 
inline void AsMatrix::_as_construct_AsMatrix()
{
	_as_construct_AsMatrix(1, 0, 0, 1, 0, 0);
}
 
bool AsMatrix::_as_static_initialized_AsMatrix = false;
AsStaticRefInitializer AsMatrix::_as_static_initializer_AsMatrix(_as_static_init_AsMatrix);
void AsMatrix::_as_static_init_AsMatrix()
{
	if (!_as_static_initialized_AsMatrix)
	{
		_as_static_initialized_AsMatrix = true;
	}
}
 
AsMatrix::AsMatrix() : 
  a(0),
  b(0),
  c(0),
  d(0),
  tx(0),
  ty(0)
{
}
