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
	static const float epsilon;
	
public:
	static const float MAX_NUMBER;
	
public:
	static float toRadians(float degrees);
	static float toDegrees(float radians);
	static bool epsilonZero(float a);
	static bool epsilonEquals(float a, float b);
	
	static void _as_static_init_AsMathHelper();
	
private:
	static bool _as_static_initialized_AsMathHelper;
	static AsStaticRefInitializer _as_static_initializer_AsMathHelper;
};
 
#endif // AsMathHelper_h__
