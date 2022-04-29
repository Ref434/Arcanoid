
#include "Arcanoid.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <sstream>
using namespace std;
using namespace sf;
bool ball_sticking = 0, disposable_bottom = 0, change_traectory = 0, second_ball_ = 0;
float Ball_SpeedXX = 0, Ball_SpeedYY = 0;
Arcanoid::Arcanoid(float Height, float Width) 
{
	blocks = new Block**[5];
	bonus = new Bonus**[5];
	for (int i = 0; i <= 5; i++)
	{
		blocks[i] = new Block*[8];
		bonus[i] = new Bonus*[8];
	}
	float Heightblock = Height / 20, Widthblock = Width / 10;
	float left = 5, right = left + Widthblock, up = 5, down = up + Heightblock;
	for (int i = 0; i <= 5; i++)
	{
		left = 5;
		right = left + Widthblock;
		for (int j = 0; j <= 8; j++)
		{
			blocks[i][j] = new Block(i, j, left, right, up, down, Heightblock, Widthblock);
			bonus[i][j] = new Bonus(i, j, left, right, up, down, Heightblock, Widthblock);
			left = right + 5;
			right = left + Widthblock;
		}
		up = down + 5;
		down = up + Heightblock;
	}
	this->Height = Height;
	this->Width = Width;
	

}

void Arcanoid::run()
{
	sf::RenderWindow window(sf::VideoMode((int)Width,(int)Height), "Arcanoid");	
	// Declare and load a font
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	// Create a text
	Text text("", font, 20);
	text.setCharacterSize(30);
	text.setStyle(Text::Bold | Text::Underlined);
	text.setColor(Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		paddle.Move(Width);
		paddle.Draw(window);
		
		ball.Move(Width, Height, paddle.GetUp(), paddle.GetDown(), paddle.GetLeft(), paddle.GetRight(), score, ball_sticking, Ball_SpeedXX, Ball_SpeedYY, disposable_bottom);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ball.Check(paddle.GetUp(), paddle.GetDown(), paddle.GetLeft(), paddle.GetRight()) == 1 )
		{
			ball_sticking = false;
			ball.SetSpeedX(Ball_SpeedXX);
			ball.SetSpeedY(Ball_SpeedYY);
		}
		if (ball.GetSpeedX() == 0)
		{
			ball.SetX((paddle.GetLeft() + paddle.GetRight())/2);
		}
		if (disposable_bottom && ball.Check(Height - 30, Height, 0, Width))
		{
			disposable_bottom = false;
		}
		if (disposable_bottom)
		{
			Rectangle Rect(0, Width, Height - 30, Height, Height, Width);
			Rect.Draw(window);
		}
		if (change_traectory)
		{
			ball.RandomTraectory(change_traectory);
			
		}
		if (second_ball_)
		{
			second_ball.Move(Width, Height, paddle.GetUp(), paddle.GetDown(), paddle.GetLeft(), paddle.GetRight(), score, ball_sticking, Ball_SpeedXX, Ball_SpeedYY, disposable_bottom);
			second_ball.Draw(window);
			CheckStatus(second_ball);
		}
		BallCollision();
		
		ball.Draw(window);
		CreateBlocks(window);
		CheckStatus(ball);
		std::ostringstream playerScoreString;    // объявили переменную
		text.setPosition(1160, 503);//задаем позицию текста, отступая от центра камеры
		playerScoreString << score;		//занесли в нее число очков, то есть формируем строку
		text.setString("Score:" + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		window.draw(text);//рисую этот текст
		for (int i = 0; i <= 5; i++)
		{
			for (int j = 0; j <= 8; j++)
			{
				bonus[i][j]->Draw(window);
				bonus[i][j]->FallBonus();
				switch (bonus[i][j]->Check(paddle.GetUp(),paddle.GetLeft(),paddle.GetRight()))
				{
				case 0:
					ball.SetSpeed();
					cout << "Bonus 1 activated" << endl;
					break;
				case 1:
					cout << "Bonus 2 activated" << endl;
					paddle.GetWidth();
					break;
				case 2:
					cout << "Bonus 3 activated" << endl;
					ball_sticking = true;
					break;
				case 3:
					cout << "Bonus 4 activated" << endl;
					disposable_bottom = true;
					break;
				case 4:
					cout << "Bonus 5 activated" << endl;
					change_traectory = 1;
					break;
				case 5:
					if (!second_ball_)
						cout << "Bonus 6 activated" << endl;
					second_ball_ = true;
					break;
				}
			}
		}
		window.display();
		

	}
}

bool Arcanoid::intersect(Block &block, Ball &ball)
{
	if (block.GetLeft() > ball.GetX() + ball.GetR() || block.GetRight() < ball.GetX())
		return false;
	if (block.GetDown()<ball.GetY() || block.GetUp()>  ball.GetY() + ball.GetR())
		return false;
	return true;
}
bool Arcanoid::intersect(Ball &ball, Ball &second_ball)
{
	if (ball.GetX() > second_ball.GetX() + ball.GetR() || ball.GetX() + ball.GetR() < second_ball.GetX())
		return false;
	if (ball.GetY() + ball.GetR()<second_ball.GetY() || ball.GetY()>  second_ball.GetY() + second_ball.GetR())
		return false;
	return true;
}
void Arcanoid::BallCollision()
{
	if (second_ball_ == 1)
	{
		if (intersect(ball, second_ball))
		{
			if (ball.GetY() + ball.GetR() == second_ball.GetY() || second_ball.GetY() + second_ball.GetR() == ball.GetY())
			{
				ball.SetSpeedY();
				second_ball.SetSpeedY();
			}
			if (ball.GetX() + ball.GetR() == second_ball.GetX() || second_ball.GetX() + second_ball.GetR() == ball.GetX())
			{
				ball.SetSpeedX();
				second_ball.SetSpeedX();
			}
		}
	}
}
void Arcanoid::CheckStatus(Ball &ball)
{
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (intersect(*blocks[i][j], ball))
			{
				if (ball.GetY() + ball.GetR() == blocks[i][j]->GetUp() || blocks[i][j]->GetDown() == ball.GetY())
				{
					ball.SetSpeedY();
				}
				if (ball.GetX() + ball.GetR() == blocks[i][j]->GetLeft() || blocks[i][j]->GetRight() == ball.GetX())
				{
					ball.SetSpeedX();
				}
				blocks[i][j]->SetHealth();
				if (blocks[i][j]->GetType() != 0)
					score++;
				if (blocks[i][j]->GetHealth() == 0)
				{
					blocks[i][j]->SetLRUD();
					bonus[i][j]->SetBonus(blocks[i][j]->GetBonus());
				}
				if (blocks[i][j]->GetType() == 1)
					ball.SetSpeed();
			}
		}
	}
}

void Arcanoid::CreateBlocks(sf::RenderWindow &window)
{
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			blocks[i][j]->Draw(window);
		}
	}
}


Arcanoid::~Arcanoid()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			delete[] blocks[i][j];
			delete[] bonus[i][j];
		}
	}
}

