#include "AsDisplayObject.h"
#include "AsDisplayObject.h"
#include "AsRectangle.h"
#include "AsPoint.h"
#include "AsMatrix.h"
#include "AsRenderSupport.h"
#include "AsEvent.h"
#include "AsTouchEvent.h"
#include "AsDisplayObjectContainer.h"
#include "AsString.h"
#include "AsTransform.h"
#include "AsAbstractClassError.h"
#include "AsAbstractMethodError.h"
#include "AsMathHelper.h"
#include "AsArgumentError.h"
#include "AsStage.h"
 
_V_AsDisplayObject_ref AsDisplayObject::sAncestors(true);
AsRectangle_ref AsDisplayObject::sHelperRect(true);
AsMatrix_ref AsDisplayObject::sHelperMatrix(true);
AsMatrix_ref AsDisplayObject::sTargetMatrix(true);
 
void AsDisplayObject::dispose()
{
	removeEventListeners();
}
 
void AsDisplayObject::removeFromParent(bool dispose)
{
	if(mParent != AS_NULL)
	{
		mParent->removeChild(this);
	}
	if(dispose)
	{
		this->dispose();
	}
}
 
void AsDisplayObject::removeFromParent()
{
	removeFromParent(false);
}
 
AsRectangle_ref AsDisplayObject::getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect)
{
	throw AS_NEW(AsAbstractMethodError,(ASL("Method needs to be implemented in subclass")));
}
 
AsRectangle_ref AsDisplayObject::getBounds(const AsDisplayObject_ref& targetSpace)
{
	return getBounds(targetSpace, AS_NULL);
}
 
AsDisplayObject_ref AsDisplayObject::hitTest(const AsPoint_ref& localPoint, bool forTouch)
{
	if((forTouch && (!(mVisible) || !(mTouchable))))
	{
		return AS_NULL;
	}
	if(getBounds(this, sHelperRect)->containsPoint(localPoint))
	{
		return this;
	}
	else
	{
		return AS_NULL;
	}
}
 
AsDisplayObject_ref AsDisplayObject::hitTest(const AsPoint_ref& localPoint)
{
	return hitTest(localPoint, false);
}
 
AsMatrix_ref AsDisplayObject::getTransformationMatrix(const AsDisplayObject_ref& targetSpace, const AsMatrix_ref& resultMatrix)
{
	if(resultMatrix != AS_NULL)
	{
		resultMatrix->identity();
	}
	else
	{
		resultMatrix = AS_NEW(AsMatrix,());
	}
	AsDisplayObject_ref currentObject = this;
	if((targetSpace == this))
	{
		return resultMatrix;
	}
	else
	{
		if(((targetSpace == mParent) || ((targetSpace == AS_NULL) && (mParent == AS_NULL))))
		{
			if(((mPivotX != 0.0f) || (mPivotY != 0.0f)))
			{
				resultMatrix->translate(-mPivotX, -mPivotY);
			}
			if(((mScaleX != 1.0f) || (mScaleY != 1.0f)))
			{
				resultMatrix->scale(mScaleX, mScaleY);
			}
			if((mRotation != 0.0f))
			{
				resultMatrix->rotate(AsMathHelper::toRadians(mRotation));
			}
			if(((mX != 0.0f) || (mY != 0.0f)))
			{
				resultMatrix->translate(mX, mY);
			}
			return resultMatrix;
		}
		else
		{
			if((targetSpace == AS_NULL))
			{
				currentObject = this;
				while(currentObject != AS_NULL)
				{
					currentObject->getTransformationMatrix(currentObject->mParent, sHelperMatrix);
					resultMatrix->concat(sHelperMatrix);
					currentObject = currentObject->getParent();
				}
				return resultMatrix;
			}
			else
			{
				if((targetSpace->mParent == this))
				{
					targetSpace->getTransformationMatrix(this, resultMatrix);
					resultMatrix->invert();
					return resultMatrix;
				}
			}
		}
	}
	sAncestors->setLength(0);
	AsDisplayObject_ref commonParent = AS_NULL;
	while(currentObject != AS_NULL)
	{
		sAncestors->push(currentObject);
		currentObject = currentObject->getParent();
	}
	currentObject = targetSpace;
	while(((currentObject != AS_NULL) && (sAncestors->indexOf(currentObject) == -1)))
	{
		currentObject = currentObject->getParent();
	}
	if((currentObject == AS_NULL))
	{
		throw AS_NEW(AsArgumentError,(ASL("Object not connected to target")));
	}
	else
	{
		commonParent = currentObject;
	}
	currentObject = this;
	while((currentObject != commonParent))
	{
		currentObject->getTransformationMatrix(currentObject->mParent, sHelperMatrix);
		resultMatrix->concat(sHelperMatrix);
		currentObject = currentObject->getParent();
	}
	sTargetMatrix->identity();
	currentObject = targetSpace;
	while((currentObject != commonParent))
	{
		currentObject->getTransformationMatrix(currentObject->mParent, sHelperMatrix);
		sTargetMatrix->concat(sHelperMatrix);
		currentObject = currentObject->getParent();
	}
	sTargetMatrix->invert();
	resultMatrix->concat(sTargetMatrix);
	return resultMatrix;
}
 
