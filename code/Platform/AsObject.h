#ifndef AsObject_h__
#define AsObject_h__
 
#include "AsBc.h"

#include "AsObjectRef.h"

/* null type */
#define AS_NULL AsObject::__as_null

/* string literal */
#define ASL(x) L##x

/* reference type */
#define AS_CLASS(type) class type; typedef AsObjectRef<type> type##_ref
#define AS_VECTOR(type) typedef _as_AsRefVector<type##_ref>::Ref _V_##type##_ref
#define AS_VECTOR_PRIMITIVE(type) typedef AsVector<type>::Ref _V_##type##_ref

/* new */
#define AS_NEW(type, initializer) type::_as_create_##type initializer
#define AS_NEW_VECTOR(type, capacity) _as_AsRefVector<type>::_as_create(capacity)
#define AS_NEW_PRIMITIVES_VECTOR(type, capacity) AsVector<type>::_as_create(capacity)

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
#define AS_INTERFACE_BOX_BEGIN(type,base) \
public: \
    class _as_interface_##base : public base { \
    private: type *m_target; \
    public: \
        AS_TYPENAME(type,base); \
    public: \
        _as_interface_##base(type *target) : m_target(target) {}
#define AS_INTERFACE_CALL(name,initializer) m_target->name initializer
#define AS_INTERFACE_BOX_END(type,base) }; \
    inline base##_ref _as_box_##base() { return base##_ref(new _as_interface_##base(this)); }

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
    void retain();
    void release();    

private:
    GcTime m_gcTime;

public:
    virtual void _as_gc_mark();
    inline bool _as_gc_mark_needed() const { return m_gcTime != AsObjectRefBase::gcGlobalTime(); }
    inline int retainCount() const { return m_refCount; }

public:
    static AsObject_ref __as_null;
/*
private:
	static StaticInit __internalStaticInitializerAsObject;
	static BOOL __internalStaticInitializedAsObject;
	
public:
	static void __internalStaticInit();
	
protected:
	AsObject();
	
public:
	void __internalGc();
*/
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
