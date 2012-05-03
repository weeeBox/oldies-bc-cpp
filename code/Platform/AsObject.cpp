#include "AsObject.h"
#include "AsString.h"

AsObject_ref AsObject::__as_null = AsObject_ref();

AsObject::AsObject() :
  m_refCount(0),
  m_gcTime(0)
{
}

AsObject::~AsObject()
{
    ASSERT(m_refCount == 0);
}

AsString_ref AsObject::toString()
{
    return AsString_ref(_as_typename());
}

int AsObject::hashCode()
{
    return (int)this;
}

void AsObject::retain()
{
    ++m_refCount;
}

void AsObject::release()
{
    ASSERT(m_refCount > 0);
    --m_refCount;

    if (m_refCount == 0)
    {
        delete this;
    }
}

void AsObject::_as_gc_mark()
{
    m_gcTime = AsObjectRefBase::gcGlobalTime();
}

void AsGlobal::trace(const AsObject& obj)
{

}

void AsGlobal::trace(int val)
{

}

void AsGlobal::trace(float val)
{

}

void AsGlobal::trace(bool val)
{

}

/*
#include "AsObject.h"
#include "AsDictionary.h"
#include "AsString.h"
#include "AsString.h"
#include "AsObject.h"
 
 
BOOL AsObject::hasOwnProperty(const AsString_ref& name)
{
	if((mProperties != null))
	{
		return (mProperties[name] != null);
	}
	return false;
}
 
AsObject_ref AsObject::getOwnProperty(const AsString_ref& name)
{
	if(hasOwnProperty(name))
	{
		return (AsObject)(mProperties[name]);
	}
	return null;
}
 
void AsObject::setOwnProperty(const AsString_ref& name, const AsObject_ref& _value)
{
	if((mProperties == null))
	{
		mProperties = new AsDictionary();
	}
	mProperties[name] = (AsObject)(_value);
}
 
void AsObject::deleteOwnProperty(const AsString_ref& name)
{
	if((mProperties != null))
	{
		mProperties.remove(name);
	}
}
 
AsString_ref AsObject::toString()
{
	return "Object";
}
 
void AsObject::__internalInitialiseAsObject()
{
}
 
StaticInit AsObject::__internalStaticInitializerAsObject(&AsObject::__internalStaticInit);
BOOL AsObject::__internalStaticInitializedAsObject = false;
 
void AsObject::__internalStaticInit()
{
	if (!__internalStaticInitializedAsObject)
	{
		__internalStaticInitializedAsObject = true;
		AsObject::__internalStaticInit();
	}
}
 
AsObject::AsObject() :
  mProperties(false)
{
}
 
void AsObject::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsObject::__internalGc();
		if (mProperties != __NULL) mProperties->__internalGc();
	}
}
 
 */