#include <iostream>
#include "List.h"
#include <string>
using namespace std;


int main() {
	int numCases, iter = 0;
	string str;
	char aux;
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		List<char>* l = new List<char>();
		cin >> str;
		aux = str.at(0);
		l->push_back(aux);
		for (int c = 1; c < str.length(); c++) {
			aux = str.at(c);
			if ((aux == ')' && l->back() == '(') || (aux == ']' && l->back() == '[') || (aux == '}' && l->back() == '{')) {
				l->pop_back();
			}
			else {
				l->push_back(aux);
			}
		}

		if (l->numElems() == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		delete l;
	}
	return 0;
}
