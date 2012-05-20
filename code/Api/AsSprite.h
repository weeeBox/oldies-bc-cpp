#ifndef AsSprite_h__
#define AsSprite_h__
 
#include "AsBc.h"
 
#include "AsDisplayObjectContainer.h"
 
 
#ifndef AsGraphics_h__
#include "AsGraphics.h"
#else
AS_CLASS(AsGraphics);
#endif // AsGraphics_h__
 
#ifndef AsEvent_h__
#include "AsEvent.h"
#else
AS_CLASS(AsEvent);
#endif // AsEvent_h__
 
 
AS_CLASS(AsSprite);
 
class AsSprite : public AsDisplayObjectContainer
{
public:
	AS_OBJ(AsSprite, AsDisplayObjectContainer);
	
private:
	AsGraphics_ref mGraphics;
	bool mUseHandCursor;
	bool mMouseChildren;
	
public:
	virtual void dispose();
	virtual bool getUseHandCursor();
	virtual void setUseHandCursor(bool value);
	virtual AsGraphics_ref getGraphics();
	
private:
	virtual void onTouch(const AsEvent_ref& evt);
	
public:
	virtual bool getMouseChildren();
	virtual void setMouseChildren(bool enable);
	virtual bool getTabChildren();
	virtual void setTabChildren(bool enable);
	
	
public:
	static AsSprite_ref _as_create_AsSprite();
	
protected:
	void _as_construct_AsSprite();
	
public:
	static void _as_static_init_AsSprite();
	
private:
	static bool _as_static_initialized_AsSprite;
	static AsStaticRefInitializer _as_static_initializer_AsSprite;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsSprite();
};
 
#endif // AsSprite_h__
