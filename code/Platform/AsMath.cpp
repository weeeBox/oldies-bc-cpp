#include "AsMath.h"
#include "AsMath.h"
 
 
float AsMath::abs(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::acos(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::asin(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::atan(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::atan2(float y, float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::ceil(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::cos(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::exp(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::floor(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::log(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::max(float x, float y)
{
	throw new AsNotImplementedError();
}
 
float AsMath::min(float x, float y)
{
	throw new AsNotImplementedError();
}
 
float AsMath::pow(float x, float y)
{
	throw new AsNotImplementedError();
}
 
float AsMath::random()
{
	throw new AsNotImplementedError();
}
 
float AsMath::round(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::sin(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::sqrt(float x)
{
	throw new AsNotImplementedError();
}
 
float AsMath::tan(float x)
{
	throw new AsNotImplementedError();
}
 
AsMath_ref AsMath::__createAsMath()
{
	AsMath_ref __reference(new AsMath());
	return __reference;
}
 
void AsMath::__internalInitialiseAsMath()
{
}
 
StaticInit AsMath::__internalStaticInitializerAsMath(&AsMath::__internalStaticInit);
BOOL AsMath::__internalStaticInitializedAsMath = false;
 
void AsMath::__internalStaticInit()
{
	if (!__internalStaticInitializedAsMath)
	{
		__internalStaticInitializedAsMath = true;
		AsObject::__internalStaticInit();
	}
}
 
AsMath::AsMath()
{
}
 
