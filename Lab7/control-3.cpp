#include <iostream>
#include <cmath>
#include <tuple> 

using std::cin;
using std::cout;
using std::endl;
using std::tuple;

// Structs

// 1. Time structure for hours, minutes and seconds
struct Time {
    int hours;
    int minutes;
    int seconds;

    // converting whole time to total seconds
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // creatinh normalized Time from total seconds
    static Time fromSeconds(int totalSeconds) {
        if (totalSeconds < 0) totalSeconds = 0;

        Time t;
        t.hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        t.minutes = totalSeconds / 60;
        t.seconds = totalSeconds % 60;
        return t;
    }

    // addition of two time intervals
    Time add(const Time& other) const {
        int total = this->toSeconds() + other.toSeconds();
        return fromSeconds(total);
    }

    // subtraction of two time intervals (absolute difference)
    Time subtract(const Time& other) const {
        int diff = this->toSeconds() - other.toSeconds();
        if (diff < 0) diff = -diff;  // natural non-negative interval
        return fromSeconds(diff);
    }

    // cout time in h m s format
    void show() const {
        cout << hours << "h " << minutes << "m " << seconds << "s";
    }
};

// 2. Structure for storing roots of quadratic equation
struct QuadSolution {
    double x1;
    double x2;
};



// Prots

// 1. Time structure
void timeTask();
Time inputTime();
void showTimeWithSeconds(const Time& t);

// 2. Quad eq with structs
void quadraticTask();
QuadSolution solveQuadratic(double a, double b, double c);
void printQuadraticSolution(const QuadSolution& s);

// 2. Quad eq with tuples
void quadraticTupleTask();
tuple<double, double, bool> solveQuadraticTuple(double a, double b, double c);
void printQuadraticTuple(const tuple<double, double, bool>& t);


int main() {
    setlocale(LC_ALL, "Russian");

    for (;;) {
        //Menu
        cout << "\n===============Menu===============" << endl;
        cout << "1. Time structure (input, seconds, sum and difference)\n";
        cout << "2. Solving quadratic equation (using structs)\n";
        cout << "3. Solving quadratic equation (using tuple)\n";
        cout << "Select an option: ";

        int choise;
        if (!(cin >> choise)) return 0;

        switch (choise) {

        // 1. Time structure (input, seconds, sum and difference)
        case 1: {
            timeTask();
            return 0;
        }

        // 2. Solving quadratic equation (using structs)
        case 2: {
            quadraticTask();
            return 0;
        }

        // 3. Solving quadratic equation (using tuple)
        case 3: {
            quadraticTupleTask();
            return 0;
        }

        default: {
            cout << "\nInvalid option. Please select 1-3\n\n";
            break;
        }
        }
    }
}



// 1. Time structure (input, seconds, sum and difference)

// func call with other funcs for solution
void timeTask() {
    cout << "\n=== Time structure demo ===\n\n";

    cout << "\nEnter first time interval:\n";
    Time t1 = inputTime();

    cout << "\nEnter second time interval:\n";
    Time t2 = inputTime();

    cout << "\nFirst time: ";
    showTimeWithSeconds(t1);

    cout << "\nSecond time: ";
    showTimeWithSeconds(t2);

    // sum and difference of intervals
    Time sum = t1.add(t2);
    Time diff = t1.subtract(t2);

    cout << "\n\nSum of intervals: ";
    showTimeWithSeconds(sum);

    cout << "\nDifference of intervals (absolute): ";
    showTimeWithSeconds(diff);

    cout << endl;
}

// asking user for a valid Time value
Time inputTime() {
    Time t;

    // tolko natural values:
    // hours >= 0, minutes 0-59, seconds 0-59

    do {
        cout << "Hours (>= 0): ";
        cin >> t.hours;
    } while (t.hours < 0);

    do {
        cout << "Minutes (0-59): ";
        cin >> t.minutes;
    } while (t.minutes < 0 || t.minutes >= 60);

    do {
        cout << "Seconds (0-59): ";
        cin >> t.seconds;
    } while (t.seconds < 0 || t.seconds >= 60);

    return t;
}

