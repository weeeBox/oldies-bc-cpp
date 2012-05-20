#ifndef AsSoundLoaderContext_h__
#define AsSoundLoaderContext_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
AS_CLASS(AsSoundLoaderContext);
 
class AsSoundLoaderContext : public AsObject
{
public:
	AS_OBJ(AsSoundLoaderContext, AsObject);
	
public:
	float bufferTime;
	bool checkPolicyFile;
	
	
public:
	static AsSoundLoaderContext_ref _as_create_AsSoundLoaderContext(float bufferTime, bool checkPolicyFile);
	static AsSoundLoaderContext_ref _as_create_AsSoundLoaderContext(float bufferTime);
	static AsSoundLoaderContext_ref _as_create_AsSoundLoaderContext();
	
protected:
	void _as_construct_AsSoundLoaderContext(float bufferTime, bool checkPolicyFile);
	void _as_construct_AsSoundLoaderContext(float bufferTime);
	void _as_construct_AsSoundLoaderContext();
	
public:
	static void _as_static_init_AsSoundLoaderContext();
	
private:
	static bool _as_static_initialized_AsSoundLoaderContext;
	static AsStaticRefInitializer _as_static_initializer_AsSoundLoaderContext;
	
	
protected:
	AsSoundLoaderContext();
};
 
#endif // AsSoundLoaderContext_h__
