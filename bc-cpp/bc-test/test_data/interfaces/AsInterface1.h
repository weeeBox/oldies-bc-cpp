#ifndef AsInterface1_h__
#define AsInterface1_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_REF(AsInterface1);
 
class AsInterface1 : public AsObject
{
public:
	AS_OBJ(AsInterface1, AsObject);
	
public:
	virtual AsString_ref string1() = 0;
};
 
class AsInterface1_ref : public AsObjectRef<AsInterface1> 
{ 
public: 
    AsInterface1_ref() : AsObjectRef() {} 
    template <class T> AsInterface1_ref(const AsObjectRef<T>& other) : AsObjectRef(other->_as_box_AsInterface1()) {} 
    AsInterface1_ref(const AsObjectRef<AsObject>& other) : AsObjectRef(other) {} 
    AsInterface1_ref(AsInterface1* obj) : AsObjectRef(obj) {} 
    explicit AsInterface1_ref(bool isStatic) : AsObjectRef(isStatic) {} 
    template <class T> inline AsInterface1_ref operator= (const T& other) { set(other->_as_box_AsInterface1()); return *this; } 
    inline AsInterface1_ref operator= (const AsObjectRef<AsObject>& other) { set(other); return *this; } 
    inline AsInterface1_ref operator= (const AsInterface1_ref& other) { set(other); return *this; } 
    template <class T> inline operator AsObjectRef<T> () 
    { 
        AsInterface1* obj = (AsInterface1*)m_object; 
        return T::_as_unbox(obj); 
    } 
};
 
#endif // AsInterface1_h__
