#include "Food.h"

void Food::initVariables()
{
}

void Food::initFood()
{
	this->food.setFillColor(sf::Color::Red);
	this->food.setSize(sf::Vector2f(25.f, 25.f));
	this->food.setPosition((rand() % 20) * 25.f, (rand() % 20) * 25.f);
}

Food::Food()
{
	this->initVariables();
	this->spawnFood();
}

Food::~Food()
{
}

void Food::spawnFood()
{
	this->initFood();
}

void Food::remove()
{
	this->initFood();
}

const sf::RectangleShape& Food::getShape() const
{
	// TODO: insert return statement here
	return this->food;
}

void Food::update()
{
}

void Food::render(sf::RenderWindow* window)
{
	window->draw(this->food);
}
