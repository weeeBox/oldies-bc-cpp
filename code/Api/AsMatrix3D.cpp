#include "AsMatrix3D.h"
#include "AsMatrix3D.h"
#include "AsVector3D.h"
#include "AsString.h"
#include "AsMathHelper.h"
#include "AsMath.h"
#include "AsNotImplementedError.h"
#include "AsArgumentError.h"
#include "AsRangeError.h"
 
 
void AsMatrix3D::appendValues(float m11, float m12, float m13, float tx, float m21, float m22, float m23, float ty, float m31, float m32, float m33, float tz)
{
	float o11 = this->m11;
	float o12 = this->m12;
	float o13 = this->m13;
	float x = this->t->x;
	float o21 = this->m21;
	float o22 = this->m22;
	float o23 = this->m23;
	float y = this->t->y;
	float o31 = this->m31;
	float o32 = this->m32;
	float o33 = this->m33;
	float z = this->t->z;
	this->m11 = (((m11 * o11) + (m12 * o21)) + (m13 * o31));
	this->m12 = (((m11 * o12) + (m12 * o22)) + (m13 * o32));
	this->m13 = (((m11 * o13) + (m12 * o23)) + (m13 * o33));
	this->t->x = ((((m11 * x) + (m12 * y)) + (m13 * z)) + tx);
	this->m21 = (((m21 * o11) + (m22 * o21)) + (m23 * o31));
	this->m22 = (((m21 * o12) + (m22 * o22)) + (m23 * o32));
	this->m23 = (((m21 * o13) + (m22 * o23)) + (m23 * o33));
	this->t->y = ((((m21 * x) + (m22 * y)) + (m23 * z)) + ty);
	this->m31 = (((m31 * o11) + (m32 * o21)) + (m33 * o31));
	this->m32 = (((m31 * o12) + (m32 * o22)) + (m33 * o32));
	this->m33 = (((m31 * o13) + (m32 * o23)) + (m33 * o33));
	this->t->z = ((((m31 * x) + (m32 * y)) + (m33 * z)) + tz);
}
 
void AsMatrix3D::prependValues(float m11, float m12, float m13, float tx, float m21, float m22, float m23, float ty, float m31, float m32, float m33, float tz)
{
	float o11 = this->m11;
	float o12 = this->m12;
	float o13 = this->m13;
	float x = this->t->x;
	float o21 = this->m21;
	float o22 = this->m22;
	float o23 = this->m23;
	float y = this->t->y;
	float o31 = this->m31;
	float o32 = this->m32;
	float o33 = this->m33;
	float z = this->t->z;
	this->m11 = (((o11 * m11) + (o12 * m21)) + (o13 * m31));
	this->m12 = (((o11 * m12) + (o12 * m22)) + (o13 * m32));
	this->m13 = (((o11 * m13) + (o12 * m23)) + (o13 * m33));
	this->t->x = ((((o11 * x) + (o12 * y)) + (o13 * z)) + tx);
	this->m21 = (((o21 * m11) + (o22 * m21)) + (o23 * m31));
	this->m22 = (((o21 * m12) + (o22 * m22)) + (o23 * m32));
	this->m23 = (((o21 * m13) + (o22 * m23)) + (o23 * m33));
	this->t->y = ((((o21 * x) + (o22 * y)) + (o23 * z)) + ty);
	this->m31 = (((o31 * m11) + (o32 * m21)) + (o33 * m31));
	this->m32 = (((o31 * m12) + (o32 * m22)) + (o33 * m32));
	this->m33 = (((o31 * m13) + (o32 * m23)) + (o33 * m33));
	this->t->z = ((((o31 * x) + (o32 * y)) + (o33 * z)) + tz);
}
 
void AsMatrix3D::append(const AsMatrix3D_ref& lhs)
{
	appendValues(lhs->m11, lhs->m12, lhs->m13, lhs->t->x, lhs->m21, lhs->m22, lhs->m23, lhs->t->y, lhs->m31, lhs->m32, lhs->m33, lhs->t->z);
}
 
