// Hash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Table.h"
using namespace std;

int main() {
	int numcases, numop, intaux, size;
	cin >> numcases;
	string acc, own, town, trec, tacc1, tacc2;
	char c;
	for (int i = 0; i < numcases; i++)
	{
		Table<string, Table<string, int>> btc = Table<string, Table<string, int>>();
		size = 0;
		cin >> numop;
		for (int i = 0; i < numop; i++)
		{
			cin >> c;
			switch (c) {
			case 'd':
				cin >> own >> acc >> intaux;
				if (btc.exists(own)) {
					if (btc.get(own).exists(acc)) {
						btc.get(own).insert(acc, btc.get(own).get(acc) + intaux);
					}
					else {
						btc.get(own).insert(acc, intaux);
					}
				}
				else {
					Table<string, int> account = Table<string, int>();
					account.insert(acc, intaux);
					btc.insert(own, account);
				}
				break;
			case 't':
				cin >> town >> tacc1 >> trec >> tacc2 >> intaux;
				if (btc.get(town).get(tacc1) >= intaux)
				{
					btc.get(town).insert(tacc1, btc.get(town).get(tacc1) - intaux);
					if (btc.exists(trec))
					{
						if (btc.get(trec).exists(tacc2))
						{
							btc.get(trec).insert(tacc2, btc.get(trec).get(tacc2) + intaux);
						}
						else {
							btc.get(trec).insert(tacc2, intaux);
						}
					}
					else {
						Table<string, int> account = Table<string, int>();
						account.insert(tacc2, intaux);
						btc.insert(trec, account);
					}

				}
				break;
			case 'm':
				cin >> own;
				Table<string, int>::Iterator iter = btc.get(own).begin();
				Table<string, int>::Iterator iterend = btc.get(own).end();
				int i = 0, aux = 0;
				while (iter != iterend) {
					aux += iter.value();
					iter.next();
				}
				cout << aux << endl;
				break;
			}
		}
	}
}