#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBc.h"

#include "AsObject.h"
#include "AsString.h"

#define AS_VECTOR_REF(type) typedef _as_AsRefVector<type##_ref>::Ref _V_##type##_ref
#define AS_VECTOR_PRIMITIVE_REF(type) typedef AsVector<type>::Ref _V_##type##_ref

#define AS_NEW_VECTOR(type, initializer) _as_AsRefVector<type##_ref>::_as_create initializer
#define AS_NEW_PRIMITIVES_VECTOR(type, initializer) AsVector<type>::_as_create initializer

#define AS_FOREACH(type, var, collection) \
    { _V_##type##_ref __##var##s_ = collection; \
    if (__##var##s_ != AS_NULL) { for(_as_AsRefVector<type##_ref>::Iterator it = (__##var##s_)->iterator(); it.hasNext();) { type##_ref var = it.next();

#define AS_PRIMITIVE_FOREACH(type, var, collection) \
    { _V_##type##_ref __##var##s_ = collection; \
    if (__##var##s_ != AS_NULL) { for(AsVector<type>::Iterator it = (__##var##s_)->iterator(); it.hasNext();) { type var = it.next();

#define AS_FOREACH_END }}}

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
            ASSERT(index >= 0 && index < _object()->getLength());
            return _object()->m_data[index];
        }

        inline Ref& operator<< (const T& element)
        {
            _object()->addElement(element);
            return *this;
        }
    };

public:
    static inline Ref _as_create(int capacity) { return Ref(new AsVector(capacity)); }
    static inline Ref _as_create(int capacity, bool fixed) { return Ref(new AsVector(capacity, fixed)); }

protected:
    virtual Ref _as_create_same(int capacity) const { return AsVector::_as_create(capacity); }

public:
    int indexOf(const T& searchElement, int fromIndex = 0);
    int lastIndexOf(const T& searchElement, int fromIndex = INDEX_MAX);
    inline int getLength() const { return m_size; }
    void setLength(int newLenght);
    inline int capacity() const { return m_capacity; }    
    AsString_ref _join(const AsString_ref& sep);
    AsString_ref _join();
    T pop();
    int push(const T& arg);
    // AsVector_ref sort(const AsFunction_ref& compareFunction);    
    AsString_ref toString();
    T shift();
    int unshift(const T& arg);

    Ref concat(const Ref& other) const
    {
        int len = m_size + other->getLength();
        
        Ref result = _as_create_same(len);        
        result->m_size = len;

        for (int i = 0; i < m_size; ++i)
        {
            result[i] = m_data[i];
        }

        for (int i = m_size, j = 0; j < other->getLength(); ++i, ++j)
        {
            result[i] = other->m_data[j];
        }

        return result;
    }
    
    Ref reverse() 
    {
        int toIndex = getLength() / 2;
        for (int i = 0, j = getLength() - 1; i < toIndex; ++i, --j)
        {
            T temp = m_data[i];
            m_data[i] = m_data[j];
            m_data[j] = temp;
        }

        return Ref(this);
    }

    Ref slice(int startIndex = 0, int endIndex = INDEX_MAX) 
    { 
        if (endIndex == INDEX_MAX)
            endIndex = getLength();

        ASSERT(startIndex >= 0 && startIndex < getLength());
        ASSERT(endIndex >= 0 && endIndex <= getLength());
        ASSERT(startIndex <= endIndex);        

        int len = endIndex - startIndex;

        Ref newVector = _as_create_same(len);
        for (int i = startIndex, j = 0; i < endIndex; ++i, ++j)
        {
            newVector->m_data[j] = m_data[i];
        }
        newVector->m_size = len;

        return newVector;
    }    

    Ref splice(int startIndex, int deleteCount = INDEX_MAX)
    {
        ASSERT(startIndex >= 0 && startIndex < getLength());

        if (deleteCount == INDEX_MAX)
            deleteCount = getLength() - startIndex;

        ASSERT(startIndex + deleteCount <= getLength());

        /* copy deleted elements to a separate vector */
        Ref result = _as_create_same(deleteCount);
        for (int i = 0, j = startIndex; i < deleteCount; ++i, ++j)
        {
            result->m_data[i] = m_data[j];
            freeElement(j);
        }
        result->m_size = deleteCount;

        /* remove elements */        
        if (deleteCount > 0)
        {
            for (int i = startIndex + deleteCount, j = startIndex; i < getLength(); ++i, ++j)
            {
                m_data[j] = m_data[i];
                freeElement(i);
            }
            m_size -= deleteCount;
        }        

        return result;
    }

    Ref splice(int startIndex, int deleteCount, const T& item)
    {
        ASSERT(startIndex >= 0 && startIndex < getLength());
        ASSERT(startIndex + deleteCount <= getLength());

        /* copy deleted elements to a separate vector */
        Ref result = _as_create_same(deleteCount);
        for (int i = 0, j = startIndex; i < deleteCount; ++i, ++j)
        {
            result->m_data[i] = m_data[j];
            freeElement(j);
        }
        result->m_size = deleteCount;

        /* remove elements */
        if (deleteCount > 0)
        {            
            if (deleteCount > 1)
            {            
                for (int i = startIndex + deleteCount, j = startIndex + 1; i < getLength(); ++i, ++j)
                {
                    m_data[j] = m_data[i];
                    freeElement(i);
                }
            }
            m_data[startIndex] = item;
            m_size -= deleteCount - 1;
        }
        else
        {
            ASSERT(deleteCount == 0);
            if (m_size == m_capacity)
            {
                int newCapacity = m_capacity > 0 ? 2 * m_capacity : DEFAULT_CAPACITY;                
                T* data = allocData(newCapacity);

                // memcpy(data, m_data, newSize); - we can't use memcpy because it makes some pointers invalid
                for (int i = 0; i < startIndex; ++i)
                {
                    data[i] = m_data[i];
                    freeElement(i);
                }

                data[startIndex] = item;

                for (int i = startIndex; i < getLength(); ++i)
                {
                    data[i+1] = m_data[i];
                    freeElement(i);
                }

                freeData(m_data);
                m_data = data;
                m_capacity = newCapacity;
                m_size++;
            }
            else
            {
                ASSERT(m_size < m_capacity);
                for (int i = getLength(); i > startIndex; --i)
                {
                    m_data[i] = m_data[i-1];
                }
                m_data[startIndex] = item;
                m_size++;
            }
        }        

        return result;
    }   

protected:
    AsVector(int capacity, bool fixed = false);

public:
    ~AsVector();

protected:
    T* m_data;
    int m_size;
    int m_capacity;

    static const int DEFAULT_CAPACITY = 16;    
    static const int INDEX_MAX = 0x7fffffff;

    T* allocData(int capacity);
    void freeData(T* data);

protected:
    void expand(int capacity);
    void addElement(const T& element);
    virtual void freeElement(int index);

public:
    class Iterator
    {
    private:
        int m_index;
        const AsVector* m_vector;

    public:
        Iterator(const AsVector* vector) : m_index(0), m_vector(vector) {}
        inline BOOL hasNext() const { return m_index < m_vector->getLength(); }
        inline const T& next() { ASSERT(hasNext()); return m_vector->m_data[m_index++]; }
    };

    inline Iterator iterator() const { return Iterator(this); }
};

template <class T>
class _as_AsRefVector : public AsVector<T>
{
public:
    AS_TYPENAME(AsVector, AsObject);

protected:
    _as_AsRefVector(int capacity = DEFAULT_CAPACITY, bool fixed = false) : AsVector(capacity, fixed) {}
    Ref _as_create_same(int capacity = DEFAULT_CAPACITY) const { return _as_AsRefVector::_as_create(capacity); }
    void freeElement(int index);

public:
    static inline Ref _as_create(int size = DEFAULT_CAPACITY) { return Ref(new _as_AsRefVector(size)); }
    static inline Ref _as_create(int size, bool fixed) { return Ref(new _as_AsRefVector(size, fixed)); }
    ~_as_AsRefVector();
};
 
template <class T>
AsVector<T>::AsVector(int capacity, bool fixed) : 
  m_data(0), 
  m_size(0), 
  m_capacity(capacity)      
{
    if (m_capacity > 0)
    {
        m_data = allocData(m_capacity);
    }
}

template <class T>
AsVector<T>::~AsVector()
{    
    freeData(m_data);    
}

template <class T>
T* AsVector<T>::allocData(int capacity)
{
    ASSERT(capacity > 0);
    int bytes = capacity * sizeof(T);

    T* data = (T*)malloc(bytes);
    memset(data, 0, bytes);

    return data;
}

template <class T>
void AsVector<T>::freeData(T* data)
{
    free(data);
}

template <class T>
void AsVector<T>::expand(int capacity)
{        
    ASSERT(capacity > 0);    

    T* data = allocData(capacity);

    // memcpy(data, m_data, newSize); - we can't use memcpy because it makes some pointers invalid
    for (int i = 0; i < getLength(); ++i)
    {
        data[i] = m_data[i];
        freeElement(i);
    }    

    freeData(m_data);
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
    ASSERT(index >= 0 && index < getLength());
    // nothing
}

template <class T>
int AsVector<T>::indexOf(const T& searchElement, int fromIndex)
{
    ASSERT(fromIndex >= 0 && fromIndex < getLength());
    for (int i = fromIndex; i < getLength(); ++i)
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
        fromIndex = getLength() - 1;

    ASSERT(fromIndex >= 0 && fromIndex < getLength());
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
void AsVector<T>::setLength(int newLenght)
{
    ASSERT(newLenght >= 0);
    if (newLenght > m_size)
    {
        expand(newLenght);
    }
    else if (newLenght < m_size)
    {
        for (int i = newLenght; i < m_size; ++i)
        {
            freeElement(i);
        }
    }
    m_size = newLenght;
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
    return _join(ASL(","));
}

template <class T>
T AsVector<T>::pop()
{
    ASSERT(m_size > 0);

    int index = m_size - 1;
    T element = m_data[index];
    freeElement(index);

    m_size--;

    return element;
}

template <class T>
int AsVector<T>::push(const T& arg)
{
    if (getLength() == capacity())
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
    return AsObject::toString();
}

template <class T>
T AsVector<T>::shift()
{
    ASSERT(m_size > 0);
        
    T element = m_data[0];    
    for (int i = 1; i < getLength(); ++i)
    {
        m_data[i - 1] = m_data[i];
    }
    freeElement(getLength()-1);
    m_size--;

    return element;
}

template <class T>
int AsVector<T>::unshift(const T& arg)
{
    if (getLength() == capacity())
    {
        int newCapacity = capacity() > 0 ? 2 * capacity() : DEFAULT_CAPACITY;
        T* data = allocData(newCapacity);

        // memcpy(data, m_data, newSize); - we can't use memcpy because it makes some pointers invalid        
        for (int i = 0; i < getLength(); ++i)
        {
            data[i + 1] = m_data[i];
            freeElement(i);
        }
        data[0] = arg;
        m_size++;

        freeData(m_data);
        m_data = data;
        m_capacity = newCapacity;
    }
    else
    {
        ASSERT(getLength() < capacity());
        
        for (int i = getLength(); i > 0; --i)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[0] = arg;
        m_size++;        
    }

    return m_size;
}

template <class T>
_as_AsRefVector<T>::~_as_AsRefVector()
{
    for (int i = 0; i < getLength(); ++i)
    {
        m_data[i] = AS_NULL;
    }
}

template <class T>
void _as_AsRefVector<T>::freeElement(int index)
{
    ASSERT(index >= 0 && index < getLength());
    m_data[index] = AS_NULL;
}

#endif // AsVector_h__
