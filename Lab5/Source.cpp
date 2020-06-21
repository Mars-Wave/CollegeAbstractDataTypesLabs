#include <iostream>
#include "List.h"
using namespace std;


int main() {
	int numMembers, numFingers, leader;
	cin >> numMembers;
	while (numMembers != -1) {
		List<int>* l = new List<int>();
		for (int i = 0; i < numMembers; i++)
		{
			l->push_back(i + 1);
		}
		cin >> numFingers;
		List<int>::MutableIterator i = l->begin();
		while (l->numElems() > 1)
		{
			for (int j = 1; j < numFingers; j++)
			{
				i.next();
				if (i == l->end()) {
					i = l->begin();
				}
			}
			i = l->remove(i);
			if (i == l->end()) {
				i = l->begin();
			}
		}
		leader = l->front();
		cout << leader << endl;
		delete l;
		cin >> numMembers;
	}
	return 0;
}