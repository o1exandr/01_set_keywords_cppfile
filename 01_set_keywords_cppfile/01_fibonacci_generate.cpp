
#include "stdafx.h"
#include <iostream> 
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>


using namespace std;

int main()
{

	int count;
	cout << "Enter countity of fibonacci: ";
	cin >> count;

	deque<int> fib(count);
	int x = 1, y = 0;
	generate(fib.begin(), fib.end(), [&]() {x += y; y = x - y; return y; });
	copy(fib.begin(), fib.end(), ostream_iterator<int>(cout, "\t"));

	cout << endl;
	system("pause");
	return 0;

}