void AsMatrix3D::appendRotation(float degrees, const AsVector3D_ref& axis, const AsVector3D_ref& pivotPoint)
{
	bool hasPivot = ((pivotPoint != AS_NULL) && (((pivotPoint->x != 0.0f) || (pivotPoint->y != 0.0f)) || (pivotPoint->z != 0.0f)));
	if(hasPivot)
	{
		appendTranslation(-pivotPoint->x, -pivotPoint->y, -pivotPoint->z);
	}
	float radians = AsMathHelper::toRadians(degrees);
	float cosA = AsMath::cos(radians);
	float sinA = AsMath::sin(radians);
	float ax = axis->x;
	float ay = axis->y;
	float az = axis->z;
	if((((ax == 0.0f) && (ay == 0.0f)) && (az == 1.0f)))
	{
		appendValues(cosA, -sinA, 0, 0, sinA, cosA, 0, 0, 0, 0, 1, 0);
	}
	else
	{
		if((((ax == 0.0f) && (ay == 1.0f)) && (az == 0.0f)))
		{
			appendValues(cosA, 0, sinA, 0, 0, 1, 0, 0, -sinA, 0, cosA, 0);
		}
		else
		{
			if((((ax == 1.0f) && (ay == 0.0f)) && (az == 0.0f)))
			{
				appendValues(1, 0, 0, 0, 0, cosA, -sinA, 0, 0, sinA, cosA, 0);
			}
			else
			{
				throw AS_NEW(AsNotImplementedError,());
			}
		}
	}
	if(hasPivot)
	{
		appendTranslation(pivotPoint->x, pivotPoint->y, pivotPoint->z);
	}
}
 
void AsMatrix3D::appendRotation(float degrees, const AsVector3D_ref& axis)
{
	appendRotation(degrees, axis, AS_NULL);
}
 
void AsMatrix3D::appendScale(float xScale, float yScale, float zScale)
{
	appendValues(xScale, 0, 0, 0, 0, yScale, 0, 0, 0, 0, zScale, 0);
}
 
void AsMatrix3D::appendTranslation(float x, float y, float z)
{
	appendValues(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z);
}
 
AsMatrix3D_ref AsMatrix3D::clone()
{
	AsMatrix3D_ref m = AS_NEW(AsMatrix3D,());
	m->m11 = m11;
	m->m12 = m12;
	m->m13 = m13;
	m->t->x = t->x;
	m->m21 = m21;
	m->m22 = m22;
	m->m23 = m23;
	m->t->y = t->y;
	m->m31 = m31;
	m->m32 = m32;
	m->m33 = m33;
	m->t->z = t->z;
	m->mDeterminant = mDeterminant;
	return m;
}
 
void AsMatrix3D::copyColumnFrom(uint column, const AsVector3D_ref& vector3D)
{
	if((column == 1))
	{
		m11 = vector3D->x;
		m21 = vector3D->y;
		m31 = vector3D->z;
	}
	else
	{
		if((column == 2))
		{
			m12 = vector3D->x;
			m22 = vector3D->y;
			m32 = vector3D->z;
		}
		else
		{
			if((column == 3))
			{
				m13 = vector3D->x;
				m23 = vector3D->y;
				m33 = vector3D->z;
			}
			else
			{
				if((column == 4))
				{
					t->x = vector3D->x;
					t->y = vector3D->y;
					t->z = vector3D->z;
				}
				else
				{
					throw AS_NEW(AsArgumentError,());
				}
			}
		}
	}
}
 
void AsMatrix3D::copyColumnTo(uint column, const AsVector3D_ref& vector3D)
{
	if((column == 1))
	{
		vector3D->x = m11;
		vector3D->y = m21;
		vector3D->z = m31;
	}
	else
	{
		if((column == 2))
		{
			vector3D->x = m12;
			vector3D->y = m22;
			vector3D->z = m32;
		}
		else
		{
			if((column == 3))
			{
				vector3D->x = m13;
				vector3D->y = m23;
				vector3D->z = m33;
			}
			else
			{
				if((column == 4))
				{
					vector3D->x = t->x;
					vector3D->y = t->y;
					vector3D->z = t->z;
				}
				else
				{
					throw AS_NEW(AsArgumentError,());
				}
			}
		}
	}
}
 
void AsMatrix3D::copyFrom(const AsMatrix3D_ref& sourceMatrix3D)
{
	m11 = sourceMatrix3D->m11;
	m12 = sourceMatrix3D->m12;
	m13 = sourceMatrix3D->m13;
	t->x = sourceMatrix3D->t->x;
	m21 = sourceMatrix3D->m21;
	m22 = sourceMatrix3D->m22;
	m23 = sourceMatrix3D->m23;
	t->y = sourceMatrix3D->t->y;
	m31 = sourceMatrix3D->m31;
	m32 = sourceMatrix3D->m32;
	m33 = sourceMatrix3D->m33;
	t->z = sourceMatrix3D->t->z;
}
 
