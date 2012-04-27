#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBc.h"

#include "AsObject.h"
#include "AsString.h"

template <class T> 
class AsVector : public AsObject
{
public:
    class Ref : public AsObjectRef<AsVector>
    {
    public:
        Ref() : AsObjectRef() {}
        Ref(const AsObjectRefBase& other) : AsObjectRef(other) {}        
        Ref(AsVector* obj) : AsObjectRef(obj) {}
        explicit Ref(bool isStatic) : AsObjectRef(isStatic) {}

        inline T& operator[] (int index) 
        {   
            ASSERT(index >= 0 && index < _object()->length());
            return _object()->m_data[index];
        }

        inline Ref& operator<< (const T& element)
        {
            _object()->add(element);
            return *this;
        }
    };

public:
    int indexOf(const T& searchElement, int fromIndex);
    int indexOf(const T& searchElement);    
    inline int length() const { return m_size; }
    inline int capacity() const { return m_capacity; }
    void length(int newLenght);	
    AsString_ref _join(const AsString_ref& sep);
    AsString_ref _join();
    int lastIndexOf(const T& searchElement, int fromIndex);
    int lastIndexOf(const T& searchElement);
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
    AsVector(size_t capacity = DEFAULT_CAPACITY);

public:
    ~AsVector();

public:
    static inline Ref _as_create(size_t size) { return Ref(new AsVector(size)); }    

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

    static const int DEFAULT_CAPACITY = 16;    
        
    void expand(int capacity);
    void add(const T& element);

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
class _as_object_ref_vector : public AsVector<T>
{

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
    T* data = (T*)malloc(capacity * sizeof(T));
    memcpy(data, m_data, m_size * sizeof(T));
    free(m_data);
    m_data = data;
    m_capacity = capacity;
}

template <class T>
void AsVector<T>::add(const T& element)
{
    ASSERT(m_size < m_capacity);
    m_data[m_size++] = element;
}

template <class T>
int AsVector<T>::indexOf(const T& searchElement, int fromIndex)
{
    IMPLEMENT_ME;
    return -1;
}

template <class T>
int AsVector<T>::indexOf(const T& searchElement)
{
    IMPLEMENT_ME;
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
int AsVector<T>::lastIndexOf(const T& searchElement, int fromIndex)
{
    IMPLEMENT_ME;
    return -1;
}

template <class T>
int AsVector<T>::lastIndexOf(const T& searchElement)
{
    IMPLEMENT_ME;
    return -1;
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
    IMPLEMENT_ME;
    return -1;
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

#endif // AsVector_h__
