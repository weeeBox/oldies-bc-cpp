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
        set_test_name("Remove test");

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
}