void AsMatrix3D::copyRawDataFrom(const _V_float_ref& vector, uint index, bool transpose)
{
	if(transpose)
	{
		throw AS_NEW(AsNotImplementedError,());
	}
	if((index == 0))
	{
		m11 = vector[0];
		m21 = vector[1];
		m31 = vector[2];
		m12 = vector[4];
		m22 = vector[5];
		m32 = vector[6];
		m13 = vector[8];
		m23 = vector[9];
		m33 = vector[10];
		t->x = vector[12];
		t->y = vector[13];
		t->z = vector[14];
	}
	else
	{
		if(((index + 14) >= vector->getLength()))
		{
			throw AS_NEW(AsArgumentError,());
		}
		m11 = vector[index];
		m21 = vector[(index + 1)];
		m31 = vector[(index + 2)];
		m12 = vector[(index + 4)];
		m22 = vector[(index + 5)];
		m32 = vector[(index + 6)];
		m13 = vector[(index + 8)];
		m23 = vector[(index + 9)];
		m33 = vector[(index + 10)];
		t->x = vector[(index + 12)];
		t->y = vector[(index + 13)];
		t->z = vector[(index + 14)];
	}
}
 
void AsMatrix3D::copyRawDataFrom(const _V_float_ref& vector, uint index)
{
	copyRawDataFrom(vector, index, false);
}
 
void AsMatrix3D::copyRawDataFrom(const _V_float_ref& vector)
{
	copyRawDataFrom(vector, (uint)(0), false);
}
 
void AsMatrix3D::copyRawDataTo(const _V_float_ref& vector, uint index, bool transpose)
{
	if(transpose)
	{
		throw AS_NEW(AsNotImplementedError,());
	}
	if((index == 0))
	{
		vector[0] = m11;
		vector[1] = m21;
		vector[2] = m31;
		vector[4] = m12;
		vector[5] = m22;
		vector[6] = m32;
		vector[8] = m13;
		vector[9] = m23;
		vector[10] = m33;
		vector[12] = t->x;
		vector[13] = t->y;
		vector[14] = t->z;
	}
	else
	{
		vector[index] = m11;
		vector[(index + 1)] = m21;
		vector[(index + 2)] = m31;
		vector[(index + 4)] = m12;
		vector[(index + 5)] = m22;
		vector[(index + 6)] = m32;
		vector[(index + 8)] = m13;
		vector[(index + 9)] = m23;
		vector[(index + 10)] = m33;
		vector[(index + 12)] = t->x;
		vector[(index + 13)] = t->y;
		vector[(index + 14)] = t->z;
	}
}
 
void AsMatrix3D::copyRawDataTo(const _V_float_ref& vector, uint index)
{
	copyRawDataTo(vector, index, false);
}
 
void AsMatrix3D::copyRawDataTo(const _V_float_ref& vector)
{
	copyRawDataTo(vector, (uint)(0), false);
}
 
void AsMatrix3D::copyRowFrom(uint row, const AsVector3D_ref& vector3D)
{
	if((row == 1))
	{
		m11 = vector3D->x;
		m12 = vector3D->y;
		m13 = vector3D->z;
		t->x = vector3D->w;
	}
	else
	{
		if((row == 2))
		{
			m21 = vector3D->x;
			m22 = vector3D->y;
			m23 = vector3D->z;
			t->y = vector3D->w;
		}
		else
		{
			if((row == 3))
			{
				m31 = vector3D->x;
				m32 = vector3D->y;
				m33 = vector3D->z;
				t->z = vector3D->w;
			}
			else
			{
				throw AS_NEW(AsRangeError,());
			}
		}
	}
}
 
void AsMatrix3D::copyRowTo(uint row, const AsVector3D_ref& vector3D)
{
	if((row == 1))
	{
		vector3D->x = m11;
		vector3D->y = m12;
		vector3D->z = m13;
		vector3D->w = t->x;
	}
	else
	{
		if((row == 2))
		{
			vector3D->x = m21;
			vector3D->y = m22;
			vector3D->z = m23;
			vector3D->w = t->y;
		}
		else
		{
			if((row == 3))
			{
				vector3D->x = m31;
				vector3D->y = m32;
				vector3D->z = m33;
				vector3D->w = t->z;
			}
			else
			{
				throw AS_NEW(AsRangeError,());
			}
		}
	}
}
 
