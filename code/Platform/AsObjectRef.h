#ifndef AsObjectRef_h__
#define AsObjectRef_h__

#include "AsBc.h"

class AsObject;

typedef unsigned short GcTime;

class AsObjectRefBase
{
public:
    AsObjectRefBase();
    AsObjectRefBase(const AsObjectRefBase& other);
    AsObjectRefBase(AsObject* obj);
    explicit AsObjectRefBase(bool isStatic);
    virtual ~AsObjectRefBase();

public:
    inline AsObjectRefBase& operator= (const AsObjectRefBase& other) { set(other.m_object); return *this; }

    inline bool operator== (const AsObjectRefBase& other) const { return m_object == other.m_object; }
    inline bool operator!= (const AsObjectRefBase& other) const { return m_object != other.m_object; }

protected:
    AsObject* m_object;
    void set(AsObject* obj);
    void set(const AsObjectRefBase& other);

private:
    enum { TYPE_UNREGISTERED, TYPE_MEMBER, TYPE_STATIC };
    char m_type;

    AsObjectRefBase* m_prev;
    AsObjectRefBase* m_next;

    static AsObjectRefBase* m_refHead;
    static AsObjectRefBase* m_refHeadStatic;

#ifndef AS_NO_DEBUG
    static int m_refsCount;
    static int m_staticRefsCount;
    static int m_unregRefsCount;
#endif // AS_NO_DEBUG
    
    void reg();
    void unreg();

    void addToList(AsObjectRefBase **listHead);
    void removeFromList(AsObjectRefBase **listHead);
    
private:
    static const GcTime kAsGcGlobalTimeMax = 32767;
    static GcTime m_gcGlobalTime;

public:
    static void gc();
    inline static GcTime gcGlobalTime() { return m_gcGlobalTime; }

#ifndef AS_NO_DEBUG
    inline static int _as_refsCount() { return m_refsCount; }
    inline static int _as_staticRefsCount() { return m_staticRefsCount; }
    inline static int _as_unregRefsCount() { return m_unregRefsCount; }
    inline static int _as_totalRefsCount() { return _as_refsCount() + _as_staticRefsCount() + _as_unregRefsCount(); }
#endif // AS_NO_DEBUG
};

template <class T>
class AsObjectRef : public AsObjectRefBase
{
public:
    AsObjectRef() : AsObjectRefBase() {}
    AsObjectRef(const AsObjectRefBase& other) : AsObjectRefBase(other) {}
    AsObjectRef(T* obj) : AsObjectRefBase(obj) {}
    explicit AsObjectRef(bool isStatic) : AsObjectRefBase(isStatic) {}

public:
    inline T* operator->() const { ASSERT(m_object); return (T*)m_object; }
    inline T* operator*() const { ASSERT(m_object); return (T*)m_object; }
    inline AsObjectRef& operator= (const AsObjectRef& other) { set(other.m_object); return *this; }

protected:
    inline T* _object() { return (T*)m_object; }
};

#endif // AsObjectRef_h__