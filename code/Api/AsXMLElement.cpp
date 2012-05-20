#include "AsXMLElement.h"
#include "AsString.h"
#include "AsXML.h"
#include "AsXMLList.h"
#include "AsXMLAttribute.h"
#include "AsVector.h"
AS_VECTOR_REF(AsXML);
 
 
AsXML_ref AsXMLElement::appendChild(const AsXML_ref& child)
{
	return mChildren->appendChild(child);
}
 
AsXML_ref AsXMLElement::appendAttribute(const AsString_ref& name, const AsString_ref& value)
{
	return mAttributes->appendChild(AS_NEW(AsXMLAttribute,(name, value)));
}
 
bool AsXMLElement::hasOwnProperty(const AsString_ref& name)
{
	return mAttributes->containsChild(name);
}
 
AsString_ref AsXMLElement::attributeValue(const AsString_ref& arg)
{
	{ _V_AsXML_ref __attrs_ = mAttributes->list(); 
	if (__attrs_ != AS_NULL) { for(_as_AsRefVector<AsXML_ref>::Iterator it = (__attrs_)->iterator(); it.hasNext();) { AsXML_ref attr = it.next();
	{
		if((attr->name() == arg))
		{
			return ((AsXMLAttribute_ref)(attr))->value();
		}
	}
	}}}
	return AS_NULL;
}
 
AsXMLList_ref AsXMLElement::attributes()
{
	return mAttributes;
}
 
AsXMLList_ref AsXMLElement::child(const AsString_ref& name)
{
	AsXMLList_ref result = AS_NEW(AsXMLList,());
	{ _V_AsXML_ref __childs_ = mChildren->list(); 
	if (__childs_ != AS_NULL) { for(_as_AsRefVector<AsXML_ref>::Iterator it = (__childs_)->iterator(); it.hasNext();) { AsXML_ref child = it.next();
	{
		if((child->name() == name))
		{
			result->appendChild(child);
		}
	}
	}}}
	return result;
}
 
AsXMLList_ref AsXMLElement::children()
{
	return mChildren;
}
 
bool AsXMLElement::contains(const AsString_ref& name)
{
	{ _V_AsXML_ref __childs_ = mChildren->list(); 
	if (__childs_ != AS_NULL) { for(_as_AsRefVector<AsXML_ref>::Iterator it = (__childs_)->iterator(); it.hasNext();) { AsXML_ref child = it.next();
	{
		if((child->name() == name))
		{
			return true;
		}
	}
	}}}
	return false;
}
 
AsXMLList_ref AsXMLElement::elements(const AsString_ref& name)
{
	if((name == ASL("*")))
	{
		return mChildren;
	}
	AsXMLList_ref result = AS_NEW(AsXMLList,());
	{ _V_AsXML_ref __childs_ = mChildren->list(); 
	if (__childs_ != AS_NULL) { for(_as_AsRefVector<AsXML_ref>::Iterator it = (__childs_)->iterator(); it.hasNext();) { AsXML_ref child = it.next();
	{
		if(((child->name() == name) && (child->nodeKind() == nodeKind())))
		{
			result->appendChild(child);
		}
	}
	}}}
	return result;
}
 
AsXMLList_ref AsXMLElement::elements()
{
	return elements(ASL("*"));
}
 
AsString_ref AsXMLElement::nodeKind()
{
	return ASL("element");
}
 
AsXMLElement_ref AsXMLElement::_as_create_AsXMLElement(const AsString_ref& name)
{
	AsXMLElement_ref __instance = new AsXMLElement();
	__instance->_as_construct_AsXMLElement(name);
	return __instance;
}
 
void AsXMLElement::_as_construct_AsXMLElement(const AsString_ref& name)
{
	_as_construct_AsXML(name);
	mAttributes = AS_NEW(AsXMLList,());
	mChildren = AS_NEW(AsXMLList,());
}
 
bool AsXMLElement::_as_static_initialized_AsXMLElement = false;
AsStaticRefInitializer AsXMLElement::_as_static_initializer_AsXMLElement(_as_static_init_AsXMLElement);
void AsXMLElement::_as_static_init_AsXMLElement()
{
	if (!_as_static_initialized_AsXMLElement)
	{
		_as_static_initialized_AsXMLElement = true;
		_as_static_init_AsXML();
	}
}
 
void AsXMLElement::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsXML::_as_gc_mark();
		AS_GC_MARK(mAttributes)
		AS_GC_MARK(mChildren)
	}
}
 
AsXMLElement::AsXMLElement() : 
  mAttributes(false),
  mChildren(false)
{
}
