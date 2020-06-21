#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int numtries, a, b;
	
	stack<int> stack;
	cin >> numtries;
	for (int i = 0; i < numtries; i++)
	{
		string aux;
		while (aux != "end") {
			cin >> aux;
			if (aux == "*")
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(a * b);
			}
			else if (aux == "+") {
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(a + b);
			}
			else if (aux == "-") {
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(b - a);
			}
			else if (aux == "end") {
			}
			else {
				stack.push(stoi(aux));
			}
		}
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}