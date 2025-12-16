#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(NULL)); // to get different numbers each time
	int a, b, c;
	// k = wrong answers, n = # of questions
	int k = 0, n = 10; 
	// for(init ; condition ; iteration)
	// while i will be less or equal to n, the loop will go
	for (int i = 1; i <= n; i++) {
		//initialization of operands with random numbers from 1 to 10
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;

		cout << a << " * " << b << " = ";
		cin >> c;

		if (a * b != c) {
			k++; 
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
	}

	cout << "Count error: " << k << endl;

	return 0;
}