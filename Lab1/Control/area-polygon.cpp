#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main() {
	cout << "This program calculates the area of a pentagon from the coordinates of its vertices" << std::endl;
	
	// zaprashivayu for each single coordinate
	double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
	cout << "\nEnter the coordinates of the first vertex of the pentagon | ex. 32 25 |: ";
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the second vertex of the pentagon: ";
	cin >> x2 >> y2;
	cout << "Enter the coordinates of the third vertex of the pentagon: ";
	cin >> x3 >> y3;
	cout << "Enter the coordinates of the fourth vertex of the pentagon: ";
	cin >> x4 >> y4;
	cout << "Enter the coordinates of the fifth vertex of the pentagon: ";
	cin >> x5 >> y5;
	
	// формула шнурков
	double area = 0.5 * fabs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5));

	std:printf("\nThe area of the pentagon with those vertices equals = %.2f\n", area);

	return 0;
}