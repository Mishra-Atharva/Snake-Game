#include "Text.h"
#include <sstream>

void Text::initVariables()
{
	this->font.loadFromFile("Font/Copyduck.otf");
}

void Text::initText()
{
	this->ui.setFont(this->font);
	this->ui.setCharacterSize(24);
	this->ui.setFillColor(sf::Color::White);
}

Text::Text()
{
	this->initVariables();
	this->initText();
}

void Text::textInfo(bool& endGame, int& points)
{
	if (endGame)
	{
		std::stringstream ss;
		ss << "You Lose\nPoints: " << points;
		this->ui.setString(ss.str());
		this->ui.setPosition(200.f, 200.f);
	}
}

void Text::update(bool& endGame, int& points)
{
	this->textInfo(endGame, points);
}

void Text::render(sf::RenderWindow* window)
{
	window->draw(this->ui);
}
