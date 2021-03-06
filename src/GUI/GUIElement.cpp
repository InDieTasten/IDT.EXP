#include <GUI\GUIElement.hpp>

GUIElement::GUIElement(AssetManager* _assets) : Responsive(_assets)
{
	EXP::log("[Info]Constructing GUIElement... " + utils::tostring(this));
	type = ElementType::undefined;
	x = 0;
	y = 0;
	EXP::log("[Info]GUIElement has been constructed: " + utils::tostring(this));
}
GUIElement::~GUIElement()
{
	EXP::log("[Info]Destructing GUIElement... " + utils::tostring(this));
	EXP::log("[Info]GUIElement has been destructed: " + utils::tostring(this));
}

void GUIElement::setX(int _x)
{
	x = _x;
	update();
}
void GUIElement::setY(int _y)
{
	y = _y;
	update();
}
int GUIElement::getX()
{
	return x;
}
int GUIElement::getY()
{
	return y;
}
