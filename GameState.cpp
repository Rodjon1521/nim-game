#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, opponents opponent, int count_heap, first_move first)
	: State(window, states)
{
	this->opponent = opponent;
	this->count_heap = count_heap;
	this->first = first;

	this->radius = this->window->getSize().y / this->count_heap / 4;
	for (int i = this->count_heap - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			sf::CircleShape circle(this->radius);
			circle.setPosition(sf::Vector2f{ (float)((this->window->getSize().x / this->count_heap) * j),
				(float)((this->window->getSize().y / this->count_heap / 2) * i + this->window->getSize().y / 2) });
			circle.setFillColor(sf::Color::Green);
			circles.push_back(circle);
		}
	}
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "ENDING MAINMENUSTATE" << std::endl;
}

void GameState::updateKeybinds()
{
	this->checkForQuit();
}

void GameState::update()
{
	this->updateKeybinds();
	for (auto& circle : this->circles)
		circle.setFillColor(sf::Color::Green);

	for (auto& circle : this->circles)
	{
		for (auto& upper_circle : this->circles)
		{
			if ((this->mousePosView.x - circle.getPosition().x - radius) * (this->mousePosView.x - circle.getPosition().x - radius) +
				(this->mousePosView.y - circle.getPosition().y - radius) * (this->mousePosView.y - circle.getPosition().y - radius)
				<= radius * radius && upper_circle.getPosition().y >= this->window->getSize().y / 2 &&
				circle.getPosition().x == upper_circle.getPosition().x && circle.getPosition().y >= upper_circle.getPosition().y)
			{
				upper_circle.setFillColor(sf::Color::Red);
			}
		}
	}
}
 
void GameState::render(sf::RenderTarget* target)
{
	for (auto& circle : this->circles)
		target->draw(circle);
}
