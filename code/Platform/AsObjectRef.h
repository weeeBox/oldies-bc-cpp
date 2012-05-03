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
    
    void reg();
    void unreg();

    void addToList(AsObjectRefBase **listHead);
    void removeFromList(AsObjectRefBase **listHead);
    
private:
    static const GcTime kAsGcGlobalTimeMax = 32767;
    static GcTime m_gcGlobalTime;
    static void gc();
    static void mark(AsObjectRefBase *refHead);
    static void sweep(AsObjectRefBase *refHead);

public:
    inline static GcTime gcGlobalTime() { return m_gcGlobalTime; }
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
    inline AsObjectRef& operator= (const AsObjectRefBase& other) { set(other.m_object); return *this; }

protected:
    inline T* _object() { return (T*)m_object; }
};

#endif // AsObjectRef_h__