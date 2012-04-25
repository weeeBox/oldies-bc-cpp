#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsBcClawSprite)
typedef AsVector<AsBcClawSprite_ref> __V_AsBcClawSprite;
typedef __V_AsBcClawSprite::Ref __V_AsBcClawSprite_ref;
ASTYPEREF(AsVector)
ASTYPEREF(AsObject)
ASTYPEREF(AsString)
ASTYPEREF(AsFunction)
 
class AsVector : public AsObject
{
public:
	ASOBJ(AsVector, AsObject);
	
public:
	virtual AsVector_ref concat(const AsObject_ref& obj);
	virtual AsVector_ref concat();
	virtual int length();
	virtual void length(int newLenght);
	virtual int indexOf(const AsObject_ref& searchElement, int fromIndex);
	virtual int indexOf(const AsObject_ref& searchElement);
	virtual AsString_ref _join(const AsString_ref& sep);
	virtual AsString_ref _join();
	virtual int lastIndexOf(const AsObject_ref& searchElement, int fromIndex);
	virtual int lastIndexOf(const AsObject_ref& searchElement);
	virtual AsObject_ref pop();
	virtual int push(const AsObject_ref& arg);
	virtual AsVector_ref reverse();
	virtual AsVector_ref slice(int startIndex, int endIndex);
	virtual AsVector_ref slice(int startIndex);
	virtual AsVector_ref slice();
	virtual AsVector_ref sort(const AsFunction_ref& compareFunction);
	virtual AsVector_ref splice(int startIndex, int deleteCount, const AsObject_ref& item);
	virtual AsVector_ref splice(int startIndex, int deleteCount);
	virtual AsString_ref toString();
	virtual int unshift(const AsObject_ref& arg);
	
public:
	static AsVector_ref __createAsVector(int length, BOOL _fixed);
	static AsVector_ref __createAsVector(int length);
	static AsVector_ref __createAsVector();
	
private:
	void __internalConstructAsVector(int length, BOOL _fixed);
	void __internalConstructAsVector(int length);
	void __internalConstructAsVector();
	
public:
	void __internalInitialiseAsVector();
	
private:
	static StaticInit __internalStaticInitializerAsVector;
	static BOOL __internalStaticInitializedAsVector;
	
public:
	static void __internalStaticInit();
	
protected:
	AsVector();
};
 
#endif // AsVector_h__
