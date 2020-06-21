#include <iostream>		
#include "Company.h"
#include "List.h"
using namespace std;

bool parseOP(Company &c, string fix);

int main() {
	string fix;
	bool aux = false;
	while (!aux) {
		Company c = Company();
		while (!parseOP(c, fix)) {
			fix = "";
		}
		cin >> fix;
		if (fix == "end")
		{
			break;
		}
	}
	return 0;
}

bool parseOP(Company &c, string fix)
{
	string aux = fix, auxs, auxm;
	int n;
	if (aux == "")
	{
		cin >> aux;
	}
	if (aux == "end")
	{
		return true;
	}
	else if (aux == "addShop") {
		cin >> auxs;
		c.addShop(auxs);
	}
	else if (aux == "addModel") {
		cin >> auxs >> auxm >> n;
		c.addModel(auxs, auxm, n);
	}
	else if (aux == "lastModels") {
		cin >> auxs >> n;
		List<string> l = c.lastModels(auxs, n);
		List<std::string>::Iterator iter = l.cbegin();
		while (iter != l.cend())
		{
			cout << iter.elem();
			iter.next();
			if (iter != l.cend())
			{
				cout << ',';
			}
			
		}
		cout << endl;
	}
	else if (aux == "shops") {
		List<string> l = c.shops();
		List<std::string>::Iterator iter = l.cbegin();
		while (iter != l.cend())
		{
			cout << iter.elem();
			iter.next();
			if (iter != l.cend())
			{
				cout << ',';
			}
		}
		cout << endl;
	}
	else if (aux == "pieces") {
		cin >> auxs >> auxm;
		cout << c.pieces(auxs, auxm) << endl;
	}

	return false;
}
