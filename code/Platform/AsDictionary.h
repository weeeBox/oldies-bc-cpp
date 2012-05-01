#ifndef AsDictionary_h__
#define AsDictionary_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
#include "AsString.h"
 
AS_CLASS(AsDictionary);
 
class AsDictionary : public AsObject
{
public:
    AS_TYPENAME(AsDictionary, AsObject);

public:
    // we can't use operator[] for setting/getting the elements    
    void _as_put(const AsString_ref& key, const AsObject_ref& value);
    void _as_put(const AsString_ref& key, const achar* value);

    AsObject_ref _as_get(const AsString_ref& key);
    void remove(const AsString_ref& key);
    inline int length() { return m_size; }

protected:
    AsDictionary();

public:
    inline static AsDictionary_ref _as_create_AsDictionary() { return AsDictionary_ref(new AsDictionary()); }
    ~AsDictionary();

private:
    static const int TABLE_SIZE = 16;

    struct Pair
    {
        AsString_ref key;
        AsObject_ref value;
        
        Pair() : next(0), prev(0) {}

        Pair* next;
        Pair* prev;
    };
    
    Pair* table[TABLE_SIZE];
    int m_size;
    
    Pair* find(const AsString_ref& key);
    void add(Pair* pair);
    void remove(Pair* pair);    
};
 
#endif // AsDictionary_h__
