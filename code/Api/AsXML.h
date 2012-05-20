#ifndef AsXML_h__
#define AsXML_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
 
AS_CLASS(AsXML);

AS_REF(AsXMLList);
 
class AsXML : public AsObject
{
public:
	AS_OBJ(AsXML, AsObject);
	
private:
	AsXML_ref mParent;
	AsString_ref mName;
	
public:
	virtual AsXML_ref appendChild(const AsXML_ref& child);
	virtual AsString_ref attributeValue(const AsString_ref& name);
	virtual AsString_ref attribute(const AsString_ref& name);
	virtual AsXMLList_ref attributes();
	virtual AsXMLList_ref child(const AsString_ref& propertyName);
	virtual int childIndex();
	virtual AsXMLList_ref children();
	virtual AsXMLList_ref comments();
	virtual bool contains(const AsString_ref& value);
	virtual AsXML_ref copy();
	virtual AsXMLList_ref elements(const AsString_ref& name);
	virtual AsXMLList_ref elements();
	virtual int length();
	virtual AsString_ref name();
	virtual AsString_ref nodeKind();
	virtual AsXML_ref parent();
	virtual AsString_ref text();
	virtual bool hasOwnProperty(const AsString_ref& name);
	
	
public:
	static AsXML_ref _as_create_AsXML(const AsString_ref& name);
	static AsXML_ref _as_create_AsXML();
	
protected:
	void _as_construct_AsXML(const AsString_ref& name);
	void _as_construct_AsXML();
	
public:
	static void _as_static_init_AsXML();
	
private:
	static bool _as_static_initialized_AsXML;
	static AsStaticRefInitializer _as_static_initializer_AsXML;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsXML();
};
 
#ifndef AsXML_h__
#include "AsXML.h"
#endif
#ifndef AsXMLList_h__
#include "AsXMLList.h"
#endif
 
#endif // AsXML_h__
