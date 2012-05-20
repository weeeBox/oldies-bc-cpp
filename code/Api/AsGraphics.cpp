#include "AsGraphics.h"
#include "AsBitmapData.h"
#include "AsString.h"
 
void AsGraphics::beginFill(uint color, float alpha)
{
}
 
void AsGraphics::beginFill(uint color)
{
	beginFill(color, 1.0f);
}
 
void AsGraphics::clear()
{
}
 
void AsGraphics::curveTo(float controlX, float controlY, float anchorX, float anchorY)
{
}
 
void AsGraphics::drawCircle(float x, float y, float radius)
{
}
 
void AsGraphics::drawEllipse(float x, float y, float width, float height)
{
}
 
void AsGraphics::drawRect(float x, float y, float width, float height)
{
}
 
void AsGraphics::drawRoundRect(float x, float y, float width, float height, float ellipseWidth, float ellipseHeight)
{
}
 
void AsGraphics::drawBitmap(const AsBitmapData_ref& bitmap, float x, float y)
{
}
 
void AsGraphics::endFill()
{
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps, const AsString_ref& joints, float miterLimit)
{
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps, const AsString_ref& joints)
{
	lineStyle(thickness, color, alpha, pixelHinting, scaleMode, caps, joints, 3);
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode, const AsString_ref& caps)
{
	lineStyle(thickness, color, alpha, pixelHinting, scaleMode, caps, AS_NULL, 3);
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha, bool pixelHinting, const AsString_ref& scaleMode)
{
	lineStyle(thickness, color, alpha, pixelHinting, scaleMode, AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha, bool pixelHinting)
{
	lineStyle(thickness, color, alpha, pixelHinting, ASL("normal"), AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineStyle(float thickness, uint color, float alpha)
{
	lineStyle(thickness, color, alpha, false, ASL("normal"), AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineStyle(float thickness, uint color)
{
	lineStyle(thickness, color, 1.0f, false, ASL("normal"), AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineStyle(float thickness)
{
	lineStyle(thickness, (uint)(0), 1.0f, false, ASL("normal"), AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineStyle()
{
	lineStyle(0, (uint)(0), 1.0f, false, ASL("normal"), AS_NULL, AS_NULL, 3);
}
 
void AsGraphics::lineTo(float x, float y)
{
}
 
void AsGraphics::moveTo(float x, float y)
{
}
 
bool AsGraphics::_as_static_initialized_AsGraphics = false;
AsStaticRefInitializer AsGraphics::_as_static_initializer_AsGraphics(_as_static_init_AsGraphics);
void AsGraphics::_as_static_init_AsGraphics()
{
	if (!_as_static_initialized_AsGraphics)
	{
		_as_static_initialized_AsGraphics = true;
	}
}
