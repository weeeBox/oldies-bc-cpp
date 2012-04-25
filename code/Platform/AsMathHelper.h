#ifndef AsMathHelper_h__
#define AsMathHelper_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsMathHelper);
 
class AsMathHelper : public AsObject
{
public:
	AS_OBJ(AsMathHelper, AsObject);
	
private:
	static const float epsilon = 0.00001f;
	
public:
	static const float MAX_NUMBER = 0x7fffffff;
	
public:
	static float toRadians(float degrees);
	static float toDegrees(float radians);
	static bool epsilonZero(float a);
	static bool epsilonEquals(float a, float b);
	
	
	
protected:
	AsMathHelper();
};
 
#endif // AsMathHelper_h__
