#ifndef PADDLE_H
#define PADDLE_H


#include <SFML/Graphics.hpp>
#include "Rectangle.h"

class Paddle :public Rectangle
{
public:
	Paddle(float left, float right, float up, float down, float Height, float Width);
	void Move(float WidthOfScreen);
	float GetUp();
	float GetLeft();
	float GetRight();
	float GetDown();
	float GetWidth();
	float GetSpeed();
	void SetWidth();
private:
	float speed;



};


#endif