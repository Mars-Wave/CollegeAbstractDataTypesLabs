#include <iostream>
#include "List.h"
using namespace std;


int main() {
	int numMembers, numFingers, leader;

	do
	{
		List<int>* l = new List<int>();
		cin >> numMembers;
		if (numMembers != -1) {
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
					if (i == l->end()) {
						i = l->begin();
					}
					else {
						i.next();
					}
				}
				if (i == l->end()) {
					i = l->begin();
				}
				i = l->remove(i);
			}
			leader = l->front();
			cout << leader << endl;
		}
		delete l;
	} while (numMembers != -1);
	return 0;
}