void AsMatrix3D::copyToMatrix3D(const AsMatrix3D_ref& dest)
{
	dest->m11 = m11;
	dest->m12 = m12;
	dest->m13 = m13;
	dest->m21 = m21;
	dest->m22 = m22;
	dest->m23 = m23;
	dest->m31 = m31;
	dest->m32 = m32;
	dest->m33 = m33;
	dest->t->x = t->x;
	dest->t->y = t->y;
	dest->t->z = t->z;
}
 
_V_AsVector3D_ref AsMatrix3D::decompose(const AsString_ref& orientationStyle)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
_V_AsVector3D_ref AsMatrix3D::decompose()
{
	return decompose(ASL("eulerAngles"));
}
 
AsVector3D_ref AsMatrix3D::deltaTransformVector(const AsVector3D_ref& v)
{
	float x = v->x;
	float y = v->y;
	float z = v->z;
	return AS_NEW(AsVector3D,((((m11 * x) + (m12 * y)) + (m13 * z)), (((m21 * x) + (m22 * y)) + (m23 * z)), (((m31 * x) + (m32 * y)) + (m33 * z))));
}
 
void AsMatrix3D::identity()
{
	m12 = m13 = m21 = m23 = m31 = m32 = 0.0f;
	m11 = m22 = m33 = 1.0f;
	t->x = t->y = t->z = 0.0f;
}
 
AsMatrix3D_ref AsMatrix3D::interpolate(const AsMatrix3D_ref& thisMat, const AsMatrix3D_ref& toMat, float percent)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix3D::interpolateTo(const AsMatrix3D_ref& toMat, float percent)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsMatrix3D::invert()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix3D::pointAt(const AsVector3D_ref& pos, const AsVector3D_ref& at, const AsVector3D_ref& up)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsMatrix3D::pointAt(const AsVector3D_ref& pos, const AsVector3D_ref& at)
{
	pointAt(pos, at, AS_NULL);
}
 
void AsMatrix3D::pointAt(const AsVector3D_ref& pos)
{
	pointAt(pos, AS_NULL, AS_NULL);
}
 
void AsMatrix3D::prepend(const AsMatrix3D_ref& rhs)
{
	prependValues(rhs->m11, rhs->m12, rhs->m13, rhs->t->x, rhs->m21, rhs->m22, rhs->m23, rhs->t->y, rhs->m31, rhs->m32, rhs->m33, rhs->t->z);
}
 
void AsMatrix3D::prependRotation(float degrees, const AsVector3D_ref& axis, const AsVector3D_ref& pivotPoint)
{
	bool hasPivot = ((pivotPoint != AS_NULL) && (((pivotPoint->x != 0.0f) || (pivotPoint->y != 0.0f)) || (pivotPoint->z != 0.0f)));
	if(hasPivot)
	{
		prependTranslation(-pivotPoint->x, -pivotPoint->y, -pivotPoint->z);
	}
	float radians = AsMathHelper::toRadians(degrees);
	float cosA = AsMath::cos(radians);
	float sinA = AsMath::sin(radians);
	float ax = axis->x;
	float ay = axis->y;
	float az = axis->z;
	if((((ax == 0.0f) && (ay == 0.0f)) && (az == 1.0f)))
	{
		prependValues(cosA, -sinA, 0, 0, sinA, cosA, 0, 0, 0, 0, 1, 0);
	}
	else
	{
		if((((ax == 0.0f) && (ay == 1.0f)) && (az == 0.0f)))
		{
			prependValues(cosA, 0, sinA, 0, 0, 1, 0, 0, -sinA, 0, cosA, 0);
		}
		else
		{
			if((((ax == 1.0f) && (ay == 0.0f)) && (az == 0.0f)))
			{
				prependValues(1, 0, 0, 0, 0, cosA, -sinA, 0, 0, sinA, cosA, 0);
			}
			else
			{
				throw AS_NEW(AsNotImplementedError,());
			}
		}
	}
	if(hasPivot)
	{
		prependTranslation(pivotPoint->x, pivotPoint->y, pivotPoint->z);
	}
}
 
void AsMatrix3D::prependRotation(float degrees, const AsVector3D_ref& axis)
{
	prependRotation(degrees, axis, AS_NULL);
}
 
