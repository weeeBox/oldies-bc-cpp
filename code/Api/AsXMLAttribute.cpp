#include "AsXMLAttribute.h"
#include "AsString.h"
 
 
AsString_ref AsXMLAttribute::value()
{
	return mValue;
}
 
AsString_ref AsXMLAttribute::nodeKind()
{
	return ASL("attribute");
}
 
AsXMLAttribute_ref AsXMLAttribute::_as_create_AsXMLAttribute(const AsString_ref& name, const AsString_ref& value)
{
	AsXMLAttribute_ref __instance = new AsXMLAttribute();
	__instance->_as_construct_AsXMLAttribute(name, value);
	return __instance;
}
 
void AsXMLAttribute::_as_construct_AsXMLAttribute(const AsString_ref& name, const AsString_ref& value)
{
	_as_construct_AsXML(name);
	mValue = value;
}
 
bool AsXMLAttribute::_as_static_initialized_AsXMLAttribute = false;
AsStaticRefInitializer AsXMLAttribute::_as_static_initializer_AsXMLAttribute(_as_static_init_AsXMLAttribute);
void AsXMLAttribute::_as_static_init_AsXMLAttribute()
{
	if (!_as_static_initialized_AsXMLAttribute)
	{
		_as_static_initialized_AsXMLAttribute = true;
		_as_static_init_AsXML();
	}
}
 
void AsXMLAttribute::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsXML::_as_gc_mark();
		AS_GC_MARK(mValue)
	}
}
 
AsXMLAttribute::AsXMLAttribute() : 
  mValue(false)
{
}
