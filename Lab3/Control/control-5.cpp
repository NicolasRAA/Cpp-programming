#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Prots 

// 1. For SNILS 
/* generally a good practice
const and '&' create a read - only reference 
not a copy of the string, just a reference
* const(read - only) 
* &(reference)
*/
bool isValidSnils(const string& s);

string pad2(int x);

// 2. For cube roots
double stndCubeRoot(double a);
double iterCubeRoot(double a);

// 3. For area of triangles
double triangleArea(double side);
double triangleArea(double side1, double side2, double side3);

// 4. Series sum
int recursiveSeriesSum(int n);

// 5. Decimal to binary
void recursiveDecimalToBinary(int num);

int main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {
		//Menu
		cout << "\n===============Menu===============" << endl;
		cout << "1. Checking СНИЛС number (special input)\n";
		cout << "2. Cube root calculation (regular pow & iteratively)\n";
		cout << "3. Area of Equilateral and Scalene triangles (overloaded function)\n";
		cout << "4. Series sum recursive function\n";
		cout << "5. Recursevly converting an decimal integer to binary\n";
		cout << "Select an option: ";

		int choise;
		if (!(cin >> choise)) return 0;

		switch (choise) {
		
		// 1. Checking СНИЛС number (special input)
		case 1: {
			string inputString;
			// std::ws consumes any leading whitespace (including the leftover '\n')
			cout << "\nEnter your СНИЛС (you may include spaces and dashes): ";
			std::getline(cin >> std::ws, inputString); // before getline, so the next line read isn't empty

			bool valid = isValidSnils(inputString);
			cout << (valid ? "\ntrue\n" : "\nfalse\n");
			break;
		}

		// 2. Cube root calculation (regular pow & iteratively)
		case 2: {
			double inputNumber;
			cout << "\nNumber to calculate: "; cin >> inputNumber;

			double stndResult = stndCubeRoot(inputNumber);
			cout << "\nStandard cube root: " << stndResult << endl;
			
			double iterResult = iterCubeRoot(inputNumber);
			cout << "Iterative cube root: " << iterResult << endl;
			break;
		}
			  
		// 3. Area of Equilateral and Scalene triangles(overloaded function)
		case 3: {
			double side1, side2, side3;
			int typeTriangle;

			cout << "\n1. Equilateral";
			cout << "\n2. Scalene\n";
			cout << "Select a type of triangle: "; cin >> typeTriangle;


			if (typeTriangle == 1) {
				cout << "Side: "; cin >> side1;
				double area = triangleArea(side1);
				cout << "Area: " << area << endl;
				return 0;
			}
			else if (typeTriangle == 2) {
				cout << "Side1: "; cin >> side1;
				cout << "Side2: "; cin >> side2;
				cout << "Side3: "; cin >> side3;

				double area = triangleArea(side1, side2, side3);
				cout << "Area: " << area << endl;
				return 0;
			}
			else {
				cout << "Not a valid option\n";
				break;
			}
		}

		// 4. Series sum recursive function
		case 4: {
			int n;
			cout << "\nEnter n (n > 0): "; cin >> n;

			if (n <= 0) {
				cout << "n must be grater than 0\n";
			}
			else {
				int result = recursiveSeriesSum(n);
				cout << "Series sum S = 5 + 10 + ... + 5*" << n << " = " << result << endl;
			}
			return 0;
		}

		// 5. Recursevly converting an decimal integer to binary
		case 5: {
			int num;
			cout << "\nEnter a positive integer in decimal: ";
			cin >> num;

			if (num < 0) {
				cout << "Must be an integer\n";
			}
			else {
				cout << "Binary: ";
				recursiveDecimalToBinary(num);
				cout << endl;
			}
			return 0;
		}

		default: {
			cout << "\nInvalid option. Please select 1-5\n\n";
			break;
		}
		}
	}
}


// 1. funcs for SNILS
// adding 0 to the left for 1 cifr int
string pad2(int x) {
	string s = std::to_string(x);
	if (s.size() == 1) s = '0' + s;
	return s;
}

bool isValidSnils(const string& inputString) {
	
	// checking the input
	string SNILSdigits;
	for (char ch : inputString) {
		if (ch == ' ' || ch == '-') continue; // ignoring
		if (ch < '0' || ch > '9') return false;
		SNILSdigits += ch; // saving the digits
	}

	if (SNILSdigits.size() != 11) return false;

	// dividing into substrings
	string main9 = SNILSdigits.substr(0, 9); // substr(pos, count) | (inicial index, lenght)
	string controlNumber = SNILSdigits.substr(9, 2); // or simply substr(9)

	// no more than 2 equal digits podryad in main9
	int streak = 1;
	for (std::size_t i = 1; i < main9.size(); i++) {
		if (main9[i] == main9[i - 1]) {
			++streak;
			if (streak == 3) {
				return false;
			}
		}
		else {
			streak = 1;
		}
	}

	// digits sumproduct
	int sumProduct = 0;
	for (int i = 0; i < 9; i++) {
		sumProduct += (main9[i] - '0') * (9 - i); // digit * position
	}

	// checking for uslovia using expected and comparing
	string expected;
	if (sumProduct < 100) { expected = pad2(sumProduct); }
	else if (sumProduct == 100 || sumProduct == 101) { expected = "00"; }
	else { // sumProduct > 101
		int rest = sumProduct % 101;
		expected = (rest < 100) ? pad2(rest) : "00";
	}

	//comparing
	return expected == controlNumber;
}


// 2. funcs for cube root calc
// Standard Cube Root
double stndCubeRoot(double a) {
	return (a >= 0) ? std::pow(a, 1.0/3):
					 -std::pow(-a, 1.0/3);
}

// Iterative Cube Root
double iterCubeRoot(double a) {
	if (a == 0.0) return 0.0;

	double xOld = a;
	double xNew = 1.0 / 3.0 * ((a / (xOld * xOld)) + (2 * xOld));

	const double epsilon = 1e-12; // a close difference
	int iter = 0, max_iter = 50;

	while (std::fabs(xNew - xOld) > epsilon && iter < max_iter) {
		xOld = xNew;
		xNew = 1.0 / 3.0 * ((a / (xOld * xOld)) + (2 * xOld));
		++iter;
	}
	return xNew;
}


// 3. Area of triangles
// Equilateral
double triangleArea(double side) {
	return (sqrt(3) / 4) * side * side;
}

// Scalene (overloaded)
double triangleArea(double side1, double side2, double side3) {
	double poluperimetr = (side1 + side2 + side3) / 2.0;
	return sqrt(poluperimetr * (poluperimetr - side1) * (poluperimetr - side2) * (poluperimetr - side3));
}


// 4. Recursive series sum
int recursiveSeriesSum(int n) {
	if (n <= 0) return 0; // base case: n <= 0, to est nothing to add
	return 5 * n + recursiveSeriesSum(n - 1); // naprm: n = 3 -> 15+10+5
}


// 5. Recursively tranforming decimal to binary
void recursiveDecimalToBinary(int num) {
	// explicit handle for 0
	if (num == 0) {
		cout << 0;
		return;
	}

	if (num > 1) {
		recursiveDecimalToBinary(num / 2);
	}

	cout << num % 2;
}