// using binary search to find the roots of a certain degree
#include <iostream>
#include <cmath>
#include <iomanip> // to fix the 6 decimals for result only

using namespace std;

long double firBinSearch(double a, int n) {
	double L = 0;
	double R = a;

	while (R - L > 1e-10) {
		double M = (L + R) / 2;
		if (pow(M, n) < a) {
			L = M;
		}
		else {
			R = M;
		}
	}
	return R;
}

int main() {
	cout << "'a' should have a value from 1 to 1000";
	double a;
	cout << "\nEnter a: "; cin >> a;

	int n;
	cout << "\n'n' should be a natural number not bigger than 10";
	cout << "\nEnter n: "; cin >> n;

	long double result = firBinSearch(a, n);
	//cout << fixed;
	//cout.precision(7);
	cout << "\nThe " << n << " root of " << a << " is " <<  fixed << setprecision(6) << result;

	return 0;
}