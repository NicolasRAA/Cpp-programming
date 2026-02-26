#include <iostream>
#include <vector>
#include <algorithm>   // std::for_each
#include <stdexcept>   // std::runtime_error

// If no even numbers -> std::runtime_error
int FindMaxEven(const std::vector<int>& numbers)
{
    bool hasEven = false;  // flag: seen at least 1 evennum
    int maxEven = 0;       // current maximum even num

    // Using STL algorithm with lambda to process all elements
    std::for_each(numbers.begin(), numbers.end(),
        [&hasEven, &maxEven](int value)
        {
            // Checking if number even
            if (value % 2 == 0) {
                // If first even number, or it larger than current max
                if (!hasEven || value > maxEven) {
                    maxEven = value;
                    hasEven = true;
                }
            }
        });

    // If never found even number -> exception
    if (!hasEven) {
        throw std::runtime_error("No even numbers in the vector");
    }

    return maxEven;
}

int main()
{
    using std::cout;
    using std::endl;

    // Test 1: normal case, even nums
    std::vector<int> v1{ 1, 2, 7, 4, 9, 10 };

    try {
        int maxEven1 = FindMaxEven(v1);
        cout << "Test 1: vector {1, 2, 7, 4, 9, 10}\n";
        cout << "Largest even number = " << maxEven1 << endl;
    }
    catch (const std::runtime_error& e) {
        cout << "Test 1 error: " << e.what() << endl;
    }

    cout << "-----------------------------\n";

    // Test 2: no even nums
    std::vector<int> v2{ 5, 3, 1, 9 };

    try {
        int maxEven2 = FindMaxEven(v2);
        cout << "Test 2: vector {5, 3, 1, 9}\n";
        cout << "Largest even number = " << maxEven2 << endl;
    }
    catch (const std::runtime_error& e) {
        cout << "Test 2: vector {5, 3, 1, 9}\n";
        cout << "Exception: " << e.what() << endl;
    }

    cout << "-----------------------------\n";

    // Test 3: negative even nums
    std::vector<int> v3{ -4, -2, -6, -3 };

    try {
        int maxEven3 = FindMaxEven(v3);
        cout << "Test 3: vector {-4, -2, -6, -3}\n";
        cout << "Largest even number = " << maxEven3 << endl;
    }
    catch (const std::runtime_error& e) {
        cout << "Test 3 error: " << e.what() << endl;
    }

    return 0;
}
