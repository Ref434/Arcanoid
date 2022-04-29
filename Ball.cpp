#include "Ball.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Ball::Ball(float x, float y, float R)
{
	this->x = x;
	this->y = y;
	this->R = R;
}
void Ball::Sticking(float &SpeedXX,float &SpeedYY)
{
	SpeedXX = SpeedX;
	SpeedYY = SpeedY;
	SpeedX = 0;
	SpeedY = 0;
}

void Ball::Draw(sf::RenderWindow &window)
{
	sf::CircleShape shape((float)R);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition((float)x, (float)y);
	window.draw(shape);
}

bool Ball::Check(float up, float down, float left, float right)
{
	if (intersect(left, right, up, down))
	{
		return true;
	}
	return false;
}
void Ball::SetSpeedX()
{
	SpeedX = -SpeedX;
}
void Ball::SetSpeedX(float SpeedX)
{
	this->SpeedX = SpeedX;
}
void Ball::SetSpeedY(float SpeedY)
{
	this->SpeedY = SpeedY;
}
void Ball::SetSpeedY()
{
	SpeedY = -SpeedY;
}
void Ball::Move(float WidthOfScreen, float &HeightOfScreen, float PaddleUp, float PaddleDown, float PaddleLeft, float PaddleRight, int &score, bool &ball_sticking, float &SpeedXX, float &SpeedYY, bool &disposable_bottom)
{
	x += SpeedX;
	y += SpeedY;
	if (x <= 0)
	{
		SpeedX = (float)-(SpeedX);
	}
	if (x+2*R >= WidthOfScreen)
	{
		SpeedX = (float)-(SpeedX);
	}
	if (y <= 0)
	{
		SpeedY = (float)-(SpeedY);
	}
	if (disposable_bottom)
	{
		if (y + 2 * R == HeightOfScreen-20)
		{
			SpeedY = (float)-(SpeedY);
		}
	}
	if (y + 2 * R >= HeightOfScreen)
	{
		SpeedY = (float)-(SpeedY);
		score--;
	}
	if (intersect(PaddleLeft, PaddleRight, PaddleUp, PaddleDown))
	{
		if (y + R == PaddleUp || PaddleDown == y)
		{
			SpeedY = -(SpeedY);
		}
		if (x + R == PaddleLeft || PaddleRight == x)
		{
			SpeedX = -(SpeedX);
		}
		if (ball_sticking)
		{
			Sticking(SpeedXX, SpeedYY);
			ball_sticking = false;
		}
	}
	

}
/*void Ball::Move(float WidthOfScreen, float &HeightOfScreen, float PaddleUp, float PaddleDown, float PaddleLeft, float PaddleRight, int &score)
{
	x += SpeedX;
	y += SpeedY;
	if (x <= 0)
	{
		SpeedX = (float)-(SpeedX);
	}
	if (x + 2 * R >= WidthOfScreen)
	{
		SpeedX = (float)-(SpeedX);
	}
	if (y <= 0)
	{
		SpeedY = (float)-(SpeedY);
	}
	if (y + 2 * R >= HeightOfScreen - 35)
	{
		SpeedY = (float)-(SpeedY);
	}
	if (y + 2 * R >= HeightOfScreen)
	{
		SpeedY = (float)-(SpeedY);
		score--;
	}
	if (intersect(PaddleLeft, PaddleRight, PaddleUp, PaddleDown))
		{
		if (y + R == PaddleUp || PaddleDown == y)
			{
				SpeedY = -(SpeedY);
			}
		if (x + R == PaddleLeft || PaddleRight == x)
			{
				SpeedX = -(SpeedX);
			}
		}

}*/
bool  Ball::intersect(float PaddleLeft, float PaddleRight, float PaddleUp, float PaddleDown)
{
	if (PaddleLeft > x + R || PaddleRight < x)
		return false;
	if (PaddleDown<y || PaddleUp>  y + R)
		return false;
	return true;
}
float Ball::GetX()
{
	return x;
}

float Ball::GetY()
{
	return y;
}
float Ball::GetR()
{
	return R;
}
void Ball::SetSpeed()
{
	speed+=0.01;
}

float Ball::GetSpeedX()
{
	return SpeedX;
}
float Ball::GetSpeedY()
{
	return SpeedY;
}
void Ball::SetX(float x)
{
	this->x = x;
}

void Ball::RandomTraectory(bool &change_traectory)
{
	int Rand = rand()%10000;
	if (Rand == 0)
	{
		SpeedX = -SpeedX;
		change_traectory = false;
	}
	if (Rand == 1)
	{
		SpeedY = -SpeedY;
		change_traectory = false;
	}
}