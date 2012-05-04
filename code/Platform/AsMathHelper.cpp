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
 
bool AsMathHelper::_as_static_initialized_AsMathHelper = false;
void AsMathHelper::_as_static_init_AsMathHelper()
{
	if (!_as_static_initialized_AsMathHelper)
	{
		_as_static_initialized_AsMathHelper = true;
	}
}
