#include <iostream>
// Sum of numbers from 1 to k and m to 100

using std::cout;
using std::cin;

int main() {
	const int MIN = 1;
	const int MAX = 100;
	int k;
	int m;
	int s{};
	
	cout << "k = "; cin >> k;
	cout << "m = "; cin >> m;

	for (int i = MIN; i <= MAX; i++) {
		if ((i > k) && (i < m))
			continue;
		s += i;
	}
	cout << s;

	return 0;
}