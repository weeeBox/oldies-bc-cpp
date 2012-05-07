#ifndef AsInterface2_h__
#define AsInterface2_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
 
AS_REF(AsInterface2);
 
class AsInterface2 : public AsObject
{
public:
	AS_OBJ(AsInterface2, AsObject);
	
public:
	virtual AsString_ref string2() = 0;
};
 
class AsInterface2_ref : public AsObjectRef<AsInterface2> 
{ 
public: 
    AsInterface2_ref() : AsObjectRef() {} 
    template <class T> AsInterface2_ref(const AsObjectRef<T>& other) : AsObjectRef(other->_as_box_AsInterface2()) {} 
    AsInterface2_ref(const AsObjectRef<AsObject>& other) : AsObjectRef(other) {} 
    AsInterface2_ref(AsInterface2* obj) : AsObjectRef(obj) {} 
    explicit AsInterface2_ref(bool isStatic) : AsObjectRef(isStatic) {} 
    template <class T> inline AsInterface2_ref operator= (const T& other) { set(other->_as_box_AsInterface2()); return *this; } 
    inline AsInterface2_ref operator= (const AsObjectRef<AsObject>& other) { set(other); return *this; } 
    inline AsInterface2_ref operator= (const AsInterface2_ref& other) { set(other); return *this; } 
    template <class T> inline operator AsObjectRef<T> () 
    { 
        AsInterface2* obj = (AsInterface2*)m_object; 
        return T::_as_unbox(obj); 
    } 
};
 
#endif // AsInterface2_h__
