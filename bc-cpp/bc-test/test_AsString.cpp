//
//  test.cpp
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tut.hpp"

#include "AsString.h"

namespace tut 
{   
    struct AsString_data
    { 
    };
    
    typedef test_group<AsString_data> AsString_test_group;
    typedef AsString_test_group::object AsString_object;
    AsString_test_group AsStringTestGroup("AsString tests");
    
    template<>
    template<>
    void AsString_object::test<1>()
    {
        set_test_name("Length test 1");
        
        AsString_ref str = ASL("1234567890");
        int len = str->length();

        ensure(len == 10);
    }

    template<>
    template<>
    void AsString_object::test<2>()
    {
        set_test_name("Length test 2");
        
        AsString_ref str = ASL("");
        int len = str->length();

        ensure(len == 0);
    }

    template<>
    template<>
    void AsString_object::test<3>()
    {
        set_test_name("Equality test 1");

        AsString_ref str1 = ASL("This is string");
        AsString_ref str2 = ASL("This is string");

        ensure(str1 == str2);
    }

    template<>
    template<>
    void AsString_object::test<4>()
    {
        set_test_name("Equality test 2");

        AsString_ref str1 = ASL("This is string");
        AsString_ref str2 = ASL("This is string");

        ensure(!(str1 != str2));
    }

