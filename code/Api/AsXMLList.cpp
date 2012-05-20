#include "AsXMLList.h"
#include "AsXML.h"
#include "AsString.h"
#include "AsNotImplementedError.h"
 
 
AsXML_ref AsXMLList::appendChild(const AsXML_ref& child)
{
	mElements->push(child);
	return child;
}
 
bool AsXMLList::containsChild(const AsString_ref& name)
{
	AS_FOREACH(AsXML, element, mElements)
	{
		if((name == element->name()))
		{
			return true;
		}
	}
	AS_FOREACH_END
	return false;
}
 
_V_AsXML_ref AsXMLList::list()
{
	return mElements;
}
 
AsXMLList_ref AsXMLList::attribute(const AsString_ref& arg)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXMLList::attributes()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXMLList::child(const AsString_ref& propertyName)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsXMLList::childIndex()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXMLList::children()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsXMLList_ref AsXMLList::copy()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsXMLList::hasOwnProperty(const AsString_ref& name)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsXMLList::length()
{
	return (int)(mElements->getLength());
}
 
AsString_ref AsXMLList::name()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsXMLList::nodeKind()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsXMLList::_as_static_initialized_AsXMLList = false;
AsStaticRefInitializer AsXMLList::_as_static_initializer_AsXMLList(_as_static_init_AsXMLList);
void AsXMLList::_as_static_init_AsXMLList()
{
	if (!_as_static_initialized_AsXMLList)
	{
		_as_static_initialized_AsXMLList = true;
	}
}
 
void AsXMLList::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(mElements)
	}
}
 
AsXMLList::AsXMLList() : 
  mElements(false)
{
    mElements = AS_NEW_VECTOR(AsXML,(0));
}
