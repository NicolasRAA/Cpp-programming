/* main.cpp */
// template to compute array average

#include <iostream>

// T - type of array elements (int, long, double, char, i t.d.)
// Returning double to keep fractional part when needed
template<typename T>
double arrayAverage(const T arr[], int size)
{
    // Simple safety check
    if (size <= 0) {
        return 0.0; // empty array -> average is 0.0
    }

    // Using double accumulator to avoid overflow / integer division issues
    double sum = 0.0;

    for (int i = 0; i < size; ++i) {
        sum += static_cast<double>(arr[i]); // converting each element to double
    }

    // Computing arithmetic mean (average)
    double average = sum / static_cast<double>(size);
    return average;
}

int main()
{
    using std::cout;
    using std::endl;

    // int array
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intSize = static_cast<int>(sizeof(intArray) / sizeof(intArray[0]));
    double intAvg = arrayAverage(intArray, intSize);
    cout << "Average of intArray: " << intAvg << endl;

    // long array
    long longArray[] = { 100L, 200L, 300L, 400L };
    int longSize = static_cast<int>(sizeof(longArray) / sizeof(longArray[0]));
    double longAvg = arrayAverage(longArray, longSize);
    cout << "Average of longArray: " << longAvg << endl;

    // double array
    double doubleArray[] = { 1.5, 2.5, 3.5 };
    int doubleSize = static_cast<int>(sizeof(doubleArray) / sizeof(doubleArray[0]));
    double doubleAvg = arrayAverage(doubleArray, doubleSize);
    cout << "Average of doubleArray: " << doubleAvg << endl;

    // char array
    // Characters treated as numbers by their ASCII codes
    char charArray[] = { 'A', 'B', 'C' }; // 65, 66, 67
    int charSize = static_cast<int>(sizeof(charArray) / sizeof(charArray[0]));
    double charAvg = arrayAverage(charArray, charSize);
    cout << "Average of charArray (by ASCII codes): " << charAvg << endl;

    return 0;
}
