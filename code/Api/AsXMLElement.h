#ifndef AsXMLElement_h__
#define AsXMLElement_h__
 
#include "AsBc.h"
 
#include "AsXML.h"
 
 
#ifndef AsXMLList_h__
#include "AsXMLList.h"
#else
AS_CLASS(AsXMLList);
#endif // AsXMLList_h__
#include "AsString.h"
 
#ifndef AsXML_h__
#include "AsXML.h"
#else
AS_CLASS(AsXML);
#endif // AsXML_h__
 
 
AS_CLASS(AsXMLElement);
 
class AsXMLElement : public AsXML
{
public:
	AS_OBJ(AsXMLElement, AsXML);
	
private:
	AsXMLList_ref mAttributes;
	AsXMLList_ref mChildren;
	
public:
	virtual AsXML_ref appendChild(const AsXML_ref& child);
	virtual AsXML_ref appendAttribute(const AsString_ref& name, const AsString_ref& value);
	virtual bool hasOwnProperty(const AsString_ref& name);
	virtual AsString_ref attributeValue(const AsString_ref& arg);
	virtual AsXMLList_ref attributes();
	virtual AsXMLList_ref child(const AsString_ref& name);
	virtual AsXMLList_ref children();
	virtual bool contains(const AsString_ref& name);
	virtual AsXMLList_ref elements(const AsString_ref& name);
	virtual AsXMLList_ref elements();
	virtual AsString_ref nodeKind();
	
	
public:
	static AsXMLElement_ref _as_create_AsXMLElement(const AsString_ref& name);
	
protected:
	void _as_construct_AsXMLElement(const AsString_ref& name);
	
public:
	static void _as_static_init_AsXMLElement();
	
private:
	static bool _as_static_initialized_AsXMLElement;
	static AsStaticRefInitializer _as_static_initializer_AsXMLElement;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsXMLElement();
};
 
#endif // AsXMLElement_h__
