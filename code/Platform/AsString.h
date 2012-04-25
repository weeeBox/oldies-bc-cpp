#ifndef AsString_h__
#define AsString_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsArray);
 
typedef wchar_t achar;

class AsString_ref;

class AsString : public AsObject
{
private:    
    size_t m_size;
    size_t m_capacity;
    achar *m_buffer;

    static const uint INDEX_MAX = 0x7fffffff;

public:
	AS_OBJ(AsString, AsObject);
	
public:
	AsString_ref charAt(uint i);
	int indexOf(const AsString_ref& s, uint i = 0);	
	int lastIndexOf(const AsString_ref& s, uint i = INDEX_MAX);	
	int length();
	AsString_ref replace(const AsString_ref& p, const AsString_ref& repl);
	AsString_ref slice(uint start, uint end = INDEX_MAX);	
	AsArray_ref split(const AsString_ref& delim);
	AsString_ref substr(uint start, uint len = INDEX_MAX);	
	AsString_ref substring(uint start, uint end = INDEX_MAX);	
	AsString_ref toLocaleLowerCase();
	AsString_ref toLocaleUpperCase();
	AsString_ref toLowerCase();
	AsString_ref toString();
	AsString_ref toUpperCase();
	AsString_ref valueOf();

    bool isEqualToString(const AsString& other) const;    
	
public:
	AsString();
    AsString(const achar* str);
    AsString(const achar* str, size_t len);

    ~AsString();

private:
    void init(size_t len, size_t capacity);
    void init(size_t len) { init (len, len + 1); }
    void reserve(size_t cap);
    void append(const achar* str, size_t len);    
};

inline bool operator== (const AsString& a, const AsString& b) { return a.isEqualToString(b); }
inline bool operator!= (const AsString& a, const AsString& b) { return !a.isEqualToString(b); }

class AsString_ref : public AsObjectRef<AsString>
{
public:
    AsString_ref() : AsObjectRef() {}
    AsString_ref(const AsObjectRefBase& other) : AsObjectRef(other) {}
    AsString_ref(AsString* obj) : AsObjectRef(obj) {}    
    explicit AsString_ref(bool isStatic) : AsObjectRef(isStatic) {}    

    AsString_ref(const achar* str) : AsObjectRef(new AsString(str)) {}

public:
    inline bool operator== (const AsString_ref& other) const { return m_object && other.m_object && (*this)->isEqualToString(**other) || !m_object && !other.m_object; }
    inline bool operator!= (const AsString_ref& other) const { return !(this->operator==(other)); }
};

#endif // AsString_h__
