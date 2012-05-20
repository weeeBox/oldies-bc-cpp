#include "AsRenderSupport.h"
#include "AsMatrix.h"
#include "AsBitmapData.h"
#include "AsNotImplementedError.h"
 
 
void AsRenderSupport::dispose()
{
}
 
void AsRenderSupport::transform(const AsMatrix_ref& matrix)
{
	mCurrentMatrix->concat(matrix);
}
 
void AsRenderSupport::pushMatrix()
{
	if((mMatrixStack->getLength() < (mMatrixStackSize + 1)))
	{
		mMatrixStack->push(AS_NEW(AsMatrix,()));
	}
	mMatrixStack[mMatrixStackSize++]->copyFrom(mCurrentMatrix);
}
 
void AsRenderSupport::popMatrix()
{
	mCurrentMatrix->copyFrom(mMatrixStack[--mMatrixStackSize]);
}
 
void AsRenderSupport::resetMatrix()
{
	mMatrixStackSize = 0;
	mCurrentMatrix->identity();
}
 
void AsRenderSupport::drawBitmap(const AsBitmapData_ref& bitmap, float alpha)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsRenderSupport_ref AsRenderSupport::_as_create_AsRenderSupport()
{
	AsRenderSupport_ref __instance = new AsRenderSupport();
	__instance->_as_construct_AsRenderSupport();
	return __instance;
}
 
void AsRenderSupport::_as_construct_AsRenderSupport()
{
	mMatrixStack = AS_NEW_VECTOR(AsMatrix,());
	mMatrixStackSize = 0;
	mCurrentMatrix = AS_NEW(AsMatrix,());
}
 
bool AsRenderSupport::_as_static_initialized_AsRenderSupport = false;
AsStaticRefInitializer AsRenderSupport::_as_static_initializer_AsRenderSupport(_as_static_init_AsRenderSupport);
void AsRenderSupport::_as_static_init_AsRenderSupport()
{
	if (!_as_static_initialized_AsRenderSupport)
	{
		_as_static_initialized_AsRenderSupport = true;
	}
}
 
void AsRenderSupport::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mMatrixStack)
		AS_GC_MARK(mCurrentMatrix)
	}
}
 
AsRenderSupport::AsRenderSupport() : 
  mMatrixStack(false),
  mMatrixStackSize(0),
  mCurrentMatrix(false)
{
}
