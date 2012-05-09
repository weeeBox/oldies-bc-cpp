#ifndef AsFieldClass_h__
#define AsFieldClass_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
#include "AsVector.h"
 
AS_VECTOR_REF(AsString);
 
AS_CLASS(AsFieldClass);
 
class AsFieldClass : public AsObject
{
public:
	AS_OBJ(AsFieldClass, AsObject);
	
public:
	static _V_AsString_ref list;
	
	
public:
	static AsFieldClass_ref _as_create_AsFieldClass(const AsString_ref& name);
	
protected:
	void _as_construct_AsFieldClass(const AsString_ref& name);
	
public:
	static void _as_static_init_AsFieldClass();
	
private:
	static bool _as_static_initialized_AsFieldClass;
	static AsStaticRefInitializer _as_static_initializer_AsFieldClass;
};
 
#endif // AsFieldClass_h__
