#include <iostream>
#include <string>

using namespace std;

// instead of using void we use string and return a value (variable)
string privet(string name) {
	string str = name + ", " + "hello!\n";
	return str;
}

int main() {
	string name;
	cout << "What's your name?" << endl;
	cin >> name;

	string nameOut = privet(name);
	cout << nameOut;

	return 0;
}
