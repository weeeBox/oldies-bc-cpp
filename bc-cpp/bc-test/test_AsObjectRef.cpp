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
    public:
        AS_GC_MARK_H;

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
        AS_GC_MARK_H;
    public:
        ClassC() :
          member(false)
        {
        }

    public:
        ClassB_ref member;        
    };

    AS_CONSTRUCTOR_CPP(ClassC,()) {}

    AS_GC_MARK_BEGIN(ClassB, AsObject);
    AS_GC_MARK(member);
    AS_GC_MARK_END

    AS_GC_MARK_BEGIN(ClassC, AsObject);
    AS_GC_MARK(member);
    AS_GC_MARK_END

    // class StaticRoot

    AS_CLASS(StaticRoot);

    class StaticRoot : public AsObject
    {
    public:
        ClassB_ref classB;
        ClassC_ref classC;

        static StaticRoot_ref instance;

        StaticRoot() : 
            classB(false),
            classC(false)
        {
            instance = this;
        }
                    
        AS_CONSTRUCTOR_H(StaticRoot, ());        
        AS_GC_MARK_H;
    };

    StaticRoot_ref StaticRoot::instance(true);

    AS_CONSTRUCTOR_CPP(StaticRoot, ()) {}

    AS_GC_MARK_BEGIN(StaticRoot, AsObject)
    AS_GC_MARK(classB);
    AS_GC_MARK(classC);
    AS_GC_MARK_END

    // methods

    AsObject_ref foo(const AsObject_ref& obj)
    {
        return obj;
    }

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
        set_test_name("gc test 1");

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

            {
                StaticRoot_ref staticRoot = AS_NEW(StaticRoot, ());
                staticRoot->classB = classB;
                staticRoot->classC = classC;
            }

            classB->member = classC;
            classC->member = classB;            

            AsObjectRefBase::gc();

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

    template<>
    template<>
    void AsObjectRef_object::test<3>()
    {
        set_test_name("gc test 2");

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

            classB = foo(classB);
            classC = foo(classC);
        }

        succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 2;
        succeed = succeed && autoRefsCount == AsObjectRefBase::_as_autoRefsCount();

        AsObjectRefBase::gc();

        succeed = succeed && refsCount == AsObjectRefBase::_as_refsCount();
        succeed = succeed && staticRefsCount == AsObjectRefBase::_as_staticRefsCount();
        succeed = succeed && autoRefsCount == AsObjectRefBase::_as_autoRefsCount();
        ensure(succeed);
    }

    template<>
    template<>
    void AsObjectRef_object::test<4>()
    {
        set_test_name("methods test");

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

            classB = foo(classB);
            classC = foo(classC);
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