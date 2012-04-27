#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBc.h"

#include "AsObject.h"
#include "AsString.h"

AS_CLASS(AsVector);

class AsVector : public AsObject
{
public:
	AS_OBJ(AsVector, AsObject);
	
public:
	AsVector_ref concat(const AsObject_ref& obj);
	AsVector_ref concat();
	int length();
	void length(int newLenght);
	int indexOf(const AsObject_ref& searchElement, int fromIndex);
	int indexOf(const AsObject_ref& searchElement);
	AsString_ref _join(const AsString_ref& sep);
	AsString_ref _join();
	int lastIndexOf(const AsObject_ref& searchElement, int fromIndex);
	int lastIndexOf(const AsObject_ref& searchElement);
	AsObject_ref pop();
	int push(const AsObject_ref& arg);
	AsVector_ref reverse();
	AsVector_ref slice(int startIndex, int endIndex);
	AsVector_ref slice(int startIndex);
	AsVector_ref slice();
	// AsVector_ref sort(const AsFunction_ref& compareFunction);
	AsVector_ref splice(int startIndex, int deleteCount, const AsObject_ref& item);
	AsVector_ref splice(int startIndex, int deleteCount);
	AsString_ref toString();
	int unshift(const AsObject_ref& arg);
	
protected:
	AsVector();
};
 
#endif // AsVector_h__
