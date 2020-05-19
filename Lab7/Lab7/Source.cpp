// EDp7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bintree.h"
#include "List.h"
using namespace std;
void example1();
Bintree<int> readBintree();
void showBintree(Bintree<int> t);
int sumOfLevel(Bintree<int> t, int depth);
/* Try this example by typing in the console the following tree:
(([1] 7 [3]) 4 [9])
*/
int main()
{
	int numcases, depth;

	cin >> numcases;
	for (int i = 0; i < numcases; i++)
	{

		Bintree<int> t = readBintree();
		cin >> depth;
		cout << sumOfLevel(t, depth)<<endl;

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

int sumOfLevel(Bintree<int> t, int depth) {
	if (depth == 0) {
		int aux = 0;
		List<int> l = t.inorder();
		List<int>::Iterator it = l.cbegin();
		while (it != l.cend()) {
			aux += it.elem();
			it.next();
		}
		return aux;
	}
	else if (t.numNodes() == 1)
	{
		return 0;
	}
	else {
		depth--;
		return sumOfLevel(t.leftChild(), depth) + sumOfLevel(t.rightChild(), depth);
	}
}

// It shows one tree using in-order tour
void showBintree(Bintree<int> t) {
	List<int> l = t.inorder();
	List<int>::Iterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem() << " ";
		it.next();
	}
}

// Example of building and showing one tree
void example1() {
	Bintree<int> t1 = Bintree<int>(Bintree<int>(1), 7, Bintree<int>(3));
	Bintree<int> t = Bintree<int>(t1, 4, Bintree<int>(9));
	showBintree(t);
}

