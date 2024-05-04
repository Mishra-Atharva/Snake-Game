#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"

class Player
{
private:
	sf::RectangleShape snake;
	std::vector<sf::RectangleShape> snake_body;

	float velocityX;
	float velocityY;
	int snakeHead;
	float moveTimer;
	float moveTimerMax;

	void initVariables();
	void initSnake();

public:
	int points;
	Player();
	virtual ~Player();

	void spawnSnake(float x, float y);
	void playerInput();
	void moveSnake();
	void windowCollision(const sf::RenderWindow& window, bool& endGame);
	void foodCollision(Food& food);
	void snakeCollision(bool& endGame);

	void update(sf::RenderWindow* window, bool& endGame, Food& food);
	void render(sf::RenderWindow* window);
};

