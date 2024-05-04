#include "Game.h"

void Game::initVariables()
{
	this->gameEnd = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(500, 500);
	this->window = new sf::RenderWindow(this->videoMode, "Snake");
	this->window->setFramerateLimit(60);
}

Game::Game() :player(), food(), text()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape || gameEnd)
			{
				this->window->close();
				break;
			}
		}
	}
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	if (!this->gameEnd)
	{
		this->player.update(this->window, this->gameEnd, this->food);
		this->text.update(this->gameEnd, this->player.points);
	}
}

void Game::render()
{
	this->window->clear();

	if (!this->gameEnd)
	{
		//classes
		this->food.render(this->window);
		this->player.render(this->window);
	}
	this->text.render(this->window);

	this->window->display();
}