AsMatrix_ref AsDisplayObject::getTransformationMatrix(const AsDisplayObject_ref& targetSpace)
{
	return getTransformationMatrix(targetSpace, AS_NULL);
}
 
AsPoint_ref AsDisplayObject::localToGlobal(const AsPoint_ref& localPoint)
{
	sTargetMatrix->identity();
	AsDisplayObject_ref currentObject = this;
	while(currentObject != AS_NULL)
	{
		currentObject->getTransformationMatrix(currentObject->mParent, sHelperMatrix);
		sTargetMatrix->concat(sHelperMatrix);
		currentObject = currentObject->getParent();
	}
	return sTargetMatrix->transformPoint(localPoint);
}
 
AsPoint_ref AsDisplayObject::globalToLocal(const AsPoint_ref& globalPoint)
{
	sTargetMatrix->identity();
	AsDisplayObject_ref currentObject = this;
	while(currentObject != AS_NULL)
	{
		currentObject->getTransformationMatrix(currentObject->mParent, sHelperMatrix);
		sTargetMatrix->concat(sHelperMatrix);
		currentObject = currentObject->getParent();
	}
	sTargetMatrix->invert();
	return sTargetMatrix->transformPoint(globalPoint);
}
 
void AsDisplayObject::render(const AsRenderSupport_ref& support, float alpha)
{
	throw AS_NEW(AsAbstractMethodError,(ASL("Method needs to be implemented in subclass")));
}
 
void AsDisplayObject::dispatchEvent(const AsEvent_ref& event)
{
	if(AS_IS(event, TouchEvent))
	{
		AsTouchEvent_ref touchEvent = ((AS_IS(event, TouchEvent)) ? ((AsTouchEvent_ref)(event)) : AS_NULL);
		if((touchEvent->getTimestamp() == mLastTouchTimestamp))
		{
			return;
		}
		else
		{
			mLastTouchTimestamp = touchEvent->getTimestamp();
		}
	}
	AsEventDispatcher::dispatchEvent(event);
}
 
void AsDisplayObject::setParent(const AsDisplayObjectContainer_ref& value)
{
	mParent = value;
}
 
void AsDisplayObject::dispatchEventOnChildren(const AsEvent_ref& event)
{
	dispatchEvent(event);
}
 
float AsDisplayObject::getWidth()
{
	return getBounds(mParent, sHelperRect)->width;
}
 
void AsDisplayObject::setWidth(float value)
{
	mScaleX = 1.0f;
	float actualWidth = getWidth();
	if((actualWidth != 0.0f))
	{
		setScaleX((value / actualWidth));
	}
	else
	{
		setScaleX(1.0f);
	}
}
 
float AsDisplayObject::getHeight()
{
	return getBounds(mParent, sHelperRect)->height;
}
 
void AsDisplayObject::setHeight(float value)
{
	mScaleY = 1.0f;
	float actualHeight = getHeight();
	if((actualHeight != 0.0f))
	{
		setScaleY((value / actualHeight));
	}
	else
	{
		setScaleY(1.0f);
	}
}
 
AsDisplayObject_ref AsDisplayObject::getRoot()
{
	AsDisplayObject_ref currentObject = this;
	while(currentObject->getParent() != AS_NULL)
	{
		currentObject = currentObject->getParent();
	}
	return currentObject;
}
 
float AsDisplayObject::getX()
{
	return mX;
}
 
void AsDisplayObject::setX(float value)
{
	mX = value;
}
 
float AsDisplayObject::getY()
{
	return mY;
}
 
void AsDisplayObject::setY(float value)
{
	mY = value;
}
 
float AsDisplayObject::getPivotX()
{
	return mPivotX;
}
 
void AsDisplayObject::setPivotX(float value)
{
	mPivotX = value;
}
 
float AsDisplayObject::getPivotY()
{
	return mPivotY;
}
 
void AsDisplayObject::setPivotY(float value)
{
	mPivotY = value;
}
 
float AsDisplayObject::getScaleX()
{
	return mScaleX;
}
 
