#include <iostream>
#include "Queue.h"
using namespace std;


int main() {
	int numtries, numints, aux, pos;
	Queue<int>* q; 
	cin >> numtries;
	for (int i = 0; i < numtries; i++)
	{
		q = new Queue<int>();
		cin >> numints;
		for (int i = 0; i < numints; i++)
		{
			cin >> aux;
			q->push(aux);
		}
		cin >> pos;
		q->penalizeElem(pos);
		for (int i = 0; i < numints; i++)
		{
			aux = q->front();
			cout << aux << " ";
			q->pop();

		}
		cout << endl;
		delete q;
	}
	return 0;
}