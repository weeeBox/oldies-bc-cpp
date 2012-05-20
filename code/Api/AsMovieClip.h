#ifndef AsMovieClip_h__
#define AsMovieClip_h__
 
#include "AsBc.h"
 
#include "AsSprite.h"
 
#include "AsString.h"
#include "AsArray.h"
#include "AsObject.h"
 
 
AS_CLASS(AsMovieClip);
 
class AsMovieClip : public AsSprite
{
public:
	AS_OBJ(AsMovieClip, AsSprite);
	
public:
	virtual int getCurrentFrame();
	virtual AsString_ref getCurrentFrameLabel();
	virtual AsString_ref getCurrentLabel();
	virtual AsArray_ref getCurrentLabels();
	virtual bool getEnabled();
	virtual void setEnabled(bool value);
	virtual int getFramesLoaded();
	virtual void gotoAndPlay(const AsObject_ref& frame, const AsString_ref& scene);
	virtual void gotoAndPlay(const AsObject_ref& frame);
	virtual void gotoAndStop(const AsObject_ref& frame, const AsString_ref& scene);
	virtual void gotoAndStop(const AsObject_ref& frame);
	virtual void nextFrame();
	virtual void play();
	virtual void prevFrame();
	virtual void prevScene();
	virtual void stop();
	virtual int getTotalFrames();
	
	static void _as_static_init_AsMovieClip();
	
private:
	static bool _as_static_initialized_AsMovieClip;
	static AsStaticRefInitializer _as_static_initializer_AsMovieClip;
};
 
#endif // AsMovieClip_h__
