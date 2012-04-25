#ifndef AsArray_h__
#define AsArray_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
AS_CLASS(AsArray);
 
class AsArray : public AsObject
{
public:
	AS_OBJ(AsArray, AsObject);
	
public:
	static const uint CASEINSENSITIVE = 1;
	static const uint DESCENDING = 2;
	static const uint UNIQUESORT = 4;
	static const uint RETURNINDEXEDARRAY = 8;
	static const uint NUMERIC = 16;
	
public:
	virtual int indexOf(const AsObject_ref& searchElement, uint fromIndex);
	virtual int indexOf(const AsObject_ref& searchElement);
	virtual int lastIndexOf(const AsObject_ref& searchElement, uint fromIndex);
	virtual int lastIndexOf(const AsObject_ref& searchElement);
	virtual uint length();
	virtual void length(uint newLength);
	virtual AsObject_ref pop();
	virtual uint push(const AsObject_ref& arg);
	
protected:
	AsArray();
};
 
#endif // AsArray_h__
