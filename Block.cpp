
#include "Block.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Block::Block(int i, int j, float left, float right, float up, float down, float Height, float Width) : Rectangle(left, right, up, down, Height, Width)
{
	health = (rand()%2)+1;
	bonus = rand()%30;
	type = rand() % 20;
}

int Block::GetBonus()
{
	return bonus;
}
float Block::GetUp()
{
	return up;
}
float Block::GetDown()
{
	return down;
}
float Block::GetLeft()
{
	return left;
}

float Block::GetRight()
{
	return right;
}
int Block::GetHealth()
{
	return health;
}
void Block::SetHealth()
{
	if (type!=0)
		health -= 1;
}
void Block::SetLRUD()
{
	left = 1100;
	right = 1200;
	down=1100;
	up = 1100;
}
int Block::GetType()
{
	return type;

}

void Block::Draw(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(Width, Height));
	if (type == 0 && health != 0)
		rectangle.setFillColor(sf::Color::Blue);
	if (type != 0 && health != 0)
		rectangle.setFillColor(sf::Color::Red);
	if (type == 1 && health != 0)
		rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(left, up);
	if (health <= 0 && type!=0)
	{
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(1100, 1100);
	}
	right = left + Width;
	down = up + Height;
	window.draw(rectangle);
}

