#include "AsMathHelper.h"
#include "AsMath.h"
 
const float AsMathHelper::epsilon = 0.00001f;
const float AsMathHelper::MAX_NUMBER = 0x7fffffff;
 
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
 
bool AsMathHelper::_as_static_initialized_AsMathHelper = false;
AsStaticRefInitializer AsMathHelper::_as_static_initializer_AsMathHelper(_as_static_init_AsMathHelper);
void AsMathHelper::_as_static_init_AsMathHelper()
{
	if (!_as_static_initialized_AsMathHelper)
	{
		_as_static_initialized_AsMathHelper = true;
	}
}
