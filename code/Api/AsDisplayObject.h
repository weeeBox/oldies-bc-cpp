#ifndef AsDisplayObject_h__
#define AsDisplayObject_h__
 
#include "AsBc.h"
 
#include "AsEventDispatcher.h"
#include "AsIBitmapDrawable.h"
 
#include "AsString.h"
 
#ifndef AsDisplayObjectContainer_h__
#include "AsDisplayObjectContainer.h"
#else
AS_CLASS(AsDisplayObjectContainer);
#endif // AsDisplayObjectContainer_h__
 
#ifndef AsRectangle_h__
#include "AsRectangle.h"
#else
AS_CLASS(AsRectangle);
#endif // AsRectangle_h__
 
#ifndef AsTransform_h__
#include "AsTransform.h"
#else
AS_CLASS(AsTransform);
#endif // AsTransform_h__
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
 
#ifndef AsStage_h__
#include "AsStage.h"
#else
AS_CLASS(AsStage);
#endif // AsStage_h__
 
AS_VECTOR_REF(AsDisplayObject);
 
AS_CLASS(AsDisplayObject);
 
class AsDisplayObject : public AsEventDispatcher
{
public:
	AS_OBJ(AsDisplayObject, AsEventDispatcher);
	
private:
	float mPivotX;
	float mPivotY;
	float mX;
	float mY;
	float mScaleX;
	float mScaleY;
	float mRotation;
	float mAlpha;
	bool mVisible;
	bool mTouchable;
	AsString_ref mName;
	float mLastTouchTimestamp;
	AsDisplayObjectContainer_ref mParent;
	AsRectangle_ref mScrollRect;
	AsTransform_ref mTransform;
	static _V_AsDisplayObject_ref sAncestors;
	static AsRectangle_ref sHelperRect;
	static AsMatrix_ref sHelperMatrix;
	static AsMatrix_ref sTargetMatrix;
	
public:
	virtual void dispose();
	virtual void removeFromParent(bool dispose);
	virtual void removeFromParent();
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect);
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint, bool forTouch);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint);
	virtual AsMatrix_ref getTransformationMatrix(const AsDisplayObject_ref& targetSpace, const AsMatrix_ref& resultMatrix);
	virtual AsMatrix_ref getTransformationMatrix(const AsDisplayObject_ref& targetSpace);
	virtual AsPoint_ref localToGlobal(const AsPoint_ref& localPoint);
	virtual AsPoint_ref globalToLocal(const AsPoint_ref& globalPoint);
	virtual void render(const AsRenderSupport_ref& support, float alpha);
	virtual void dispatchEvent(const AsEvent_ref& event);
	virtual void setParent(const AsDisplayObjectContainer_ref& value);
	virtual void dispatchEventOnChildren(const AsEvent_ref& event);
	virtual float getWidth();
	virtual void setWidth(float value);
	virtual float getHeight();
	virtual void setHeight(float value);
	virtual AsDisplayObject_ref getRoot();
	virtual float getX();
	virtual void setX(float value);
	virtual float getY();
	virtual void setY(float value);
	virtual float getPivotX();
	virtual void setPivotX(float value);
	virtual float getPivotY();
	virtual void setPivotY(float value);
	virtual float getScaleX();
	virtual void setScaleX(float value);
	virtual float getScaleY();
	virtual void setScaleY(float value);
	virtual float getRotation();
	virtual void setRotation(float value);
	virtual float getAlpha();
	virtual void setAlpha(float value);
	virtual bool getVisible();
	virtual void setVisible(bool value);
	virtual bool getTouchable();
	virtual void setTouchable(bool value);
	virtual AsString_ref getName();
	virtual void setName(const AsString_ref& value);
	virtual AsDisplayObjectContainer_ref getParent();
	virtual AsStage_ref getStage();
	virtual AsTransform_ref getTransform();
	virtual void setTransform(const AsTransform_ref& value);
	virtual AsRectangle_ref getScrollRect();
	virtual void setScrollRect(const AsRectangle_ref& value);
	virtual uint getOpaqueBackground();
	virtual void setOpaqueBackground(uint value);
	
	
public:
	static AsDisplayObject_ref _as_create_AsDisplayObject();
	
protected:
	void _as_construct_AsDisplayObject();
	
public:
	static void _as_static_init_AsDisplayObject();
	
private:
	static bool _as_static_initialized_AsDisplayObject;
	static AsStaticRefInitializer _as_static_initializer_AsDisplayObject;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsDisplayObject();
	
/* AsIBitmapDrawable interface wrapper */
public:
	class _as_interface_AsIBitmapDrawable : public AsIBitmapDrawable
	{
	public:
		_as_interface_AsIBitmapDrawable(AsDisplayObject *target) : m_target(target) { m_target->retain(); } 
		~_as_interface_AsIBitmapDrawable() { m_target->release(); } 
		void _as_gc_mark() { if (_as_gc_mark_needed()) { AsIBitmapDrawable::_as_gc_mark(); AS_GC_MARK(m_target); }} 
		private: AsDisplayObject *m_target; 
		friend class AsDisplayObject;
		
	public:
	};
	
	inline AsIBitmapDrawable_ref _as_box_AsIBitmapDrawable() { return new _as_interface_AsIBitmapDrawable(this); }
	inline static AsDisplayObject* _as_unbox(AsIBitmapDrawable* obj) { return ((_as_interface_AsIBitmapDrawable*)obj)->m_target; }
};
 
#endif // AsDisplayObject_h__
