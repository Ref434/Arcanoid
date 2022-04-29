#ifndef ARKANOID_H
#define ARKANOID_H


#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "Block.h"
#include "Paddle.h"
#include "Ball.h"
#include <stdlib.h>
#include "Bonus.h"

class Arcanoid
{

public:
	Arcanoid(float Width, float Height);
	void CreateBlocks(sf::RenderWindow &window);
	void CheckStatus(Ball &ball);
	void BallCollision();
	void run();
	bool intersect(Block &block, Ball &ball);
	bool intersect(Ball &ball, Ball &second_ball);
	~Arcanoid();

private:
	float Height;
	float Width;
	int score = 0;
	sf::RenderWindow window;
	Block ***blocks;
	Paddle paddle = {600,680,700,730,30,80};
	Ball ball = { 800, 600, 10 };
	Ball second_ball = { 800, 600, 10 };
	Bonus ***bonus;
};


#endif
