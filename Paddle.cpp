
#include "Paddle.h"
#include <cstdlib>
Paddle::Paddle(float left, float right, float up, float down, float Height, float Width) : Rectangle(left, right, up, down, Height, Width)
{
	srand((unsigned int)time(NULL));
	speed = 0;
}
void Paddle::Move(float WidthOfScreen)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			speed = -1;
			left += (float)speed;
			if (left <= 0)
			{
				left += (float) 1;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			speed = 1;
			left += (float)speed;
			if (right >= WidthOfScreen)
			{
				left -= (float) 1;
			}
		}
}
float Paddle::GetSpeed()
{
	return speed;
}
void Paddle::SetWidth()
{
	Width += 10;
}
float Paddle::GetUp()
{
	return up;
}
float Paddle::GetDown()
{
	return down;
}
float Paddle::GetLeft()
{
	return left;
}

float Paddle::GetRight()
{
	return right;
}
float Paddle::GetWidth()
{
	return Width;
}