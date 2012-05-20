#ifndef AsRectangle_h__
#define AsRectangle_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsPoint_h__
#include "AsPoint.h"
#else
AS_CLASS(AsPoint);
#endif // AsPoint_h__
 
#ifndef AsRectangle_h__
#include "AsRectangle.h"
#else
AS_CLASS(AsRectangle);
#endif // AsRectangle_h__
#include "AsString.h"
 
 
AS_CLASS(AsRectangle);
 
class AsRectangle : public AsObject
{
public:
	AS_OBJ(AsRectangle, AsObject);
	
public:
	float x;
	float y;
	float width;
	float height;
	
public:
	virtual float getBottom();
	virtual void setBottom(float value);
	virtual AsPoint_ref getBottomRight();
	virtual void setBottomRight(const AsPoint_ref& value);
	virtual AsRectangle_ref clone();
	virtual bool contains(float x, float y);
	virtual bool containsPoint(const AsPoint_ref& point);
	virtual bool containsRect(const AsRectangle_ref& rect);
	virtual bool equals(const AsRectangle_ref& toCompare);
	virtual void inflate(float dx, float dy);
	virtual void inflatePoint(const AsPoint_ref& point);
	virtual AsRectangle_ref intersection(const AsRectangle_ref& toIntersect);
	virtual bool intersects(const AsRectangle_ref& toIntersect);
	virtual bool isEmpty();
	virtual float getLeft();
	virtual void setLeft(float value);
	virtual void offset(float dx, float dy);
	virtual void offsetPoint(const AsPoint_ref& point);
	virtual float getRight();
	virtual void setRight(float value);
	virtual void setEmpty();
	virtual AsPoint_ref getSize();
	virtual void setSize(const AsPoint_ref& value);
	virtual float getTop();
	virtual void setTop(float value);
	virtual AsPoint_ref getTopLeft();
	virtual void setTopLeft(const AsPoint_ref& value);
	virtual AsRectangle_ref _union(const AsRectangle_ref& toUnion);
	virtual AsString_ref toString();
	
	
public:
	static AsRectangle_ref _as_create_AsRectangle(float x, float y, float width, float height);
	static AsRectangle_ref _as_create_AsRectangle(float x, float y, float width);
	static AsRectangle_ref _as_create_AsRectangle(float x, float y);
	static AsRectangle_ref _as_create_AsRectangle(float x);
	static AsRectangle_ref _as_create_AsRectangle();
	
protected:
	void _as_construct_AsRectangle(float x, float y, float width, float height);
	void _as_construct_AsRectangle(float x, float y, float width);
	void _as_construct_AsRectangle(float x, float y);
	void _as_construct_AsRectangle(float x);
	void _as_construct_AsRectangle();
	
public:
	static void _as_static_init_AsRectangle();
	
private:
	static bool _as_static_initialized_AsRectangle;
	static AsStaticRefInitializer _as_static_initializer_AsRectangle;
	
	
protected:
	AsRectangle();
};
 
#endif // AsRectangle_h__
