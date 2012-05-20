#include "AsTouchData.h"
#include "AsTouch.h"
#include "AsDisplayObject.h"
 
 
AsTouchData_ref AsTouchData::_as_create_AsTouchData(const AsTouch_ref& touch, const AsDisplayObject_ref& target)
{
	AsTouchData_ref __instance = new AsTouchData();
	__instance->_as_construct_AsTouchData(touch, target);
	return __instance;
}
 
void AsTouchData::_as_construct_AsTouchData(const AsTouch_ref& touch, const AsDisplayObject_ref& target)
{
	this->touch = touch;
	this->target = target;
}
 
bool AsTouchData::_as_static_initialized_AsTouchData = false;
AsStaticRefInitializer AsTouchData::_as_static_initializer_AsTouchData(_as_static_init_AsTouchData);
void AsTouchData::_as_static_init_AsTouchData()
{
	if (!_as_static_initialized_AsTouchData)
	{
		_as_static_initialized_AsTouchData = true;
	}
}
 
void AsTouchData::_as_gc_mark()
{
	if (_as_gc_mark_needed())
	{
		AsObject::_as_gc_mark();
		AS_GC_MARK(touch)
		AS_GC_MARK(target)
	}
}
 
AsTouchData::AsTouchData() : 
  touch(false),
  target(false)
{
}
