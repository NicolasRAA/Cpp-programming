#include <iostream>
#include <math.h>

// Changing the loops of Ex2 from pre to post and vice versa

using std::cout;
using std::cin;
using std::endl;

int main() {
	cout.precision(3);
	//Ex2 1 post -> pre
	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;

	cout << "\tx\tsin(x)\n";

	x = x1;
	// First the condition gets checked, and then the loop
	while (x <= x2) { // x == x2 -> no loop, only till x-0.01
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x += 0.01;
	}


	//Ex2 2 pre -> post
	int a, b, temp;
	cout << "\na = "; cin >> a;
	cout << "b = "; cin >> b;

	do {
		if (a > b)
			a -= b;
		else
			b -= a;
	} while (a != b);
	cout << "GCD = " << a << endl;

	return 0;
}