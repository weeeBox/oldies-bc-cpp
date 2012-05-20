#ifndef AsRenderSupport_h__
#define AsRenderSupport_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsVector.h"
 
AS_CLASS(AsMatrix);
AS_VECTOR_REF(AsMatrix);
AS_CLASS(AsBitmapData);
 
AS_CLASS(AsRenderSupport);
 
class AsRenderSupport : public AsObject
{
public:
	AS_OBJ(AsRenderSupport, AsObject);
	
private:
	_V_AsMatrix_ref mMatrixStack;
	int mMatrixStackSize;
	AsMatrix_ref mCurrentMatrix;
	
public:
	virtual void dispose();
	virtual void transform(const AsMatrix_ref& matrix);
	virtual void pushMatrix();
	virtual void popMatrix();
	virtual void resetMatrix();
	virtual void drawBitmap(const AsBitmapData_ref& bitmap, float alpha);
	
	
public:
	static AsRenderSupport_ref _as_create_AsRenderSupport();
	
protected:
	void _as_construct_AsRenderSupport();
	
public:
	static void _as_static_init_AsRenderSupport();
	
private:
	static bool _as_static_initialized_AsRenderSupport;
	static AsStaticRefInitializer _as_static_initializer_AsRenderSupport;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsRenderSupport();
};
 
#endif // AsRenderSupport_h__
