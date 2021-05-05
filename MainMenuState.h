#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <map>

#include "State.h"
#include "Button.h"
#include "Label.h"
#include "GameState.h"

class MainMenuState :
	public State
{
private:
	sf::Texture bgTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;
	std::vector<Label*> labels;

	opponents opponet;
	int count_heap;
	first_move first;

	void initFonts();
	void initButtons();
	void initLabels();
	void initBackground();

public:
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainMenuState();

	void endState();
	void updateKeybinds();
	void updateButtons();
	void update();
	void renderButtons(sf::RenderTarget* target = nullptr);
	void renderLabels(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};

#endif

