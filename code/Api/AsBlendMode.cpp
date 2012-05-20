#include "AsBlendMode.h"
 
AsString_ref AsBlendMode::NORMAL(true);
AsString_ref AsBlendMode::LAYER(true);
AsString_ref AsBlendMode::MULTIPLY(true);
AsString_ref AsBlendMode::SCREEN(true);
AsString_ref AsBlendMode::LIGHTEN(true);
AsString_ref AsBlendMode::DARKEN(true);
AsString_ref AsBlendMode::ADD(true);
AsString_ref AsBlendMode::SUBTRACT(true);
AsString_ref AsBlendMode::DIFFERENCE(true);
AsString_ref AsBlendMode::INVERT(true);
AsString_ref AsBlendMode::OVERLAY(true);
AsString_ref AsBlendMode::HARDLIGHT(true);
AsString_ref AsBlendMode::ALPHA(true);
AsString_ref AsBlendMode::ERASE(true);
AsString_ref AsBlendMode::SHADER(true);
 
bool AsBlendMode::_as_static_initialized_AsBlendMode = false;
AsStaticRefInitializer AsBlendMode::_as_static_initializer_AsBlendMode(_as_static_init_AsBlendMode);
void AsBlendMode::_as_static_init_AsBlendMode()
{
	if (!_as_static_initialized_AsBlendMode)
	{
		_as_static_initialized_AsBlendMode = true;
		
		NORMAL = ASL("normal");
		LAYER = ASL("layer");
		MULTIPLY = ASL("multiply");
		SCREEN = ASL("screen");
		LIGHTEN = ASL("lighten");
		DARKEN = ASL("darken");
		ADD = ASL("add");
		SUBTRACT = ASL("subtract");
		DIFFERENCE = ASL("difference");
		INVERT = ASL("invert");
		OVERLAY = ASL("overlay");
		HARDLIGHT = ASL("hardlight");
		ALPHA = ASL("alpha");
		ERASE = ASL("erase");
		SHADER = ASL("shader");
	}
}
