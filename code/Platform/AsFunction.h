#ifndef AsFunction_h__
#define AsFunction_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
class AsFunction : public AsObject
{
public:
	AS_OBJ(AsFunction, AsObject);

public:
    AsFunction(AsObject* target, void* funcPtr) : m_target(target), m_funcPtr(funcPtr) { ASSERT(target); target->retain(); }
    ~AsFunction() { m_target->release(); }  

    template <class T>
    inline T call() 
    {
        T (*funcPtr)(AsObject*) = (T (*)(AsObject*))m_funcPtr;
        return funcPtr(m_target);
    }       

    template <class T, class ARG_1>
    inline T call(const ARG_1& arg) 
    {
        T (*funcPtr)(AsObject*, const ARG_1&) = (T (*)(AsObject*, const ARG_1&))m_funcPtr;
        return funcPtr(m_target, arg);
    }

    template <class T, class ARG_1, class ARG_2>
    inline T call(const ARG_1& arg1, const ARG_2& arg2) 
    {
        T (*funcPtr)(AsObject*, const ARG_1&, const ARG_2&) = (T (*)(AsObject*, const ARG_1&, const ARG_2&))m_funcPtr;
        return funcPtr(m_target, arg1, arg2);
    }

    template <class T, class ARG_1, class ARG_2, class ARG_3>
    inline T call(const ARG_1& arg1, const ARG_2& arg2, const ARG_3& arg3) 
    {
        T (*funcPtr)(AsObject*, const ARG_1&, const ARG_2&, const ARG_3&) = (T (*)(AsObject*, const ARG_1&, const ARG_2&, const ARG_3&))m_funcPtr;
        return funcPtr(m_target, arg1, arg2, arg3);
    }

    template <class T, class ARG_1, class ARG_2, class ARG_3, class ARG_4>
    inline T call(const ARG_1& arg1, const ARG_2& arg2, const ARG_3& arg3, const ARG_4& arg4) 
    {
        T (*funcPtr)(AsObject*, const ARG_1&, const ARG_2&, const ARG_3&, const ARG_4&) = (T (*)(AsObject*, const ARG_1&, const ARG_2&, const ARG_3&, const ARG_4&))m_funcPtr;
        return funcPtr(m_target, arg1, arg2, arg3, arg4);
    }

public:
    void _as_gc_mark()
    {
        if (_as_gc_mark_needed())
        {
            AsObject::_as_gc_mark();
            if (m_target) m_target->_as_gc_mark();
        }
    }

private:
    friend class AsFunction_ref;

    void* m_funcPtr;
    AsObject* m_target;
};
 
#endif // AsFunction_h__
