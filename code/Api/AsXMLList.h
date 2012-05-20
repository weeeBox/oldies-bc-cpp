#ifndef AsXMLList_h__
#define AsXMLList_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsVector.h"
#include "AsString.h"
 
AS_CLASS(AsXML);
AS_VECTOR_REF(AsXML);

class AsXMLList;

class AsXMLList_ref : public AsObjectRef<AsXMLList>
{
public:
    AsXMLList_ref() : AsObjectRef() {}
    AsXMLList_ref(const AsObjectRefBase& other) : AsObjectRef(other) {}        
    AsXMLList_ref(AsXMLList* obj) : AsObjectRef(obj) {}
    explicit AsXMLList_ref(bool isStatic) : AsObjectRef(isStatic) {}

    inline AsXMLList_ref& operator= (const AsObjectRefBase& other) { set(other); return *this; }

    inline AsXML_ref& operator[] (int index);
};
 
class AsXMLList : public AsObject
{
public:
	AS_OBJ(AsXMLList, AsObject);
	
private:
	_V_AsXML_ref mElements;
    friend class AsXMLList_ref;
	
public:
	virtual AsXML_ref appendChild(const AsXML_ref& child);
	virtual bool containsChild(const AsString_ref& name);
	virtual _V_AsXML_ref list();
	virtual AsXMLList_ref attribute(const AsString_ref& arg);
	virtual AsXMLList_ref attributes();
	virtual AsXMLList_ref child(const AsString_ref& propertyName);
	virtual int childIndex();
	virtual AsXMLList_ref children();
	virtual AsXMLList_ref copy();
	virtual bool hasOwnProperty(const AsString_ref& name);
	virtual int length();
	virtual AsString_ref name();
	virtual AsString_ref nodeKind();
	
public:
	inline static AsXMLList_ref _as_create_AsXMLList()
    {        
        return AsXMLList_ref(new AsXMLList());
    }
	
public:
	static void _as_static_init_AsXMLList();
	
private:
	static bool _as_static_initialized_AsXMLList;
	static AsStaticRefInitializer _as_static_initializer_AsXMLList;
	
public:
	void _as_gc_mark();	
	
protected:
	AsXMLList();
};

inline AsXML_ref& AsXMLList_ref::operator[] (int index) 
{               
    return object()->mElements[index];
}
 
#endif // AsXMLList_h__
