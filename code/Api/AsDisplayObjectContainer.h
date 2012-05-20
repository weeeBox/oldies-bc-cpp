#ifndef AsDisplayObjectContainer_h__
#define AsDisplayObjectContainer_h__
 
#include "AsBc.h"
 
#include "AsInteractiveObject.h"
 
#include "AsVector.h"
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
#ifndef AsMatrix_h__
#include "AsMatrix.h"
#else
AS_CLASS(AsMatrix);
#endif // AsMatrix_h__
 
#ifndef AsPoint_h__
#include "AsPoint.h"
#else
AS_CLASS(AsPoint);
#endif // AsPoint_h__
#include "AsString.h"
 
#ifndef AsRectangle_h__
#include "AsRectangle.h"
#else
AS_CLASS(AsRectangle);
#endif // AsRectangle_h__
 
#ifndef AsRenderSupport_h__
#include "AsRenderSupport.h"
#else
AS_CLASS(AsRenderSupport);
#endif // AsRenderSupport_h__
 
#ifndef AsEvent_h__
#include "AsEvent.h"
#else
AS_CLASS(AsEvent);
#endif // AsEvent_h__
 
AS_VECTOR_REF(AsDisplayObject);
 
AS_CLASS(AsDisplayObjectContainer);
 
class AsDisplayObjectContainer : public AsInteractiveObject
{
public:
	AS_OBJ(AsDisplayObjectContainer, AsInteractiveObject);
	
private:
	_V_AsDisplayObject_ref mChildren;
	static AsMatrix_ref sHelperMatrix;
	static AsPoint_ref sHelperPoint;
	
public:
	virtual void dispose();
	virtual void addChild(const AsDisplayObject_ref& child);
	virtual void addChildAt(const AsDisplayObject_ref& child, int index);
	virtual void removeChild(const AsDisplayObject_ref& child, bool dispose);
	virtual void removeChild(const AsDisplayObject_ref& child);
	virtual void removeChildAt(int index, bool dispose);
	virtual void removeChildAt(int index);
	virtual void removeChildren(int beginIndex, int endIndex, bool dispose);
	virtual void removeChildren(int beginIndex, int endIndex);
	virtual void removeChildren(int beginIndex);
	virtual void removeChildren();
	virtual AsDisplayObject_ref getChildAt(int index);
	virtual AsDisplayObject_ref getChildByName(const AsString_ref& name);
	virtual int getChildIndex(const AsDisplayObject_ref& child);
	virtual void setChildIndex(const AsDisplayObject_ref& child, int index);
	virtual void swapChildren(const AsDisplayObject_ref& child1, const AsDisplayObject_ref& child2);
	virtual void swapChildrenAt(int index1, int index2);
	virtual bool contains(const AsDisplayObject_ref& child);
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect);
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint, bool forTouch);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint);
	virtual void render(const AsRenderSupport_ref& support, float alpha);
	virtual void broadcastEvent(const AsEvent_ref& event);
	virtual void dispatchEventOnChildren(const AsEvent_ref& event);
	
private:
	virtual void getChildEventListeners(const AsDisplayObject_ref& object, const AsString_ref& eventType, const _V_AsDisplayObject_ref& listeners);
	
public:
	virtual int getNumChildren();
	
	
public:
	static AsDisplayObjectContainer_ref _as_create_AsDisplayObjectContainer();
	
protected:
	void _as_construct_AsDisplayObjectContainer();
	
public:
	static void _as_static_init_AsDisplayObjectContainer();
	
private:
	static bool _as_static_initialized_AsDisplayObjectContainer;
	static AsStaticRefInitializer _as_static_initializer_AsDisplayObjectContainer;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsDisplayObjectContainer();
};
 
#endif // AsDisplayObjectContainer_h__
