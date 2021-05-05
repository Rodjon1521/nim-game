#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Nim");
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
	this->width = 1280;
	this->height = 720;
	this->initWindow();
	this->initStates();

	/*this->radius = this->height / this->count_row / 4;
	for (int i = this->count_row - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{	
			sf::CircleShape circle(this->radius);
			circle.setPosition(sf::Vector2f{ (float)((this->width / this->count_row) * j),
				(float)((this->height / this->count_row / 2) * i + this->height / 2) });
			circle.setFillColor(sf::Color::Green);
			circles.push_back(circle);
		}
	}*/
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateSFMLEvent()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		//if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		//{
		//	for (auto& circle : this->circles)
		//	{
		//		for (auto& upper_circle : this->circles)
		//		{
		//			if ((this->mousePosView.x - circle.getPosition().x - radius) * (this->mousePosView.x - circle.getPosition().x - radius) +
		//				(this->mousePosView.y - circle.getPosition().y - radius) * (this->mousePosView.y - circle.getPosition().y - radius)
		//				<= radius * radius && upper_circle.getPosition().y >= height / 2 &&
		//				circle.getPosition().x == upper_circle.getPosition().x && circle.getPosition().y >= upper_circle.getPosition().y)
		//			{
		//				circle.move(0, -(this->height - upper_circle.getPosition().y));
		//				//upper_circle.setPosition(sf::Vector2f{ upper_circle.getPosition().x, this->height - upper_circle.getPosition().y - radius*2 });
		//			}
		//		}
		//	}
		//}
			
	}
}

void Game::update()
{
	this->updateSFMLEvent();
	if (!this->states.empty())
	{
		this->states.top()->update();

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->window->close();
	}

	/*for (auto& circle : this->circles)
		circle.setFillColor(sf::Color::Green);

	for (auto& circle : this->circles)
	{
		for (auto& upper_circle : this->circles)
		{
			if ((this->mousePosView.x - circle.getPosition().x - radius) * (this->mousePosView.x - circle.getPosition().x - radius) +
				(this->mousePosView.y - circle.getPosition().y - radius) * (this->mousePosView.y - circle.getPosition().y - radius)
				<= radius * radius && upper_circle.getPosition().y >= height / 2 &&
				circle.getPosition().x == upper_circle.getPosition().x && circle.getPosition().y >= upper_circle.getPosition().y)
			{
				upper_circle.setFillColor(sf::Color::Red);
			}
		}
	}*/

}

void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
	{
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