// cout time and total number of seconds
void showTimeWithSeconds(const Time& t) {
    t.show();
    cout << "  (total seconds = " << t.toSeconds() << ")";
}


// 2. Solving quadratic equation(using structs)

// Main task logic
void quadraticTask() {
    cout << "\n=== Quadratic equation: ax^2 + bx + c = 0 ===\n\n";

    double a, b, c;

    cout << "Enter coefficient a (!= 0): ";
    cin >> a;
    while (a == 0.0) {   // simple check so it is really quadratic
        cout << "a must not be zero! Enter again: ";
        cin >> a;
    }

    cout << "Enter coefficient b: ";
    cin >> b;

    cout << "Enter coefficient c: ";
    cin >> c;

    QuadSolution roots = solveQuadratic(a, b, c);
    printQuadraticSolution(roots);
}

// Solving equation and returning roots in struct
QuadSolution solveQuadratic(double a, double b, double c) {
    QuadSolution res{};
    double D = b * b - 4 * a * c;   // discriminant

    if (D < 0) {
        // no real roots – keeping both roots as 0 and print message
        cout << "No real roots (discriminant < 0)\n";
        res.x1 = 0.0;
        res.x2 = 0.0;
    }
    else if (D == 0.0) {
        // one real root (double root)
        double x = -b / (2 * a);
        res.x1 = x;
        res.x2 = x;
    }
    else {
        // two different real roots
        double sqrtD = std::sqrt(D);
        res.x1 = (-b + sqrtD) / (2 * a);
        res.x2 = (-b - sqrtD) / (2 * a);
    }

    return res; // returningstruct with both roots
}

// Cout the roots stored in QuadSolution
void printQuadraticSolution(const QuadSolution& s) {
    cout << "Roots of the equation:\n";
    cout << "x1 = " << s.x1 << "\n";
    cout << "x2 = " << s.x2 << "\n";
}


// 3. Solving quadratic equation (using tuple)

// Main logic
void quadraticTupleTask() {
    cout << "\n=== Quadratic equation (tuple version) ===\n\n";

    double a, b, c;

    cout << "Enter coefficient a (!= 0): ";
    cin >> a;
    while (a == 0.0) {
        cout << "a must not be zero! Enter again: ";
        cin >> a;
    }

    cout << "Enter coefficient b: ";
    cin >> b;

    cout << "Enter coefficient c: ";
    cin >> c;

    // solving and geting tuple (x1, x2, hasRoots)
    auto result = solveQuadraticTuple(a, b, c);

    // cout result
    printQuadraticTuple(result);
}

// Solving eq returning (x1, x2, hasRealRoots)
tuple<double, double, bool> solveQuadraticTuple(double a, double b, double c) {
    double D = b * b - 4 * a * c;  // discriminant

    if (D < 0.0) {
        // no real roots
        cout << "No real roots (discriminant < 0).\n";
        return std::make_tuple(0.0, 0.0, false);
    }
    else if (D == 0.0) {
        // one real (double) root
        double x = -b / (2 * a);
        return std::make_tuple(x, x, true);
    }
    else {
        // two distinct real roots
        double sqrtD = std::sqrt(D);
        double x1 = (-b + sqrtD) / (2 * a);
        double x2 = (-b - sqrtD) / (2 * a);
        return std::make_tuple(x1, x2, true);
    }
}


// Cout roots stored in tuple (x1, x2, flag)
void printQuadraticTuple(const tuple<double, double, bool>& t) {
    bool hasRoots = std::get<2>(t);

    if (!hasRoots) {
        cout << "No real roots to print.\n";
    }
    else {
        cout << "Roots of the equation:\n";
        cout << "x1 = " << std::get<0>(t) << "\n";
        cout << "x2 = " << std::get<1>(t) << "\n";
    }
}


