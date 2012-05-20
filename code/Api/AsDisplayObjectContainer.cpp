#include "AsDisplayObjectContainer.h"
#include "AsDisplayObject.h"
#include "AsString.h"
#include "AsDisplayObjectContainer.h"
#include "AsRectangle.h"
#include "AsPoint.h"
#include "AsRenderSupport.h"
#include "AsEvent.h"
#include "AsVector.h"
AS_VECTOR_REF(AsDisplayObject);
#include "AsMatrix.h"
#include "AsAbstractClassError.h"
#include "AsRangeError.h"
#include "AsArgumentError.h"
#include "AsMathHelper.h"
 
AsMatrix_ref AsDisplayObjectContainer::sHelperMatrix(true);
AsPoint_ref AsDisplayObjectContainer::sHelperPoint(true);
 
void AsDisplayObjectContainer::dispose()
{
	int numChildren = (int)(mChildren->getLength());
	int i = 0;
	for (; (i < numChildren); ++i)
	{
		mChildren[i]->dispose();
	}
	AsInteractiveObject::dispose();
}
 
void AsDisplayObjectContainer::addChild(const AsDisplayObject_ref& child)
{
	addChildAt(child, getNumChildren());
}
 
void AsDisplayObjectContainer::addChildAt(const AsDisplayObject_ref& child, int index)
{
	if(((index >= 0) && (index <= getNumChildren())))
	{
		child->removeFromParent();
		mChildren->splice(index, (uint)(0), child);
		child->setParent(this);
		child->dispatchEvent(AS_NEW(AsEvent,(AsEvent::ADDED, true)));
		if(getStage() != AS_NULL)
		{
			child->dispatchEventOnChildren(AS_NEW(AsEvent,(AsEvent::ADDED_TO_STAGE)));
		}
	}
	else
	{
		throw AS_NEW(AsRangeError,(ASL("Invalid child index")));
	}
}
 
void AsDisplayObjectContainer::removeChild(const AsDisplayObject_ref& child, bool dispose)
{
	int childIndex = getChildIndex(child);
	if((childIndex != -1))
	{
		removeChildAt(childIndex, dispose);
	}
}
 
void AsDisplayObjectContainer::removeChild(const AsDisplayObject_ref& child)
{
	removeChild(child, false);
}
 
void AsDisplayObjectContainer::removeChildAt(int index, bool dispose)
{
	if(((index >= 0) && (index < getNumChildren())))
	{
		AsDisplayObject_ref child = mChildren[index];
		child->dispatchEvent(AS_NEW(AsEvent,(AsEvent::REMOVED, true)));
		if(getStage() != AS_NULL)
		{
			child->dispatchEventOnChildren(AS_NEW(AsEvent,(AsEvent::REMOVED_FROM_STAGE)));
		}
		child->setParent(AS_NULL);
		mChildren->splice(index, (uint)(1));
		if(dispose)
		{
			child->dispose();
		}
	}
	else
	{
		throw AS_NEW(AsRangeError,(ASL("Invalid child index")));
	}
}
 
void AsDisplayObjectContainer::removeChildAt(int index)
{
	removeChildAt(index, false);
}
 
void AsDisplayObjectContainer::removeChildren(int beginIndex, int endIndex, bool dispose)
{
	if(((endIndex < 0) || (endIndex >= getNumChildren())))
	{
		endIndex = (getNumChildren() - 1);
	}
	int i = beginIndex;
	for (; (i <= endIndex); ++i)
	{
		removeChildAt(beginIndex, dispose);
	}
}
 
void AsDisplayObjectContainer::removeChildren(int beginIndex, int endIndex)
{
	removeChildren(beginIndex, endIndex, false);
}
 
void AsDisplayObjectContainer::removeChildren(int beginIndex)
{
	removeChildren(beginIndex, -1, false);
}
 
void AsDisplayObjectContainer::removeChildren()
{
	removeChildren(0, -1, false);
}
 
AsDisplayObject_ref AsDisplayObjectContainer::getChildAt(int index)
{
	if(((index >= 0) && (index < getNumChildren())))
	{
		return mChildren[index];
	}
	else
	{
		throw AS_NEW(AsRangeError,(ASL("Invalid child index")));
	}
}
 
AsDisplayObject_ref AsDisplayObjectContainer::getChildByName(const AsString_ref& name)
{
	int numChildren = (int)(mChildren->getLength());
	int i = 0;
	for (; (i < numChildren); ++i)
	{
		if((mChildren[i]->getName() == name))
		{
			return mChildren[i];
		}
	}
	return AS_NULL;
}
 
