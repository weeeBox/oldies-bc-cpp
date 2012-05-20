#ifndef AsVector3D_h__
#define AsVector3D_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsVector3D_h__
#include "AsVector3D.h"
#else
AS_CLASS(AsVector3D);
#endif // AsVector3D_h__
#include "AsString.h"
 
 
AS_CLASS(AsVector3D);
 
class AsVector3D : public AsObject
{
public:
	AS_OBJ(AsVector3D, AsObject);
	
public:
	static AsVector3D_ref X_AXIS;
	static AsVector3D_ref Y_AXIS;
	static AsVector3D_ref Z_AXIS;
	float x;
	float y;
	float z;
	float w;
	
public:
	virtual AsVector3D_ref add(const AsVector3D_ref& a);
	static float angleBetween(const AsVector3D_ref& a, const AsVector3D_ref& b);
	virtual AsVector3D_ref clone();
	virtual void copyFrom(const AsVector3D_ref& sourceVector3D);
	virtual AsVector3D_ref crossProduct(const AsVector3D_ref& a);
	virtual void decrementBy(const AsVector3D_ref& a);
	static float distance(const AsVector3D_ref& pt1, const AsVector3D_ref& pt2);
	virtual float dotProduct(const AsVector3D_ref& a);
	virtual bool equals(const AsVector3D_ref& toCompare, bool allFour);
	virtual bool equals(const AsVector3D_ref& toCompare);
	virtual void incrementBy(const AsVector3D_ref& a);
	virtual float getLength();
	virtual float getLengthSquared();
	virtual bool nearEquals(const AsVector3D_ref& toCompare, float tolerance, bool allFour);
	virtual bool nearEquals(const AsVector3D_ref& toCompare, float tolerance);
	virtual void negate();
	virtual float normalize();
	virtual void project();
	virtual void scaleBy(float s);
	virtual void setTo(float xa, float ya, float za);
	virtual AsVector3D_ref subtract(const AsVector3D_ref& a);
	virtual AsString_ref toString();
	
private:
	static bool epsilonEquals(float a, float b);
	
	
public:
	static AsVector3D_ref _as_create_AsVector3D(float x, float y, float z, float w);
	static AsVector3D_ref _as_create_AsVector3D(float x, float y, float z);
	static AsVector3D_ref _as_create_AsVector3D(float x, float y);
	static AsVector3D_ref _as_create_AsVector3D(float x);
	static AsVector3D_ref _as_create_AsVector3D();
	
protected:
	void _as_construct_AsVector3D(float x, float y, float z, float w);
	void _as_construct_AsVector3D(float x, float y, float z);
	void _as_construct_AsVector3D(float x, float y);
	void _as_construct_AsVector3D(float x);
	void _as_construct_AsVector3D();
	
public:
	static void _as_static_init_AsVector3D();
	
private:
	static bool _as_static_initialized_AsVector3D;
	static AsStaticRefInitializer _as_static_initializer_AsVector3D;
	
	
protected:
	AsVector3D();
};
 
#endif // AsVector3D_h__
