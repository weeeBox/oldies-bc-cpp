#ifndef AsTransform_h__
#define AsTransform_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
#ifndef AsColorTransform_h__
#include "AsColorTransform.h"
#else
AS_CLASS(AsColorTransform);
#endif // AsColorTransform_h__
 
#ifndef AsMatrix_h__
#include "AsMatrix.h"
#else
AS_CLASS(AsMatrix);
#endif // AsMatrix_h__
 
#ifndef AsMatrix3D_h__
#include "AsMatrix3D.h"
#else
AS_CLASS(AsMatrix3D);
#endif // AsMatrix3D_h__
 
 
AS_CLASS(AsTransform);
 
class AsTransform : public AsObject
{
public:
	AS_OBJ(AsTransform, AsObject);
	
private:
	AsDisplayObject_ref mDisplayObject;
	AsColorTransform_ref mColorTransform;
	AsMatrix_ref mMatrix;
	AsMatrix3D_ref mMatrix3D;
	
public:
	virtual AsColorTransform_ref getColorTransform();
	virtual void setColorTransform(const AsColorTransform_ref& value);
	virtual AsColorTransform_ref getConcatenatedColorTransform();
	virtual AsMatrix_ref getConcatenatedMatrix();
	virtual AsMatrix_ref getMatrix();
	virtual void setMatrix(const AsMatrix_ref& value);
	virtual AsMatrix3D_ref getMatrix3D();
	virtual void setMatrix3D(const AsMatrix3D_ref& m);
	
	
public:
	static AsTransform_ref _as_create_AsTransform(const AsDisplayObject_ref& displayObject);
	
protected:
	void _as_construct_AsTransform(const AsDisplayObject_ref& displayObject);
	
public:
	static void _as_static_init_AsTransform();
	
private:
	static bool _as_static_initialized_AsTransform;
	static AsStaticRefInitializer _as_static_initializer_AsTransform;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsTransform();
};
 
#endif // AsTransform_h__
