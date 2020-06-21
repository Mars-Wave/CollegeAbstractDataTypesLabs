// EDp7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bintree.h"
#include "List.h"
using namespace std;
Bintree<int> readBintree();

//Exam code by: Tomas Moro Lias 2o I.


/*
solveSpecials is a generalization of the requested by the problem function. It makes use of
t.empty() with O(1), t.leftChild() and t.rightChild() with O(1) and also the observer t.root() with O(1),
so I will discard making any observations about these calls to external functions.

This function is recursive and traverses every element of the tree carrying the odds above the node
being examined and the ones below when the stack pointer is receding to calculate the number of special nodes,
which is used as an input - output parameter.

Since it goes through every element of the tree and examines them just once using the t.root() call, it is very
clear that the cost is linear O(n).
*/
int solveSpecials(Bintree<int> t, int &spnodes, int oddabove, int oddbelow) {
	if (t.empty())
	{
		return 0;
	}
	else
	{
		int oddnow = oddabove;

		if (t.root() % 2 == 1)
		{
			oddnow++;
		}

		oddbelow = solveSpecials(t.leftChild(), spnodes, oddnow, oddbelow) + solveSpecials(t.rightChild(), spnodes, oddnow, oddbelow);

		if (oddabove > oddbelow)
		{
			spnodes++;
		}

		if (t.root() % 2 == 1)
		{
			oddbelow++;
		}
	}
	return oddbelow;
}

/* It solves the case for a given input binary tree, and returns
the number.
The student should implement this function and probably
the generalization of this function. */
int solveCase(Bintree<int> t) {
	int aux = 0;
	solveSpecials(t, aux, 0, 0);
	return aux;
}






/* Main function*/
int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		Bintree<int> t = readBintree();
		cout << solveCase(t) << endl;
	}
	return 0;
}


// It reads a binary tree of integers from the standard input
Bintree<int> readBintree() {
	char c;
	cin >> c;
	switch (c) {
	case '#': return Bintree<int>();
	case '[': {
		int raiz;
		cin >> raiz;
		cin >> c;
		return Bintree<int>(raiz);
	}
	case '(': {
		Bintree<int> left = readBintree();
		int root;
		cin >> root;
		Bintree<int> right = readBintree();
		cin >> c;
		return Bintree<int>(left, root, right);
	}
	default:
		return Bintree<int>();
	}
}
