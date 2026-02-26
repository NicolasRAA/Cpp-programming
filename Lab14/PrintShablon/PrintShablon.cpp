// template function Print for containers

#include <iostream>
#include <vector>
#include <list>
#include <string>

// Template prints all elements of container
// container - any container that supports range-based for
// separator - string printed between elements
template<typename Container>
void Print(const Container& container, const std::string& separator)
{
    using std::cout;

    bool first = true; // to control when to print separator

    // Range-based for over the container
    // Usштп const reference to avoid copying elements of container
    for (const auto& element : container) {
        if (!first) {
            cout << separator;  // print separator before every element except the first
        }
        cout << element;
        first = false;
    }

    cout << '\n'; // newline at the end
}

int main()
{
    using std::cout;
    using std::endl;

    // Ex 1: vector<int>
    std::vector<int> intData = { 1, 2, 3, 4 };
    cout << "Integers: ";
    Print(intData, ", ");      // Output: 1, 2, 3, 4

    // Ex 2: vector<std::string> 
    std::vector<std::string> words = { "hello", "world", "C++", "templates" };
    cout << "Strings: ";
    Print(words, " | ");       // Output: hello | world | C++ | templates

    // Ex 3: std::list<double>
    std::list<double> doubles = { 1.1, 2.2, 3.3 };
    cout << "Doubles: ";
    Print(doubles, " ; ");     // Output: 1.1 ; 2.2 ; 3.3

    return 0;
}
