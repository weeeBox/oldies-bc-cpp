//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsFoo.h"
#include "AsBar.h"

namespace tut 
{   
    struct interfaces_data
    { 
    };

    typedef test_group<interfaces_data> interfaces_test_group;
    typedef interfaces_test_group::object interfaces_object;
    interfaces_test_group interfacesTestGroup("interfaces tests");

    template<>
    template<>
    void interfaces_object::test<1>()
    {
        set_test_name("References test 1");

        AsFoo_ref foo = AS_NEW(AsFoo,());
        AsBar_ref bar = AS_NEW(AsBar,());

        bool succeed = true;

        succeed = succeed && foo->retainCount() == 1;
        succeed = succeed && bar->retainCount() == 1;

        AsInterface1_ref fooIntr1 = foo;
        AsInterface1_ref barIntr1 = bar;

        succeed = succeed && foo->retainCount() == 2;
        succeed = succeed && bar->retainCount() == 2;

        AsInterface2_ref barIntr2 = bar;
        AsInterface2_ref fooIntr2 = foo;

        succeed = succeed && foo->retainCount() == 3;
        succeed = succeed && bar->retainCount() == 3;

        succeed = (succeed && (fooIntr1->string1() == foo->string1()));
        succeed = (succeed && (fooIntr2->string2() == foo->string2()));

        succeed = (succeed && (barIntr1->string1() == bar->string1()));
        succeed = (succeed && (barIntr2->string2() == bar->string2()));

        fooIntr1 = AS_NULL;
        barIntr1 = AS_NULL;

        succeed = succeed && foo->retainCount() == 2;
        succeed = succeed && bar->retainCount() == 2;

        barIntr2 = AS_NULL;
        fooIntr2 = AS_NULL;

        succeed = succeed && foo->retainCount() == 1;
        succeed = succeed && bar->retainCount() == 1;

        ensure(succeed);
    }
        
    template<>
    template<>
    void interfaces_object::test<2>()
    {
        set_test_name("References test 2");

        AsFoo_ref foo = AS_NEW(AsFoo,());
        AsBar_ref bar = AS_NEW(AsBar,());

        AsInterface1_ref fooIntr1 = foo;
        AsInterface2_ref fooIntr2 = foo;

        AsInterface1_ref barIntr1 = bar;
        AsInterface2_ref barIntr2 = bar;

        AsString_ref fooStr1 = foo->string1();
        AsString_ref fooStr2 = foo->string2();

        AsString_ref barStr1 = bar->string1();
        AsString_ref barStr2 = bar->string2();

        foo = AS_NULL;
        bar = AS_NULL;

        bool succeed = true;

        succeed = (succeed && (fooIntr1->string1() == fooStr1));
        succeed = (succeed && (fooIntr2->string2() == fooStr2));

        succeed = (succeed && (barIntr1->string1() == barStr1));
        succeed = (succeed && (barIntr2->string2() == barStr2));

        ensure(succeed);
    }    
}