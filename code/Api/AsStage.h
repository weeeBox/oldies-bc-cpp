#ifndef AsStage_h__
#define AsStage_h__
 
#include "AsBc.h"
 
#include "AsDisplayObjectContainer.h"
 
#include "AsString.h"
 
#ifndef AsRectangle_h__
#include "AsRectangle.h"
#else
AS_CLASS(AsRectangle);
#endif // AsRectangle_h__
 
#ifndef AsStage_h__
#include "AsStage.h"
#else
AS_CLASS(AsStage);
#endif // AsStage_h__
 
#ifndef AsDisplayObject_h__
#include "AsDisplayObject.h"
#else
AS_CLASS(AsDisplayObject);
#endif // AsDisplayObject_h__
 
#ifndef AsPoint_h__
#include "AsPoint.h"
#else
AS_CLASS(AsPoint);
#endif // AsPoint_h__
 
 
AS_CLASS(AsStage);
 
class AsStage : public AsDisplayObjectContainer
{
public:
	AS_OBJ(AsStage, AsDisplayObjectContainer);
	
private:
	int mWidth;
	int mHeight;
	uint mColor;
	AsString_ref mStageQuality;
	float mFrameRate;
	AsString_ref mAlign;
	AsString_ref mScaleMode;
	AsRectangle_ref mFullScreenSourceRect;
	bool mStageFocusRect;
	bool mTabChildren;
	static AsStage_ref mCurrentStage;
	
public:
	static AsStage_ref getInstance();
	virtual void tick(float dt);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint, bool forTouch);
	virtual AsDisplayObject_ref hitTest(const AsPoint_ref& localPoint);
	virtual void setWidth(float value);
	virtual void setHeight(float value);
	virtual void setX(float value);
	virtual void setY(float value);
	virtual void setScaleX(float value);
	virtual void setScaleY(float value);
	virtual void setRotation(float value);
	virtual uint getColor();
	virtual void setColor(uint value);
	virtual int getStageWidth();
	virtual void setStageWidth(int value);
	virtual int getStageHeight();
	virtual void setStageHeight(int value);
	virtual AsString_ref getQuality();
	virtual void setQuality(const AsString_ref& value);
	virtual float getFrameRate();
	virtual void setFrameRate(float value);
	virtual AsString_ref getAlign();
	virtual void setAlign(const AsString_ref& value);
	virtual AsString_ref getScaleMode();
	virtual void setScaleMode(const AsString_ref& value);
	virtual AsRectangle_ref getFullScreenSourceRect();
	virtual void setFullScreenSourceRect(const AsRectangle_ref& value);
	virtual bool getStageFocusRect();
	virtual void setStageFocusRect(bool on);
	virtual bool getTabChildren();
	virtual void setTabChildren(bool value);
	virtual void keyPressed(uint code);
	virtual void keyReleased(uint code);
	virtual void touchDown(float x, float y, int touchId);
	virtual void touchMove(float x, float y, int touchId);
	virtual void touchDragged(float x, float y, int touchId);
	virtual void touchUp(float x, float y, int touchId);
	
	
public:
	static AsStage_ref _as_create_AsStage(int width, int height, uint color);
	static AsStage_ref _as_create_AsStage(int width, int height);
	
protected:
	void _as_construct_AsStage(int width, int height, uint color);
	void _as_construct_AsStage(int width, int height);
	
public:
	static void _as_static_init_AsStage();
	
private:
	static bool _as_static_initialized_AsStage;
	static AsStaticRefInitializer _as_static_initializer_AsStage;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsStage();
};
 
#endif // AsStage_h__