void AsDisplayObject::setScaleX(float value)
{
	mScaleX = value;
}
 
float AsDisplayObject::getScaleY()
{
	return mScaleY;
}
 
void AsDisplayObject::setScaleY(float value)
{
	mScaleY = value;
}
 
float AsDisplayObject::getRotation()
{
	return mRotation;
}
 
void AsDisplayObject::setRotation(float value)
{
	while((value < -180))
	{
		value = (value + 360);
	}
	while((value > 180))
	{
		value = (value - 360);
	}
	mRotation = value;
}
 
float AsDisplayObject::getAlpha()
{
	return mAlpha;
}
 
void AsDisplayObject::setAlpha(float value)
{
	mAlpha = (((value < 0.0f)) ? (0.0f) : ((((value > 1.0f)) ? (1.0f) : (value))));
}
 
bool AsDisplayObject::getVisible()
{
	return mVisible;
}
 
void AsDisplayObject::setVisible(bool value)
{
	mVisible = value;
}
 
bool AsDisplayObject::getTouchable()
{
	return mTouchable;
}
 
void AsDisplayObject::setTouchable(bool value)
{
	mTouchable = value;
}
 
AsString_ref AsDisplayObject::getName()
{
	return mName;
}
 
void AsDisplayObject::setName(const AsString_ref& value)
{
	mName = value;
}
 
AsDisplayObjectContainer_ref AsDisplayObject::getParent()
{
	return mParent;
}
 
AsStage_ref AsDisplayObject::getStage()
{
	return AsStage::getInstance();
}
 
AsTransform_ref AsDisplayObject::getTransform()
{
	return mTransform;
}
 
void AsDisplayObject::setTransform(const AsTransform_ref& value)
{
	mTransform = value;
}
 
AsRectangle_ref AsDisplayObject::getScrollRect()
{
	return mScrollRect;
}
 
void AsDisplayObject::setScrollRect(const AsRectangle_ref& value)
{
	mScrollRect = value;
}
 
uint AsDisplayObject::getOpaqueBackground()
{
	return (uint)(0xffffffff);
}
 
void AsDisplayObject::setOpaqueBackground(uint value)
{
}
 
AsDisplayObject_ref AsDisplayObject::_as_create_AsDisplayObject()
{
	AsDisplayObject_ref __instance = new AsDisplayObject();
	__instance->_as_construct_AsDisplayObject();
	return __instance;
}
 
void AsDisplayObject::_as_construct_AsDisplayObject()
{
	_as_construct_AsEventDispatcher();
	if((AsGlobal::getQualifiedClassName(this) == ASL("starling.display::DisplayObject")))
	{
		throw AS_NEW(AsAbstractClassError,());
	}
	mX = mY = mPivotX = mPivotY = mRotation = 0.0f;
	mScaleX = mScaleY = mAlpha = 1.0f;
	mVisible = mTouchable = true;
	mLastTouchTimestamp = -1;
	mTransform = AS_NEW(AsTransform,(this));
}
 
bool AsDisplayObject::_as_static_initialized_AsDisplayObject = false;
AsStaticRefInitializer AsDisplayObject::_as_static_initializer_AsDisplayObject(_as_static_init_AsDisplayObject);
void AsDisplayObject::_as_static_init_AsDisplayObject()
{
	if (!_as_static_initialized_AsDisplayObject)
	{
		_as_static_initialized_AsDisplayObject = true;
		_as_static_init_AsEventDispatcher();
		
		AsRectangle::_as_static_init_AsRectangle();
		AsMatrix::_as_static_init_AsMatrix();
		AsTransform::_as_static_init_AsTransform();
		AsTouchEvent::_as_static_init_AsTouchEvent();
		
		sAncestors = AS_NEW_VECTOR(AsDisplayObject,());
		sHelperRect = AS_NEW(AsRectangle,());
		sHelperMatrix = AS_NEW(AsMatrix,());
		sTargetMatrix = AS_NEW(AsMatrix,());
	}
}
 
void AsDisplayObject::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsEventDispatcher::_as_gc_mark();
		AS_GC_MARK(mName)
		AS_GC_MARK(mParent)
		AS_GC_MARK(mScrollRect)
		AS_GC_MARK(mTransform)
	}
}
 
AsDisplayObject::AsDisplayObject() : 
  mPivotX(0),
  mPivotY(0),
  mX(0),
  mY(0),
  mScaleX(0),
  mScaleY(0),
  mRotation(0),
  mAlpha(0),
  mVisible(0),
  mTouchable(0),
  mName(false),
  mLastTouchTimestamp(0),
  mParent(false),
  mScrollRect(false),
  mTransform(false)
{
}
