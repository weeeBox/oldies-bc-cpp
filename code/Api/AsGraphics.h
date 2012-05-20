#ifndef AsGraphics_h__
#define AsGraphics_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
 
#ifndef AsBitmapData_h__
#include "AsBitmapData.h"
#else
AS_CLASS(AsBitmapData);
#endif // AsBitmapData_h__
#include "AsString.h"
 
 
AS_CLASS(AsGraphics);
 
class AsGraphics : public AsObject
{
public:
	AS_OBJ(AsGraphics, AsObject);
	
public:
	virtual void beginFill(uint color, float alpha);
	virtual void beginFill(uint color);
	virtual void clear();
	virtual void curveTo(float controlX, float controlY, float anchorX, float anchorY);
	virtual void drawCircle(float x, float y, float radius);
	virtual void drawEllipse(float x, float y, float width, float height);
	virtual void drawRect(float x, float y, float width, float height);
	virtual void drawRoundRect(float x, float y, float width, float height, float ellipseWidth, float ellipseHeight);
	virtual void drawBitmap(const AsBitmapData_ref& bitmap, float x, float y);
	virtual void endFill();
	virtual void lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps, const AsString_ref& joints, float miterLimit);
	virtual void lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps, const AsString_ref& joints);
	virtual void lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps);
	virtual void lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode);
	virtual void lineStyle(float thickness, uint color, float alpha, bool pixelHinting);
	virtual void lineStyle(float thickness, uint color, float alpha);
	virtual void lineStyle(float thickness, uint color);
	virtual void lineStyle(float thickness);
	virtual void lineStyle();
	virtual void lineTo(float x, float y);
	virtual void moveTo(float x, float y);
	
	static void _as_static_init_AsGraphics();
	
private:
	static bool _as_static_initialized_AsGraphics;
	static AsStaticRefInitializer _as_static_initializer_AsGraphics;
};
 
#endif // AsGraphics_h__
