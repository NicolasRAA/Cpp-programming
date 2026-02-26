#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   // dlya system()

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Ports

// 1. poem in file
void writePoemToFile();

// 2. saving massives on file
void saveArraysToTextFile();
void selectionSort(int n, int arr[]);   // from zanyatua 5

int main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {
		//Menu
		cout << "\n===============Menu===============" << endl;
		cout << "1. Writing a short poem on a file\n";
		cout << "2. Saving original and sorted arrays to text file\n";
		cout << "Select an option: ";

		int choise;
		if (!(cin >> choise)) return 0;

		switch (choise) {

		// 1. 
		case 1: {
			writePoemToFile();
			return 0;
		}

		// 2. 
		case 2: {
            saveArraysToTextFile();
            return 0;
		}

		default: {
			cout << "\nInvalid option. Please select 1 or 2\n\n";
			break;
		}
		}
	}
}

// 1. Writing a short poem on a file
void writePoemToFile() {
    // after menu, there is a '\n' left in buffer
    // ignoring for correct getline
    cin.ignore(10000, '\n');

    string filename;
    cout << "\nEnter file name to save the poem (e.g.: poem.txt): ";
    cin >> filename;

    // ignoring newline after file name before getline
    cin.ignore(10000, '\n');

    std::ofstream out(filename);
    if (!out) {
        cout << "Error: cannot open file for writing\n";
        return;
    }

    cout << "Enter your poem line by line.\n";
    cout << "Enter an empty line to finish.\n\n";

    string line;
    while (true) {
        std::getline(cin, line);
        if (line.empty()) {
            // empty line = end of poem
            break;
        }
        out << line << '\n';  // writing each line to file
    }

    out.close();
    cout << "\nPoem has been written to file \"" << filename << "\".\n";

    // auto opening file
    string command = "notepad \"" + filename + "\"";
    std::system(command.c_str());
}

// 2. Saving original and sorted arrays to text file
// from zad 2 zanyatia 5
void selectionSort(int n, int arr[]) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;  // current minimum

        // finding index of real minimum in remaining part
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap if found smaller element
        if (minIndex != i) {
            int buf = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = buf;
        }
    }
}

// Function to save original and sorted arrays
void saveArraysToTextFile() {
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    // copy to keep the original values
    int original[N];
    for (int i = 0; i < N; ++i) {
        original[i] = a[i];
    }

    // sorting array "a" using selection sort
    selectionSort(N, a);

    // asking for file name
    std::string filename;
    cout << "\nEnter file name to save arrays (e.g.: arrays.txt): ";
    cin >> filename;

    std::ofstream out(filename);
    if (!out) {
        cout << "Error: cannot open file for writing\n";
        return;
    }

    // writing original array
    out << "Original array:\n";
    for (int i = 0; i < N; ++i) {
        out << original[i] << ' ';
    }
    out << "\n\n";

    // writing sorted array
    out << "Sorted array:\n";
    for (int i = 0; i < N; ++i) {
        out << a[i] << ' ';
    }
    out << '\n';

    out.close();

    cout << "\nArrays have been written to file \"" << filename << "\".\n";

    // auto open
    std::string command = "notepad \"" + filename + "\"";
    std::system(command.c_str());
}
