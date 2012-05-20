#ifndef AsColorTransform_h__
#define AsColorTransform_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsColorTransform_h__
#include "AsColorTransform.h"
#else
AS_CLASS(AsColorTransform);
#endif // AsColorTransform_h__
 
 
AS_CLASS(AsColorTransform);
 
class AsColorTransform : public AsObject
{
public:
	AS_OBJ(AsColorTransform, AsObject);
	
public:
	float redMultiplier;
	float greenMultiplier;
	float blueMultiplier;
	float alphaMultiplier;
	float redOffset;
	float greenOffset;
	float blueOffset;
	float alphaOffset;
	
public:
	virtual uint getColor();
	virtual void setColor(uint newColor);
	virtual void concat(const AsColorTransform_ref& second);
	
	
public:
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset, float alphaOffset);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier, float greenMultiplier);
	static AsColorTransform_ref _as_create_AsColorTransform(float redMultiplier);
	static AsColorTransform_ref _as_create_AsColorTransform();
	
protected:
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset, float alphaOffset);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset, float blueOffset);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset, float greenOffset);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier, float redOffset);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier, float alphaMultiplier);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier, float blueMultiplier);
	void _as_construct_AsColorTransform(float redMultiplier, float greenMultiplier);
	void _as_construct_AsColorTransform(float redMultiplier);
	void _as_construct_AsColorTransform();
	
public:
	static void _as_static_init_AsColorTransform();
	
private:
	static bool _as_static_initialized_AsColorTransform;
	static AsStaticRefInitializer _as_static_initializer_AsColorTransform;
	
	
protected:
	AsColorTransform();
};
 
#endif // AsColorTransform_h__
