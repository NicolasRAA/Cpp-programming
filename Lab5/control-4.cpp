#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

// Prots

// 1. Array to func
// Filling and printing
void fillArray(int n, int arr[]);
void printArray(int n, const int arr[]);

// Basic processing (from upra 1)
int sumAll(int n, const int arr[]);
double averageArray(int n, const int arr[]);
int sumNegative(int n, const int arr[]);
int sumPositive(int n, const int arr[]);
int sumOddIndex(int n, const int arr[]);
int sumEvenIndex(int n, const int arr[]);

// Extra tasks
int minIndex(int n, const int arr[]);
int maxIndex(int n, const int arr[]);
long long productBetweenMinMax(int n, const int arr[]);

// Selection sort (from upra 2)
void selectionSort(int n, int arr[]);


// 2. Arr from func
int* max_vect(int kc, const int a[], const int b[]);


// 3. Search alg
int transpositionSearch(int n, int arr[], int key);


// 4. Parms to prgm
bool processArgs(int argc, const char* argv[], int& result);


int main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {
		//Menu
		cout << "\n===============Menu===============" << endl;
		cout << "1. Passing an array to a function\n";
		cout << "2. Returning an array from a function\n";
		cout << "3. Implementation of search algorithms by transposition method\n";
		cout << "4. Passing parameters to the program\n";
		cout << "Select an option: ";

		int choise;
		if (!(cin >> choise)) return 0;

		switch (choise) {

		case 1: {
            const int N = 10;
            int a[N];

            // reading array from keyboard
            fillArray(N, a);

            cout << "\nArray elements: ";
            printArray(N, a);
            cout << endl;

            int total = sumAll(N, a);
            cout << "\nSum of all elements: " << total << endl;

            double avg = averageArray(N, a);
            cout << "Average value: " << avg << endl;

            int sNeg = sumNegative(N, a);
            int sPos = sumPositive(N, a);
            int sOdd = sumOddIndex(N, a);
            int sEven = sumEvenIndex(N, a);

            cout << "Sum of negative elements: " << sNeg << endl;
            cout << "Sum of positive elements: " << sPos << endl;
            cout << "Sum of elements with odd indices: " << sOdd << endl;
            cout << "Sum of elements with even indices: " << sEven << endl;

            int mnIdx = minIndex(N, a);
            int mxIdx = maxIndex(N, a);

            cout << "Minimum element: " << a[mnIdx] << ", index = " << mnIdx << endl;
            cout << "Maximum element: " << a[mxIdx] << ", index = " << mxIdx << endl;

            long long prod = productBetweenMinMax(N, a);
            cout << "Product of elements between min and max: " << prod << endl;

            // using selection sort from upra 2
            selectionSort(N, a);

            cout << "\nArray after selection sort: ";
            printArray(N, a);
            cout << endl;

            return 0;
        }

        // 2. Returning an array from a function
        case 2: {
            // Two source arrays of the same size
            int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
            int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };

            int kc = sizeof(a) / sizeof(a[0]); // number of elements

            cout << "\nArray a: ";
            for (int i = 0; i < kc; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;

            cout << "Array b: ";
            for (int i = 0; i < kc; ++i) {
                cout << b[i] << " ";
            }
            cout << endl;

            // pointer to resulting array
            int* c = max_vect(kc, a, b);

            cout << "Result (element-wise maximum): ";
            for (int i = 0; i < kc; ++i) {
                cout << c[i] << " ";
            }
            cout << endl;

            // freeing memory created inside max_vect
            delete[] c;

            return 0;
        }

        // 3. Implementation of search algorithms by transposition method
        case 3: {
            const int N = 10;
            int a[N] = { 5, 3, 7, 3, 9, 1, 4, 8, 6, 2 };

            while (true) {
                cout << "Current array: ";
                printArray(N, a);
                cout << endl;

                cout << "Enter value to search: ";
                int key;
                cin >> key;

                if (!cin) { // input error, exit to menu
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (key == -1) {
                    // exit search loop and return to main menu
                    break;
                }

                int pos = transpositionSearch(N, a, key);

                if (pos == -1) {
                    cout << "Key not found.\n";
                }
                else {
                    cout << "Key found at index " << pos << " (index after transposition).\n";
                }

                cout << endl;
            }

            return 0;
        }

        // 4. Passing parameters to the program
        case 4: {
            // using tastecases like:
            // nameProg -a 12 45
            // nameProg -m 12 45

            int result;
            bool ok;

            // Test 1: sum
            const char* test1[] = { "nameProg", "-a", "12", "45" };
            cout << "\nTest 1: nameProg -a 12 45\n";
            ok = processArgs(4, test1, result);
            if (ok) {
                cout << "Result = " << result << "\n\n";
            }
            else {
                cout << "Error in arguments!\n\n";
            }

            // Test 2: mult
            const char* test2[] = { "nameProg", "-m", "12", "45" };
            cout << "Test 2: nameProg -m 12 45\n";
            ok = processArgs(4, test2, result);
            if (ok) {
                cout << "Result = " << result << "\n\n";
            }
            else {
                cout << "Error in arguments!\n\n";
            }

            // Test 3: wrong flag
            const char* test3[] = { "nameProg", "-x", "12", "45" };
            cout << "Test 3: nameProg -x 12 45 (wrong flag)\n";
            ok = processArgs(4, test3, result);
            if (ok) {
                cout << "Result = " << result << "\n\n";
            }
            else {
                cout << "Error in arguments!\n\n";
            }

            // Test 4: not enough parameters
            const char* test4[] = { "nameProg", "-a", "12" };
            cout << "Test 4: nameProg -a 12  (too few params)\n";
            ok = processArgs(3, test4, result);
            if (ok) {
                cout << "Result = " << result << "\n\n";
            }
            else {
                cout << "Error in arguments!\n\n";
            }

            /*
            // For input ot samogo sebya
            char flagStr[3];
            int x, y;
            cout << "Enter flag (-a or -m): ";
            cin >> flagStr;
            cout << "Enter two integers: ";
            cin >> x >> y;
            
            // Computing directly, without argc/argv:
            if (flagStr[0] == '-' && flagStr[1] == 'a') {
                cout << "Sum = " << (x + y) << endl;
            } else if (flagStr[0] == '-' && flagStr[1] == 'm') {
                cout << "Product = " << (x * y) << endl;
            } else {
                cout << "Invalid flag.\n";
            }

            */

            return 0;
        }

		default: {
			cout << "\nInvalid option. Please select 1-4\n\n";
			break;
		}
		}
	}
}


