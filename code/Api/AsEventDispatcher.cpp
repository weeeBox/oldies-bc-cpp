#include "AsEventDispatcher.h"
#include "AsString.h"
#include "AsVector.h"
AS_VECTOR_REF(AsEventListenerCallback);
#include "AsEvent.h"
#include "AsEventDispatcher.h"
#include "AsDisplayObject.h"
#include "AsDictionary.h"
 
 
void AsEventDispatcher::addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture, int priority, bool useWeakReference)
{
	if((mEventListeners == AS_NULL))
	{
		mEventListeners = AS_NEW(AsDictionary,());
	}
	_V_AsEventListenerCallback_ref listeners = (_V_AsEventListenerCallback_ref)(mEventListeners[type]);
	if((listeners == AS_NULL))
	{
		listeners = AS_NEW_VECTOR(AsEventListenerCallback,());
		mEventListeners[type] = listeners;
	}
	listeners->push(listener);
}
 
void AsEventDispatcher::addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture, int priority)
{
	addEventListener(type, listener, useCapture, priority, false);
}
 
void AsEventDispatcher::addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture)
{
	addEventListener(type, listener, useCapture, 0, false);
}
 
void AsEventDispatcher::addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener)
{
	addEventListener(type, listener, false, 0, false);
}
 
void AsEventDispatcher::removeEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener)
{
	if(mEventListeners != AS_NULL)
	{
		_V_AsEventListenerCallback_ref listeners = (_V_AsEventListenerCallback_ref)(mEventListeners[type]);
		if(listeners != AS_NULL)
		{
			_V_AsEventListenerCallback_ref remainListeners = AS_NEW_VECTOR(AsEventListenerCallback,());
			{ _V_AsEventListenerCallback_ref __eventListeners_ = listeners; 
			if (__eventListeners_ != AS_NULL) { for(_as_AsRefVector<AsEventListenerCallback_ref>::Iterator it = (__eventListeners_)->iterator(); it.hasNext();) { AsEventListenerCallback_ref eventListener = it.next();
			{
				if((eventListener != listener))
				{
					remainListeners->push(eventListener);
				}
			}
			}}}
			if((remainListeners->getLength() > 0))
			{
				mEventListeners[type] = remainListeners;
			}
			else
			{
				mEventListeners.remove(type);
			}
		}
	}
}
 
void AsEventDispatcher::removeEventListeners(const AsString_ref& type)
{
	if(((type != AS_NULL) && (mEventListeners != AS_NULL)))
	{
		mEventListeners.remove(type);
	}
	else
	{
		mEventListeners = AS_NULL;
	}
}
 
void AsEventDispatcher::removeEventListeners()
{
	removeEventListeners(AS_NULL);
}
 
void AsEventDispatcher::dispatchEvent(const AsEvent_ref& event)
{
	_V_AsEventListenerCallback_ref listeners = (_V_AsEventListenerCallback_ref)(((mEventListeners != AS_NULL) ? (mEventListeners[event->getType()]) : (AS_NULL)));
	if(((listeners == AS_NULL) && !(event->getBubbles())))
	{
		return;
	}
	AsEventDispatcher_ref previousTarget = event->getTarget();
	if(((previousTarget == AS_NULL) || (event->getCurrentTarget() != AS_NULL)))
	{
		event->setTarget(this);
	}
	bool stopImmediatePropagation = false;
	uint numListeners = (uint)((((listeners == AS_NULL)) ? (0) : (listeners->getLength())));
	if((numListeners != 0))
	{
		event->setCurrentTarget(this);
		int i = 0;
		for (; (i < numListeners); ++i)
		{
			AsEventListenerCallback_ref listener = listeners[i];
			listener(event);
			if(event->getStopsImmediatePropagation())
			{
				stopImmediatePropagation = true;
				break;
			}
		}
	}
	if((((!(stopImmediatePropagation) && event->getBubbles()) && !(event->getStopsPropagation())) && AS_IS(this, DisplayObject)))
	{
		AsDisplayObject_ref targetDisplayObject = ((AS_IS(this, DisplayObject)) ? ((AsDisplayObject_ref)(this)) : AS_NULL);
		if((targetDisplayObject->getParent() != AS_NULL))
		{
			event->setCurrentTarget(AS_NULL);
			targetDisplayObject->getParent()->dispatchEvent(event);
		}
	}
	if(previousTarget != AS_NULL)
	{
		event->setTarget(previousTarget);
	}
}
 
bool AsEventDispatcher::hasEventListener(const AsString_ref& type)
{
	return ((mEventListeners != AS_NULL) && (mEventListeners[type] != AS_NULL));
}
 
AsEventDispatcher_ref AsEventDispatcher::_as_create_AsEventDispatcher()
{
	AsEventDispatcher_ref __instance = new AsEventDispatcher();
	__instance->_as_construct_AsEventDispatcher();
	return __instance;
}
 
void AsEventDispatcher::_as_construct_AsEventDispatcher()
{
}
 
bool AsEventDispatcher::_as_static_initialized_AsEventDispatcher = false;
AsStaticRefInitializer AsEventDispatcher::_as_static_initializer_AsEventDispatcher(_as_static_init_AsEventDispatcher);
void AsEventDispatcher::_as_static_init_AsEventDispatcher()
{
	if (!_as_static_initialized_AsEventDispatcher)
	{
		_as_static_initialized_AsEventDispatcher = true;
	}
}
 
void AsEventDispatcher::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mEventListeners)
	}
}
 
AsEventDispatcher::AsEventDispatcher() : 
  mEventListeners(false)
{
}