void AsMatrix3D::prependScale(float xScale, float yScale, float zScale)
{
	prependValues(xScale, 0, 0, 0, 0, yScale, 0, 0, 0, 0, zScale, 0);
}
 
void AsMatrix3D::prependTranslation(float x, float y, float z)
{
	prependValues(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z);
}
 
bool AsMatrix3D::recompose(const _V_AsVector3D_ref& components, const AsString_ref& orientationStyle)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsMatrix3D::recompose(const _V_AsVector3D_ref& components)
{
	return recompose(components, ASL("eulerAngles"));
}
 
AsVector3D_ref AsMatrix3D::transformVector(const AsVector3D_ref& v)
{
	float x = v->x;
	float y = v->y;
	float z = v->z;
	return AS_NEW(AsVector3D,(((((m11 * x) + (m12 * y)) + (m13 * z)) + t->x), ((((m21 * x) + (m22 * y)) + (m23 * z)) + t->y), ((((m31 * x) + (m32 * y)) + (m33 * z)) + t->z)));
}
 
void AsMatrix3D::transformVectors(const _V_float_ref& vin, const _V_float_ref& vout)
{
	int len = (int)(vin->getLength());
	if(((len % 3) != 0))
	{
		throw AS_NEW(AsArgumentError,());
	}
	if((len > vout->getLength()))
	{
		throw AS_NEW(AsArgumentError,());
	}
	int i = 0;
	for (; (i < len); i = (i + 3))
	{
		float x = vin[i];
		float y = vin[(i + 1)];
		float z = vin[(i + 2)];
		vout[i] = ((((m11 * x) + (m12 * y)) + (m13 * z)) + t->x);
		vout[(i + 1)] = ((((m21 * x) + (m22 * y)) + (m23 * z)) + t->y);
		vout[(i + 2)] = ((((m31 * x) + (m32 * y)) + (m33 * z)) + t->z);
	}
}
 
void AsMatrix3D::transpose()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsMatrix3D::getDeterminant()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsVector3D_ref AsMatrix3D::getPosition()
{
	return t;
}
 
_V_float_ref AsMatrix3D::getRawData()
{
	return AS_NEW_PRIMITIVES_VECTOR(float,(16)) << m11 << m21 << m31 << 0 << m12 << m22 << m32 << 0 << m13 << m23 << m33 << 0 << t->x << t->y << t->z << 1;
}
 
AsMatrix3D_ref AsMatrix3D::_as_create_AsMatrix3D(const _V_float_ref& v)
{
	AsMatrix3D_ref __instance = new AsMatrix3D();
	__instance->_as_construct_AsMatrix3D(v);
	return __instance;
}
 
AsMatrix3D_ref AsMatrix3D::_as_create_AsMatrix3D()
{
	AsMatrix3D_ref __instance = new AsMatrix3D();
	__instance->_as_construct_AsMatrix3D();
	return __instance;
}
 
void AsMatrix3D::_as_construct_AsMatrix3D(const _V_float_ref& v)
{
	t = AS_NEW(AsVector3D,());
	if((v != AS_NULL))
	{
		m11 = v[0];
		m21 = v[1];
		m31 = v[2];
		m12 = v[4];
		m22 = v[5];
		m32 = v[6];
		m13 = v[8];
		m23 = v[9];
		m33 = v[10];
		t->x = v[12];
		t->y = v[13];
		t->z = v[14];
	}
	else
	{
		m12 = m13 = m21 = m23 = m31 = m32 = 0.0f;
		m11 = m22 = m33 = 1.0f;
	}
}
 
inline void AsMatrix3D::_as_construct_AsMatrix3D()
{
	_as_construct_AsMatrix3D(AS_NULL);
}
 
bool AsMatrix3D::_as_static_initialized_AsMatrix3D = false;
AsStaticRefInitializer AsMatrix3D::_as_static_initializer_AsMatrix3D(_as_static_init_AsMatrix3D);
void AsMatrix3D::_as_static_init_AsMatrix3D()
{
	if (!_as_static_initialized_AsMatrix3D)
	{
		_as_static_initialized_AsMatrix3D = true;
	}
}
 
void AsMatrix3D::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(t)
	}
}
 
AsMatrix3D::AsMatrix3D() : 
  m11(0),
  m12(0),
  m13(0),
  m21(0),
  m22(0),
  m23(0),
  m31(0),
  m32(0),
  m33(0),
  t(false),
  mDeterminant(0)
{
}
