#ifndef AsEventDispatcher_h__
#define AsEventDispatcher_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsDictionary.h"
#include "AsString.h"
 
#ifndef AsEvent_h__
#include "AsEvent.h"
#else
AS_CLASS(AsEvent);
#endif // AsEvent_h__
 
 
#include "AsFunction.h"
class AsEventListenerCallback_ref : public AsObjectRef<AsFunction>
{
public:
	AsEventListenerCallback_ref() : AsObjectRef() {} 
	AsEventListenerCallback_ref(const AsObjectRefBase& other) : AsObjectRef(other) {} 
	AsEventListenerCallback_ref(const AsEventListenerCallback_ref& other) : AsObjectRef(other) {} 
	AsEventListenerCallback_ref(AsFunction* obj) : AsObjectRef(obj) {} 
	explicit AsEventListenerCallback_ref(bool isStatic) : AsObjectRef(isStatic) {}
	
	inline void operator() (const AsEvent_ref& event)
	{
		return object()->call<void>(event);
	}
};
 
AS_CLASS(AsEventDispatcher);
 
class AsEventDispatcher : public AsObject
{
	
public:
	AS_OBJ(AsEventDispatcher, AsObject);
	
private:
	AsDictionary_ref mEventListeners;
	
public:
	virtual void addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture, int priority, bool useWeakReference);
	virtual void addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture, int priority);
	virtual void addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener, bool useCapture);
	virtual void addEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener);
	virtual void removeEventListener(const AsString_ref& type, const AsEventListenerCallback_ref& listener);
	virtual void removeEventListeners(const AsString_ref& type);
	virtual void removeEventListeners();
	virtual void dispatchEvent(const AsEvent_ref& event);
	virtual bool hasEventListener(const AsString_ref& type);
	
	
public:
	static AsEventDispatcher_ref _as_create_AsEventDispatcher();
	
protected:
	void _as_construct_AsEventDispatcher();
	
public:
	static void _as_static_init_AsEventDispatcher();
	
private:
	static bool _as_static_initialized_AsEventDispatcher;
	static AsStaticRefInitializer _as_static_initializer_AsEventDispatcher;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsEventDispatcher();
};
 
#endif // AsEventDispatcher_h__
