#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stack>

#include "State.h"
#include "MainMenuState.h"

class Game
{
private: 
	int width, height;
	sf::RenderWindow* window;

	sf::Event sfEvent;

	std::stack<State*> states;

	int count_row = 4;
	float radius;
	std::vector<sf::CircleShape> circles;

	sf::Vector2f mousePosView;

	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	void updateSFMLEvent();
	void update();

	void render();

	void run();
};

