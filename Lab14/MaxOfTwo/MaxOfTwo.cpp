#include <iostream>
#include <concepts>

// conceptÑ type must support operator< returning bool
template <typename T>
concept Comparable = requires(const T & a, const T & b) {
    { a < b } -> std::convertible_to<bool>;
};

// Template returns maximum of two values
template <Comparable T>
T maxOfTwo(const T& a, const T& b)
{
    return (a < b) ? b : a;
}

// class with operator<
class Box {
private:
    double value_;   // stored numeric value

public:
    // Constructor with one parameter
    explicit Box(double value)
        : value_(value)
    {
    }

    // Getter for value
    double getValue() const
    {
        return value_;
    }

    // Operator< so Box can be used with Comparable
    bool operator<(const Box& other) const
    {
        return value_ < other.value_;
    }
};

int main()
{
    using std::cout;
    using std::endl;

    // --- Test with int ---
    int a = 5;
    int b = 10;
    int maxInt = maxOfTwo(a, b);
    cout << "maxOfTwo(int):   max(" << a << ", " << b << ") = "
        << maxInt << endl;

    // --- Test with double ---
    double x = 1.5;
    double y = 0.3;
    double maxDouble = maxOfTwo(x, y);
    cout << "maxOfTwo(double): max(" << x << ", " << y << ") = "
        << maxDouble << endl;

    // --- Test with user-defined class Box ---
    Box box1(3.14);
    Box box2(2.71);
    Box maxBox = maxOfTwo(box1, box2);
    cout << "maxOfTwo(Box):   max(" << box1.getValue()
        << ", " << box2.getValue() << ") = "
        << maxBox.getValue() << endl;

    return 0;
}
