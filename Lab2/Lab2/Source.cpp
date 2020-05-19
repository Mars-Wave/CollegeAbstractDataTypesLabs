#include <iostream>
#include "Polynomial.h"
using namespace std;


int main() {
	const int maxCoef = 10;
	int numtries, lengthA, lengthB, op;
	int coefA[maxCoef];
	int coefB[maxCoef];
	Polynomial<int> A, B, C;
	cin >> numtries;
	for (int i = 0; i < numtries; i++)
	{
		cin >> lengthA;
		for (int i = 0; i < lengthA + 1; i++)
		{
			cin >> coefA[i];
		}
		cin >> lengthB;
		for (int i = 0; i < lengthB + 1; i++)
		{
			cin >> coefB[i];
		}
		cin >> op;
		A = Polynomial<int>(lengthA, coefA);
		B = Polynomial<int>(lengthB, coefB);
		C = A + B;
		cout << C.Evaluate(op) << endl;
	}
	return 0;
}