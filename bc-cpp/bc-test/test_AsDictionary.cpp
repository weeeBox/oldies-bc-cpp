#include "tut.hpp"

#include "AsDictionary.h"

namespace tut 
{   
    struct AsDictionary_data
    { 
    };

    typedef test_group<AsDictionary_data> AsDictionary_test_group;
    typedef AsDictionary_test_group::object AsDictionary_object;
    AsDictionary_test_group AsDictionaryTestGroup("AsDictionary tests");    

    template<>
    template<>
    void AsDictionary_object::test<1>()
    {
        set_test_name("Length test 1");
        
        AsDictionary_ref dict = AS_NEW(AsDictionary,());
        bool succeed = dict->length() == 0;

        ensure(succeed);
    }

    template<>
    template<>
    void AsDictionary_object::test<2>()
    {
        set_test_name("Length test 2");

        AsDictionary_ref dict = AS_NEW(AsDictionary,());
        dict->_as_put(ASL("key"), ASL("value"));
        dict->_as_put(ASL("key"), ASL("value"));

        bool succeed = dict->length() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsDictionary_object::test<3>()
    {
        set_test_name("Remove test 1");

        AsDictionary_ref dict = AS_NEW(AsDictionary,());
        dict->_as_put(ASL("key"), ASL("value"));
        dict->_as_put(ASL("key"), ASL("value"));

        bool succeed = dict->length() == 1;

        dict->remove(ASL("key"));
        succeed = succeed && dict->length() == 0;

        dict->remove(ASL("key"));
        succeed = succeed && dict->length() == 0;

        ensure(succeed);
    }

    template<>
    template<>
    void AsDictionary_object::test<4>()
    {
        set_test_name("Remove test 2");

        AsDictionary_ref dict = AS_NEW(AsDictionary,());
        dict->_as_put(ASL("key-1"), ASL("value"));
        dict->_as_put(ASL("key-2"), ASL("value"));

        bool succeed = dict->length() == 2;

        dict->remove(ASL("key-1"));
        succeed = succeed && dict->length() == 1;

        dict->remove(ASL("key"));
        succeed = succeed && dict->length() == 1;

        ensure(succeed);
    }

    template<>
    template<>
    void AsDictionary_object::test<5>()
    {
        set_test_name("Lookup test 3");

        AsString_ref key1 = ASL("1");
        AsString_ref key2 = ASL("2");
        AsString_ref key3 = ASL("3");
        AsString_ref key4 = ASL("4");
        AsString_ref key5 = ASL("5");

        AsObject_ref val1 = AS_NEW(AsObject,());
        AsObject_ref val2 = AS_NEW(AsObject,());
        AsObject_ref val3 = AS_NEW(AsObject,());
        AsObject_ref val4 = AS_NEW(AsObject,());
        AsObject_ref val5 = AS_NEW(AsObject,());

        AsDictionary_ref dict = AS_NEW(AsDictionary,());
        dict->_as_put(key1, val1);
        dict->_as_put(key2, val2);
        dict->_as_put(key3, val3);
        dict->_as_put(key4, val4);
        dict->_as_put(key5, val5);

        bool succeed = dict->length() == 5;

        succeed = succeed && key1->retainCount() == 2;
        succeed = succeed && key2->retainCount() == 2;
        succeed = succeed && key3->retainCount() == 2;
        succeed = succeed && key4->retainCount() == 2;
        succeed = succeed && key5->retainCount() == 2;

        succeed = succeed && val1->retainCount() == 2;
        succeed = succeed && val2->retainCount() == 2;
        succeed = succeed && val3->retainCount() == 2;
        succeed = succeed && val4->retainCount() == 2;
        succeed = succeed && val5->retainCount() == 2;

        succeed = succeed && dict->_as_get(key1) == val1;
        succeed = succeed && dict->_as_get(key2) == val2;
        succeed = succeed && dict->_as_get(key3) == val3;
        succeed = succeed && dict->_as_get(key4) == val4;
        succeed = succeed && dict->_as_get(key5) == val5;

        dict->remove(key1);
        dict->remove(key2);
        dict->remove(key3);
        dict->remove(key4);
        dict->remove(key5);

        succeed = succeed && dict->length() == 0;

        succeed = succeed && key1->retainCount() == 1;
        succeed = succeed && key2->retainCount() == 1;
        succeed = succeed && key3->retainCount() == 1;
        succeed = succeed && key4->retainCount() == 1;
        succeed = succeed && key5->retainCount() == 1;

        succeed = succeed && val1->retainCount() == 1;
        succeed = succeed && val2->retainCount() == 1;
        succeed = succeed && val3->retainCount() == 1;
        succeed = succeed && val4->retainCount() == 1;
        succeed = succeed && val5->retainCount() == 1;

        ensure(succeed);
    }
}