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

    template<>
    template<>
    void AsMath_object::test<8>()
    {
        set_test_name("exp test");

        bool succeed = true;
        succeed = succeed && AsMath::exp(0) == 1.0f;
        succeed = succeed && AsMath::exp(1) == AsMath::E;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<9>()
    {
        set_test_name("floor test");

        bool succeed = true;
        succeed = succeed && AsMath::floor(1.0f) == 1.0f;
        succeed = succeed && AsMath::floor(1.1f) == 1.0f;
        succeed = succeed && AsMath::floor(1.5f) == 1.0f;

        succeed = succeed && AsMath::floor(-1.0f) == -1.0f;
        succeed = succeed && AsMath::floor(-1.1f) == -2.0f;
        succeed = succeed && AsMath::floor(-1.5f) == -2.0f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<10>()
    {
        set_test_name("log test");

        bool succeed = true;
        succeed = succeed && abs(AsMath::log(AsMath::E) - 1) < 0.00001f;
        succeed = succeed && abs(AsMath::log(2) - 0.6931471805599453f) < 0.00001f;
        succeed = succeed && abs(AsMath::log(10) - 2.302585092994046f) < 0.00001f;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<11>()
    {
        set_test_name("max test");

        bool succeed = true;
        succeed = succeed && AsMath::max(1, 0) == 1;
        succeed = succeed && AsMath::max(0, 0) == 0;
        succeed = succeed && AsMath::max(0, 1) == 1;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<12>()
    {
        set_test_name("min test");

        bool succeed = true;
        succeed = succeed && AsMath::min(1, 0) == 0;
        succeed = succeed && AsMath::min(0, 0) == 0;
        succeed = succeed && AsMath::min(0, 1) == 0;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<13>()
    {
        set_test_name("pow test");

        bool succeed = true; 
        succeed = succeed && AsMath::pow(2, 2) == 4;
        succeed = succeed && AsMath::pow(2, -1) == 0.5;        

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<14>()
    {
        set_test_name("random test");

        bool succeed = true; 
        succeed = succeed && AsMath::random() >= 0.0f && AsMath::random() <= 1.0f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<15>()
    {
        set_test_name("round test");

        bool succeed = true; 
        succeed = succeed && AsMath::round(1.1f) == 1;
        succeed = succeed && AsMath::round(1.5f) == 2;
        succeed = succeed && AsMath::round(1.6f) == 2;

        succeed = succeed && AsMath::round(-1.1f) == -1;
        succeed = succeed && AsMath::round(-1.5f) == -1;
        succeed = succeed && AsMath::round(-1.6f) == -2;

        ensure(succeed);
    }    

    template<>
    template<>
    void AsMath_object::test<16>()
    {
        set_test_name("sin test");

        bool succeed = true;
        succeed = succeed && AsMath::sin(0.0f) == 0.0f;
        succeed = succeed && abs(AsMath::sin(0.5f * AsMath::PI) - 1) < 0.00001f;
        succeed = succeed && abs(AsMath::sin(AsMath::PI)) < 0.00001f;
        succeed = succeed && abs(AsMath::sin(1.5f * AsMath::PI) + 1) < 0.00001f;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<17>()
    {
        set_test_name("sqrt test");

        bool succeed = true;
        succeed = succeed && AsMath::sqrt(4) == 2;
        succeed = succeed && AsMath::sqrt(0.25) == 0.5;

        ensure(succeed);
    }

    template<>
    template<>
    void AsMath_object::test<18>()
    {
        set_test_name("tan test");

        bool succeed = true;
        succeed = succeed && abs(AsMath::tan(0)) < 0.00001f;
        succeed = succeed && abs(AsMath::tan(0.25f * AsMath::PI) - 1.0f) < 0.00001f;
        succeed = succeed && abs(AsMath::tan(0.75f * AsMath::PI) + 1.0f) < 0.00001f;
        succeed = succeed && abs(AsMath::tan(AsMath::PI)) < 0.00001f;

        ensure(succeed);
    }    
}