//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsPlayGround.h"
#include "AsPlayGround2.h"

namespace tut 
{   
    struct interfaces_data
    { 
    };

    void foo(const AsBcInterface_ref& interface)
    {
        interface->foo(AS_NULL, 10);
        interface->bar(20);
        interface->baz(30);
    }

    AsBcInterface_ref bar(const AsPlayGround_ref& obj)
    {
        return obj;
    }

    AsBcInterface_ref bar(const AsPlayGround2_ref& obj)
    {
        return obj;
    }

    typedef test_group<interfaces_data> interfaces_test_group;
    typedef interfaces_test_group::object interfaces_object;
    interfaces_test_group interfacesTestGroup("interfaces tests");

    template<>
    template<>
    void interfaces_object::test<1>()
    {
        AsPlayGround_ref obj1 = AS_NEW(AsPlayGround,(10));
        AsPlayGround2_ref obj2 = AS_NEW(AsPlayGround2,(20));

        obj1->go();

        AsBcInterface_ref interface1 = AS_NULL;
        interface1 = obj1;

        obj1 = interface1;
        AsPlayGround_ref object1 = interface1;

        interface1->foo(AS_NULL, 10);
        interface1->bar(20);
        interface1->baz(30);

        interface1 = obj2;

        interface1->foo(AS_NULL, 10);
        interface1->bar(20);
        interface1->baz(30);

        foo(obj1);
        foo(obj2);

        AsBcInterface_ref interface3 = bar(obj1);
        interface3->foo(AS_NULL, 10);
        interface3->bar(20);
        interface3->baz(30);

        AsBcInterface_ref interface4 = bar(obj2);
        interface4->foo(AS_NULL, 10);
        interface4->bar(20);
        interface4->baz(30);        
    }    
}