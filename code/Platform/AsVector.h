#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBc.h"

#include "AsObject.h"
#include "AsString.h"

template <class T> 
class AsVectorBase : public AsObject
{
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

    static const int DEFAULT_SIZE = 16;

public:
    AsVectorBase(size_t size = DEFAULT_SIZE) : m_data(0), m_size(size), m_capacity(size)
    {
        m_data = (T*)malloc(m_capacity * sizeof(T));
    }

    void expand(int capacity)
    {        
        T* data = (T*)malloc(capacity * sizeof(T));
        memcpy(data, m_data, m_size * sizeof(T));
        free(m_data);
        m_data = data;
        m_capacity = capacity;
    }

public:
    inline int length() const { return m_size; }
    virtual void length(int newLenght) { IMPLEMENT_ME; }

    int indexOf(const T& searchElement, int fromIndex);
    int indexOf(const T& searchElement);

public:
    class Ref : public AsObjectRef<AsVectorBase>
    {
    public:
        Ref() : AsObjectRef() {}
        Ref(const AsObjectRefBase& other) : AsObjectRef(other) {}        
        Ref(AsVectorBase* obj) : AsObjectRef(obj) {}
        explicit Ref(bool isStatic) : AsObjectRef(isStatic) {}
    };

public:
    static inline Ref _as_create(size_t size, ...) 
    { 
        va_list args;
        va_start(args, size);

        Ref _ref(new AsVectorBase(size)); 
        _ref->init(size, args); 

        va_end(args);
        return _ref; 
    }

private:
    void init(size_t size, va_list args)
    {
        ASSERT(size <= m_capacity);
        for (size_t i = 0; i < size; ++i)
        {
            m_data[i] = va_arg(args, T);
        }
    }

public:
    class Iterator
    {
    private:
        int m_index;
        AsVectorBase* m_vector;
    public:
        Iterator(AsVectorBase* vector) : m_index(0), m_vector(vector) {}

        inline BOOL hasNext() const { return m_index < m_vector->getLength(); }
        inline const T& next() const { ASSERT(hasNext()); return m_vector->m_data[m_index++]; }
    };
};

template<class T>
class AsVector : public AsVectorBase<T>
{
public:
	AS_OBJ(AsVector, AsObject);
	
public:
	Ref concat(const AsObject_ref& obj);
	Ref concat();
	int length();
	void length(int newLenght);	
	AsString_ref _join(const AsString_ref& sep);
	AsString_ref _join();
	int lastIndexOf(const AsObject_ref& searchElement, int fromIndex);
	int lastIndexOf(const AsObject_ref& searchElement);
	AsObject_ref pop();
	int push(const AsObject_ref& arg);
	Ref reverse();
	Ref slice(int startIndex, int endIndex);
	Ref slice(int startIndex);
	Ref slice();
	// AsVector_ref sort(const AsFunction_ref& compareFunction);
	Ref splice(int startIndex, int deleteCount, const AsObject_ref& item);
	Ref splice(int startIndex, int deleteCount);
	AsString_ref toString();
	int unshift(const AsObject_ref& arg);
};
 
#endif // AsVector_h__
