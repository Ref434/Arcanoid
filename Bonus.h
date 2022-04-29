#ifndef BONUS_H
#define BONUS_H


#include <SFML/Graphics.hpp>
#include "Rectangle.h"

class Bonus :public Rectangle
{
public:
	Bonus(int i, int j, float left, float right, float up, float down, float Height, float Width);
	void Draw(sf::RenderWindow &window);
	int Check(float upPaddle, float leftPaddle, float rightPaddle);
	float GetLeft();
	float GetRight();
	float GetUp();
	float GetDown();
	int GetBonus();
	void SetLRUD();
	void SetBonus(int bonus);
	void FallBonus(); 


private:
	int bonus;
	int i;
	int j;



};


#endif