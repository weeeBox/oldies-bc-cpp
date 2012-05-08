#ifndef AsObject_h__
#define AsObject_h__
 
#include "AsBc.h"

#include "AsObjectRef.h"

/* null type */
#define AS_NULL AsObject::__as_null

/* string literal */
#define ASL(x) L##x

/* reference type */
#define AS_REF(type) class type##_ref

/* reference class definition */
#define AS_CLASS(type) class type; typedef AsObjectRef<type> type##_ref

/* new */
#define AS_NEW(type, initializer) type::_as_create_##type initializer

/* runtime type info */
#define AS_TYPENAME(type, base) \
    public: inline static const char* _as_typename() { return #type; } \
    protected: const char* _as_typename(int depth) { if (depth) return base::_as_typename(depth - 1); else return _as_typename(); }

/* common object code */
#define AS_OBJ(type, base) \
    AS_TYPENAME(type, base)    

/* type checking */
#define AS_INSTANCE(obj, typeName) (obj != nil && obj->__internalInstanceOf(typeName::_as_typename()))

/* gc */
#define AS_GC_MARK(x) if (x != AS_NULL) (x)->_as_gc_mark();

/* interface boxing */
#define AS_INTERFACE(type, base) \
_as_interface_##base(type *target) : m_target(target) { m_target->retain(); } \
~_as_interface_##base() { m_target->release(); } \
void _as_gc_mark() { if (_as_gc_mark_needed()) { base::_as_gc_mark(); AS_GC_MARK(m_target); }} \
private: type *m_target; \
friend class type;

#define AS_INTERFACE_REF(type) \
class type##_ref : public AsObjectRef<type> \
{ \
public: \
    type##_ref() : AsObjectRef() {} \
    template <class T> type##_ref(const AsObjectRef<T>& other) : AsObjectRef(other->_as_box_##type()) {} \
    type##_ref(const AsObjectRef<AsObject>& other) : AsObjectRef(other) {} \
    type##_ref(type* obj) : AsObjectRef(obj) {} \
    explicit type##_ref(bool isStatic) : AsObjectRef(isStatic) {} \
    template <class T> inline type##_ref operator= (const T& other) { set(other->_as_box_##type()); return *this; } \
    inline type##_ref operator= (const AsObjectRef<AsObject>& other) { set(other); return *this; } \
    inline type##_ref operator= (const type##_ref& other) { set(other); return *this; } \
    template <class T> inline operator AsObjectRef<T> () \
    { \
        type* obj = (type*)m_object; \
        return T::_as_unbox(obj); \
    } \
};

#define AS_UNBOX(type, obj) type::_as_unbox(*obj)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static init

typedef void (*_as_static_init_func)(void);

class AsStaticRefInitializer
{
public:
    AsStaticRefInitializer(_as_static_init_func func);
    static void init();

private:
    static AsStaticRefInitializer* root;
    AsStaticRefInitializer* next;
    _as_static_init_func func;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

AS_CLASS(AsObject);

class AsString_ref;

class AsObject
{
/*private:
	AsDictionary_ref mProperties;
	
public:
	virtual BOOL hasOwnProperty(const AsString_ref& name);
	virtual AsObject_ref getOwnProperty(const AsString_ref& name);
	virtual void setOwnProperty(const AsString_ref& name, const AsObject_ref& _value);
	virtual void deleteOwnProperty(const AsString_ref& name);	
*/

public:
    virtual AsString_ref toString();
    virtual int hashCode();    

public:
    AsObject();
    virtual ~AsObject();

public:
    inline static AsObject_ref _as_create_AsObject() { return AsObject_ref(new AsObject()); }
    inline static const char* _as_typename() { return "AsObject"; }

protected: 
    virtual const char* _as_typename(int depth) { return _as_typename(); }

private:
    friend class AsObjectRefBase;

    int m_refCount;    

    inline int refCount() { return m_refCount; }    

private:
    GcTime m_gcTime;

public:
    virtual void _as_gc_mark();
    inline bool _as_gc_mark_needed() const { return m_gcTime != AsObjectRefBase::gcGlobalTime(); }
    inline int retainCount() const { return m_refCount; }
    void retain();
    void release();

public:
    static AsObject_ref __as_null;
};

namespace AsGlobal
{
    void trace(const AsObject& obj);
    void trace(const AsString_ref& obj);
    void trace(int val);
    void trace(float val);
    void trace(bool val);
}

#endif // AsObject_h__
