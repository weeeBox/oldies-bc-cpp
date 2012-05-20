#ifndef AsMatrix_h__
#define AsMatrix_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
AS_CLASS(AsMatrix);
AS_CLASS(AsVector3D);
AS_CLASS(AsPoint);
 
AS_CLASS(AsMatrix);
 
class AsMatrix : public AsObject
{
public:
	AS_OBJ(AsMatrix, AsObject);
	
public:
	float a;
	float b;
	float c;
	float d;
	float tx;
	float ty;
	
public:
	virtual AsMatrix_ref clone();
	virtual void concat(const AsMatrix_ref& m);
	virtual void concatValues(float a, float b, float c, float d, float tx, float ty);
	virtual void copyColumnFrom(uint column, const AsVector3D_ref& vector3D);
	virtual void copyColumnTo(uint column, const AsVector3D_ref& vector3D);
	virtual void copyFrom(const AsMatrix_ref& sourceMatrix);
	virtual void copyRowFrom(uint row, const AsVector3D_ref& vector3D);
	virtual void copyRowTo(uint row, const AsVector3D_ref& vector3D);
	virtual void createBox(float scaleX, float scaleY, float rotation, float tx, float ty);
	virtual void createBox(float scaleX, float scaleY, float rotation, float tx);
	virtual void createBox(float scaleX, float scaleY, float rotation);
	virtual void createBox(float scaleX, float scaleY);
	virtual void createGradientBox(float width, float height, float rotation, float tx, float ty);
	virtual void createGradientBox(float width, float height, float rotation, float tx);
	virtual void createGradientBox(float width, float height, float rotation);
	virtual void createGradientBox(float width, float height);
	virtual AsPoint_ref deltaTransformPoint(const AsPoint_ref& point);
	virtual void identity();
	virtual void invert();
	virtual void rotate(float angle);
	virtual void scale(float sx, float sy);
	virtual void setTo(float a, float b, float c, float d, float tx, float ty);
	virtual AsPoint_ref transformPoint(const AsPoint_ref& point);
	virtual void transformPointCords(float x, float y, const AsPoint_ref& point);
	virtual void translate(float dx, float dy);
	virtual AsString_ref toString();
	
	
public:
	static AsMatrix_ref _as_create_AsMatrix(float a, float b, float c, float d, float tx, float ty);
	static AsMatrix_ref _as_create_AsMatrix(float a, float b, float c, float d, float tx);
	static AsMatrix_ref _as_create_AsMatrix(float a, float b, float c, float d);
	static AsMatrix_ref _as_create_AsMatrix(float a, float b, float c);
	static AsMatrix_ref _as_create_AsMatrix(float a, float b);
	static AsMatrix_ref _as_create_AsMatrix(float a);
	static AsMatrix_ref _as_create_AsMatrix();
	
protected:
	void _as_construct_AsMatrix(float a, float b, float c, float d, float tx, float ty);
	void _as_construct_AsMatrix(float a, float b, float c, float d, float tx);
	void _as_construct_AsMatrix(float a, float b, float c, float d);
	void _as_construct_AsMatrix(float a, float b, float c);
	void _as_construct_AsMatrix(float a, float b);
	void _as_construct_AsMatrix(float a);
	void _as_construct_AsMatrix();
	
public:
	static void _as_static_init_AsMatrix();
	
private:
	static bool _as_static_initialized_AsMatrix;
	static AsStaticRefInitializer _as_static_initializer_AsMatrix;
	
	
protected:
	AsMatrix();
};
 
#endif // AsMatrix_h__
