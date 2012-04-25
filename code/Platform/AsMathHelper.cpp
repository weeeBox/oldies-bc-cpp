#include "AsMathHelper.h"
#include "AsMathHelper.h"
 
 
float AsMathHelper::toRadians(float degrees)
{
	return (0.0174532925199433f * degrees);
}
 
float AsMathHelper::toDegrees(float radians)
{
	return (57.2957795130823209f * radians);
}
 
bool AsMathHelper::epsilonZero(float a)
{
	return (AsMath::abs(a) < epsilon);
}
 
bool AsMathHelper::epsilonEquals(float a, float b)
{
	return (AsMath::abs((a - b)) < epsilon);
}
 
AsMathHelper::AsMathHelper()
{
}
 
AS_STATIC_INIT_BEGIN(AsMathHelper,AsObject)
AS_STATIC_INIT_END
