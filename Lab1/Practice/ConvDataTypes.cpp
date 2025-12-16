#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // to write in russian
    cout.precision(3); // in C++ the decimals go up to 6
    // with this function they will go up to k numbers cout.precision(k)
    string name; // adding a name string
    cout << "Enter your name: \n"; // asking for the name
    double a, b;
    cout << "Введите a и b:\n";
    cin >> a; // saving value for a
    cin >> name; // saivng the name between a and b, for expample:
    //25Nico
    //56
    // The compilator knows what is the variable name, when he reaches a string, after passing the first double
    // The same if double (space) double, he knows which double addes to which variable (when no name)
    cin >> b; // saving value for b
    double x = a / b; // calculating the value of x
    cout << "\nx = " << x << endl; // output
    //cout << sizeof(a / b) << ends << sizeof(x) << endl; // calculating the ammount of used memory
    cout << sizeof(a / b) << " " << sizeof(x) << endl; // calculating the ammount of used memory "with spaces"
    //first is the bythes for a/b and second for x, double = 8, float = 4, int = 4, char = 1
    //int x => 84
    // double x => 88
    cout << "\nHello " << name << "!\n";

    return 0;

    // more about string formatin on c++ https://kvodo.ru/urok-10-formatirovannyiy-vvod-vyivod-v-c.html 
}

