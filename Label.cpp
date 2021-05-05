#include "Label.h"


Label::Label(float x, float y, sf::Font* font, std::string text, int size, sf::Color color,
	sf::Text::Style style)
{
	this->text.setPosition(sf::Vector2f{ x,y });

	this->font = font;
	this->text.setFont(*this->font);

	this->text.setString(text);

	this->color = color;
	this->text.setFillColor(this->color);

	this->text.setCharacterSize(size);

	this->text.setStyle(style);
}

Label::~Label()
{

}

void Label::render(sf::RenderTarget* target)
{
	target->draw(this->text);
}