#include <iostream>
#include <string>

using namespace std; // for not to write std::count

int main()
{
    string name; // var for input
    cout << "What's your name?:";
    //cin >> name; // givin znachenie to the var | only first word in a sentence
    getline(cin, name); // saves a whole sentence
    cout << "Hello " << name << "!\n"; // using the var with znachenie for output

    return 0; // good practice
}


