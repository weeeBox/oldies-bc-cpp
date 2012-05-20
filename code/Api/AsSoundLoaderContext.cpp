#include "AsSoundLoaderContext.h"
 
 
AsSoundLoaderContext_ref AsSoundLoaderContext::_as_create_AsSoundLoaderContext(float bufferTime, bool checkPolicyFile)
{
	AsSoundLoaderContext_ref __instance = new AsSoundLoaderContext();
	__instance->_as_construct_AsSoundLoaderContext(bufferTime, checkPolicyFile);
	return __instance;
}
 
AsSoundLoaderContext_ref AsSoundLoaderContext::_as_create_AsSoundLoaderContext(float bufferTime)
{
	AsSoundLoaderContext_ref __instance = new AsSoundLoaderContext();
	__instance->_as_construct_AsSoundLoaderContext(bufferTime);
	return __instance;
}
 
AsSoundLoaderContext_ref AsSoundLoaderContext::_as_create_AsSoundLoaderContext()
{
	AsSoundLoaderContext_ref __instance = new AsSoundLoaderContext();
	__instance->_as_construct_AsSoundLoaderContext();
	return __instance;
}
 
void AsSoundLoaderContext::_as_construct_AsSoundLoaderContext(float bufferTime, bool checkPolicyFile)
{
	this->bufferTime = bufferTime;
	this->checkPolicyFile = checkPolicyFile;
}
 
inline void AsSoundLoaderContext::_as_construct_AsSoundLoaderContext(float bufferTime)
{
	_as_construct_AsSoundLoaderContext(bufferTime, false);
}
 
inline void AsSoundLoaderContext::_as_construct_AsSoundLoaderContext()
{
	_as_construct_AsSoundLoaderContext(1000, false);
}
 
bool AsSoundLoaderContext::_as_static_initialized_AsSoundLoaderContext = false;
AsStaticRefInitializer AsSoundLoaderContext::_as_static_initializer_AsSoundLoaderContext(_as_static_init_AsSoundLoaderContext);
void AsSoundLoaderContext::_as_static_init_AsSoundLoaderContext()
{
	if (!_as_static_initialized_AsSoundLoaderContext)
	{
		_as_static_initialized_AsSoundLoaderContext = true;
	}
}
 
AsSoundLoaderContext::AsSoundLoaderContext() : 
  bufferTime(0),
  checkPolicyFile(0)
{
}
