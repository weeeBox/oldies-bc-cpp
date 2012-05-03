#include "AsObjectRef.h"
#include "AsObject.h"

#include "AsDebug.h"

AsObjectRefBase* AsObjectRefBase::m_refHead = 0;
AsObjectRefBase* AsObjectRefBase::m_refHeadStatic = 0;

GcTime AsObjectRefBase::m_gcGlobalTime = 0;

#ifndef AS_NO_DEBUG
int AsObjectRefBase::m_refsCount = 0;
int AsObjectRefBase::m_staticRefsCount = 0;
int AsObjectRefBase::m_autoRefsCount = 0;
#endif // AS_NO_DEBUG

AsObjectRefBase::AsObjectRefBase() :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_state(MASK_AUTO)
{
    AS_DEBUG(++m_autoRefsCount);
}

AsObjectRefBase::AsObjectRefBase(const AsObjectRefBase& other) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_state(MASK_AUTO)
{
    set(other.m_object); 
    AS_DEBUG(++m_autoRefsCount);
}

AsObjectRefBase::AsObjectRefBase(AsObject* obj) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_state(MASK_AUTO)
{
    set(obj);
    AS_DEBUG(++m_autoRefsCount);
}

AsObjectRefBase::AsObjectRefBase(bool staticFlag) :
  m_object(0),
  m_prev(0),
  m_next(0),
  m_state(staticFlag ? MASK_STATIC : MASK_MEMBER)
{
    reg();

#ifndef AS_NO_DEBUG
    if (staticFlag) ++m_staticRefsCount;
    else ++m_refsCount;
#endif // AS_NO_DEBUG
}

AsObjectRefBase::~AsObjectRefBase()
{
    set(0);
    unreg();

#ifndef AS_NO_DEBUG
    if (m_state == MASK_AUTO) --m_autoRefsCount;
    else if (m_state == MASK_MEMBER) --m_refsCount;
    else if (m_state == MASK_STATIC) --m_staticRefsCount;    
#endif // AS_NO_DEBUG
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
    if (isMember())
    {
        addToList(&m_refHead);        
    }
    else if (isStatic())
    {
        addToList(&m_refHeadStatic);        
    }
    else
    {
        ASSERT(false);
    }
}

void AsObjectRefBase::unreg()
{
    if (isInList())
    {    
        if (isMember())
        {
            removeFromList(&m_refHead);        
        }
        else if (isStatic())
        {
            removeFromList(&m_refHeadStatic);        
        }
        else
        {
            ASSERT(false);
        }
    }
}

void AsObjectRefBase::addToList(AsObjectRefBase **listHead)
{    
    ASSERT(!isInList());
    markInList();

    if (*listHead) (*listHead)->m_prev = this;    

    m_prev = NULL;
    m_next = *listHead;
    
    *listHead = this;
}

void AsObjectRefBase::removeFromList(AsObjectRefBase **listHead)
{
    ASSERT(isInList());
    markNotInList();

    if (m_prev) m_prev->m_next = m_next;
    else *listHead = m_next;

    if (m_next) m_next->m_prev = m_prev;    
}

void AsObjectRefBase::gc()
{
    // inc gc time    
    m_gcGlobalTime = m_gcGlobalTime == kAsGcGlobalTimeMax ? 1 : (m_gcGlobalTime + 1);

    // mark	all statics    
    for (AsObjectRefBase* ref = m_refHeadStatic; ref; ref = ref->m_next)
    {       
        AsObject* obj = ref->m_object;
        if (obj) obj->_as_gc_mark();
    }

    // sweep unmarked statics
    for (AsObjectRefBase* ref = m_refHeadStatic; ref;)
    {
        AsObject* obj = ref->m_object;
        if (obj && obj->_as_gc_mark_needed())
        {            
            AsObjectRefBase* prev = ref->m_prev;

            ref->unreg();
            ref->set(0);			

            if (prev) ref = prev->m_prev;
            else ref = m_refHeadStatic;
        }
        else
        {
            ref = ref->m_next;
        }
    }

    // sweep unmarked non-statics    
    for (AsObjectRefBase* ref = m_refHead; ref;)
    {
        AsObject* obj = ref->m_object;
        if (obj && obj->_as_gc_mark_needed())
        {            
            AsObjectRefBase* prev = ref->m_prev;

            ref->unreg();
            ref->set(0);			

            if (prev) ref = prev->m_prev;
            else ref = m_refHead;
        }
        else
        {
            ref = ref->m_next;
        }
    }
}