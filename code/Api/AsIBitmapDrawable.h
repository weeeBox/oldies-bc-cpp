#ifndef AsIBitmapDrawable_h__
#define AsIBitmapDrawable_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
AS_REF(AsIBitmapDrawable);
 
class AsIBitmapDrawable : public AsObject
{
public:
	AS_OBJ(AsIBitmapDrawable, AsObject);
};
 
class AsIBitmapDrawable_ref : public AsObjectRef<AsIBitmapDrawable> 
{ 
public: 
    AsIBitmapDrawable_ref() : AsObjectRef() {} 
    template <class T> AsIBitmapDrawable_ref(const AsObjectRef<T>& other) : AsObjectRef(other->_as_box_AsIBitmapDrawable()) {} 
    AsIBitmapDrawable_ref(const AsObjectRef<AsObject>& other) : AsObjectRef(other) {} 
    AsIBitmapDrawable_ref(AsIBitmapDrawable* obj) : AsObjectRef(obj) {} 
    explicit AsIBitmapDrawable_ref(bool isStatic) : AsObjectRef(isStatic) {} 
    template <class T> inline AsIBitmapDrawable_ref operator= (const T& other) { set(other->_as_box_AsIBitmapDrawable()); return *this; } 
    inline AsIBitmapDrawable_ref operator= (const AsObjectRef<AsObject>& other) { set(other); return *this; } 
    inline AsIBitmapDrawable_ref operator= (const AsIBitmapDrawable_ref& other) { set(other); return *this; } 
    template <class T> inline operator AsObjectRef<T> () 
    { 
        AsIBitmapDrawable* obj = (AsIBitmapDrawable*)m_object; 
        return T::_as_unbox(obj); 
    } 
};
 
#endif // AsIBitmapDrawable_h__
