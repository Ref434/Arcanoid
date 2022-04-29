#ifndef Rectangle_H
#define Rectangle_H


#include <SFML/Graphics.hpp>

class Rectangle
{
public:
	Rectangle(float left, float right, float up, float down, float Height, float Width);
	virtual void Draw(sf::RenderWindow &window);

protected:
	float left;
	float right;
	float up;
	float down;
	float Height;
	float Width;
};



#endif
