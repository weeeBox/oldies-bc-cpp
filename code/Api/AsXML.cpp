#include "AsXML.h"
#include "AsString.h"
#include "AsXML.h"
#include "AsNotImplementedError.h"
#include "AsAbstractClassError.h"
 
 
AsXML_ref AsXML::appendChild(const AsXML_ref& child)
{
	return child;
}
 
AsString_ref AsXML::attributeValue(const AsString_ref& name)
{
	return AS_NULL;
}
 
AsString_ref AsXML::attribute(const AsString_ref& name)
{
	return attributeValue(name);
}
 
AsXMLList_ref AsXML::attributes()
{
	return AS_NULL;
}
 
AsXMLList_ref AsXML::child(const AsString_ref& propertyName)
{
	return AS_NULL;
}
 
int AsXML::childIndex()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXML::children()
{
	return AS_NULL;
}
 
AsXMLList_ref AsXML::comments()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsXML::contains(const AsString_ref& value)
{
	return false;
}
 
AsXML_ref AsXML::copy()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXML::elements(const AsString_ref& name)
{
	return AS_NULL;
}
 
AsXMLList_ref AsXML::elements()
{
	return elements(ASL("*"));
}
 
int AsXML::length()
{
	return 1;
}
 
AsString_ref AsXML::name()
{
	return mName;
}
 
AsString_ref AsXML::nodeKind()
{
	throw AS_NEW(AsAbstractClassError,());
}
 
AsXML_ref AsXML::parent()
{
	return mParent;
}
 
AsString_ref AsXML::text()
{
	return AS_NULL;
}
 
bool AsXML::hasOwnProperty(const AsString_ref& name)
{
	return false;
}
 
AsXML_ref AsXML::_as_create_AsXML(const AsString_ref& name)
{
	AsXML_ref __instance = new AsXML();
	__instance->_as_construct_AsXML(name);
	return __instance;
}
 
AsXML_ref AsXML::_as_create_AsXML()
{
	AsXML_ref __instance = new AsXML();
	__instance->_as_construct_AsXML();
	return __instance;
}
 
void AsXML::_as_construct_AsXML(const AsString_ref& name)
{
	mName = name;
}
 
inline void AsXML::_as_construct_AsXML()
{
	_as_construct_AsXML(AS_NULL);
}
 
bool AsXML::_as_static_initialized_AsXML = false;
AsStaticRefInitializer AsXML::_as_static_initializer_AsXML(_as_static_init_AsXML);
void AsXML::_as_static_init_AsXML()
{
	if (!_as_static_initialized_AsXML)
	{
		_as_static_initialized_AsXML = true;
	}
}
 
void AsXML::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mParent)
		AS_GC_MARK(mName)
	}
}
 
AsXML::AsXML() : 
  mParent(false),
  mName(false)
{
}
