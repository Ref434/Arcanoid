#include "Bonus.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int QuantityBonus = 5;
Bonus::Bonus(int i, int j, float left, float right, float up, float down, float Height, float Width) : Rectangle(left, right, up, down, Height, Width)
{
	bonus = 20;
}
void Bonus::SetBonus(int bonus)
{
	this->bonus = bonus;
}
int Bonus::GetBonus()
{
	return bonus;
}
float Bonus::GetUp()
{
	return up;
}
float Bonus::GetDown()
{
	return down;
}
float Bonus::GetLeft()
{
	return left;
}

float Bonus::GetRight()
{
	return right;
}
int Bonus::Check(float upPaddle, float leftPaddle, float rightPaddle)
{
	if (down >= upPaddle && down <= upPaddle + 1 && ((leftPaddle <= right && leftPaddle >= left) || (rightPaddle <= right && rightPaddle >= left)))
	{
		SetLRUD();
		return bonus;
	}
	return 20;
}

void Bonus::SetLRUD()
{
	left = 1100;
	right = 1200;
	down = 1100;
	up = 1100;
}


void Bonus::Draw(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(Width, Height));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(left, up);
	rectangle.setFillColor(sf::Color::Red);
	right = left + Width;
	down = up + Height;
	if (bonus <= QuantityBonus)
		window.draw(rectangle);
}

void Bonus::FallBonus()
{
	if (bonus <= QuantityBonus)
	{
		up +=(float) 0.1;
		down += (float)0.1;
	}
}
