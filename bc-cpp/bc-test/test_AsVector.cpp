//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsVector.h"

namespace tut 
{   
    struct AsVector_data
    { 
    };
    
    typedef test_group<AsVector_data> AsVector_test_group;
    typedef AsVector_test_group::object AsVector_object;
    AsVector_test_group AsVectorTestGroup("AsVector tests");
    
    template<>
    template<>
    void AsVector_object::test<1>()
    {
        set_test_name("Length test 1");
        
        const int size = 5;
        AsVector<int>::Ref vector = AS_NEW_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;

        ensure(vector->length() == size);
    }

    template<>
    template<>
    void AsVector_object::test<2>()
    {
        set_test_name("Integral objects test 1");
        
        const int size = 5;
        int arr[size] = {1, 2, 3, 4, 5};

        AsVector<int>::Ref vector = AS_NEW_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->length() == size;

        for (int i = 0; i < vector->length(); ++i)
        {
            succeed = succeed && arr[i] == vector[i];
        }

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<3>()
    {
        set_test_name("Objects refs test 1");
        
        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsString_ref arr[] = 
        {
            str1, str2, str3, str4, str5
        };

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, size) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == size;

        for (int i = 0; i < vector->length(); ++i)
        {
            succeed = succeed && arr[i] == vector[i];
        }

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<4>()
    {
        set_test_name("Objects refs test 2");

        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        bool succeed = true;
        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        AsString_ref **arr = new AsString_ref*[size];
        arr[0] = &str1;
        arr[1] = &str2;
        arr[2] = &str3;
        arr[3] = &str4;
        arr[4] = &str5;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, size) << str1 << str2 << str3 << str4 << str5;
        succeed = succeed && vector->length() == size;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;



        ensure(succeed);
    }
}
