#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <concepts>

// Concept: type must support both < and > returning bool
template <typename T>
concept Sortable = requires(const T & a, const T & b) {
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
};

// Template checks if container is sorted in non-decreasing order
// Require: container must have value_type and begin()/end()
template <typename Container>
    requires Sortable<typename Container::value_type>
bool is_sorted(const Container& cont)
{
    // Empty or single-element container - always sorted
    if (cont.begin() == cont.end()) {
        return true;
    }

    auto prev = cont.begin();
    auto it = prev;
    ++it;

    // Checking each next element is not smaller than the previous one
    for (; it != cont.end(); ++it, ++prev) {
        if (*it < *prev) {  // not sorted in ascending order
            return false;
        }
    }
    return true;
}

// Helper function to print container
template <typename T>
void print_vector(const std::vector<T>& v, const std::string& label)
{
    std::cout << label << ": ";
    for (const auto& x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main()
{
    using std::cout;
    using std::endl;

    // vector<int>
    std::vector<int> vi_sorted{ 1, 2, 3, 4, 5 };
    std::vector<int> vi_unsorted{ 3, 1, 4, 2, 5 };

    print_vector(vi_sorted, "vi_sorted");
    print_vector(vi_unsorted, "vi_unsorted");

    cout << "vi_sorted   is_sorted?   "
        << (is_sorted(vi_sorted) ? "true" : "false") << endl;
    cout << "vi_unsorted is_sorted?   "
        << (is_sorted(vi_unsorted) ? "true" : "false") << endl;

    // vec string
    std::vector<std::string> vs_sorted{ "Alice", "Bob", "Charlie" };
    std::vector<std::string> vs_unsorted{ "Bob", "Alice", "Charlie" };

    print_vector(vs_sorted, "vs_sorted");
    print_vector(vs_unsorted, "vs_unsorted");

    cout << "vs_sorted   is_sorted?   "
        << (is_sorted(vs_sorted) ? "true" : "false") << endl;
    cout << "vs_unsorted is_sorted?   "
        << (is_sorted(vs_unsorted) ? "true" : "false") << endl;

    // non-sortable type (complex numbers)
    /*
    std::vector<std::complex<double>> vc{
        {1.0, 2.0},
        {0.5, 0.5}
    };
    bool c_sorted = is_sorted(vc);  // <- compile-time error
    */
    return 0;
}
