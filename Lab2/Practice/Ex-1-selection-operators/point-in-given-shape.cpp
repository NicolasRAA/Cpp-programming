#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main() {
	double x = 0;
	double y = 0;

	cout << "Enter x and y: ";
	cin >> x >> y;

	if (x * x + y * y < 9 && y > 0) {
		cout << "Inside";
	}
	else if (x * x + y * y > 9 || y < 0) {
		cout << "Outside";
	}
	else {
		cout << "In the border";
	}

	return 0;
}