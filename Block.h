#ifndef BLOCK_H
#define BLOCK_H


#include <SFML/Graphics.hpp>
#include "Rectangle.h"

class Block:public Rectangle
{
public:
	Block(int i, int j, float left, float right, float up, float down, float Height, float Width);
	void Draw(sf::RenderWindow &window);
	float GetLeft();
	float GetRight();
	float GetUp();
	float GetDown();
	int GetType();
	int GetHealth();
	int GetBonus();
	void SetHealth();
	void SetLRUD();
	

private:
	int health;
	int bonus;
	int type;
	int i;
	int j;


	
};


#endif