#include "AsArray.h"
 
int AsArray::indexOf(const AsObject_ref& searchElement, uint fromIndex)
{    
    IMPLEMENT_ME;
	return -1;
}
 
int AsArray::indexOf(const AsObject_ref& searchElement)
{
	return indexOf((AsObject_ref)(searchElement), (uint)(0));
}
 
int AsArray::lastIndexOf(const AsObject_ref& searchElement, uint fromIndex)
{
    IMPLEMENT_ME;
    return -1;
}
 
int AsArray::lastIndexOf(const AsObject_ref& searchElement)
{
	return lastIndexOf((AsObject_ref)(searchElement), (uint)(2147483647));
}
 
uint AsArray::length()
{
    IMPLEMENT_ME;
    return -1;
}
 
void AsArray::length(uint newLength)
{
    IMPLEMENT_ME;    
}
 
AsObject_ref AsArray::pop()
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
uint AsArray::push(const AsObject_ref& arg)
{
    IMPLEMENT_ME;
    return -1;
}
 
AsArray::AsArray()
{
}
 
AS_STATIC_INIT_BEGIN(AsArray,AsObject)
AS_STATIC_INIT_END
