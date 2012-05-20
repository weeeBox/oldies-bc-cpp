#ifndef AsSound_h__
#define AsSound_h__
 
#include "AsBc.h"
 
#include "AsEventDispatcher.h"
 
#include "AsString.h"
 
AS_CLASS(AsURLRequest);
AS_CLASS(AsSoundLoaderContext);
AS_CLASS(AsSoundChannel);
AS_CLASS(AsSoundTransform);
 
AS_CLASS(AsSound);
 
class AsSound : public AsEventDispatcher
{
public:
	AS_OBJ(AsSound, AsEventDispatcher);
	
private:
	AsURLRequest_ref mRequest;
	AsSoundLoaderContext_ref mContext;
	
public:
	virtual uint getBytesLoaded();
	virtual int getBytesTotal();
	virtual void close();
	virtual float getLength();
	virtual void load(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context);
	virtual void load(const AsURLRequest_ref& request);
	virtual AsSoundChannel_ref play(float startTime, int loops, const AsSoundTransform_ref& sndTransform);
	virtual AsSoundChannel_ref play(float startTime, int loops);
	virtual AsSoundChannel_ref play(float startTime);
	virtual AsSoundChannel_ref play();
	virtual AsString_ref getUrl();
	
	
public:
	static AsSound_ref _as_create_AsSound(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context);
	static AsSound_ref _as_create_AsSound(const AsURLRequest_ref& request);
	static AsSound_ref _as_create_AsSound();
	
protected:
	void _as_construct_AsSound(const AsURLRequest_ref& request, const AsSoundLoaderContext_ref& context);
	void _as_construct_AsSound(const AsURLRequest_ref& request);
	void _as_construct_AsSound();
	
public:
	static void _as_static_init_AsSound();
	
private:
	static bool _as_static_initialized_AsSound;
	static AsStaticRefInitializer _as_static_initializer_AsSound;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsSound();
};
 
#endif // AsSound_h__