int AsDisplayObjectContainer::getChildIndex(const AsDisplayObject_ref& child)
{
	return mChildren->indexOf(child);
}
 
void AsDisplayObjectContainer::setChildIndex(const AsDisplayObject_ref& child, int index)
{
	int oldIndex = getChildIndex(child);
	if((oldIndex == -1))
	{
		throw AS_NEW(AsArgumentError,(ASL("Not a child of this container")));
	}
	mChildren->splice(oldIndex, (uint)(1));
	mChildren->splice(index, (uint)(0), child);
}
 
void AsDisplayObjectContainer::swapChildren(const AsDisplayObject_ref& child1, const AsDisplayObject_ref& child2)
{
	int index1 = getChildIndex(child1);
	int index2 = getChildIndex(child2);
	if(((index1 == -1) || (index2 == -1)))
	{
		throw AS_NEW(AsArgumentError,(ASL("Not a child of this container")));
	}
	swapChildrenAt(index1, index2);
}
 
void AsDisplayObjectContainer::swapChildrenAt(int index1, int index2)
{
	AsDisplayObject_ref child1 = getChildAt(index1);
	AsDisplayObject_ref child2 = getChildAt(index2);
	mChildren[index1] = child2;
	mChildren[index2] = child1;
}
 
bool AsDisplayObjectContainer::contains(const AsDisplayObject_ref& child)
{
	if((child == this))
	{
		return true;
	}
	int numChildren = (int)(mChildren->getLength());
	int i = 0;
	for (; (i < numChildren); ++i)
	{
		AsDisplayObject_ref currentChild = mChildren[i];
		AsDisplayObjectContainer_ref currentChildContainer = ((AS_IS(currentChild, DisplayObjectContainer)) ? ((AsDisplayObjectContainer_ref)(currentChild)) : AS_NULL);
		if(((currentChildContainer != AS_NULL) && currentChildContainer->contains(child)))
		{
			return true;
		}
		else
		{
			if((currentChild == child))
			{
				return true;
			}
		}
	}
	return false;
}
 
AsRectangle_ref AsDisplayObjectContainer::getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect)
{
	if((resultRect == AS_NULL))
	{
		resultRect = AS_NEW(AsRectangle,());
	}
	int numChildren = (int)(mChildren->getLength());
	if((numChildren == 0))
	{
		getTransformationMatrix(targetSpace, sHelperMatrix);
		AsGlobal::transformCoords(sHelperMatrix, 0.0f, 0.0f, sHelperPoint);
		resultRect->x = sHelperPoint->x;
		resultRect->y = sHelperPoint->y;
		resultRect->width = resultRect->height = 0;
		return resultRect;
	}
	else
	{
		if((numChildren == 1))
		{
			return mChildren[0]->getBounds(targetSpace, resultRect);
		}
		else
		{
			float minX = AsMathHelper::MAX_NUMBER;
			float maxX = -AsMathHelper::MAX_NUMBER;
			float minY = AsMathHelper::MAX_NUMBER;
			float maxY = -AsMathHelper::MAX_NUMBER;
			int i = 0;
			for (; (i < numChildren); ++i)
			{
				mChildren[i]->getBounds(targetSpace, resultRect);
				minX = (((minX < resultRect->x)) ? (minX) : (resultRect->x));
				maxX = (((maxX > resultRect->getRight())) ? (maxX) : (resultRect->getRight()));
				minY = (((minY < resultRect->y)) ? (minY) : (resultRect->y));
				maxY = (((maxY > resultRect->getBottom())) ? (maxY) : (resultRect->getBottom()));
			}
			resultRect->x = minX;
			resultRect->y = minY;
			resultRect->width = (maxX - minX);
			resultRect->height = (maxY - minY);
			return resultRect;
		}
	}
}
 
AsRectangle_ref AsDisplayObjectContainer::getBounds(const AsDisplayObject_ref& targetSpace)
{
	return getBounds(targetSpace, AS_NULL);
}
 
AsDisplayObject_ref AsDisplayObjectContainer::hitTest(const AsPoint_ref& localPoint, bool forTouch)
{
	if((forTouch && (!(getVisible()) || !(getTouchable()))))
	{
		return AS_NULL;
	}
	float localX = localPoint->x;
	float localY = localPoint->y;
	int numChildren = (int)(mChildren->getLength());
	int i = (numChildren - 1);
	for (; (i >= 0); --i)
	{
		AsDisplayObject_ref child = mChildren[i];
		getTransformationMatrix(child, sHelperMatrix);
		AsGlobal::transformCoords(sHelperMatrix, localX, localY, sHelperPoint);
		AsDisplayObject_ref target = child->hitTest(sHelperPoint, forTouch);
		if(target != AS_NULL)
		{
			return target;
		}
	}
	return AS_NULL;
}
 
