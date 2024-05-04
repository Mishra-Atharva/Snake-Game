#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Food.h"
#include "Text.h"

class Game
{
private:
  sf::RenderWindow* window;
  sf::VideoMode videoMode;
  sf::Event ev;

  bool gameEnd;
  
  void initVariables();
  void initWindow();


  //classes
  Player player;
  Food food;
  Text text;

public:
  Game();
  virtual ~Game();

  void pollEvents();
  const bool isRunning() const;
  void update();
  void render();
};

