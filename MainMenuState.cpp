#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	this->font.loadFromFile("Fonts/arial.ttf");
}

void MainMenuState::initButtons()
{
	// OPPONENT
	this->buttons["BEGINER"] = new Button(100, 100, 200, 60,
		&this->font, "Beginner",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["ADVANCED"] = new Button(400, 100, 200, 60,
		&this->font, "Advanced",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["PROFESSIONAL"] = new Button(700, 100, 200, 60,
		&this->font, "Professional",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["HUMAN"] = new Button(1000, 100, 200, 60,
		&this->font, "Human",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	// number of heap
	this->buttons["1"] = new Button(100, 300, 100, 60,
		&this->font, "1",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["2"] = new Button(300, 300, 100, 60,
		&this->font, "2",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["3"] = new Button(500, 300, 100, 60,
		&this->font, "3",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["4"] = new Button(700, 300, 100, 60,
		&this->font, "4",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["5"] = new Button(900, 300, 100, 60,
		&this->font, "5",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	//who goes first
	this->buttons["PLAYER"] = new Button(100, 500, 200, 60,
		&this->font, "Player",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["COMPUTER"] = new Button(400, 500, 200, 60,
		&this->font, "Computer",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["START"] = new Button(1100, 600, 100, 100,
		&this->font, "Start",
		sf::Color(40, 40, 40, 255), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void MainMenuState::initLabels()
{
	this->labels.push_back(new Label(100, 0, &this->font, "Choose your opponent", 40, sf::Color::Black, sf::Text::Style::Bold));
	this->labels.push_back(new Label(100, 200, &this->font, "Select the number of heaps", 40, sf::Color::Black, sf::Text::Style::Bold));
	this->labels.push_back(new Label(100, 400, &this->font, "Choose who goes first", 40, sf::Color::Black, sf::Text::Style::Bold));
}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	/*this->bgTexture.loadFromFile("Textures/bg.png");
	this->background.setTexture(&this->bgTexture);*/
	this->background.setFillColor(sf::Color::White);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	initFonts();
	initButtons();
	initBackground();
	initLabels();
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "ENDING MAINMENUSTATE" << std::endl;
}

void MainMenuState::updateKeybinds()
{
	this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void MainMenuState::update()
{
	this->updateKeybinds();
	this->updateMousePos();

	this->updateButtons();
	
	if (buttons["START"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states, this->opponet, this->count_heap, this->first));
	}
	
	if (buttons["BEGINER"]->isPressed()) this->opponet = opponents::BEGINER;
	if (buttons["ADVANCED"]->isPressed()) this->opponet = opponents::ADVANCED;
	if (buttons["PROFESSIONAL"]->isPressed()) this->opponet = opponents::PROFESSIONAL;
	if (buttons["HUMAN"]->isPressed()) this->opponet = opponents::HUMAN;

	if (buttons["1"]->isPressed()) this->count_heap = 1;
	if (buttons["2"]->isPressed()) this->count_heap = 2;
	if (buttons["3"]->isPressed()) this->count_heap = 3;
	if (buttons["4"]->isPressed()) this->count_heap = 4;
	if (buttons["5"]->isPressed()) this->count_heap = 5;

	if (buttons["COMPUTER"]->isPressed()) this->first = first_move::COMPUTER;
	if (buttons["PLAYER"]->isPressed()) this->first = first_move::PLAYER;
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
		it.second->render(target);
}

void MainMenuState::renderLabels(sf::RenderTarget* target)
{
	for (auto& it : this->labels)
		it->render(target);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
	this->renderLabels(target);

}

