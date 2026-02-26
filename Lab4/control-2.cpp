#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// Prots

// 1. Roots
int Myroot(double, double, double, double&, double&);

// 2. Input
bool Input(int& a, int& b);


int main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {
		//Menu
		cout << "\n===============Menu===============" << endl;
		cout << "1. Calculation of the roots of a quadratic equation\n";
		cout << "2. Input with validation\n";
		cout << "Select an option: ";

		int choise;
		if (!(cin >> choise)) return 0;

		switch (choise) {

		// 1. Calculation of the roots of a quadratic equation
		case 1: {
			double a, b, c;
			double x1, x2;
			
			cout << "\nВведите коэффициенты a, b и c: ";
			cin >> a >> b >> c;

			int flag = Myroot(a, b, c, x1, x2);

			if (flag == -1) {
				cout << "\nКорней уравнения нет\n";
			}
			else if (flag == 0) {
				cout << "\nКорень уравнения один x1 = x2 = " << x1 << endl;
			}
			else if (flag == 1) {
				cout << "\nКорни уравнения x1 = " << x1 << ", x2 = " << x2 << endl;
			}
			return 0;
		}

		// 2. Input with validation
		case 2: {
			int a, b;

			if (Input(a, b) == false) {
				std::cerr << "\nerror\n";
				return 1; // exiting on error
			}

			int s = a + b;
			cout << "\nSum a + b = " << s << endl;
			return 0;
		}

		default: {
			cout << "\nInvalid option. Please select 1-5\n\n";
			break;
		}
		}
	}
}

// 1. Function to compute real roots of a quadratic equation
int Myroot(double a, double b, double c, double& x1, double& x2) {
	// ax^2 + bx + c = 0

	// if a == 0, ne kvad equation
	if (a == 0) {
		return -1;
	}

	double D = b * b - 4 * a * c; // discriminant

	if (D < 0) {
		// no real roots
		return -1;
	}
	else if (D == 0) {
		// one real root ~ double root
		x1 = x2 = -b / (2 * a);
		return 0;
	}
	else {
		// two different real roots
		double sqrtD = std::sqrt(D);
		x1 = (-b + sqrtD) / (2 * a);
		x2 = (-b - sqrtD) / (2 * a);
		return 1;
	}
}


// 2. Function to read two integers with simple validation
bool Input(int& a, int& b) {
	cout << "\nEnter 2 integers (a & b): ";

	// trying to read a and b
	if (!(cin >> a >> b)) {
		// input failed, napr not integers
		return false;
	}
	return true; // ok inpuit
}
