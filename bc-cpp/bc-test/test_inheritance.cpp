//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsChildClass.h"
#include "AsFieldClass.h"

namespace tut 
{   
    struct inheritance_data
    { 
    };

    typedef test_group<inheritance_data> inheritance_test_group;
    typedef inheritance_test_group::object inheritance_object;
    inheritance_test_group inheritanceTestGroup("inheritance tests");

    template<>
    template<>
    void inheritance_object::test<1>()
    {
        set_test_name("Call order test");

        AS_NEW(AsChildClass,());

        bool succeed = true;

        _V_AsString_ref list = AsFieldClass::list;

        succeed = (succeed && (list != AS_NULL));
        succeed = (succeed && (list->getLength() == 4));

        succeed = (succeed && (list[0] == ASL("Child field")));
        succeed = (succeed && (list[1] == ASL("Base field")));
        succeed = (succeed && (list[2] == ASL("Base constructor")));
        succeed = (succeed && (list[3] == ASL("Child constructor")));

        ensure(succeed);
    }
}