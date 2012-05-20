#include "AsEvent.h"
#include "AsString.h"
#include "AsEventDispatcher.h"
 
AsString_ref AsEvent::ACTIVATE(true);
AsString_ref AsEvent::CANCEL(true);
AsString_ref AsEvent::CHANGE(true);
AsString_ref AsEvent::CLEAR(true);
AsString_ref AsEvent::CLOSE(true);
AsString_ref AsEvent::CONNECT(true);
AsString_ref AsEvent::COPY(true);
AsString_ref AsEvent::CUT(true);
AsString_ref AsEvent::DEACTIVATE(true);
AsString_ref AsEvent::FRAME_CONSTRUCTED(true);
AsString_ref AsEvent::EXIT_FRAME(true);
AsString_ref AsEvent::ID3(true);
AsString_ref AsEvent::INIT(true);
AsString_ref AsEvent::MOUSE_LEAVE(true);
AsString_ref AsEvent::OPEN(true);
AsString_ref AsEvent::PASTE(true);
AsString_ref AsEvent::RENDER(true);
AsString_ref AsEvent::SCROLL(true);
AsString_ref AsEvent::TEXT_INTERACTION_MODE_CHANGE(true);
AsString_ref AsEvent::SELECT(true);
AsString_ref AsEvent::SELECT_ALL(true);
AsString_ref AsEvent::SOUND_COMPLETE(true);
AsString_ref AsEvent::TAB_CHILDREN_CHANGE(true);
AsString_ref AsEvent::TAB_ENABLED_CHANGE(true);
AsString_ref AsEvent::TAB_INDEX_CHANGE(true);
AsString_ref AsEvent::UNLOAD(true);
AsString_ref AsEvent::FULLSCREEN(true);
AsString_ref AsEvent::ADDED(true);
AsString_ref AsEvent::ADDED_TO_STAGE(true);
AsString_ref AsEvent::ENTER_FRAME(true);
AsString_ref AsEvent::REMOVED(true);
AsString_ref AsEvent::REMOVED_FROM_STAGE(true);
AsString_ref AsEvent::TRIGGERED(true);
AsString_ref AsEvent::MOVIE_COMPLETED(true);
AsString_ref AsEvent::FLATTEN(true);
AsString_ref AsEvent::RESIZE(true);
AsString_ref AsEvent::COMPLETE(true);
AsString_ref AsEvent::CONTEXT3D_CREATE(true);
 
void AsEvent::stopPropagation()
{
	mStopsPropagation = true;
}
 
void AsEvent::stopImmediatePropagation()
{
	mStopsPropagation = mStopsImmediatePropagation = true;
}
 
AsString_ref AsEvent::toString()
{
	return (ASL("Event ") + mType);
}
 
void AsEvent::setTarget(const AsEventDispatcher_ref& target)
{
	mTarget = target;
}
 
void AsEvent::setCurrentTarget(const AsEventDispatcher_ref& currentTarget)
{
	mCurrentTarget = currentTarget;
}
 
bool AsEvent::getStopsPropagation()
{
	return mStopsPropagation;
}
 
bool AsEvent::getStopsImmediatePropagation()
{
	return mStopsImmediatePropagation;
}
 
bool AsEvent::getBubbles()
{
	return mBubbles;
}
 
AsEventDispatcher_ref AsEvent::getTarget()
{
	return mTarget;
}
 
AsEventDispatcher_ref AsEvent::getCurrentTarget()
{
	return mCurrentTarget;
}
 
AsString_ref AsEvent::getType()
{
	return mType;
}
 
AsEvent_ref AsEvent::_as_create_AsEvent(const AsString_ref& type, bool bubbles)
{
	AsEvent_ref __instance = new AsEvent();
	__instance->_as_construct_AsEvent(type, bubbles);
	return __instance;
}
 
AsEvent_ref AsEvent::_as_create_AsEvent(const AsString_ref& type)
{
	AsEvent_ref __instance = new AsEvent();
	__instance->_as_construct_AsEvent(type);
	return __instance;
}
 
void AsEvent::_as_construct_AsEvent(const AsString_ref& type, bool bubbles)
{
	mType = type;
	mBubbles = bubbles;
}
 
inline void AsEvent::_as_construct_AsEvent(const AsString_ref& type)
{
	_as_construct_AsEvent(type, false);
}
 
bool AsEvent::_as_static_initialized_AsEvent = false;
AsStaticRefInitializer AsEvent::_as_static_initializer_AsEvent(_as_static_init_AsEvent);
void AsEvent::_as_static_init_AsEvent()
{
	if (!_as_static_initialized_AsEvent)
	{
		_as_static_initialized_AsEvent = true;
		
		ACTIVATE = ASL("activate");
		CANCEL = ASL("cancel");
		CHANGE = ASL("change");
		CLEAR = ASL("clear");
		CLOSE = ASL("close");
		CONNECT = ASL("connect");
		COPY = ASL("copy");
		CUT = ASL("cut");
		DEACTIVATE = ASL("deactivate");
		FRAME_CONSTRUCTED = ASL("frameConstructed");
		EXIT_FRAME = ASL("exitFrame");
		ID3 = ASL("id3");
		INIT = ASL("init");
		MOUSE_LEAVE = ASL("mouseLeave");
		OPEN = ASL("open");
		PASTE = ASL("paste");
		RENDER = ASL("render");
		SCROLL = ASL("scroll");
		TEXT_INTERACTION_MODE_CHANGE = ASL("textInteractionModeChange");
		SELECT = ASL("select");
		SELECT_ALL = ASL("selectAll");
		SOUND_COMPLETE = ASL("soundComplete");
		TAB_CHILDREN_CHANGE = ASL("tabChildrenChange");
		TAB_ENABLED_CHANGE = ASL("tabEnabledChange");
		TAB_INDEX_CHANGE = ASL("tabIndexChange");
		UNLOAD = ASL("unload");
		FULLSCREEN = ASL("fullScreen");
		ADDED = ASL("added");
		ADDED_TO_STAGE = ASL("addedToStage");
		ENTER_FRAME = ASL("enterFrame");
		REMOVED = ASL("removed");
		REMOVED_FROM_STAGE = ASL("removedFromStage");
		TRIGGERED = ASL("triggered");
		MOVIE_COMPLETED = ASL("movieCompleted");
		FLATTEN = ASL("flatten");
		RESIZE = ASL("resize");
		COMPLETE = ASL("complete");
		CONTEXT3D_CREATE = ASL("context3DCreate");
	}
}
 
void AsEvent::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mTarget)
		AS_GC_MARK(mCurrentTarget)
		AS_GC_MARK(mType)
	}
}
 
AsEvent::AsEvent() : 
  mTarget(false),
  mCurrentTarget(false),
  mType(false),
  mBubbles(0),
  mStopsPropagation(0),
  mStopsImmediatePropagation(0)
{
}
