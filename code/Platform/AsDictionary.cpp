#include "AsDictionary.h"

inline static int indexFor(int hash, int size)
{
    return (hash & size - 1);
}

AsDictionary::AsDictionary() :    
    m_size(0)
{
    memset(table, 0, sizeof(table));
}

AsDictionary::~AsDictionary()
{

}

void AsDictionary::_as_put(const AsString_ref& key, const AsObject_ref& value)
{
    IMPLEMENT_ME;
}

void AsDictionary::_as_put(const achar* key, const AsObject_ref& value)
{
    IMPLEMENT_ME;
}

AsObject_ref AsDictionary::_as_get(const AsString_ref& key)
{
    IMPLEMENT_ME;
    return AS_NULL;
}

AsObject_ref AsDictionary::_as_get(const achar* key)
{
    IMPLEMENT_ME;
    return AS_NULL;
}

void AsDictionary::remove(const AsString_ref& key)
{
    IMPLEMENT_ME;
}

void AsDictionary::remove(const achar* key)
{
    IMPLEMENT_ME;
}

/*
void AsDictionary::add(Pair* pair)
{

}

void AsDictionary::remove(Pair* pair)
{

}

AsDictionary::Pair* AsDictionary::find(const AsString_ref& key)
{

}
*/