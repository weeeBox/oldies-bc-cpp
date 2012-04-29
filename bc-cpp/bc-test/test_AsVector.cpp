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
        AsVector<int>::Ref vector = AS_NEW_PRIMITIVES_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;

        ensure(vector->length() == size);
    }

    template<>
    template<>
    void AsVector_object::test<2>()
    {
        set_test_name("Integral objects test 1");
        
        const int size = 5;
        int arr[size] = {1, 2, 3, 4, 5};

        AsVector<int>::Ref vector = AS_NEW_PRIMITIVES_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;
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

        for (int i = 0; i < vector->length(); ++i)
        {
            succeed = succeed && *arr[i] == vector[i];
        }

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<5>()
    {
        set_test_name("IndexOf test 1");

        const int size = 5;       

        AsVector<int>::Ref vector = AS_NEW_PRIMITIVES_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->length() == size;

        succeed = succeed && vector->indexOf(1) == 0;
        succeed = succeed && vector->indexOf(2) == 1;
        succeed = succeed && vector->indexOf(3) == 2;
        succeed = succeed && vector->indexOf(4) == 3;
        succeed = succeed && vector->indexOf(5) == 4;

        succeed = succeed && vector->indexOf(6) == -1;

        succeed = succeed && vector->indexOf(1, 1) == -1;
        succeed = succeed && vector->indexOf(2, 1) == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<6>()
    {
        set_test_name("IndexOf test 2");

        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        AsString_ref str6 = ASL("6");
        AsString_ref str7 = ASL("5");
                
        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, size) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == size;

        succeed = succeed && vector->indexOf(str1) == 0;
        succeed = succeed && vector->indexOf(str2) == 1;
        succeed = succeed && vector->indexOf(str3) == 2;
        succeed = succeed && vector->indexOf(str4) == 3;
        succeed = succeed && vector->indexOf(str5) == 4;

        succeed = succeed && vector->indexOf(str6) == -1;
        succeed = succeed && vector->indexOf(str7) == 4;

        succeed = succeed && vector->indexOf(str1, 1) == -1;
        succeed = succeed && vector->indexOf(str2, 1) == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<7>()
    {
        set_test_name("LastIndexOf test 1");

        const int size = 5;       

        AsVector<int>::Ref vector = AS_NEW_PRIMITIVES_VECTOR(int, size) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->length() == size;

        succeed = succeed && vector->lastIndexOf(1) == 0;
        succeed = succeed && vector->lastIndexOf(2) == 1;
        succeed = succeed && vector->lastIndexOf(3) == 2;
        succeed = succeed && vector->lastIndexOf(4) == 3;
        succeed = succeed && vector->lastIndexOf(5) == 4;

        succeed = succeed && vector->lastIndexOf(6) == -1;

        succeed = succeed && vector->lastIndexOf(5, 3) == -1;
        succeed = succeed && vector->lastIndexOf(4, 3) == 3;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<8>()
    {
        set_test_name("LastIndexOf test 2");

        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        AsString_ref str6 = ASL("6");
        AsString_ref str7 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, size) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == size;

        succeed = succeed && vector->lastIndexOf(str1) == 0;
        succeed = succeed && vector->lastIndexOf(str2) == 1;
        succeed = succeed && vector->lastIndexOf(str3) == 2;
        succeed = succeed && vector->lastIndexOf(str4) == 3;
        succeed = succeed && vector->lastIndexOf(str5) == 4;

        succeed = succeed && vector->lastIndexOf(str6) == -1;
        succeed = succeed && vector->lastIndexOf(str7) == 4;

        succeed = succeed && vector->lastIndexOf(str5, 3) == -1;
        succeed = succeed && vector->lastIndexOf(str4, 3) == 3;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<9>()
    {
        set_test_name("push test 1");

        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        AsString_ref str6 = ASL("6");
        AsString_ref str7 = ASL("5");
        
        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, size);
        bool succeed = vector->length() == 0;
        succeed = succeed && vector->capacity() == size;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->push(str1);
        vector->push(str2);
        vector->push(str3);
        vector->push(str4);
        vector->push(str5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && vector->length() == size;
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;        

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<10>()
    {
        set_test_name("push test 2");

        const int size = 5;
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        AsString_ref str6 = ASL("6");
        AsString_ref str7 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 0);
        bool succeed = vector->length() == 0;
        succeed = succeed && vector->capacity() == 0;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->push(str1);
        vector->push(str2);
        vector->push(str3);
        vector->push(str4);
        vector->push(str5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && vector->length() == size;        
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;        

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<12>()
    {
        set_test_name("push test 3");
                
        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        AsString_ref str6 = ASL("6");
        AsString_ref str7 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 3) << str1 << str2 << str3;
        bool succeed = vector->length() == 3;        

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;
                
        vector->push(str4);
        vector->push(str5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && vector->length() == 5;        
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;        

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<13>()
    {
        set_test_name("pop test 1");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");        

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 3) << str1 << str2 << str3;
        bool succeed = vector->length() == 3;        

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->push(str4);
        vector->push(str5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && vector->length() == 5;        
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;        

        AsString_ref popStr = vector->pop();
        succeed = succeed && vector->length() == 4;
        succeed = succeed && popStr == str5;
        popStr = AS_NULL;
        succeed = succeed && str5->retainCount() == 1;
        
        popStr = vector->pop();
        succeed = succeed && vector->length() == 3;
        succeed = succeed && popStr == str4;
        popStr = AS_NULL;
        succeed = succeed && str4->retainCount() == 1;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<14>()
    {
        set_test_name("pop test 2");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");
        

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 0);
        bool succeed = vector->length() == 0;

        vector->push(str1);
        vector->push(str2);
        vector->push(str3);
        vector->push(str4);
        vector->push(str5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector->pop();
        vector->pop();        

        succeed = succeed && vector->length() == 3;
        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->push(str1);
        vector->push(str1);
        vector->push(str2);

        succeed = succeed && vector->length() == 6;
        succeed = succeed && str1->retainCount() == 4;
        succeed = succeed && str2->retainCount() == 3;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<15>()
    {
        set_test_name("unshift test");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 1);
        bool succeed = vector->length() == 0;

        vector->unshift(str1);
        succeed = succeed && vector->length() == 1;
        succeed = succeed && vector[0] == str1;        

        vector->unshift(str2);
        succeed = succeed && vector->length() == 2;
        succeed = succeed && vector[0] == str2;
        succeed = succeed && vector[1] == str1;
        

        vector->unshift(str3);
        succeed = succeed && vector->length() == 3;
        succeed = succeed && vector[0] == str3;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str1;        

        vector->unshift(str4);
        succeed = succeed && vector->length() == 4;
        succeed = succeed && vector[0] == str4;
        succeed = succeed && vector[1] == str3;
        succeed = succeed && vector[2] == str2;
        succeed = succeed && vector[3] == str1;        

        vector->unshift(str5);
        succeed = succeed && vector->length() == 5;
        succeed = succeed && vector[0] == str5;
        succeed = succeed && vector[1] == str4;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str2;
        succeed = succeed && vector[4] == str1;    

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector->pop();
        vector->pop();        
        
        succeed = succeed && vector->length() == 3;

        succeed = succeed && vector[0] == str5;
        succeed = succeed && vector[1] == str4;
        succeed = succeed && vector[2] == str3;        

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector->unshift(str1);
        vector->unshift(str1);
        vector->unshift(str2);
        
        succeed = succeed && vector->length() == 6;

        succeed = succeed && vector[0] == str2;
        succeed = succeed && vector[1] == str1;
        succeed = succeed && vector[2] == str1; 
        succeed = succeed && vector[3] == str5;
        succeed = succeed && vector[4] == str4;
        succeed = succeed && vector[5] == str3; 

        succeed = succeed && str1->retainCount() == 3;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<16>()
    {
        set_test_name("shift test");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 1);
        bool succeed = vector->length() == 0;

        vector->unshift(str1);
        vector->unshift(str2);
        vector->unshift(str3);        
        vector->unshift(str4);
        vector->unshift(str5);

        succeed = succeed && vector->length() == 5;
        succeed = succeed && vector[0] == str5;
        succeed = succeed && vector[1] == str4;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str2;
        succeed = succeed && vector[4] == str1;    

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector->shift();
        vector->shift();

        succeed = succeed && vector->length() == 3;

        succeed = succeed && vector[0] == str3;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str1;        

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->unshift(str1);
        vector->unshift(str1);
        vector->unshift(str2);

        succeed = succeed && vector->length() == 6;

        succeed = succeed && vector[0] == str2;
        succeed = succeed && vector[1] == str1;
        succeed = succeed && vector[2] == str1; 
        succeed = succeed && vector[3] == str3;
        succeed = succeed && vector[4] == str2;
        succeed = succeed && vector[5] == str1; 

        succeed = succeed && str1->retainCount() == 4;
        succeed = succeed && str2->retainCount() == 3;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->shift();
        vector->shift();
        vector->shift();
        vector->push(str4);
        vector->push(str5);        

        succeed = succeed && vector->length() == 5;

        succeed = succeed && vector[0] == str3;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str1;        
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;
        

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<17>()
    {
        set_test_name("set length test");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 3) << str1 << str2 << str3;
        bool succeed = vector->length() == 3;
        
        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->length(5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        succeed = succeed && vector->length() == 5;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;        
        succeed = succeed && vector[3] == AS_NULL;
        succeed = succeed && vector[4] == AS_NULL;
        succeed = succeed && AS_NULL == vector[3];
        succeed = succeed && AS_NULL == vector[4];

        vector[3] = str4;
        vector[4] = str5;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;        
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        vector->length(3);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        succeed = succeed && vector->length() == 3;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;

        vector = AS_NULL;

        succeed = succeed && str1->retainCount() == 1;
        succeed = succeed && str2->retainCount() == 1;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<18>()
    {
        set_test_name("Slice test 1");

        int int1 = 1;
        int int2 = 2;
        int int3 = 3;
        int int4 = 4;
        int int5 = 5;

        AsVector<int>::Ref vector = AS_NEW_PRIMITIVES_VECTOR(int, 5) << int1 << int2 << int3 << int4 << int5;
        bool succeed = vector->length() == 5;

        AsVector<int>::Ref v1 = vector->slice();
        succeed = succeed && v1->length() == 5;
        
        succeed = succeed && v1[0] == int1;
        succeed = succeed && v1[1] == int2;
        succeed = succeed && v1[2] == int3;        
        succeed = succeed && v1[3] == int4;
        succeed = succeed && v1[4] == int5;               

        v1 = vector->slice(2);
        succeed = succeed && v1->length() == 3;        

        succeed = succeed && v1[0] == int3;
        succeed = succeed && v1[1] == int4;
        succeed = succeed && v1[2] == int5;        

        v1 = vector->slice(1, 3);
        succeed = succeed && v1->length() == 2;        

        succeed = succeed && v1[0] == int2;
        succeed = succeed && v1[1] == int3;        

        v1 = vector->slice(1, 1);
        succeed = succeed && v1->length() == 0;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<19>()
    {
        set_test_name("Slice test 2");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 5) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        AsVector<AsString_ref>::Ref v1 = vector->slice();
        succeed = succeed && v1->length() == 5;

        succeed = succeed && str1->retainCount() == 3;
        succeed = succeed && str2->retainCount() == 3;
        succeed = succeed && str3->retainCount() == 3;
        succeed = succeed && str4->retainCount() == 3;
        succeed = succeed && str5->retainCount() == 3;

        succeed = succeed && v1[0] == str1;
        succeed = succeed && v1[1] == str2;
        succeed = succeed && v1[2] == str3;        
        succeed = succeed && v1[3] == str4;
        succeed = succeed && v1[4] == str5;

        v1 = AS_NULL;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        v1 = vector->slice(2);
        succeed = succeed && v1->length() == 3;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 3;
        succeed = succeed && str4->retainCount() == 3;
        succeed = succeed && str5->retainCount() == 3;

        succeed = succeed && v1[0] == str3;
        succeed = succeed && v1[1] == str4;
        succeed = succeed && v1[2] == str5;        

        v1 = AS_NULL;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        v1 = vector->slice(1, 3);
        succeed = succeed && v1->length() == 2;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 3;
        succeed = succeed && str3->retainCount() == 3;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && v1[0] == str2;
        succeed = succeed && v1[1] == str3;        

        v1 = AS_NULL;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        v1 = vector->slice(1, 1);
        succeed = succeed && v1->length() == 0;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;
        
        v1 = AS_NULL;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<20>()
    {
        set_test_name("Splice test 1");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 5) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        AsVector<AsString_ref>::Ref deleted = vector->splice(0);
        succeed = succeed && vector->length() == 0;
        succeed = succeed && deleted->length() == 5;

        succeed = succeed && deleted[0] == str1;
        succeed = succeed && deleted[1] == str2;
        succeed = succeed && deleted[2] == str3;        
        succeed = succeed && deleted[3] == str4;
        succeed = succeed && deleted[4] == str5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<21>()
    {
        set_test_name("Splice test 2");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 5) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        AsVector<AsString_ref>::Ref deleted = vector->splice(0, 2);
        succeed = succeed && vector->length() == 3;
        succeed = succeed && deleted->length() == 2;

        succeed = succeed && deleted[0] == str1;
        succeed = succeed && deleted[1] == str2;

        succeed = succeed && vector[0] == str3;        
        succeed = succeed && vector[1] == str4;
        succeed = succeed && vector[2] == str5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<22>()
    {
        set_test_name("Splice test 3");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 5) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        AsVector<AsString_ref>::Ref deleted = vector->splice(2, 2);
        succeed = succeed && vector->length() == 3;
        succeed = succeed && deleted->length() == 2;

        succeed = succeed && deleted[0] == str3;
        succeed = succeed && deleted[1] == str4;

        succeed = succeed && vector[0] == str1;        
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<23>()
    {
        set_test_name("Splice test 4");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        AsVector<AsString_ref>::Ref vector = AS_NEW_VECTOR(AsString_ref, 5) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->length() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        AsVector<AsString_ref>::Ref deleted = vector->splice(2);
        succeed = succeed && vector->length() == 2;
        succeed = succeed && deleted->length() == 3;

        succeed = succeed && deleted[0] == str3;
        succeed = succeed && deleted[1] == str4;
        succeed = succeed && deleted[2] == str5;

        succeed = succeed && vector[0] == str1;        
        succeed = succeed && vector[1] == str2;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;        

        ensure(succeed);
    }
}