#include <iostream>
#include "List.h"
#include "StackLL.h"
using namespace std;

//Tomás Moro Lías 2o I

// This is the funtion to be implemented by the student
// The cost is very clearly linear
int solveCase(List<int> list) {
	int aux = 0;
	StackLL<int> s = StackLL<int>();
	List<int>::Iterator iter = list.cbegin();
	s.push(-1); //not to check empty in if condition and improve efficiency
	while (iter != list.cend())
	{
		if (iter.elem() == s.top())
		{
			s.pop();
			aux++;
		}
		else {
			s.push(iter.elem());
		}
		iter.next();
	}
	return aux; // To be removed when implementing this function
}

// It reads a list of integers ended by -1 from the 
// the standard input
List<int> readList() {
	int elem;
	cin >> elem;
	List<int> list = List<int>();
	while (elem >= 0) {
		list.push_back(elem);
		cin >> elem;
	}
	return list;
}

// The main function for processing all the input cases 
// and providing the outputs
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		List<int> list = readList();
		int solution = solveCase(list);
		cout << solution << endl;
	}
	return 0;
}

