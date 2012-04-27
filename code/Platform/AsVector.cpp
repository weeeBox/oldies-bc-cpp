#include "AsVector.h"

AsVector_ref AsVector::concat(const AsObject_ref& obj)
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsVector_ref AsVector::concat()
{
	return concat(AS_NULL);
}
 
int AsVector::length()
{
	IMPLEMENT_ME;
    return -1;
}
 
void AsVector::length(int newLenght)
{
	IMPLEMENT_ME;
}
 
int AsVector::indexOf(const AsObject_ref& searchElement, int fromIndex)
{
	IMPLEMENT_ME;
    return -1;
}
 
int AsVector::indexOf(const AsObject_ref& searchElement)
{
	IMPLEMENT_ME;
    return -1;
}
 
AsString_ref AsVector::_join(const AsString_ref& sep)
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsVector::_join()
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
int AsVector::lastIndexOf(const AsObject_ref& searchElement, int fromIndex)
{
	IMPLEMENT_ME;
    return -1;
}
 
int AsVector::lastIndexOf(const AsObject_ref& searchElement)
{
	IMPLEMENT_ME;
    return -1;
}
 
AsObject_ref AsVector::pop()
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
int AsVector::push(const AsObject_ref& arg)
{
	IMPLEMENT_ME;
    return -1;
}
 
AsVector_ref AsVector::reverse()
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsVector_ref AsVector::slice(int startIndex, int endIndex)
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsVector_ref AsVector::slice(int startIndex)
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsVector_ref AsVector::slice()
{
	IMPLEMENT_ME;
    return AS_NULL;
}

/*
AsVector_ref AsVector::sort(const AsFunction_ref& compareFunction)
{
	IMPLEMENT_ME;
}
*/
 
AsVector_ref AsVector::splice(int startIndex, int deleteCount, const AsObject_ref& item)
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
AsVector_ref AsVector::splice(int startIndex, int deleteCount)
{
    IMPLEMENT_ME;
	return AS_NULL;
}
 
AsString_ref AsVector::toString()
{
	IMPLEMENT_ME;
    return AS_NULL;
}
 
int AsVector::unshift(const AsObject_ref& arg)
{
	IMPLEMENT_ME;
    return -1;
}
 
AsVector::AsVector()
{
}
 
