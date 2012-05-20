#ifndef AsEvent_h__
#define AsEvent_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
#ifndef AsEventDispatcher_h__
#include "AsEventDispatcher.h"
#else
AS_CLASS(AsEventDispatcher);
#endif // AsEventDispatcher_h__
 
 
AS_CLASS(AsEvent);
 
class AsEvent : public AsObject
{
public:
	AS_OBJ(AsEvent, AsObject);
	
public:
	static AsString_ref ACTIVATE;
	static AsString_ref CANCEL;
	static AsString_ref CHANGE;
	static AsString_ref CLEAR;
	static AsString_ref CLOSE;
	static AsString_ref CONNECT;
	static AsString_ref COPY;
	static AsString_ref CUT;
	static AsString_ref DEACTIVATE;
	static AsString_ref FRAME_CONSTRUCTED;
	static AsString_ref EXIT_FRAME;
	static AsString_ref ID3;
	static AsString_ref INIT;
	static AsString_ref MOUSE_LEAVE;
	static AsString_ref OPEN;
	static AsString_ref PASTE;
	static AsString_ref RENDER;
	static AsString_ref SCROLL;
	static AsString_ref TEXT_INTERACTION_MODE_CHANGE;
	static AsString_ref SELECT;
	static AsString_ref SELECT_ALL;
	static AsString_ref SOUND_COMPLETE;
	static AsString_ref TAB_CHILDREN_CHANGE;
	static AsString_ref TAB_ENABLED_CHANGE;
	static AsString_ref TAB_INDEX_CHANGE;
	static AsString_ref UNLOAD;
	static AsString_ref FULLSCREEN;
	static AsString_ref ADDED;
	static AsString_ref ADDED_TO_STAGE;
	static AsString_ref ENTER_FRAME;
	static AsString_ref REMOVED;
	static AsString_ref REMOVED_FROM_STAGE;
	static AsString_ref TRIGGERED;
	static AsString_ref MOVIE_COMPLETED;
	static AsString_ref FLATTEN;
	static AsString_ref RESIZE;
	static AsString_ref COMPLETE;
	static AsString_ref CONTEXT3D_CREATE;
	
private:
	AsEventDispatcher_ref mTarget;
	AsEventDispatcher_ref mCurrentTarget;
	AsString_ref mType;
	bool mBubbles;
	bool mStopsPropagation;
	bool mStopsImmediatePropagation;
	
public:
	virtual void stopPropagation();
	virtual void stopImmediatePropagation();
	virtual AsString_ref toString();
	virtual void setTarget(const AsEventDispatcher_ref& target);
	virtual void setCurrentTarget(const AsEventDispatcher_ref& currentTarget);
	virtual bool getStopsPropagation();
	virtual bool getStopsImmediatePropagation();
	virtual bool getBubbles();
	virtual AsEventDispatcher_ref getTarget();
	virtual AsEventDispatcher_ref getCurrentTarget();
	virtual AsString_ref getType();
	
	
public:
	static AsEvent_ref _as_create_AsEvent(const AsString_ref& type, bool bubbles);
	static AsEvent_ref _as_create_AsEvent(const AsString_ref& type);
	
protected:
	void _as_construct_AsEvent(const AsString_ref& type, bool bubbles);
	void _as_construct_AsEvent(const AsString_ref& type);
	
public:
	static void _as_static_init_AsEvent();
	
private:
	static bool _as_static_initialized_AsEvent;
	static AsStaticRefInitializer _as_static_initializer_AsEvent;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsEvent();
};
 
#endif // AsEvent_h__