AsDisplayObject_ref AsDisplayObjectContainer::hitTest(const AsPoint_ref& localPoint)
{
	return hitTest(localPoint, false);
}
 
void AsDisplayObjectContainer::render(const AsRenderSupport_ref& support, float alpha)
{
	alpha = (alpha * this->getAlpha());
	int numChildren = (int)(mChildren->getLength());
	int i = 0;
	for (; (i < numChildren); ++i)
	{
		AsDisplayObject_ref child = mChildren[i];
		if(((((child->getAlpha() != 0.0f) && child->getVisible()) && (child->getScaleX() != 0.0f)) && (child->getScaleY() != 0.0f)))
		{
			support->pushMatrix();
			support->transform(child->getTransform()->getMatrix());
			child->render(support, alpha);
			support->popMatrix();
		}
	}
}
 
void AsDisplayObjectContainer::broadcastEvent(const AsEvent_ref& event)
{
	if(event->getBubbles())
	{
		throw AS_NEW(AsArgumentError,(ASL("Broadcast of bubbling events is prohibited")));
	}
	dispatchEventOnChildren(event);
}
 
void AsDisplayObjectContainer::dispatchEventOnChildren(const AsEvent_ref& event)
{
	_V_AsDisplayObject_ref listeners = AS_NEW_VECTOR(AsDisplayObject,());
	getChildEventListeners(this, event->getType(), listeners);
	int numListeners = (int)(listeners->getLength());
	int i = 0;
	for (; (i < numListeners); ++i)
	{
		listeners[i]->dispatchEvent(event);
	}
}
 
void AsDisplayObjectContainer::getChildEventListeners(const AsDisplayObject_ref& object, const AsString_ref& eventType, const _V_AsDisplayObject_ref& listeners)
{
	AsDisplayObjectContainer_ref container = ((AS_IS(object, DisplayObjectContainer)) ? ((AsDisplayObjectContainer_ref)(object)) : AS_NULL);
	if(object->hasEventListener(eventType))
	{
		listeners->push(object);
	}
	if(container != AS_NULL)
	{
		_V_AsDisplayObject_ref children = container->mChildren;
		int numChildren = (int)(children->getLength());
		int i = 0;
		for (; (i < numChildren); ++i)
		{
			getChildEventListeners(children[i], eventType, listeners);
		}
	}
}
 
int AsDisplayObjectContainer::getNumChildren()
{
	return (int)(mChildren->getLength());
}
 
AsDisplayObjectContainer_ref AsDisplayObjectContainer::_as_create_AsDisplayObjectContainer()
{
	AsDisplayObjectContainer_ref __instance = new AsDisplayObjectContainer();
	__instance->_as_construct_AsDisplayObjectContainer();
	return __instance;
}
 
void AsDisplayObjectContainer::_as_construct_AsDisplayObjectContainer()
{
	_as_construct_AsInteractiveObject();
	if((AsGlobal::getQualifiedClassName(this) == ASL("DisplayObjectContainer")))
	{
		throw AS_NEW(AsAbstractClassError,());
	}
	mChildren = AS_NEW_VECTOR(AsDisplayObject,());
}
 
bool AsDisplayObjectContainer::_as_static_initialized_AsDisplayObjectContainer = false;
AsStaticRefInitializer AsDisplayObjectContainer::_as_static_initializer_AsDisplayObjectContainer(_as_static_init_AsDisplayObjectContainer);
void AsDisplayObjectContainer::_as_static_init_AsDisplayObjectContainer()
{
	if (!_as_static_initialized_AsDisplayObjectContainer)
	{
		_as_static_initialized_AsDisplayObjectContainer = true;
		_as_static_init_AsInteractiveObject();
		
		AsMatrix::_as_static_init_AsMatrix();
		AsPoint::_as_static_init_AsPoint();
		AsEvent::_as_static_init_AsEvent();
		AsDisplayObject::_as_static_init_AsDisplayObject();
		AsRectangle::_as_static_init_AsRectangle();
		
		sHelperMatrix = AS_NEW(AsMatrix,());
		sHelperPoint = AS_NEW(AsPoint,());
	}
}
 
void AsDisplayObjectContainer::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsInteractiveObject::_as_gc_mark();
		AS_GC_MARK(mChildren)
	}
}
 
AsDisplayObjectContainer::AsDisplayObjectContainer() : 
  mChildren(false)
{
}
