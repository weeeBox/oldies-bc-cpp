#include "AsDictionary.h"

inline static int indexForHash(int hash, int size)
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
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        Pair* pair = table[i];
        while (pair)
        {
            Pair* next = pair->next;
            delete pair;
            pair = next;
        }        
    }
}

void AsDictionary::_as_put(const AsString_ref& key, const AsObject_ref& value)
{
    Pair* pair = find(key);
    if (pair)
    {
        pair->value = value;
    }
    else
    {
        pair = new Pair();
        pair->key = key;
        pair->value = value;

        add(pair);
    }
}

void AsDictionary::_as_put(const AsString_ref& key, const achar* value)
{
    _as_put(key, AsString_ref(value));
}

AsObject_ref AsDictionary::_as_get(const AsString_ref& key)
{
    Pair* pair = find(key);
    if (pair)
    {
        return pair->value;
    }
    return AS_NULL;
}

void AsDictionary::remove(const AsString_ref& key)
{
    Pair* pair = find(key);
    if (pair)
    {
        remove(pair);
    }
}

AsDictionary::Pair* AsDictionary::find(const AsString_ref& key)
{
    int hash = key->hashCode();
    int index = indexForHash(hash, TABLE_SIZE);

    Pair* pair = table[index];
    while (pair)
    {
        if (hash == pair->key->hashCode() && pair->key->isEqualToString(key))
        {
            return pair;
        }

        pair = pair->next;
    }

    return NULL;
}

void AsDictionary::add(Pair* pair)
{
    int hash = pair->key->hashCode();
    int index = indexForHash(hash, TABLE_SIZE);

    Pair* last = table[index];
    if (last) last->prev = pair;
    pair->next = last;    

    table[index] = pair;

    ++m_size;
}

void AsDictionary::remove(Pair* pair)
{
    Pair* next = pair->next;
    Pair* prev = pair->prev;

    if (next) 
        next->prev = prev;

    if (prev) 
        prev->next = next;
    else 
    {
        int hash = pair->key->hashCode();
        int index = indexForHash(hash, TABLE_SIZE);
        table[index] = next;
    }    

    delete pair;
    --m_size;
}