#ifndef BALL_H
#define BALL_H


#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float x, float y, float R);
	void Draw(sf::RenderWindow &window);
	void Move(float WidthOfScreen, float &HeightOfScreen, float PaddleUp, float PaddleDown, float PaddleLeft, float PaddleRight, int &score, bool &ball_sticking, float &S11, float &S22, bool &disposable_bottom);
	//void Move(float WidthOfScreen, float &HeightOfScreen, float PaddleUp, float PaddleDown, float PaddleLeft, float PaddleRight, int &score);
	bool Check(float up, float down, float left, float right);
	bool intersect(float PaddleLeft, float PaddleRight, float PaddleUp, float PaddleDown);
	void Sticking(float &SpeedXX,float &SpeedYY);
	float GetX();
	float GetY();
	float GetR();
	float GetSpeedX();
	float GetSpeedY();
	void SetSpeedX();
	void RandomTraectory(bool &change_traectory);
	void SetX(float x);
	void SetSpeedX(float SpeedX);
	void SetSpeedY();
	void SetSpeedY(float SpeedY);
	void SetSpeed();
protected:
	float x;
	float y;
	float R;
	double speed = {0.5 };
	float SpeedX = (float)-speed;
	float SpeedY = (float)-speed;
	
};



#endif
