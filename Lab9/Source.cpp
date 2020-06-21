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
int specialNodes(Bintree<int> t, int &total, int prod = 1);
int terrorists(Bintree<char> t, int &tot);
Bintree<char> readCharBintree();

int main()
{
	int numcases;
	int total;
	cin >> numcases;
	for (int i = 0; i < numcases; i++)
	{
		total = 0;
		Bintree<char> t = readCharBintree();
		terrorists(t, total);
		cout << total << endl;
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

Bintree<char> readCharBintree() {
	char c;
	cin >> c;
	switch (c) {
	case '#': return Bintree<char>();
	case '[': {
		char raiz;
		cin >> raiz;
		cin >> c;
		return Bintree<char>(raiz);
	}
	case '(': {
		Bintree<char> left = readCharBintree();
		char root;
		cin >> root;
		Bintree<char> right = readCharBintree();
		cin >> c;
		return Bintree<char>(left, root, right);
	}
	default:
		return Bintree<char>();
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

int specialNodes(Bintree<int> t, int &total, int prod)
{
	if (t.empty()) {
		return 1;
	}
	else {
		int aux = specialNodes(t.leftChild(), total, prod * t.root()) * specialNodes(t.rightChild(), total, prod * t.root());
		if (aux == prod)
		{
			total++;
		}
		return aux * t.root();
	}
}

int terrorists(Bintree<char> t, int &tot)
{
	if (t.empty()) {
		return 0;
	}
	else {
		if (terrorists(t.leftChild(), tot) == 1 | terrorists(t.rightChild(), tot) == 1) {
			return 1;
		}
		else {
			if (t.root() == 'P')
			{
				tot++;
			}
			else if (t.root() == 'S') {
				return 1;
			}
			return 0;
		}
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
