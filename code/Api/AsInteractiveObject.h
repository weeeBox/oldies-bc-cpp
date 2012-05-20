#ifndef AsInteractiveObject_h__
#define AsInteractiveObject_h__
 
#include "AsBc.h"
 
#include "AsDisplayObject.h"
 
 
AS_CLASS(AsInteractiveObject);
 
class AsInteractiveObject : public AsDisplayObject
{
public:
	AS_OBJ(AsInteractiveObject, AsDisplayObject);
	
private:
	bool m_mouseEnabled;
	bool m_doubleClickEnabled;
	bool mFocusRect;
	
public:
	virtual bool getDoubleClickEnabled();
	virtual void setDoubleClickEnabled(bool enabled);
	virtual bool getFocusRect();
	virtual void setFocusRect(bool focusRect);
	virtual bool getMouseEnabled();
	virtual void setMouseEnabled(bool enabled);
	
	static void _as_static_init_AsInteractiveObject();
	
private:
	static bool _as_static_initialized_AsInteractiveObject;
	static AsStaticRefInitializer _as_static_initializer_AsInteractiveObject;
	
	
protected:
	AsInteractiveObject();
};
 
#endif // AsInteractiveObject_h__
