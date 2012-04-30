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

    // we can't use operator[] for setting/getting the elements
    void _as_put(const achar* key, const AsObject_ref& value);
    inline void _as_put(const AsString_ref& key, const AsObject_ref& value) { _as_put(key->data(), value); }

    AsObject_ref _as_get(const achar* key);
    inline AsObject_ref _as_get(const AsString_ref& key) { return _as_get(key->data()); }
        
    void remove(const achar* key);
    inline void remove(const AsString_ref& key) { remove(key->data()); }

protected:
    AsDictionary();

public:
    ~AsDictionary();

private:
    static const int TABLE_SIZE = 16;

    struct Pair
    {
        AsString_ref key;
        AsObject_ref value;

        Pair* next;
        Pair* prev;
    };
    
    Pair* table[TABLE_SIZE];
    int m_size;

    /*
    Pair* add(const AsString_ref& key, const AsObject_ref& value);
    void remove(const AsString_ref& key);
    Pair* find(const AsString_ref& key);
    */
    
};
 
#endif // AsDictionary_h__
