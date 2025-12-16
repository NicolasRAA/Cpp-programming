#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

int main() {
	cout.precision(3);
	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;

	cout << "\tx\tsin(x)\n";

	x = x1;

	do {
		y = sin(x);
		cout << "\t" << x << "\t" << y << std::endl;
		x += 0.1;
	} while (x <= x2);


	return 0;
}