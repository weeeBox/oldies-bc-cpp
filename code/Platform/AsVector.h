#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBc.h"

#include "AsObject.h"
#include "AsString.h"

template <class T> 
class AsVector : public AsObject
{
public:
    AS_TYPENAME(AsVector, AsObject);

public:
    class Ref : public AsObjectRef<AsVector>
    {
    public:
        Ref() : AsObjectRef() {}
        Ref(const AsObjectRefBase& other) : AsObjectRef(other) {}        
        Ref(AsVector* obj) : AsObjectRef(obj) {}
        explicit Ref(bool isStatic) : AsObjectRef(isStatic) {}

        inline Ref& operator= (const AsObjectRefBase& other) { set(other); return *this; }

        inline T& operator[] (int index) 
        {   
            ASSERT(index >= 0 && index < _object()->length());
            return _object()->m_data[index];
        }

        inline Ref& operator<< (const T& element)
        {
            _object()->addElement(element);
            return *this;
        }
    };

public:
    static inline Ref _as_create(size_t capacity) { return Ref(new AsVector(capacity)); }

public:
    int indexOf(const T& searchElement, int fromIndex = 0);
    int lastIndexOf(const T& searchElement, int fromIndex = INDEX_MAX);
    inline int length() const { return m_size; }
    void length(int newLenght);
    inline int capacity() const { return m_capacity; }    
    AsString_ref _join(const AsString_ref& sep);
    AsString_ref _join();
    T pop();
    int push(const T& arg);
    // AsVector_ref sort(const AsFunction_ref& compareFunction);    
    AsString_ref toString();
    int unshift(const AsObject_ref& arg);

    Ref concat(const AsObject_ref& obj) { IMPLEMENT_ME; return AS_NULL; }
    Ref concat() { IMPLEMENT_ME; return AS_NULL; }
    Ref reverse() { IMPLEMENT_ME; return AS_NULL; }
    Ref slice(int startIndex, int endIndex) { IMPLEMENT_ME; return AS_NULL; }
    Ref slice(int startIndex) { IMPLEMENT_ME; return AS_NULL; }
    Ref slice() { IMPLEMENT_ME; return AS_NULL; }
    Ref splice(int startIndex, int deleteCount, const T& item) { IMPLEMENT_ME; return AS_NULL; }
    Ref splice(int startIndex, int deleteCount) { IMPLEMENT_ME; return AS_NULL; }

protected:
    AsVector(size_t capacity);

public:
    ~AsVector();

protected:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

    static const int DEFAULT_CAPACITY = 16;    
    static const int INDEX_MAX = 0x7fffffff;

protected:
    void expand(int capacity);
    void addElement(const T& element);
    virtual void freeElement(int index);

public:
    class Iterator
    {
    private:
        int m_index;
        AsVector* m_vector;
    public:
        Iterator(AsVector* vector) : m_index(0), m_vector(vector) {}

        inline BOOL hasNext() const { return m_index < m_vector->getLength(); }
        inline const T& next() const { ASSERT(hasNext()); return m_vector->m_data[m_index++]; }
    };

    inline Iterator iterator() const { return Iterator(this); }
};

template <class T>
class _as_AsRefVector : public AsVector<T>
{
public:
    AS_TYPENAME(AsVector, AsObject);

protected:
    _as_AsRefVector(size_t capacity = DEFAULT_CAPACITY) : AsVector(capacity) {}
    void freeElement(int index);

public:
    static inline Ref _as_create(size_t size) { return Ref(new _as_AsRefVector(size)); }
    ~_as_AsRefVector();
};
 
template <class T>
AsVector<T>::AsVector(size_t capacity) : 
  m_data(0), 
  m_size(0), 
  m_capacity(capacity)      
{
    m_data = (T*)malloc(m_capacity * sizeof(T));
    memset(m_data, 0, m_capacity * sizeof(T));
}

template <class T>
AsVector<T>::~AsVector()
{    
    free(m_data);    
}

template <class T>
void AsVector<T>::expand(int capacity)
{        
    ASSERT(capacity > 0);

    size_t newSize = capacity * sizeof(T);
    T* data = (T*)malloc(newSize);
    memset(data, 0, newSize);
    // memcpy(data, m_data, newSize); - we can't use memcpy because it makes some pointers invalid
    for (int i = 0; i < length(); ++i)
    {
        data[i] = m_data[i];
        freeElement(i);
    }    

    free(m_data);
    m_data = data;
    m_capacity = capacity;
}

template <class T>
void AsVector<T>::addElement(const T& element)
{
    ASSERT(m_size < m_capacity);
    m_data[m_size++] = element;
}

template <class T>
void AsVector<T>::freeElement(int index)
{
    ASSERT(index >= 0 && index < length());
    // nothing
}

template <class T>
int AsVector<T>::indexOf(const T& searchElement, int fromIndex)
{
    ASSERT(fromIndex >= 0 && fromIndex < length());
    for (int i = fromIndex; i < length(); ++i)
    {
        if (m_data[i] == searchElement)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
int AsVector<T>::lastIndexOf(const T& searchElement, int fromIndex)
{
    if (fromIndex == INDEX_MAX)
        fromIndex = length() - 1;

    ASSERT(fromIndex >= 0 && fromIndex < length());
    for (int i = fromIndex; i >= 0; --i)
    {
        if (m_data[i] == searchElement)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
void AsVector<T>::length(int newLenght)
{
    IMPLEMENT_ME;    
}

template <class T>
AsString_ref AsVector<T>::_join(const AsString_ref& sep)
{
    IMPLEMENT_ME;
    return AS_NULL;
}

template <class T>
AsString_ref AsVector<T>::_join()
{
    IMPLEMENT_ME;
    return AS_NULL;
}

template <class T>
T AsVector<T>::pop()
{
    IMPLEMENT_ME;
    return AS_NULL;
}

template <class T>
int AsVector<T>::push(const T& arg)
{
    if (length() == capacity())
    {
        int newCapacity = capacity() > 0 ? 2 * capacity() : DEFAULT_CAPACITY;
        expand(newCapacity);
    }

    m_data[m_size++] = arg;
    return m_size;
}

template <class T>
AsString_ref AsVector<T>::toString()
{
    IMPLEMENT_ME;
    return AS_NULL;
}

template <class T>
int AsVector<T>::unshift(const AsObject_ref& arg)
{
    IMPLEMENT_ME;
    return -1;
}

template <class T>
_as_AsRefVector<T>::~_as_AsRefVector()
{
    for (int i = 0; i < length(); ++i)
    {
        m_data[i] = AS_NULL;
    }
}

template <class T>
void _as_AsRefVector<T>::freeElement(int index)
{
    ASSERT(index >= 0 && index < length());
    m_data[index] = AS_NULL;
}

#endif // AsVector_h__
