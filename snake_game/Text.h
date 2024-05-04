#pragma once
#include <SFML/Graphics.hpp>

class Text
{
private:
	sf::Font font;
	sf::Text ui;

	void initVariables();
	void initText();

public:
	Text();
	
	void textInfo(bool& endGame, int& points);
	void update(bool& endGame, int& points);
	void render(sf::RenderWindow* window);
};

