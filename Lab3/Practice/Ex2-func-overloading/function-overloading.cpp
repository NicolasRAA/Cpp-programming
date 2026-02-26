#include <iostream>
#include <string>

using namespace std;

void privet(string name) {
	cout << name << ", hello!" << endl;
}

void privet(string name, int k) { // we ask for a parameter more
	cout << name << ", " << "hello!" << " Your input " << k << endl;
}


void display(int num) {
	cout << "Integer: " << num << endl;
}

void display(double num) {
	cout << "Double: " << num << endl;
}

void display(string text) {
	cout << "String: " << text << endl;
}

int main() {
	string name;
	int k;

	cout << "What's your name?" << endl;
	cin >> name;

	cout << "Input number: " << endl; cin >> k;

	privet(name);
	privet(name, k); // calling the overleaded function

	/* Function overloading allows  to create multiple functions with the same name but different parameters
	* The compiler figures out which one to call based on the arguments provided
	*/
	cout << "\n";
	
	// calling overloaded functions with fixed parameters
	display(10);      // Calls int version
	display(3.14);    // Calls double version  
	display("Hello"); // Calls string version

	return 0;
}
