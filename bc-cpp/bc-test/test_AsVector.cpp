//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsVector.h"

AS_VECTOR_PRIMITIVE_REF(int);
AS_VECTOR_REF(AsString);

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
        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(size)) << 1 << 2 << 3 << 4 << 5;

        ensure(vector->getLength() == size);
    }

    template<>
    template<>
    void AsVector_object::test<2>()
    {
        set_test_name("Integral objects test 1");
        
        const int size = 5;
        int arr[size] = {1, 2, 3, 4, 5};

        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(size)) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->getLength() == size;

        for (int i = 0; i < vector->getLength(); ++i)
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == size;

        for (int i = 0; i < vector->getLength(); ++i)
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size)) << str1 << str2 << str3 << str4 << str5;
        succeed = succeed && vector->getLength() == size;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        for (int i = 0; i < vector->getLength(); ++i)
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

        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(size)) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->getLength() == size;

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
                
        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == size;

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

        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(size)) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->getLength() == size;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == size;

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
        
        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size));
        bool succeed = vector->getLength() == 0;
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

        succeed = succeed && vector->getLength() == size;
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(0));
        bool succeed = vector->getLength() == 0;
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

        succeed = succeed && vector->getLength() == size;        
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(3)) << str1 << str2 << str3;
        bool succeed = vector->getLength() == 3;        

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

        succeed = succeed && vector->getLength() == 5;        
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(3)) << str1 << str2 << str3;
        bool succeed = vector->getLength() == 3;        

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

        succeed = succeed && vector->getLength() == 5;        
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[4] == str5;        

        AsString_ref popStr = vector->pop();
        succeed = succeed && vector->getLength() == 4;
        succeed = succeed && popStr == str5;
        popStr = AS_NULL;
        succeed = succeed && str5->retainCount() == 1;
        
        popStr = vector->pop();
        succeed = succeed && vector->getLength() == 3;
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
        

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(0));
        bool succeed = vector->getLength() == 0;

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

        succeed = succeed && vector->getLength() == 3;
        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->push(str1);
        vector->push(str1);
        vector->push(str2);

        succeed = succeed && vector->getLength() == 6;
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(1));
        bool succeed = vector->getLength() == 0;

        vector->unshift(str1);
        succeed = succeed && vector->getLength() == 1;
        succeed = succeed && vector[0] == str1;        

        vector->unshift(str2);
        succeed = succeed && vector->getLength() == 2;
        succeed = succeed && vector[0] == str2;
        succeed = succeed && vector[1] == str1;
        

        vector->unshift(str3);
        succeed = succeed && vector->getLength() == 3;
        succeed = succeed && vector[0] == str3;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str1;        

        vector->unshift(str4);
        succeed = succeed && vector->getLength() == 4;
        succeed = succeed && vector[0] == str4;
        succeed = succeed && vector[1] == str3;
        succeed = succeed && vector[2] == str2;
        succeed = succeed && vector[3] == str1;        

        vector->unshift(str5);
        succeed = succeed && vector->getLength() == 5;
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
        
        succeed = succeed && vector->getLength() == 3;

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
        
        succeed = succeed && vector->getLength() == 6;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(1));
        bool succeed = vector->getLength() == 0;

        vector->unshift(str1);
        vector->unshift(str2);
        vector->unshift(str3);        
        vector->unshift(str4);
        vector->unshift(str5);

        succeed = succeed && vector->getLength() == 5;
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

        succeed = succeed && vector->getLength() == 3;

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

        succeed = succeed && vector->getLength() == 6;

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

        succeed = succeed && vector->getLength() == 5;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(3)) << str1 << str2 << str3;
        bool succeed = vector->getLength() == 3;
        
        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        vector->setLength(5);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        succeed = succeed && vector->getLength() == 5;

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

        vector->setLength(3);

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        succeed = succeed && vector->getLength() == 3;

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

        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(5)) << int1 << int2 << int3 << int4 << int5;
        bool succeed = vector->getLength() == 5;

        _V_int_ref v1 = vector->slice();
        succeed = succeed && v1->getLength() == 5;
        
        succeed = succeed && v1[0] == int1;
        succeed = succeed && v1[1] == int2;
        succeed = succeed && v1[2] == int3;        
        succeed = succeed && v1[3] == int4;
        succeed = succeed && v1[4] == int5;               

        v1 = vector->slice(2);
        succeed = succeed && v1->getLength() == 3;        

        succeed = succeed && v1[0] == int3;
        succeed = succeed && v1[1] == int4;
        succeed = succeed && v1[2] == int5;        

        v1 = vector->slice(1, 3);
        succeed = succeed && v1->getLength() == 2;        

        succeed = succeed && v1[0] == int2;
        succeed = succeed && v1[1] == int3;        

        v1 = vector->slice(1, 1);
        succeed = succeed && v1->getLength() == 0;        

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref v1 = vector->slice();
        succeed = succeed && v1->getLength() == 5;

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
        succeed = succeed && v1->getLength() == 3;

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
        succeed = succeed && v1->getLength() == 2;

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
        succeed = succeed && v1->getLength() == 0;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref deleted = vector->splice(0);
        succeed = succeed && vector->getLength() == 0;
        succeed = succeed && deleted->getLength() == 5;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref deleted = vector->splice(0, 2);
        succeed = succeed && vector->getLength() == 3;
        succeed = succeed && deleted->getLength() == 2;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref deleted = vector->splice(2, 2);
        succeed = succeed && vector->getLength() == 3;
        succeed = succeed && deleted->getLength() == 2;

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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref deleted = vector->splice(2);
        succeed = succeed && vector->getLength() == 2;
        succeed = succeed && deleted->getLength() == 3;

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

    template<>
    template<>
    void AsVector_object::test<24>()
    {
        set_test_name("Splice test 5");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref deleted = vector->splice(2, 0);
        succeed = succeed && vector->getLength() == 5;
        succeed = succeed && deleted->getLength() == 0;

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

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<25>()
    {
        set_test_name("Splice test 6");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(3)) << str1 << str2 << str3;
        bool succeed = vector->getLength() == 3;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 1;

        _V_AsString_ref deleted = vector->splice(2, 0, str4);
        succeed = succeed && vector->getLength() == 4;
        succeed = succeed && deleted->getLength() == 0;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str4;
        succeed = succeed && vector[3] == str3;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 1;

        deleted = vector->splice(2, 1, str5);

        succeed = succeed && vector->getLength() == 4;
        succeed = succeed && deleted->getLength() == 1;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str5;
        succeed = succeed && vector[3] == str3;

        succeed = succeed && deleted[0] == str4;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        deleted = vector->splice(2, 1);

        succeed = succeed && vector->getLength() == 3;
        succeed = succeed && deleted->getLength() == 1;

        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;        
        succeed = succeed && vector[2] == str3;

        succeed = succeed && deleted[0] == str5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 1;
        succeed = succeed && str5->retainCount() == 2;

        deleted = vector->splice(0, 0, str4);

        succeed = succeed && vector->getLength() == 4;
        succeed = succeed && deleted->getLength() == 0;

        succeed = succeed && vector[0] == str4;
        succeed = succeed && vector[1] == str1;
        succeed = succeed && vector[2] == str2;        
        succeed = succeed && vector[3] == str3;        

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 1;

        deleted = vector->splice(vector->getLength() - 1, 0, str5);

        succeed = succeed && vector->getLength() == 5;
        succeed = succeed && deleted->getLength() == 0;

        succeed = succeed && vector[0] == str4;
        succeed = succeed && vector[1] == str1;
        succeed = succeed && vector[2] == str2;
        succeed = succeed && vector[3] == str5;
        succeed = succeed && vector[4] == str3;                

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<26>()
    {
        set_test_name("Reverse test 1");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        succeed = succeed && vector[4] == str5;
        succeed = succeed && vector[3] == str4;
        succeed = succeed && vector[2] == str3;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[0] == str1;

        vector->splice(2, 1);

        succeed = succeed && vector->getLength() == 4;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 1;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;
        
        succeed = succeed && vector[0] == str1;
        succeed = succeed && vector[1] == str2;
        succeed = succeed && vector[2] == str4;
        succeed = succeed && vector[3] == str5;       

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<27>()
    {
        set_test_name("Reverse test 2");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(0));
        bool succeed = vector->getLength() == 0;

        vector->reverse();
        succeed = succeed && vector->getLength() == 0;

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<28>()
    {
        set_test_name("Concat test");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(3)) << str1 << str2 << str3;
        bool succeed = vector->getLength() == 3;

        _V_AsString_ref v = AS_NEW_VECTOR(AsString,(2)) << str4 << str5;
        succeed = succeed && v->getLength() == 2;

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;

        _V_AsString_ref concat = vector->concat(v);
        succeed = succeed && concat->getLength() == 5;

        succeed = succeed && str1->retainCount() == 3;
        succeed = succeed && str2->retainCount() == 3;
        succeed = succeed && str3->retainCount() == 3;
        succeed = succeed && str4->retainCount() == 3;
        succeed = succeed && str5->retainCount() == 3;

        succeed = succeed && concat[0] == str1;
        succeed = succeed && concat[1] == str2;
        succeed = succeed && concat[2] == str3;
        succeed = succeed && concat[3] == str4;
        succeed = succeed && concat[4] == str5;

        ensure(succeed);
    }    

    template<>
    template<>
    void AsVector_object::test<29>()
    {
        set_test_name("Sort test");

        ensure(false);
    }

    template<>
    template<>
    void AsVector_object::test<30>()
    {
        set_test_name("Join test");

        ensure(false);
    }

    template<>
    template<>
    void AsVector_object::test<31>()
    {
        set_test_name("To string test");

        AsString_ref str1 = ASL("1");
        AsString_ref str2 = ASL("2");
        AsString_ref str3 = ASL("3");
        AsString_ref str4 = ASL("4");
        AsString_ref str5 = ASL("5");

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(5)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == 5;

        succeed = succeed && vector->toString() == ASL("[1,2,3,4,5]");

        succeed = succeed && str1->retainCount() == 2;
        succeed = succeed && str2->retainCount() == 2;
        succeed = succeed && str3->retainCount() == 2;
        succeed = succeed && str4->retainCount() == 2;
        succeed = succeed && str5->retainCount() == 2;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<32>()
    {
        set_test_name("Primitive foreach test 1");
        
        const int size = 5;
        int arr[size] = {1, 2, 3, 4, 5};

        _V_int_ref vector = AS_NEW_PRIMITIVES_VECTOR(int,(size)) << 1 << 2 << 3 << 4 << 5;
        bool succeed = vector->getLength() == size;

        int i = 0;
        AS_PRIMITIVE_FOREACH(int, element, vector)
        {
            succeed = succeed && arr[i++] == element;
        }
        AS_FOREACH_END

        ensure(succeed);
    }

    template<>
    template<>
    void AsVector_object::test<33>()
    {
        set_test_name("Foreach test 1");
        
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

        _V_AsString_ref vector = AS_NEW_VECTOR(AsString,(size)) << str1 << str2 << str3 << str4 << str5;
        bool succeed = vector->getLength() == size;

        int i = 0;
        AS_FOREACH(AsString, element, vector)
        {
            succeed = succeed && arr[i++] == element;
        }
        AS_FOREACH_END

        ensure(succeed);
    }
}