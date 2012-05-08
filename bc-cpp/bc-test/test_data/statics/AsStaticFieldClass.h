#ifndef AsStaticFieldClass_h__
#define AsStaticFieldClass_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
#include "AsVector.h"
 
AS_VECTOR_REF(AsString);
AS_CLASS(AsStaticDummy);
 
AS_CLASS(AsStaticFieldClass);
 
class AsStaticFieldClass : public AsObject
{
public:
	AS_OBJ(AsStaticFieldClass, AsObject);
	
public:
	static _V_AsString_ref list;
	
	
public:
	static AsStaticFieldClass_ref _as_create_AsStaticFieldClass(const AsStaticDummy_ref& dummy);
	
protected:
	void _as_construct_AsStaticFieldClass(const AsStaticDummy_ref& dummy);
	
public:
	static void _as_static_init_AsStaticFieldClass();
	
private:
	static bool _as_static_initialized_AsStaticFieldClass;
	static AsStaticRefInitializer _as_static_initializer_AsStaticFieldClass;
};
 
#endif // AsStaticFieldClass_h__
