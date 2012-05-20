#include "AsTransform.h"
#include "AsDisplayObject.h"
#include "AsColorTransform.h"
#include "AsMatrix.h"
#include "AsMatrix3D.h"
#include "AsNotImplementedError.h"
 
 
AsColorTransform_ref AsTransform::getColorTransform()
{
	return mColorTransform;
}
 
void AsTransform::setColorTransform(const AsColorTransform_ref& value)
{
	mColorTransform = value;
}
 
AsColorTransform_ref AsTransform::getConcatenatedColorTransform()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsMatrix_ref AsTransform::getConcatenatedMatrix()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsMatrix_ref AsTransform::getMatrix()
{
	mMatrix = mDisplayObject->getTransformationMatrix(mDisplayObject->getParent());
	return mMatrix;
}
 
void AsTransform::setMatrix(const AsMatrix_ref& value)
{
	mMatrix = value;
}
 
AsMatrix3D_ref AsTransform::getMatrix3D()
{
	return mMatrix3D;
}
 
void AsTransform::setMatrix3D(const AsMatrix3D_ref& m)
{
	mMatrix3D = m;
}
 
AsTransform_ref AsTransform::_as_create_AsTransform(const AsDisplayObject_ref& displayObject)
{
	AsTransform_ref __instance = new AsTransform();
	__instance->_as_construct_AsTransform(displayObject);
	return __instance;
}
 
void AsTransform::_as_construct_AsTransform(const AsDisplayObject_ref& displayObject)
{
	mDisplayObject = displayObject;
	mColorTransform = AS_NEW(AsColorTransform,());
	mMatrix = AS_NEW(AsMatrix,());
}
 
bool AsTransform::_as_static_initialized_AsTransform = false;
AsStaticRefInitializer AsTransform::_as_static_initializer_AsTransform(_as_static_init_AsTransform);
void AsTransform::_as_static_init_AsTransform()
{
	if (!_as_static_initialized_AsTransform)
	{
		_as_static_initialized_AsTransform = true;
	}
}
 
void AsTransform::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mDisplayObject)
		AS_GC_MARK(mColorTransform)
		AS_GC_MARK(mMatrix)
		AS_GC_MARK(mMatrix3D)
	}
}
 
AsTransform::AsTransform() : 
  mDisplayObject(false),
  mColorTransform(false),
  mMatrix(false),
  mMatrix3D(false)
{
}
