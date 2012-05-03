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

    template<>
    template<>
    void AsObjectRef_object::test<1>()
    {
        set_test_name("abs test");

        int refsCount = AsObjectRefBase::_as_refsCount();
        int staticRefsCount = AsObjectRefBase::_as_staticRefsCount();
        int unregRefsCount = AsObjectRefBase::_as_unregRefsCount();

        bool succeed = true;

        {
            ClassA_ref classA = AS_NEW(ClassA, ());
            succeed = succeed && (AsObjectRefBase::_as_refsCount() - refsCount) == 1;
            succeed = succeed && (AsObjectRefBase::_as_unregRefsCount() - unregRefsCount) == 1;
        }

        succeed = succeed && refsCount == AsObjectRefBase::_as_refsCount();
        succeed = succeed && staticRefsCount == AsObjectRefBase::_as_staticRefsCount();
        succeed = succeed && unregRefsCount == AsObjectRefBase::_as_unregRefsCount();
        ensure(succeed);
    }
}