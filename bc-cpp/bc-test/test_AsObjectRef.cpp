#include "tut.hpp"

#include "AsObject.h"

namespace tut 
{   
    struct AsObjectRef_data
    { 
    };

    typedef test_group<AsObjectRef_data> AsObjectRef_test_group;
    typedef AsObjectRef_test_group::object AsObjectRef_object;
    AsObjectRef_test_group AsObjectRefTestGroup("AsObjectRef tests");    

    // classA

    AS_CLASS(ClassA);

    class ClassA : public AsObject
    {
    public:
        AS_OBJ(ClassA, AsObject);
        AS_CONSTRUCTOR_H(ClassA,());
    public:
        ClassA() :
          member(false)
        {
        }

    private:
        AsObject_ref member;
        static AsObject_ref staticMember;
    };

    AsObject_ref ClassA::staticMember(true);
    AS_CONSTRUCTOR_CPP(ClassA,()) {}

    // classB

    AS_CLASS(ClassB);
    AS_CLASS(ClassC);

    class ClassB : public AsObject
    {
    public:
        AS_OBJ(ClassB, AsObject);
    public: inline static ClassB_ref _as_create_ClassB () 
    { 
        ClassB *obj = new ClassB();
        ClassB_ref __instance(obj); 
        __instance->_as_constructor_ClassB (); 
        return __instance; 
    }

    protected: void _as_constructor_ClassB ();
    public:
        ClassB() :
          member(false)
        {
        }

    public:
        ClassC_ref member;        
    };

    AS_CONSTRUCTOR_CPP(ClassB,()) {}

    // classC

    class ClassC : public AsObject
    {
    public:
        AS_OBJ(ClassC, AsObject);
        AS_CONSTRUCTOR_H(ClassC,());
    public:
        ClassC() :
          member(false)
        {
        }

    public:
        ClassB_ref member;        
    };

    AS_CONSTRUCTOR_CPP(ClassC,()) {}

    // tests

    template<>
    template<>
    void AsObjectRef_object::test<1>()
    {
        set_test_name("reg/unreg test");

        int refsCount = AsObjectRefBase::_as_refsCount();
        int staticRefsCount = AsObjectRefBase::_as_staticRefsCount();
        int autoRefsCount = AsObjectRefBase::_as_autoRefsCount();

        bool succeed = true;

        {
            ClassA_ref classA = AS_NEW(ClassA, ());
            succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 1;
            succeed = succeed && (AsObjectRefBase::_as_autoRefsCount() - autoRefsCount) == 1;
        }

        succeed = succeed && refsCount == AsObjectRefBase::_as_refsCount();
        succeed = succeed && staticRefsCount == AsObjectRefBase::_as_staticRefsCount();
        succeed = succeed && autoRefsCount == AsObjectRefBase::_as_autoRefsCount();
        ensure(succeed);
    }

    template<>
    template<>
    void AsObjectRef_object::test<2>()
    {
        set_test_name("gc test");

        int refsCount = AsObjectRefBase::_as_refsCount();
        int staticRefsCount = AsObjectRefBase::_as_staticRefsCount();
        int autoRefsCount = AsObjectRefBase::_as_autoRefsCount();

        bool succeed = true;

        {
            ClassB_ref classB = AS_NEW(ClassB, ());
            succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 1;
            succeed = succeed && (AsObjectRefBase::_as_autoRefsCount() - autoRefsCount) == 1;

            ClassC_ref classC = AS_NEW(ClassC, ());
            succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 2;
            succeed = succeed && (AsObjectRefBase::_as_autoRefsCount() - autoRefsCount) == 2;

            classB->member = classC;
            classC->member = classB;

            succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 2;
            succeed = succeed && (AsObjectRefBase::_as_autoRefsCount() - autoRefsCount) == 2;
        }

        succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 2;
        succeed = succeed && autoRefsCount == AsObjectRefBase::_as_autoRefsCount();

        AsObjectRefBase::gc();

        succeed = succeed && refsCount == AsObjectRefBase::_as_refsCount();
        succeed = succeed && staticRefsCount == AsObjectRefBase::_as_staticRefsCount();
        succeed = succeed && autoRefsCount == AsObjectRefBase::_as_autoRefsCount();
        ensure(succeed);
    }
}