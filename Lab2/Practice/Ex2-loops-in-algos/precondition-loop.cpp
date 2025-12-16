#include <iostream>

using std::cout;
using std::cin;

int main() {
	int a, b, temp;

	cout << "a= "; cin >> a;
	cout << "b= "; cin >> b;

	while (a != b) {
		if (a > b)
			a -= b; // the same way a = a - b
		else
			b -= a;
	}
	cout << "GCD = " << a << std::endl;

	return 0;
}