// 1. Passing an array to a function
// Filling and printing
// Reading n elements from keyboard
void fillArray(int n, int arr[]) {
	for (int i = 0; i < n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}

// couting all elements in one line
void printArray(int n, const int arr[]) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << '\t';
	}
}

// from uprzh 1
// ums of all elements
int sumAll(int n, const int arr[]) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += arr[i];
    }
    return s;
}

// Avrg of elements
double averageArray(int n, const int arr[]) {
    if (n == 0) return 0.0;  // na vsyaki
    int s = sumAll(n, arr);  // reusing sumAll
    return static_cast<double>(s) / n;
}

// Sum of negative elements
int sumNegative(int n, const int arr[]) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) s += arr[i];
    }
    return s;
}

// Sum of positive elements
int sumPositive(int n, const int arr[]) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) s += arr[i];
    }
    return s;
}

// Sum of elements with odd indices: 1, 3, 5 y t.d.
int sumOddIndex(int n, const int arr[]) {
    int s = 0;
    for (int i = 1; i < n; i += 2) {
        s += arr[i];
    }
    return s;
}

// Sum of elements with even indices: 0, 2, 4 y t.d.
int sumEvenIndex(int n, const int arr[]) {
    int s = 0;
    for (int i = 0; i < n; i += 2) {
        s += arr[i];
    }
    return s;
}

// extra^ min, max, product
// Index of minimal element in the array
int minIndex(int n, const int arr[]) {
    if (n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[idx]) {
            idx = i;
        }
    }
    return idx;
}

// Index of maximal element in the array
int maxIndex(int n, const int arr[]) {
    if (n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[idx]) {
            idx = i;
        }
    }
    return idx;
}

// Product of elements located strictly between min and max
long long productBetweenMinMax(int n, const int arr[]) {
    if (n <= 0) return 0;

    int mn = minIndex(n, arr);
    int mx = maxIndex(n, arr);

    if (mn == -1 || mx == -1 || mn == mx) {
        // no elements strictly between min and max
        return 0;
    }

    // ensure start < end
    int start = (mn < mx) ? mn + 1 : mx + 1;
    int end = (mn < mx) ? mx : mn;

    if (start >= end) return 0;

    long long prod = 1; // using long long for no overflow na vsyaki
    for (int i = start; i < end; ++i) {
        prod *= arr[i];
    }
    return prod;
}

// from uprazh 2
// Classic selection sort: finding minimal element and swaping it forward
void selectionSort(int n, int arr[]) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i; // index of current minimal element

        // finding real minimal element in the rest of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // swaping arr[i] and arr[minIdx]
        int buf = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = buf;
    }
}



// 2. Returning an array from a function
int* max_vect(int kc, const int a[], const int b[]) {
    // allocating memory for the resulting array
    int* result = new int[kc];

    // fililgn each element with the bigger value from a and b
    for (int i = 0; i < kc; ++i) {
        // max
        result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }

    // returning pointer to newly created array
    return result;
}



/* 3. Implementation of search algorithms by transposition method
Returns index of key after transposition, or -1 if not found.
Each time key is found at position i (> 0), it is swapped with a[i - 1].
*/
int transpositionSearch(int n, int arr[], int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            
            if (i == 0) {
                // element already at beginning
                cout << "Element already at position 0. Transposition is not possible.\n";
                return 0;
            }

            // if not at beginning, swap with previous
            if (i > 0) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1;  // new index after transposition
            }
            // element at index 0, nothing to swap
            return 0;
        }
    }
    // key not found
    return -1;
}



/* 4. Passing parameters to the program
argc  - number of parameters (including program name)
argv  - array of C-strings: [0] = program name, [1] = flag, [2] = num1, [3] = num2
result - return sum or product
returns true - if all okey, false - if error
*/
bool processArgs(int argc, const char* argv[], int& result) {
    // checking number of arguments: program name + flag + 2 numbers
    if (argc < 4) {
        cout << "Error: too few parameters. Expected: nameProg -a|-m num1 num2\n";
        return false;
    }

    const char* flag = argv[1];

    // checking flag format: must be "-a" or "-m"
    // strncmp returns 0 if first 'count' chars are equal
    bool isAdd = (std::strncmp(flag, "-a", 2) == 0 && flag[2] == '\0');
    bool isMul = (std::strncmp(flag, "-m", 2) == 0 && flag[2] == '\0');

    if (!isAdd && !isMul) {
        cout << "Error: invalid flag. Use -a (sum) or -m (multiply).\n";
        return false;
    }

    // converting strings to integers
    int x = std::atoi(argv[2]);
    int y = std::atoi(argv[3]);

    // if flag is -a, computing sum; if -m, computing product
    if (isAdd) {
        result = x + y;
    } else { // isMul
        result = x * y;
    }

    return true;
}
