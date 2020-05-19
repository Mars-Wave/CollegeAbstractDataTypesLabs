#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

const double pi = 3.1416;

Circle::Circle(int leftx, int lefty, int rightx, int righty)
{
	this->leftx = leftx;
	this->rightx = rightx;
	this->lefty = lefty;
	this->righty = righty;
	this->radius = (rightx - leftx) / 2;
}

Circle::Circle()
{
	this->leftx = 0;
	this->rightx = 0;
	this->lefty = 0;
	this->righty = 0;
	this->radius =0;
}
int Circle::area()
{
	return int(pow(radius,2)*pi);
}

bool Circle::isin(int x, int y)
{
	int movex = rightx - radius;
	int movey = righty; //prepare for move to 0,0
	x -= movex;
	y -= movey; //Move points to assume center of the circle is in 0,0
	return (sqrt(pow(x, 2) + pow(y, 2)) <= radius); //Pythagoras for distance <= radius?
}
