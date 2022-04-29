#include <SFML/Graphics.hpp>

#include "Arcanoid.h"
#include <iostream>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	Arcanoid Arcanoid(800.f, 1300.f);
	Arcanoid.run();
	cout << "END"<<endl;
	return 0;
}