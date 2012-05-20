#ifndef AsXMLAttribute_h__
#define AsXMLAttribute_h__
 
#include "AsBc.h"
 
#include "AsXML.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsXMLAttribute);
 
class AsXMLAttribute : public AsXML
{
public:
	AS_OBJ(AsXMLAttribute, AsXML);
	
private:
	AsString_ref mValue;
	
public:
	virtual AsString_ref value();
	virtual AsString_ref nodeKind();
	
	
public:
	static AsXMLAttribute_ref _as_create_AsXMLAttribute(const AsString_ref& name, const AsString_ref& value);
	
protected:
	void _as_construct_AsXMLAttribute(const AsString_ref& name, const AsString_ref& value);
	
public:
	static void _as_static_init_AsXMLAttribute();
	
private:
	static bool _as_static_initialized_AsXMLAttribute;
	static AsStaticRefInitializer _as_static_initializer_AsXMLAttribute;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsXMLAttribute();
};
 
#endif // AsXMLAttribute_h__
