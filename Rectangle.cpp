#include "Rectangle.h"

Rectangle::Rectangle(float left, float right, float up, float down, float Height, float Width)
{
	this->left = left;
	this->right = left + Width;
	this->up = up;
	this->down = down;
	this->Height = Height;
	this->Width = Width;
}


void Rectangle::Draw(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(Width, Height));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(left,up);
	right = left + Width;
	down = up + Height;

	window.draw(rectangle);
}
