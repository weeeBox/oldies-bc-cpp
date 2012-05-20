#ifndef AsBitmap_h__
#define AsBitmap_h__
 
#include "AsBc.h"
 
#include "AsDisplayObject.h"
 
#include "AsString.h"
 
AS_CLASS(AsBitmapData);
AS_CLASS(AsPoint);
AS_CLASS(AsMatrix);
AS_CLASS(AsRenderSupport);
AS_CLASS(AsRectangle);
AS_CLASS(AsDisplayObject);
 
AS_CLASS(AsBitmap);
 
class AsBitmap : public AsDisplayObject
{
public:
	AS_OBJ(AsBitmap, AsDisplayObject);
	
private:
	AsBitmapData_ref mBitmapData;
	AsString_ref mPixelSnapping;
	bool mSmoothing;
	static AsPoint_ref sHelperPoint;
	static AsMatrix_ref sHelperMatrix;
	static AsPoint_ref sPosition;
	
public:
	virtual void render(const AsRenderSupport_ref& support, float alpha);
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace, const AsRectangle_ref& resultRect);
	virtual AsRectangle_ref getBounds(const AsDisplayObject_ref& targetSpace);
	virtual AsBitmapData_ref getBitmapData();
	virtual void setBitmapData(const AsBitmapData_ref& value);
	virtual AsString_ref getPixelSnapping();
	virtual void setPixelSnapping(const AsString_ref& value);
	virtual bool getSmoothing();
	virtual void setSmoothing(bool value);
	
	
public:
	static AsBitmap_ref _as_create_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping, bool smoothing);
	static AsBitmap_ref _as_create_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping);
	static AsBitmap_ref _as_create_AsBitmap(const AsBitmapData_ref& bitmapData);
	static AsBitmap_ref _as_create_AsBitmap();
	
protected:
	void _as_construct_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping, bool smoothing);
	void _as_construct_AsBitmap(const AsBitmapData_ref& bitmapData, const AsString_ref& pixelSnapping);
	void _as_construct_AsBitmap(const AsBitmapData_ref& bitmapData);
	void _as_construct_AsBitmap();
	
public:
	static void _as_static_init_AsBitmap();
	
private:
	static bool _as_static_initialized_AsBitmap;
	static AsStaticRefInitializer _as_static_initializer_AsBitmap;
	
public:
	void _as_gc_mark();
	
	
protected:
	AsBitmap();
};
 
#endif // AsBitmap_h__
