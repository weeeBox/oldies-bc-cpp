//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsStaticFoo.h"
#include "AsStaticBar.h"
#include "AsStaticFieldClass.h"

namespace tut 
{   
    struct statics_data
    { 
    };

    typedef test_group<statics_data> statics_test_group;
    typedef statics_test_group::object statics_object;
    statics_test_group staticsTestGroup("statics tests");

    template<>
    template<>
    void statics_object::test<1>()
    {
        set_test_name("Static init test");

        AsStaticRefInitializer::init();

        bool succeed = true;

        _V_AsString_ref list = AsStaticFieldClass::list;

        succeed = succeed && list != AS_NULL;
        succeed = succeed && list->length() == 5;

        succeed = succeed && list[0] == ASL("Dummy");
        succeed = succeed && list[1] == ASL("FooBase");
        succeed = succeed && list[2] == ASL("BarBase");
        succeed = succeed && list[3] == ASL("Bar");
        succeed = succeed && list[4] == ASL("Foo");

	    ensure(succeed);
    }
}