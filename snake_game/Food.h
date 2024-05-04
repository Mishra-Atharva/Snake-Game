#pragma once
#include <SFML/Graphics.hpp>

class Food
{
private:
	sf::RectangleShape food;
	
	void initVariables();
	void initFood();

public:
	Food();
	virtual ~Food();

	const sf::RectangleShape& getShape() const;
	
	void spawnFood();
	void remove();

	void update();
	void render(sf::RenderWindow* window);
};