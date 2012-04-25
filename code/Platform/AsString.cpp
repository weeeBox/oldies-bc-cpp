#include "AsString.h"

#include "AsArray.h"

static size_t wide_len(const achar* str)
{
    const achar *p = str;
    while (*p) 
        ++p;
    return p - str;
}

static const achar* wide_find(const achar* from, const achar* what)
{
    while (*from)
    {
        const achar* f = from;
        const achar* w = what;

        while (*w && *f == *w)
        {
            w++;
            f++;
        }

        if (!*w)
            return from;
        from++;
    }

    return 0;
}

static bool wide_equals(const wchar_t* str1, const wchar_t* str2)
{
    wchar_t c1 = *str1;
    wchar_t c2 = *str2;
    while (c1 || c2)
    {
        if (c1 != c2)
            return false;

        str1++;
        str2++;

        c1 = *str1;
        c2 = *str2;
    }

    if (c1 == 0 && c2 == 0)
        return true;

    return false;
}

AsString_ref AsString::charAt(uint index)
{
    if (index >= 0 && index < length())
    {
        achar chr = m_buffer[index];
        return AsString_ref(new AsString(&chr, 1));
    }
    
    return AsString_ref(new AsString(ASL(""), 1));
}
 
int AsString::indexOf(const AsString_ref& s, uint startIndex)
{
    ASSERT(startIndex >= 0 && startIndex < length());
    const achar* ptr = wide_find(m_buffer + startIndex, s->m_buffer);

    return ptr ? (ptr - m_buffer) : -1;
}
 
int AsString::lastIndexOf(const AsString_ref& s, uint i)
{    
    return -1;
}
 
int AsString::length()
{
    return m_size;
}
 
AsString_ref AsString::replace(const AsString_ref& p, const AsString_ref& repl)
{
    const achar* pStart = wide_find(m_buffer, p->m_buffer);    
    if (!pStart)
    {
        return AsString_ref(this);
    }

    int diff = repl->length() - p->length();    
    size_t newLen = length() + diff;

    achar* newBuf = (achar*)malloc(newLen * sizeof(achar));
    achar* from = m_buffer;
    achar* to = newBuf;

    size_t lenA = pStart - m_buffer;
    size_t lenB = length() - (lenA + p->length());

    memcpy(to, from, lenA * sizeof(achar));
    from += lenA;
    to += lenA;    

    memcpy(to, repl->m_buffer, repl->length() * sizeof(achar));
    from += p->length();
    to += repl->length();    

    memcpy(to, from, lenB * sizeof(achar));

    AsString_ref str = AsString_ref(new AsString(newBuf, newLen));
    free(newBuf);

    return str;
}
 
AsString_ref AsString::slice(uint start, uint end)
{
    if (end == INDEX_MAX)
        end = length();

    ASSERT(start >= 0 && start < length());
    ASSERT(end >= 0 && end <= length());

    int count = end - start;
    if (count > 0)
    {
        return AsString_ref(new AsString(m_buffer + start, count));
    }

    return AsString_ref(new AsString(ASL(""), 1));
}
 
AsArray_ref AsString::split(const AsString_ref& delim)
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsString::substr(uint start, uint len)
{
    if (len == INDEX_MAX)
        len = length() - start;

    ASSERT(start >= 0 && start < length());
    ASSERT(len >= 0 && len <= length());

    return AsString_ref(new AsString(m_buffer + start, len));
}
 
AsString_ref AsString::substring(uint start, uint end)
{
    if (end == INDEX_MAX)
        end = length();

    ASSERT(start >= 0 && start < length());
    ASSERT(end >= 0 && end <= length());

    int count = end - start;
    if (count < 0)
    {
        count = -count;
        start = end;
    }

    return AsString_ref(new AsString(m_buffer + start, count));
}
 
AsString_ref AsString::toLocaleLowerCase()
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsString::toLocaleUpperCase()
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsString::toLowerCase()
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsString::toString()
{    
    return AsString_ref(this);
}
 
AsString_ref AsString::toUpperCase()
{
    IMPLEMENT_ME;
    return AS_NULL;
}
 
AsString_ref AsString::valueOf()
{
    IMPLEMENT_ME;
    return AS_NULL;
}

bool AsString::isEqualToString(const AsString& other) const
{
    return wide_equals(m_buffer, other.m_buffer);
}

AsString::AsString() : 
  m_size(0),
  m_capacity(0),
  m_buffer(0)
{    
}

AsString::AsString(const achar* str) : 
  m_size(0),
  m_capacity(0),
  m_buffer(0)
{
    init(wide_len(str));
    memcpy(m_buffer, str, length() * sizeof(achar));
}

AsString::AsString(const achar* str, size_t len) :
  m_size(0),
  m_capacity(0),
  m_buffer(0)
{
    init(len);
    memcpy(m_buffer, str, len * sizeof(achar));
}

AsString::~AsString()
{
    free(m_buffer);
}

void AsString::init(size_t sz, size_t cap)
{
    if (cap)
    {        
        ASSERT(cap > sz);
        ASSERT(!m_buffer);

        m_buffer = (achar*)malloc(cap * sizeof(achar));
        m_buffer[m_size = sz] = '\0';
        m_capacity = cap;
    }    
}

void AsString::reserve(size_t cap)
{
    if (cap > m_capacity)
    {        
        ASSERT(m_buffer);
        realloc(m_buffer, cap);
        m_capacity = cap;
    }
}

void AsString::append(const achar* str, size_t len)
{
    /*size_t newsize = length() + len;
    if (newsize > capacity())
    {
        reserve (newsize + capacity());
    }
    memmove(m_buffer + rep_->capacity, str, len);
    setLength(newsize);    */
    IMPLEMENT_ME;
}
 
AS_STATIC_INIT_BEGIN(AsString,AsObject)
AS_STATIC_INIT_END
