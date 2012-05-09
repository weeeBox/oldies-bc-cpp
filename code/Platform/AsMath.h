#ifndef AsMath_h__
#define AsMath_h__

#include "AsBc.h"
#include <math.h>

class AsMath
{
public:
    static const float E;
    static const float LN10;
    static const float LN2;
    static const float LOG10E;
    static const float LOG2E;
    static const float PI;
    static const float SQRT1_2;
    static const float SQRT2;

public:
    inline static float abs(float x) { return ::abs(x); }
    inline static float acos(float x) { return ::acos(x); }
    inline static float asin(float x) { return ::asin(x); }
    inline static float atan(float x) { return ::atan(x); }
    inline static float atan2(float y, float x) { return ::atan2(y, x); }
    inline static float ceil(float x) { return ::ceil(x); }
    inline static float cos(float x) { return ::cos(x); }
    inline static float exp(float x) { return ::exp(x); }
    inline static float floor(float x) { return ::floor(x); }
    inline static float log(float x) { return ::log(x); }
    inline static float max(float x, float y) { return x > y ? x : y; }
    inline static float min(float x, float y) { return x < y ? x : y; }
    inline static float pow(float x, float y) { return ::pow(x, y); }
    inline static float random() { return rand() * RAND_MAX_INV; }
    inline static float round(float x) 
    { 
        int trunc = int(x);
        float diff = x - trunc; 
        if (diff >= 0.5f) 
            return trunc + 1.0f;
        if (diff < -0.5f)
            return trunc - 1.0f;

        return float(trunc);
    }
    inline static float sin(float x) { return ::sin(x); }
    inline static float sqrt(float x) { return ::sqrt(x); }
    inline static float tan(float x) { return ::tan(x); }

private:
    static const float RAND_MAX_INV;
};

#endif // AsMath_h__
