#ifndef AsString_h__
#define AsString_h__

#include "AsBc.h"

#include "AsObject.h"

AS_CLASS(AsArray);

typedef wchar_t achar;

class AsString_ref;

static const int TEMP_BUFFER_SIZE = 128;
static char tempBuf[TEMP_BUFFER_SIZE];

class AsString : public AsObject
{
private:    
    size_t m_size;
    size_t m_capacity;
    achar *m_buffer;

    static const uint INDEX_MAX = 0x7fffffff;

public:
    AS_TYPENAME(AsString, AsObject);

public:
    AsString_ref charAt(int i);
    int indexOf(const AsString_ref& s, int i = 0);	
    int lastIndexOf(const AsString_ref& s, int i = INDEX_MAX);	
    int length() const;
    AsString_ref replace(const AsString_ref& p, const AsString_ref& repl);
    AsString_ref slice(int start, int end = INDEX_MAX);	
    AsArray_ref split(const AsString_ref& delim);
    AsString_ref substr(int start, int len = INDEX_MAX);	
    AsString_ref substring(int start, int end = INDEX_MAX);	
    AsString_ref toLocaleLowerCase();
    AsString_ref toLocaleUpperCase();
    AsString_ref toLowerCase();
    AsString_ref toString();
    AsString_ref toUpperCase();
    AsString_ref valueOf();

    bool isEqualToString(const AsString& other) const;

public:
    AsString();
    AsString(const char* str, size_t len = -1);
    AsString(const achar* str, size_t len = -1);
    AsString(const AsString& other);

    ~AsString();

public:
    inline AsString& operator+= (const AsString& other) { append(other); return *this; }
    inline AsString& operator+= (const achar* str) { append(str); return *this; }

private:
    friend class AsString_ref;

    void init(size_t len, size_t capacity);
    void init(size_t len) { init (len, len + 1); }
    void resize(size_t cap);
    void append(const achar* str, size_t len = -1);
    void append(const char* str, size_t len = -1);
    void append(const AsString& other);
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
    AsString_ref(const char* str) : AsObjectRef(new AsString(str)) {}

public:
    inline bool operator== (const AsString_ref& other) const { return m_object && other.m_object && (*this)->isEqualToString(**other) || !m_object && !other.m_object; }
    inline bool operator!= (const AsString_ref& other) const { return !(this->operator==(other)); }

    inline AsString_ref& operator+= (const achar* str)
    {
        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(str);
        set(newStr);

        return *this; 
    }

    inline AsString_ref& operator+= (const char* str)
    {
        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(str);
        set(newStr);

        return *this; 
    }

    inline AsString_ref& operator+= (const AsString_ref& other) 
    {         
        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(**other);
        set(newStr);

        return *this; 
    }

    inline AsString_ref& operator+= (int val) 
    {
        sprintf(tempBuf, "%d", val);

        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(tempBuf);
        set(newStr);

        return *this; 
    }

    inline AsString_ref& operator+= (float val) 
    {
        sprintf(tempBuf, "%g", val);

        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(tempBuf);
        set(newStr);

        return *this; 
    }

    inline AsString_ref& operator+= (bool val) 
    {
        sprintf(tempBuf, "%s", val ? "true" : "false");

        AsString* oldStr = (AsString*)m_object;
        AsString* newStr = new AsString(*oldStr);       

        newStr->append(tempBuf);
        set(newStr);

        return *this; 
    }
};

inline AsString_ref operator+ (const AsString_ref& a, const AsString_ref& b)
{
    AsString_ref str(new AsString(**a));
    str += b;
    return str;
}

inline AsString_ref operator+ (const AsString_ref& a, const achar* b)
{
    AsString_ref str(new AsString(**a));
    str += b;
    return str;
}

inline AsString_ref operator+ (const achar* a, const AsString_ref& b)
{
    AsString_ref str(new AsString(a));
    str += b;
    return str;
}

inline AsString_ref operator+ (const AsString_ref& a, int val)
{
    AsString_ref str(new AsString(**a));
    str += val;
    return str;
}

inline AsString_ref operator+ (int val, const AsString_ref& a)
{
    sprintf(tempBuf, "%d", val);

    AsString_ref str(new AsString(tempBuf));
    str += a;
    return str;
}

inline AsString_ref operator+ (const AsString_ref& a, float val)
{
    AsString_ref str(new AsString(**a));
    str += val;
    return str;
}

inline AsString_ref operator+ (float val, const AsString_ref& a)
{
    sprintf(tempBuf, "%g", val);

    AsString_ref str(new AsString(tempBuf));
    str += a;
    return str;
}

inline AsString_ref operator+ (const AsString_ref& a, bool val)
{
    AsString_ref str(new AsString(**a));
    str += val;
    return str;
}

inline AsString_ref operator+ (bool val, const AsString_ref& a)
{
    sprintf(tempBuf, "%s", val ? "true" : "false");

    AsString_ref str(new AsString(tempBuf));
    str += a;
    return str;
}

inline AsString_ref operator+ (const AsString_ref& a, const AsObject_ref& obj)
{
    AsString_ref str(new AsString(**a));
    str += obj->toString();
    return str;
}

inline AsString_ref operator+ (const AsObject_ref& obj, const AsString_ref& a)
{
    AsString_ref str = obj->toString();
    str += a;
    return str;
}

#endif // AsString_h__
