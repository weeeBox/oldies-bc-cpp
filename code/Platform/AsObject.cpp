#include "AsObject.h"

#include "AsString.h"
#include "AsDictionary.h"

AsStaticRefInitializer* AsStaticRefInitializer::root = NULL;

AsStaticRefInitializer::AsStaticRefInitializer(_as_static_init_func f) : func(f), next(root)
{
    root = this;
}

void AsStaticRefInitializer::init()
{
    AsStaticRefInitializer* c = root;
    while (c)
    {
        c->func();
        c = c->next;
    }
    root = NULL;
}

AsObject_ref AsObject::__as_null = AsObject_ref();

AsObject::AsObject() :
  m_refCount(0),
  m_gcTime(0),
  m_properties(false)
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
    AS_GC_MARK(m_properties);
}

void AsGlobal::trace(const AsObject& obj)
{
    
}

void AsGlobal::trace(const AsString_ref& str)
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
 
BOOL AsObject::hasOwnProperty(const AsString_ref& name)
{
	if(m_properties != AS_NULL)
	{
		return m_properties->_as_get(name) != AS_NULL;
	}
	return false;
}
 
AsObject_ref AsObject::getOwnProperty(const AsString_ref& name)
{
	if(hasOwnProperty(name))
	{
		return m_properties->_as_get(name);
	}
	return AS_NULL;
}
 
void AsObject::setOwnProperty(const AsString_ref& name, const AsObject_ref& value)
{
	if(m_properties == AS_NULL)
	{
		m_properties = AS_NEW(AsDictionary,());
	}
	m_properties->_as_put(name, value);
}
 
void AsObject::deleteOwnProperty(const AsString_ref& name)
{
	if(m_properties != AS_NULL)
	{
		m_properties->remove(name);
	}
}