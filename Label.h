#ifndef LABEL_H
#define LABEL_H

#include <SFML/Graphics.hpp>
#include <string>

class Label
{
private:
	sf::Text text;
	sf::Font* font;
	sf::Color color;

public:
	Label(float x, float y, sf::Font* font, std::string text, int size, sf::Color color, sf::Text::Style style);
	~Label();

	void render(sf::RenderTarget* target);
};

#endif // !LABEL_H
