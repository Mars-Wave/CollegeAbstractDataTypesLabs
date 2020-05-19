#include <algorithm>
#include <string>
#include <iostream>
#include "Deck.h"
using namespace std;

Deck readIntDeck();


int main() {
	int numtries;
	cin >> numtries;
	Deck d1, d2;
	for (int i = 0; i < numtries; i++)
	{
		d1 = readIntDeck();
		d2 = readIntDeck();
		cout << d1.numCommonStickers(d2) << endl;
	}

	return 0;
}

//reads integer deck
Deck readIntDeck()
{
	Deck aux = Deck();
	char c;
	string straux="";
	int int1, int2;
	cin >> c;
	if (c == '[')
	{
		while (c!=']')
		{	
			cin >> c;
			if (c != ']')
			{
				
				while (c != ':')
				{
					straux += c;
					cin >> c;
				}
				int1 = stoi(straux);
				straux = "";
			}
			else {
				break;
			}
			cin >> int2;
			aux.addStickers(int1, int2);
			cin >> c;
		}
	}
	return aux;
}