#include "tut.hpp"

#include "AsMath.h"

namespace tut 
{   
    struct AsMath_data
    { 
    };

    typedef test_group<AsMath_data> AsMath_test_group;
    typedef AsMath_test_group::object AsMath_object;
    AsMath_test_group AsMathTestGroup("AsMath tests");    

    template<>
    template<>
    void AsMath_object::test<1>()
    {
        set_test_name("abs test");

        bool succeed = true;
        succeed = succeed && AsMath::abs(-1) == 1;
        succeed = succeed && AsMath::abs(1) == 1;
        succeed = succeed && AsMath::abs(0) == 0;

        ensure(succeed);
    }    

    template<>
    template<>
    void AsMath_object::test<2>()
    {
        set_test_name("acos test");
        
        bool succeed = true;
        succeed = succeed && AsMath::acos(0.0) == 1.5707963267948966f;
        succeed = succeed && AsMath::acos(0.5) == 1.0471975511965976f;
        succeed = succeed && AsMath::acos(1.0) == 0;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<3>()
    {
        set_test_name("asin test");

        bool succeed = true;
        succeed = succeed && AsMath::asin(0.0) == 0;
        succeed = succeed && AsMath::asin(0.5) == 0.5235987755982989f;
        succeed = succeed && AsMath::asin(1.0) == 1.5707963267948966f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<4>()
    {
        set_test_name("atan test");

        bool succeed = true;
        succeed = succeed && AsMath::atan(0.0) == 0;        
        succeed = succeed && AsMath::atan(1.0) == 0.7853981633974483f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<5>()
    {
        set_test_name("atan test");

        bool succeed = true;
        succeed = succeed && AsMath::atan2(0, 1) == 0;
        succeed = succeed && AsMath::atan2(1, 0) == 1.5707963267948966f;
        succeed = succeed && AsMath::atan2(1, 1) == 0.7853981633974483f;
        succeed = succeed && AsMath::atan2(2, 1) == 1.1071487177940904f;
        succeed = succeed && AsMath::atan2(1, 2) == 0.4636476090008061f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<6>()
    {
        set_test_name("ceil test");

        bool succeed = true;
        succeed = succeed && AsMath::ceil(1.0f) == 1.0f;
        succeed = succeed && AsMath::ceil(1.1f) == 2.0f;
        succeed = succeed && AsMath::ceil(1.5f) == 2.0f;

        succeed = succeed && AsMath::ceil(-1.0f) == -1.0f;
        succeed = succeed && AsMath::ceil(-1.1f) == -1.0f;
        succeed = succeed && AsMath::ceil(-1.5f) == -1.0f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<7>()
    {
        set_test_name("cos test");

        bool succeed = true;
        succeed = succeed && AsMath::cos(0.0f) == 1.0f;
        succeed = succeed && abs(AsMath::cos(0.5f * AsMath::PI)) < 0.00001f;
        succeed = succeed && AsMath::cos(AsMath::PI) == -1.0f;
        succeed = succeed && abs(AsMath::cos(1.5f * AsMath::PI)) < 0.00001f;

        ensure(succeed);
    }

    /*    
    inline static float exp(float x) { return ::exp(x); }
    inline static float floor(float x) { return ::floor(x); }
    inline static float log(float x) { return ::log(x); }
    inline static float max(float x, float y) { return x > y ? x : y; }
    inline static float min(float x, float y) { return x < y ? x : y; }
    inline static float pow(float x, float y) { return ::pow(x, y); }
    inline static float random() { return rand(); }
    inline static float round(float x) { return (x - int(x) < 0.5f) ? x : (x + 1); }
    inline static float sin(float x) { return ::sin(x); }
    inline static float sqrt(float x) { return ::sqrt(x); }
    inline static float tan(float x) { return ::tan(x); }
    */
}