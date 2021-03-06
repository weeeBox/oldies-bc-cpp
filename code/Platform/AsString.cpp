#include "AsString.h"

#include "AsArray.h"

static size_t wide_len(const achar* str)
{
    const achar *p = str;
    while (*p) 
        ++p;
    return p - str;
}

static void wide_copy(achar* dst, const char* src)
{
    while (*dst++ = *src++)
        ;
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

static const achar* wide_find_last(const achar* from, const achar* start, const achar* what)
{
    while (from <= start)
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

        from--;
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

static int wide_hash(const wchar_t* str)
{
    int hash = 0;    
    while (*str) 
    {
        hash = 31 * hash + *str++;
    }
    return hash;
}

AsString_ref AsString::charAt(int index)
{
    if (index >= 0 && index < getLength())
    {
        achar chr = m_buffer[index];
        return AsString_ref(new AsString(&chr, 1));
    }
    
    return AsString_ref(new AsString(ASL(""), 1));
}
 
int AsString::indexOf(const AsString_ref& s, int startIndex)
{
    ASSERT(startIndex >= 0 && startIndex < getLength());
    const achar* ptr = wide_find(m_buffer + startIndex, s->m_buffer);

    return ptr ? (ptr - m_buffer) : -1;
}
 
int AsString::lastIndexOf(const AsString_ref& s, int startIndex)
{   
    if (startIndex == INDEX_MAX)
        startIndex = getLength()-1;

    const achar* ptr = wide_find_last(m_buffer + startIndex, m_buffer, s->m_buffer);

    return ptr ? (ptr - m_buffer) : -1;
}
 
int AsString::getLength() const
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

    int diff = repl->getLength() - p->getLength();    
    size_t newLen = getLength() + diff;

    achar* newBuf = (achar*)malloc(newLen * sizeof(achar));
    achar* from = m_buffer;
    achar* to = newBuf;

    size_t lenA = pStart - m_buffer;
    size_t lenB = getLength() - (lenA + p->getLength());

    memcpy(to, from, lenA * sizeof(achar));
    from += lenA;
    to += lenA;    

    memcpy(to, repl->m_buffer, repl->getLength() * sizeof(achar));
    from += p->getLength();
    to += repl->getLength();    

    memcpy(to, from, lenB * sizeof(achar));

    AsString_ref str = AsString_ref(new AsString(newBuf, newLen));
    free(newBuf);

    return str;
}
 
AsString_ref AsString::slice(int start, int end)
{
    if (end == INDEX_MAX)
        end = getLength();

    ASSERT(start >= 0 && start < getLength());
    ASSERT(end >= 0 && end <= getLength());

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
 
AsString_ref AsString::substr(int start, int len)
{
    if (len == INDEX_MAX)
        len = getLength() - start;

    ASSERT(start >= 0 && start < getLength());
    ASSERT(len >= 0 && len <= getLength());

    return AsString_ref(new AsString(m_buffer + start, len));
}
 
AsString_ref AsString::substring(int start, int end)
{
    if (end == INDEX_MAX)
        end = getLength();

    ASSERT(start >= 0 && start < getLength());
    ASSERT(end >= 0 && end <= getLength());

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
    return AsString_ref(this);
}

float AsString::parseFloat(const AsString_ref& value)
{
    IMPLEMENT_ME;
    return 0;
}

int AsString::parseInt(const AsString_ref& value)
{
    IMPLEMENT_ME;
    return 0;
}

uint AsString::parseUint(const AsString_ref& value)
{
    IMPLEMENT_ME;
    return 0;
}

bool AsString::parseBool(const AsString_ref& value)
{
    IMPLEMENT_ME;
    return false;
}

bool AsString::isEqualToString(const AsString& other) const
{
    return wide_equals(m_buffer, other.m_buffer);
}

bool AsString::isEqualToString(const AsString_ref& other) const
{
    return wide_equals(m_buffer, other->m_buffer);
}

int AsString::hashCode()
{
    if (m_hashCode == 0 && m_size > 0)
    {
        m_hashCode = wide_hash(m_buffer);
    }
    return m_hashCode;
}

int AsString::hashCode(const achar* str)
{
    return wide_hash(str);
}

AsString::AsString() : 
  m_size(0),
  m_capacity(0),
  m_buffer(0),
  m_hashCode(0)
{    
}

AsString::AsString(const char* str, size_t len) :
  m_size(0),
  m_capacity(0),
  m_buffer(0),
  m_hashCode(0)
{
    if (len == -1)
        len = strlen(str);

    init(len);    
    wide_copy(m_buffer, str);
}

AsString::AsString(const achar* str, size_t len) :
  m_size(0),
  m_capacity(0),
  m_buffer(0),
  m_hashCode(0)
{
    if (len == -1)
        len = wide_len(str);

    init(len);
    memcpy(m_buffer, str, len * sizeof(achar));
}

AsString::AsString(const AsString& other) :
  m_size(0),
  m_capacity(0),
  m_buffer(0),
  m_hashCode(0)
{
    init(other.getLength());
    memcpy(m_buffer, other.m_buffer, other.getLength() * sizeof(achar));
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

void AsString::resize(size_t cap)
{
    ASSERT(m_buffer);
    if (m_capacity < cap)
    {
        achar* newBuffer = (achar*)malloc(cap * sizeof(achar));
        memcpy(newBuffer, m_buffer, m_size * sizeof(achar));
        free(m_buffer);
        m_buffer = newBuffer;
    }
    else
    {
        realloc(m_buffer, cap * sizeof(achar));
    }    
    m_capacity = cap;
}

void AsString::append(const achar* str, size_t len)
{
    if (len == -1)
        len = wide_len(str);

    size_t newLen = getLength() + len;
    if (newLen + 1 > m_capacity)
    {
        resize(newLen + 1);
    }    

    memcpy(m_buffer + getLength(), str, len * sizeof(achar));
    m_buffer[m_size = newLen] = '\0';    
}

void AsString::append(const char* str, size_t len)
{
    if (len == -1)
        len = strlen(str);

    size_t newLen = getLength() + len;
    if (newLen + 1 > m_capacity)
    {
        resize(newLen + 1);
    }    
        
    wide_copy(m_buffer + getLength(), str);
    m_buffer[m_size = newLen] = '\0';    
}

void AsString::append(const AsString& other)
{
    append(other.m_buffer, other.getLength());
}