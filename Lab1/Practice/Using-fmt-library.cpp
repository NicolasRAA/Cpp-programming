#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING 1 // to stop treating warnings as error
// because of the depreciated version of fmt (7.0) from NuGet

// library for string and output formating
// alternative for printf and std::cout
#include <fmt/core.h> 
#include <fmt/chrono.h>
#include <string>
#include <iostream>
#include <chrono> // for time 

//using namespace std;
//using namespace fmt;

int main()
{
    int x = 41;
    const double pi = 3.1416;
    std::string name = "Alice";

    // Print with formating
    fmt::print("Hello, {}, the answer is {}!\n", name, x);
    fmt::print("Hello, {1}, the answer is {0}!\n", name, x); // places for variables on output

    fmt::print("Hex: {:#x}\n", x); // Hexadecimal number: 49 -> 29

    // lenght and position of the output
    fmt::print("|{:>10}|\n", 42); // right
    fmt::print("|{:<10}|\n", 42); // left
    fmt::print("|{:^10}|\n", 42); // center

    // fomaring with decimal point
    fmt::print("Fixed: {:.2f}\n", pi); // 2 decimals
    fmt::print("Scientific: {:.3e}\n", pi); // exponential format

    //using std (formating with no output)
    std::string s = fmt::format("Pi ~= {:.3f}", pi);
    fmt::print("{}\n", s);

    int number1 = 563;
    fmt::print("Dec: {} | Hex: {:#x} | Bi: {:#b}\n", number1, number1, number1);


    // output example for control process
    auto now = std::chrono::system_clock::now();
    //converting time to ti the old C type time_t because of the depreceated version of fmt
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    // %F = YYYY-MM-DD, %T = HH:MM:SS
    // localtime(t) turns time_t into a std::tm in local time (std::localtime)
    fmt::print("[{:%F %T}] [INFO]    Application started\n", fmt::localtime(t));
    fmt::print("[{:%F %T}] [WARNING] Low disk space\n", fmt::localtime(t));
    fmt::print("[{:%F %T}] [ERROR]   Failed to open file\n", fmt::localtime(t));

    return 0;
}