    template<>
    template<>
    void AsString_object::test<5>()
    {
        set_test_name("Equality test 3");

        AsString_ref str1 = ASL("This is string");
        AsString_ref str2 = AS_NULL;
        AsString_ref str3 = AS_NULL;

        bool succeed = true;
        succeed = succeed && str1 != str2;
        succeed = succeed && str2 != str1;
        succeed = succeed && str2 == str3;

        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<6>()
    {
        set_test_name("charAt test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = true;
        succeed = succeed && str1->charAt(0) == ASL("T");
        succeed = succeed && str1->charAt(5) == ASL("i");
        succeed = succeed && str1->charAt(10) != ASL("!");
        succeed = succeed && str1->charAt(100) == ASL("");

        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<7>()
    {
        set_test_name("indexOf test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = true;
        succeed = succeed && str1->indexOf(ASL(" is ")) == 4;
        succeed = succeed && str1->indexOf(ASL(" iz ")) == -1;
        succeed = succeed && str1->indexOf(ASL(" string")) == 7;
        succeed = succeed && str1->indexOf(ASL("This ")) == 0;
        succeed = succeed && str1->indexOf(ASL("This "), 1) == -1;
        succeed = succeed && str1->indexOf(ASL("is"), 2) == 2;
        succeed = succeed && str1->indexOf(ASL("is"), 3) == 5;
        succeed = succeed && str1->indexOf(ASL("stra"), 3) == -1;

        ensure(succeed);
    }
    
    template<>
    template<>
    void AsString_object::test<8>()
    {
        set_test_name("lastIndexOf test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = false;
        /*succeed = succeed && str1->indexOf(ASL(" is ")) == 4;
        succeed = succeed && str1->indexOf(ASL(" iz ")) == -1;
        succeed = succeed && str1->indexOf(ASL(" string")) == 7;
        succeed = succeed && str1->indexOf(ASL("This ")) == 0;
        succeed = succeed && str1->indexOf(ASL("This "), 1) == -1;
        succeed = succeed && str1->indexOf(ASL("is"), 2) == 2;
        succeed = succeed && str1->indexOf(ASL("is"), 3) == 5;
        succeed = succeed && str1->indexOf(ASL("stra"), 3) == -1;*/

        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<9>()
    {
        set_test_name("replace test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = false;
        /*succeed = succeed && str1->indexOf(ASL(" is ")) == 4;
        succeed = succeed && str1->indexOf(ASL(" iz ")) == -1;
        succeed = succeed && str1->indexOf(ASL(" string")) == 7;
        succeed = succeed && str1->indexOf(ASL("This ")) == 0;
        succeed = succeed && str1->indexOf(ASL("This "), 1) == -1;
        succeed = succeed && str1->indexOf(ASL("is"), 2) == 2;
        succeed = succeed && str1->indexOf(ASL("is"), 3) == 5;
        succeed = succeed && str1->indexOf(ASL("stra"), 3) == -1;*/

        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<10>()
    {
        set_test_name("slice test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = true;
        succeed = succeed && str1->slice(5) == ASL("is string");
        succeed = succeed && str1->slice(5, 7) == ASL("is");
        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<11>()
    {
        set_test_name("split test");

        bool succeed = false;        
        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<12>()
    {
        set_test_name("substr test");

        AsString_ref str1 = ASL("This is string");

        bool succeed = true;        
        succeed = succeed && str1->substr(5) == ASL("is string");
        succeed = succeed && str1->substr(5, 2) == ASL("is");
        succeed = succeed && str1->substr(5, 0) == ASL("");
        ensure(succeed);
    }

    template<>
    template<>
    void AsString_object::test<13>()
    {
        set_test_name("substring test");

        AsString_ref str1 = ASL("This is string");        

        bool succeed = true;
        succeed = succeed && str1->substring(5) == ASL("is string");
        succeed = succeed && str1->substring(5, 7) == ASL("is");
        succeed = succeed && str1->substring(7, 5) == ASL("is");
        ensure(succeed);
    }

    /*template<>
    template<>
    void AsString_object::test<2>()
    {
        set_test_name("Equality test 2");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is string");

        ensure("str2==str1", str2->isEqualToString(str1));
    }
    
    template<>
    template<>
    void AsString_object::test<3>()
    {
        set_test_name("Equality test 3");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is string!");
        
        ensure("str1!=str2", !str1->isEqualToString(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<4>()
    {
        set_test_name("Equality test 4");
        
        AsString* str1 = NSS("");
        AsString* str2 = NSS("");
        
        ensure("str1!=str2", str1->isEqualToString(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<5>()
    {
        set_test_name("Equality test 5");
        
        AsString* str1 = NSS("");
        AsString* str2 = nil;
        
        ensure("str1!=str2", !str1->isEqualToString(str2));
    } 
    
    template<>
    template<>
    void AsString_object::test<6>()
    {
        set_test_name("Length test");

        AsString* str1 = NSS("123456");
        AsString* str2 = NSS("123");
        AsString* str3 = NSS("");
        
        ensure(str1->length()==6 && str2->length()==3 && str3->length()==0);
    }
    
    template<>
    template<>
    void AsString_object::test<7>()
    {
        set_test_name("Range test 1");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS(" is s");
        
        NSRange range = str1->rangeOfString(str2);        
        ensure(range.location == 4 && range.length == 5);
    }
    
    template<>
    template<>
    void AsString_object::test<8>()
    {
        set_test_name("Range test 2");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is ");
        
        NSRange range = str1->rangeOfString(str2);        
        ensure(range.location == 0 && range.length == 8);
    }
    
    template<>
    template<>
    void AsString_object::test<9>()
    {
        set_test_name("Range test 3");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This!");
        
        NSRange range = str1->rangeOfString(str2);        
        ensure(range.location == NSNotFound && range.length == 0);
    }
    
    template<>
    template<>
    void AsString_object::test<10>()
    {
        set_test_name("Concat test");
        
        AsString* str1 = NSS("This");
        AsString* str2 = NSS(" is ");
        AsString* str3 = NSS("string");
        
        AsString* str4 = str1->stringByAppendingString(str2)->stringByAppendingString(str3);
        AsString* str5 = NSS("This is string");
        
        ensure(str5->isEqualToString(str4));
    }
    
    template<>
    template<>
    void AsString_object::test<11>()
    {
        set_test_name("Prefix test 1");

        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is ");
        
        ensure(str1->hasPrefix(str2));
    }

    template<>
    template<>
    void AsString_object::test<12>()
    {
        set_test_name("Prefix test 2");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is!");
        
        ensure(!str1->hasPrefix(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<13>()
    {
        set_test_name("Prefix test 3");
        
        AsString* str1 = NSS("This is ");
        AsString* str2 = NSS("This is string");
        
        ensure(!str1->hasPrefix(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<14>()
    {
        set_test_name("Suffix test 1");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("s string");        
        
        ensure(str1->hasSuffix(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<15>()
    {
        set_test_name("Suffix test 2");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("is string!");        
        
        ensure(!str1->hasSuffix(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<16>()
    {
        set_test_name("Suffix test 3");
        
        AsString* str1 = NSS("This is string");
        AsString* str2 = NSS("This is string!");        
        
        ensure(!str1->hasSuffix(str2));
    }
    
    template<>
    template<>
    void AsString_object::test<17>()
    {
        set_test_name("bool value test");

        bool result = NSS("1")->boolValue() &&
        NSS("-2")->boolValue() &&
        NSS("+2")->boolValue() &&
        !NSS("0")->boolValue() &&
        !NSS("00")->boolValue() &&
        !NSS("-0")->boolValue() &&
        NSS("123456")->boolValue() &&
        !NSS("0xff")->boolValue() &&
        !NSS("d")->boolValue() &&
        NSS("yes")->boolValue() &&
        NSS("Yes")->boolValue() &&
        NSS("YEs")->boolValue() &&
        NSS("YES")->boolValue() &&
        NSS("true")->boolValue() &&
        NSS("True")->boolValue() &&
        NSS("TRUE")->boolValue() &&        
        !NSS("")->boolValue() &&
        !NSS("foo")->boolValue();
        
        ensure(result);
    }
    
    template<>
    template<>
    void AsString_object::test<18>()
    {
        set_test_name("format test 1");
        
        char buf[128];
        sprintf(buf, "Test: int=%d float=%f str=%s", 10, 3.14, "This is string");
        
        AsString* str1 = AsString::stringWithFormat(NSS("Test: int=%d float=%f str=%@"), 10, 3.14, NSS("This is string"));
        AsString* str2 = AsString::alloc()->initWithAscii(buf);
        ensure(str2->isEqualToString(str1));
    }    

    template<>
    template<>
    void AsString_object::test<19>()
    {
        set_test_name("format test 2");

        char buf[128];
        sprintf(buf, "Test: int=%d float=%f str=%s", 10, 3.14, "This is string");

        AsString* str1 = AsString::stringWithFormat(NSL("Test: int=%d float=%f str=%@"), 10, 3.14, NSS("This is string"));
        AsString* str2 = AsString::alloc()->initWithAscii(buf);
        ensure(str2->isEqualToString(str1));
    }   

    template<>
    template<>
    void AsString_object::test<20>()
    {
        set_test_name("format test 3");

        // TODO
    }   

    template<>
    template<>
    void AsString_object::test<21>()
    {
        set_test_name("hash test 1");

        const wchar_t* cstr = NSL("This is string!");
        AsString* str = AsString::alloc()->initWithUnicode(cstr);

        ensure(str->hash() == AsString::hash(cstr));
    }

    template<>
    template<>
    void AsString_object::test<22>()
    {
        set_test_name("hash test 2");

        const wchar_t* cstr = NSL("");
        AsString* str = AsString::alloc()->initWithUnicode(cstr);

        ensure(str->hash() == AsString::hash(cstr));
    }
    */
}
