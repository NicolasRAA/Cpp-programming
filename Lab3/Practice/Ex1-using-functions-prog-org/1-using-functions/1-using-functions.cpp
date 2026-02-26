#include <iostream>
#include <string>

using namespace std;

// function prototype
void privet(string);

int main() {
	string name;
	cout << "What's your name?" << endl;
	cin >> name;

	privet(name);

	return 0;
}

// the function itself (could go before main)
void privet(string name) {
	cout << name << ", hello!" << endl;
}