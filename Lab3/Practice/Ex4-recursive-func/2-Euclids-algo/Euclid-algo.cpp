#include <iostream>

using namespace std;

int gcd(int m, int n) {
	if (n == 0) return m;
	return gcd(n, m % n);
}

int main() {
	int m;
	int n;
	cout << "This program calculates the GCD of 2 numbers" << endl;
	cout << "m: "; cin >> m;
	cout << "n: "; cin >> n;

	int resultGCD = gcd(m, n);
	/* m = 10, n = 4
	gcd(10, 4) -> gcd(4, 2)
	gcd(4, 2) -> gcd (2, 0)
	gcd(2, 0) -> 2 
	result = 2

	|| gcd(4, 10) -> gcd(10, 4) ...
	result = 2

	|| gcd(17, 8) -> gcd(8, 1)
	gcd(8, 1) -> gcd(1, 0)
	gcd(1, 0) -> 1
	result = 1
	*/
	cout << "GCD: " << resultGCD;

	return 0;
}