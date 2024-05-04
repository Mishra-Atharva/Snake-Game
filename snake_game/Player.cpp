#include "Player.h"
#include <iostream>

void Player::initVariables()
{
	this->velocityX = 0.f;
	this->velocityY = 0.f;
	this->snakeHead = 0;
	this->moveTimerMax = 70.f;
	this->moveTimer = this->moveTimerMax;
	this->points = 0;
}

void Player::initSnake()
{
	this->snake.setFillColor(sf::Color::Green);
	this->snake.setOutlineThickness(2.f);
	this->snake.setOutlineColor(sf::Color::White);
	this->snake.setSize(sf::Vector2f(25.f, 25.f));
}

Player::Player()
{
	this->initVariables();
	this->initSnake();
	this->spawnSnake(250.f, 250.f);
}

Player::~Player()
{
}

void Player::spawnSnake(float x, float y)
{
	this->snake.setPosition(x, y);
	this->snake_body.push_back(this->snake);
}

void Player::playerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->velocityX != -1.f)
	{
		this->velocityX = 1.f;
		this->velocityY = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->velocityX != 1.f)
	{
		this->velocityX = -1.f;
		this->velocityY = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->velocityY != 1.f)
	{
		this->velocityX = 0.f;
		this->velocityY = -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->velocityY != -1.f)
	{
		this->velocityX = 0.f;
		this->velocityY = 1.f;
	}
}

void Player::moveSnake()
{
	if (this->moveTimer < this->moveTimerMax)
	{
		this->moveTimer += 10.f;
	}
	else 
	{
		this->snake_body[this->snakeHead].setPosition(this->snake_body[this->snakeHead].getPosition().x + (this->velocityX * 25.f), this->snake_body[this->snakeHead].getPosition().y + (this->velocityY * 25.f));
		if (this->snake_body.size() > 1)
		{
			for (size_t body = this->snake_body.size()-1; body > 0; body--)
			{
				this->snake_body[body].setPosition(this->snake_body[body-1].getPosition());
			}	
		}		
		this->moveTimer = 0.f;
	}
	
}

void Player::windowCollision(const sf::RenderWindow& window, bool& endGame)
{
	
	if (this->snake_body[this->snakeHead].getPosition().x < 0)
	{
		endGame = true;
	}
	else if (this->snake_body[this->snakeHead].getPosition().x > window.getSize().x - this->snake.getSize().x)
	{
		endGame = true;
	}
	else if (this->snake_body[this->snakeHead].getPosition().y < 0)
	{
		endGame = true;
	}
	else if (this->snake_body[this->snakeHead].getPosition().y > window.getSize().y - this->snake.getSize().y)
	{
		endGame = true;
	}
}

void Player::foodCollision(Food& food)
{
	if (this->snake_body[this->snakeHead].getPosition().x == food.getShape().getPosition().x && this->snake_body[this->snakeHead].getPosition().y == food.getShape().getPosition().y)
	{
		this->spawnSnake(food.getShape().getPosition().x, food.getShape().getPosition().y-25.f);
		food.remove();
		this->points++;
	}
}

void Player::snakeCollision(bool& endGame)
{
	for (size_t body = 2; body < this->snake_body.size(); body++)
	{
		if (this->snake_body[this->snakeHead].getPosition().x == this->snake_body[body].getPosition().x && this->snake_body[this->snakeHead].getPosition().y == this->snake_body[body].getPosition().y)
		{
			endGame = true;
			/*
			std::cout << "Head: " << body << std::endl;
			std::cout << this->snake_body[this->snakeHead].getPosition().x << "," << this->snake_body[this->snakeHead].getPosition().y << std::endl;
			std::cout << this->snake_body[1].getPosition().x << "," << this->snake_body[1].getPosition().y << std::endl;
			std::cout << this->snake_body[body].getPosition().x << "," << this->snake_body[body].getPosition().y << std::endl;
			*/
		}
	}
}


void Player::update(sf::RenderWindow* window, bool& endGame, Food& food)
{
	this->moveSnake();
	this->playerInput();
	this->snakeCollision(endGame);
	this->windowCollision(*window, endGame);
	this->foodCollision(food);
}

void Player::render(sf::RenderWindow* window)
{
	for (auto& snake : this->snake_body)
	{
		window->draw(snake);
	}
}
