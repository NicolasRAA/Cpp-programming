#include <iostream>

using std::cout;
using std::cin;

int main() {
	char op;

	cout << "Make a desition, create the car of your dreams: ";
	cin >> op;

	switch (op) {
	case 'S':
		cout << "The radio should play\n";
		cout << "The weels are round\n";
		cout << "Powerful engine\n";
		break;

	case 'V':
		cout << "I want air conditioner\n";
		cout << "The radio should play\n";
		cout << "The weels are round\n";
		cout << "Powerful engine\n";
		break;

	default:
		cout << "The weels are round\n";
		cout << "Powerful engine\n";
	}

	/* Using fallthrough (without brake;)
	* This way I prevent the repetition of code
	*/
	
	char op2;

	cout << "\nCreate the car of your dreams (fallthrough): ";
	cin >> op2;
	
	switch (op2) {
	case 'V':
		cout << "I want air conditioner\n";
	case 'S':
		cout << "The radio should play\n";
	default:
		cout << "The weels are round\n";
		cout << "Powerful engine\n";
	}

	return 0;
}