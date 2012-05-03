#include "AsObjectRef.h"
#include "AsObject.h"

AsObjectRefBase* AsObjectRefBase::m_refHead = 0;
AsObjectRefBase* AsObjectRefBase::m_refHeadStatic = 0;

GcTime AsObjectRefBase::m_gcGlobalTime = 0;

AsObjectRefBase::AsObjectRefBase() :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_type(TYPE_UNREGISTERED)
{    
}

AsObjectRefBase::AsObjectRefBase(const AsObjectRefBase& other) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_type(TYPE_UNREGISTERED)
{
    set(other.m_object); 
}

AsObjectRefBase::AsObjectRefBase(AsObject* obj) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_type(TYPE_UNREGISTERED)
{
    set(obj);    
}

AsObjectRefBase::AsObjectRefBase(bool isStatic) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_type(isStatic ? TYPE_STATIC : TYPE_UNREGISTERED)
{
    reg();
}

AsObjectRefBase::~AsObjectRefBase()
{
    set(0);
    unreg();
}

void AsObjectRefBase::set(AsObject* obj)
{
    AsObject* prevObj = m_object;
    m_object = obj;

    if (obj) obj->retain();
    if (prevObj) prevObj->release();
}

void AsObjectRefBase::set(const AsObjectRefBase& other)
{
    set(other.m_object);
}

void AsObjectRefBase::reg()
{    
    if (m_type == TYPE_MEMBER)
    {
        addToList(&m_refHead);
    }
    else if (m_type == TYPE_STATIC)
    {
        addToList(&m_refHeadStatic);
    }
}

void AsObjectRefBase::unreg()
{
    if (m_type == TYPE_MEMBER)
    {
        removeFromList(&m_refHead);
    }
    else if (m_type == TYPE_STATIC)
    {
        removeFromList(&m_refHeadStatic);
    }    
}

void AsObjectRefBase::addToList(AsObjectRefBase **listHead)
{    
    if (*listHead) (*listHead)->m_next = this;
    m_prev = *listHead;
    *listHead = this;
}

void AsObjectRefBase::removeFromList(AsObjectRefBase **listHead)
{
    if (m_prev) m_prev->m_next = m_next;
    else *listHead = m_next;

    if (m_next) m_next->m_prev = m_prev;
}

void AsObjectRefBase::gc()
{
    // inc gc time    
    m_gcGlobalTime = m_gcGlobalTime == kAsGcGlobalTimeMax ? 1 : (m_gcGlobalTime + 1);

    // mark	all statics
    mark(m_refHeadStatic);

    // sweep unmarked statics
    sweep(m_refHeadStatic);

    // sweep unmarked non-statics
    sweep(m_refHead);   
}

void AsObjectRefBase::mark(AsObjectRefBase *refHead)
{
    for (AsObjectRefBase* ref = refHead; ref; ref = ref->m_next)
    {       
        AsObject* obj = ref->m_object;
        if (obj) obj->_as_gc_mark();
    }
}

void AsObjectRefBase::sweep(AsObjectRefBase *refHead)
{
    for (AsObjectRefBase* ref = refHead; ref;)
    {
        AsObject* obj = ref->m_object;
        if (obj && obj->_as_gc_mark_needed())
        {
            AsObjectRefBase* prev = ref->m_prev;

            ref->unreg();
            ref->set(0);

            if (prev) ref = prev->m_next;
            else ref = refHead;
        }
        else
        {
            ref = ref->m_next;
        }
    }
}