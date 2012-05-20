#ifndef AsPoint_h__
#define AsPoint_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsPoint_h__
#include "AsPoint.h"
#else
AS_CLASS(AsPoint);
#endif // AsPoint_h__
 
 
AS_CLASS(AsPoint);
 
class AsPoint : public AsObject
{
public:
	AS_OBJ(AsPoint, AsObject);
	
public:
	float x;
	float y;
	
public:
	virtual AsPoint_ref add(const AsPoint_ref& v);
	virtual AsPoint_ref clone();
	static float distance(const AsPoint_ref& pt1, const AsPoint_ref& pt2);
	virtual bool equals(const AsPoint_ref& toCompare);
	static AsPoint_ref interpolate(const AsPoint_ref& pt1, const AsPoint_ref& pt2, float ratio);
	virtual float getLength();
	virtual void normalize(float thickness);
	virtual void offset(float dx, float dy);
	static AsPoint_ref polar(float len, float angle);
	virtual AsPoint_ref subtract(const AsPoint_ref& v);
	
	
public:
	static AsPoint_ref _as_create_AsPoint(float x, float y);
	static AsPoint_ref _as_create_AsPoint(float x);
	static AsPoint_ref _as_create_AsPoint();
	
protected:
	void _as_construct_AsPoint(float x, float y);
	void _as_construct_AsPoint(float x);
	void _as_construct_AsPoint();
	
public:
	static void _as_static_init_AsPoint();
	
private:
	static bool _as_static_initialized_AsPoint;
	static AsStaticRefInitializer _as_static_initializer_AsPoint;
	
	
protected:
	AsPoint();
};
 
#endif // AsPoint_h__
