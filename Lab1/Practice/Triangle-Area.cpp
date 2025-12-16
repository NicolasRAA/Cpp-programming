#include <iostream>
#include <fmt/core.h>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "This program calculates the area of an equilateral triangle whose perimeter is known\n";
	double perimeter;
	cout << "\nPerimeter: ";
	cin >> perimeter;

	double side = perimeter / 3;
	double poluPerimeter = perimeter / 2;

	double area = sqrt(poluPerimeter * (pow((poluPerimeter- side),3)));

	fmt::print("\n|{:^12} | {:^12}|\n", "Сторона", "Площадь");
	fmt::print("|{:-^13}+{:-^13}|\n", "", "");          // separating line
	fmt::print("|{:^12.2f} | {:^12.2f}|\n", side, area);

	return 0;
}