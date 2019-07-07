#include "pch.h"
#include "State.h"

void State::InitBorders()
{
	//A falak elhelyezkedése
//a fenti fal _____________
	
	UpperRect.setPosition(10.0f, 0.0f);
	UpperRect.setFillColor(sf::Color::Blue);
	UpperRect.setSize(sf::Vector2f(780.0f, 10.0f));

	//bal oldali
	//    ___________
	//   |
	//   | 
	//   |
	//   |
	LeftRect.setPosition(0.0f, 0.0f);
	LeftRect.setFillColor(sf::Color::Blue);
	LeftRect.setSize(sf::Vector2f(10.0f, 600.0f));

	//lenti fal lenti vízszintes
	//  ______________
	// |
	// |
	// |
	// |______________

	DownRect.setPosition(10.0f, 590.0f);
	DownRect.setFillColor(sf::Color::Blue);
	DownRect.setSize(sf::Vector2f(780.0f, 10.0f));

	//jobb oldali fal
	//  _____________
	// |             |
	// |             |
	// |             |
	// |_____________|

	RightRect.setPosition(790.0f, 0.0f);
	RightRect.setFillColor(sf::Color::Blue);
	RightRect.setSize(sf::Vector2f(10.0f, 600.0f));

	borders.push_back(UpperRect);
	borders.push_back(DownRect);
	borders.push_back(LeftRect);
	borders.push_back(RightRect);

	if (!font.loadFromFile("arial.ttf")) {
	
	}
}

State::State(sf::RenderWindow* window):

		play(false),
		quit(false)
{

	this->window = window;
}

State::~State()
{
}
