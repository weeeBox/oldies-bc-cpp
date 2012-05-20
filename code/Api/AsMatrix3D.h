#ifndef AsMatrix3D_h__
#define AsMatrix3D_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsVector.h"
#include "AsString.h"
 
AS_CLASS(AsVector3D);
AS_VECTOR_PRIMITIVE_REF(float);
AS_CLASS(AsMatrix3D);
AS_VECTOR_REF(AsVector3D);
 
AS_CLASS(AsMatrix3D);
 
class AsMatrix3D : public AsObject
{
public:
	AS_OBJ(AsMatrix3D, AsObject);
	
private:
	float m11;
	float m12;
	float m13;
	float m21;
	float m22;
	float m23;
	float m31;
	float m32;
	float m33;
	AsVector3D_ref t;
	float mDeterminant;
	
private:
	virtual void appendValues(float m11, float m12, float m13, float tx, float m21, float m22, float m23, float ty, float m31, float m32, float m33, float tz);
	virtual void prependValues(float m11, float m12, float m13, float tx, float m21, float m22, float m23, float ty, float m31, float m32, float m33, float tz);
	
public:
	virtual void append(const AsMatrix3D_ref& lhs);
	virtual void appendRotation(float degrees, const AsVector3D_ref& axis, const AsVector3D_ref& pivotPoint);
	virtual void appendRotation(float degrees, const AsVector3D_ref& axis);
	virtual void appendScale(float xScale, float yScale, float zScale);
	virtual void appendTranslation(float x, float y, float z);
	virtual AsMatrix3D_ref clone();
	virtual void copyColumnFrom(uint column, const AsVector3D_ref& vector3D);
	virtual void copyColumnTo(uint column, const AsVector3D_ref& vector3D);
	virtual void copyFrom(const AsMatrix3D_ref& sourceMatrix3D);
	virtual void copyRawDataFrom(const _V_float_ref& vector, uint index, bool transpose);
	virtual void copyRawDataFrom(const _V_float_ref& vector, uint index);
	virtual void copyRawDataFrom(const _V_float_ref& vector);
	virtual void copyRawDataTo(const _V_float_ref& vector, uint index, bool transpose);
	virtual void copyRawDataTo(const _V_float_ref& vector, uint index);
	virtual void copyRawDataTo(const _V_float_ref& vector);
	virtual void copyRowFrom(uint row, const AsVector3D_ref& vector3D);
	virtual void copyRowTo(uint row, const AsVector3D_ref& vector3D);
	virtual void copyToMatrix3D(const AsMatrix3D_ref& dest);
	virtual _V_AsVector3D_ref decompose(const AsString_ref& orientationStyle);
	virtual _V_AsVector3D_ref decompose();
	virtual AsVector3D_ref deltaTransformVector(const AsVector3D_ref& v);
	virtual void identity();
	static AsMatrix3D_ref interpolate(const AsMatrix3D_ref& thisMat, const AsMatrix3D_ref& toMat, float percent);
	virtual void interpolateTo(const AsMatrix3D_ref& toMat, float percent);
	virtual bool invert();
	virtual void pointAt(const AsVector3D_ref& pos, const AsVector3D_ref& at, const AsVector3D_ref& up);
	virtual void pointAt(const AsVector3D_ref& pos, const AsVector3D_ref& at);
	virtual void pointAt(const AsVector3D_ref& pos);
	virtual void prepend(const AsMatrix3D_ref& rhs);
	virtual void prependRotation(float degrees, const AsVector3D_ref& axis, const AsVector3D_ref& pivotPoint);
	virtual void prependRotation(float degrees, const AsVector3D_ref& axis);
	virtual void prependScale(float xScale, float yScale, float zScale);
	virtual void prependTranslation(float x, float y, float z);
	virtual bool recompose(const _V_AsVector3D_ref& components, const AsString_ref& orientationStyle);
	virtual bool recompose(const _V_AsVector3D_ref& components);
	virtual AsVector3D_ref transformVector(const AsVector3D_ref& v);
	virtual void transformVectors(const _V_float_ref& vin, const _V_float_ref& vout);
	virtual void transpose();
	virtual float getDeterminant();
	virtual AsVector3D_ref getPosition();
	virtual _V_float_ref getRawData();
	
	
public:
	static AsMatrix3D_ref _as_create_AsMatrix3D(const _V_float_ref& v);
	static AsMatrix3D_ref _as_create_AsMatrix3D();
	
protected:
	void _as_construct_AsMatrix3D(const _V_float_ref& v);
	void _as_construct_AsMatrix3D();
	
public:
	static void _as_static_init_AsMatrix3D();
	
private:
	static bool _as_static_initialized_AsMatrix3D;
	static AsStaticRefInitializer _as_static_initializer_AsMatrix3D;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsMatrix3D();
};
 
#endif // AsMatrix3D_h__
