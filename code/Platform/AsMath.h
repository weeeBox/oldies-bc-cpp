#ifndef AsMath_h__
#define AsMath_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsMath)
 
class AsMath : public AsObject
{
public:
	ASOBJ(AsMath, AsObject);
	
public:
	static const float E = 2.718281828459045f;
	static const float LN10 = 2.302585092994046f;
	static const float LN2 = 0.6931471805599453f;
	static const float LOG10E = 0.4342944819032518f;
	static const float LOG2E = 1.4426950408889634f;
	static const float PI = 3.141592653589793f;
	static const float SQRT1_2 = 0.7071067811865476f;
	static const float SQRT2 = 1.4142135623730951f;
	
public:
	static float abs(float x);
	static float acos(float x);
	static float asin(float x);
	static float atan(float x);
	static float atan2(float y, float x);
	static float ceil(float x);
	static float cos(float x);
	static float exp(float x);
	static float floor(float x);
	static float log(float x);
	static float max(float x, float y);
	static float min(float x, float y);
	static float pow(float x, float y);
	static float random();
	static float round(float x);
	static float sin(float x);
	static float sqrt(float x);
	static float tan(float x);
	
public:
	static AsMath_ref __createAsMath();
	void __internalInitialiseAsMath();
	
private:
	static StaticInit __internalStaticInitializerAsMath;
	static BOOL __internalStaticInitializedAsMath;
	
public:
	static void __internalStaticInit();
	
protected:
	AsMath();
};
 
#endif // AsMath_h__
