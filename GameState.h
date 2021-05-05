#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "MainMenuState.h"

class GameState :
	public State
{
private:
	opponents opponent;
	int count_heap;
	first_move first;

	float radius;
	std::vector<sf::CircleShape> circles;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states, opponents opponent, int count_heap, first_move first);
	virtual ~GameState();

	void endState();
	void updateKeybinds();

	void update();
	void render(sf::RenderTarget* target = nullptr);
};


#endif
