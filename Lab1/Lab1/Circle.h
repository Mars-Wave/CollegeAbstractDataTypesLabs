#ifndef CIRCLE_H_
#define CIRCLE_H_
class Circle {
public:
	Circle(int leftx, int lefty, int rightx, int righty);
	Circle();
	int area();
	bool isin(int a, int b);
private:
	int leftx;
	int rightx;
	int lefty;
	int righty;
	double radius;
};

#endif
