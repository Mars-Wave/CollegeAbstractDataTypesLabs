// EDp7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SearchTree.h"
#include "List.h"
#include "Exceptions.h"
#include "StackLL.h"
using namespace std;



int main()
{
	int numcases, numitems, pts, numplayers;
	string name;
	
	cin >> numcases;
	for (int i = 0; i < numcases; i++)
	{
		SearchTree<string, int> s = SearchTree<string, int>();
		cin >> numitems;
		numplayers = 0;
		for (int i = 0; i < numitems; i++)
		{
			cin >> name >> pts;
			if (s.exists(name)) {
				int a = s.get(name);
				pts += a;
			}
			else {
				numplayers++;
			}
			s.insert(name, pts);
		}
		SearchTree<string, int>::Iterator iter = s.begin();
		for (int i = 0; i < numplayers; i++)
		{
			cout << "(" << iter.key() << ":" << iter.value() << ")";
			iter.next();
		}
		cout << endl;
	}
	return 0;
}
