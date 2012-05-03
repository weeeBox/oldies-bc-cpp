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

    template<>
    template<>
    void AsObjectRef_object::test<1>()
    {
        set_test_name("abs test");

        bool succeed = AsObjectRefBase::_as_staticRefsCount() == 0;
        succeed = succeed && AsObjectRefBase::_as_refsCount() == 0;
        succeed = succeed && AsObjectRefBase::_as_unregRefsCount() == 0;
        ensure(succeed);
    }
}