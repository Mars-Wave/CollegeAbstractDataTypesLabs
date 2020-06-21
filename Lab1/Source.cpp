//TOMAS MORO and HUGO GARCIA I05
#include <iostream>
#include "Circle.h"
using namespace std;

int main() {
	int n, i = 0, rightx, righty, leftx, lefty, x, y;
	cin >> n; 
	Circle *c = new Circle();
	while (i < n) {
		cin >> leftx >> lefty >> rightx >> righty >> x >> y;
		*c = Circle(leftx, lefty, rightx, righty);
		cout << c->area() << " ";
		if (c->isin(x, y) ) {
			cout << "yes";
			}
		else {
			cout << "no";
		}
		cout << endl;
		i++;
	}
	return 0;
}

/*
When we began we thought that we could spatially arrange all of the objects so that we could know by knowing all of the possible points inside the circle
if the target point could be inside it. Then we changed minds when we thought about a different approach. 
By "Centering" the circle in the 0,0 point we can just check if pythagoras of the point on the 1st quadrant respect to 0,0 is less or equal than the radius,
if it is it must be inside the circle, if it isn't it must not.

We didn't use point objects since the goal of the exercise was very simple and it seemed like writing the object itself would have taken more time than just
using primitive data types.
*/