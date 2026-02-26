#include <iostream>

using namespace std;

int addNumbers(int n) {
	if (n == 1) return 1; // exit of the recursive function
	else return (n + addNumbers(n - 1));
}

int substractNumbers(int n) {
	if (n == 1) return 1;
	else return (n - substractNumbers(n - 1));
}

int realSubNumbers(int n) {
	if (n == 1) return 1;
	else return realSubNumbers(n - 1) - n + 2;
}

int addNumbers(int min, int n) {
	if (n < min) return 0; // security case
	if (n == min) return min;
	else return n + addNumbers(min, n - 1);
}
/* Also possible to this incrementing min and decrementing n:

* Incrementing min
int addNumbers(int min, int n) {
	if (min > n) return 0;
	if (min == n) return min;
	return min + addNumbers(min + 1, n);
}

* Decrementing n
int addNumbers(int min, int n) {
	if (n < min) return 0; 
	if (n == min) return min;
	return n + addNumbers(min, n - 1);
}
*/

int main() {
	int min;
	int n;
	cout << "The value of n should be higher than the value of min | (min < n)" << endl;
	cout << "Enter the value of min: "; cin >> min;
	cout << "Enter the value of n: "; cin >> n;
	
	int resultAddition = addNumbers(n);
	cout << "Sum to n: \t" << resultAddition << endl;

	int resultSubstraction = substractNumbers(n);
	/* n = 10 -> (n/2) |up
	substractNumbers(1) = 1
	substractNumbers(2) = 2 - 1 = 1
	substractNumbers(3) = 3 - 1 = 2
	substractNumbers(4) = 4 - 2 = 2
	substractNumbers(5) = 5 - 2 = 3
	substractNumbers(6) = 6 - 3 = 3
	substractNumbers(7) = 7 - 3 = 4
	substractNumbers(8) = 8 - 4 = 4
	substractNumbers(9) = 9 - 4 = 5
	substractNumbers(10) = 10 - 5 = 5
	*/
	cout << "Fake sub to n: \t" << resultSubstraction << endl;

	int realResultSub = realSubNumbers(n);
	/* n = 5
	realSubNumbers(1) = 1
	realSubNumbers(2) = 1-2+2 = 1
	realSubNumbers(3) = 1-3+2 = 0
	realSubNumbers(4) = 0-4+2 = -2
	realSubNumbers(5) = -2-5+2 = -5
	*/
	cout << "Real sub to n: \t" << realResultSub << endl;

	int resultIntervalAdd = addNumbers(min, n); // overloaded function
	/* min = 2, n =5
	addNumbers(2, 5)
	n + addNumbers(min, n - 1)
	5 + addNumbers(2, 5 - 1) = 5 + addNumbers(2, 4) = 9 + 5 = 14
	
	addNumbers(2, 4) = 4 + addNumbers(2, 3) = 4 + 5 = 9

	addNumbers(2, 3) = 3 + addNumbers(2, 2) = 3 + 2 = 5
	*/
	cout << "Interval addition: " << resultIntervalAdd;

	return 0;
}