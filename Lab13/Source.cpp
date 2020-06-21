#include <iostream>
#include "LawFirm.h"
using namespace std;

void parseOP(LawFirm & lf);

int main() {
	int numcases, op;
	cin >> numcases;
	for (int i = 0; i < numcases; i++)
	{
		cin >> op;
		LawFirm lf = LawFirm();
		for (int j = 0; j < op; j++)
		{
			parseOP(lf);
		}
	}
	return 0;
}

void parseOP(LawFirm & lf)
{
	string op, aux1, aux2, aux3;
	int aux4;
	cin >> op;
	if (op == "add")
	{
		cin >> aux1 >> aux2 >> aux3 >> aux4;
		lf.addCase(aux1, aux2, aux3, aux4);
	}
	else if (op == "get") {
		cin >> aux1;
		try {
			lf.getCase(aux1, aux2, aux3);
			cout << aux2 << " " << aux3 << endl;
		}
		catch (EWrongKey e) {
			cout << e.msg() << endl;
		}
		
	}
	else if (op == "next") {
		lf.nextCase(aux1, aux4);
		if (aux4 == -1) {
			cout << "There are no cases" << endl;
		}
		else {
			cout << aux1 << " " << aux4 << endl;
		}
	}
	else if (op == "remove") {
		lf.removeNextCase();
	}
	else if (op == "empty") {
		if (lf.empty())
		{
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}
