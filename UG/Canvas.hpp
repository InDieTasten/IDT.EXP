#ifndef _Canvas_hpp_
#define _Canvas_hpp_

#include <string.h>
#include "DataBank.hpp"

class Canvas
{
	//MEMBERS
private:
public:
	int X;
	int Y;
	int Height;
	int Width;
	std::string ID;

	//CONSTRUCTORS

	//DESTRUCTORS

	//METHODS
	void Show();
	void Hide();

	void Setup();
	void Update(DataBank* _dataLink);
	void Render(DataBank* _dataLink);
	void handleEvent(sf::Event* _event, const sf::Input* _input);
};

#endif