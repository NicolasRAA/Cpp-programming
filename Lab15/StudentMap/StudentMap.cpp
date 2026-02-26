#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <cctype>

// key = student name, value = grade (char)
using GradeBook = std::map<std::string, char>;


// Utilities
// Flushing bad input and leftover characters
void clearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reading and validating grade as char
// Accepts: A B C D E F (case-insensitive) OR digits 5-1
char readGrade() {
    while (true) {
        std::cout << "Enter grade (A-F or 5-1): ";
        std::string s;
        std::getline(std::cin, s);

        if (s.size() == 1) {
            char g = s[0];
            // Normalizing to upper case for letters
            if (std::isalpha(static_cast<unsigned char>(g)))
                g = static_cast<char>(std::toupper(static_cast<unsigned char>(g)));

            bool okLetter = (g >= 'A' && g <= 'F');
            bool okDigit = (g >= '1' && g <= '5');
            if (okLetter || okDigit) return g;
        }
        std::cout << "Invalid grade. Please try again.\n";
    }
}

// Actions
// 1) Adding or updating student's grade
void addOrUpdateStudent(GradeBook& book) {
    std::cout << "Enter student name: ";
    std::string name;
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "Name cannot be empty.\n";
        return;
    }

    char grade = readGrade();

    // map::insert to check if not already a existing key
    auto [it, inserted] = book.insert({ name, grade });
    if (!inserted) {
        // Already existed -> update
        it->second = grade;
        std::cout << "Updated: " << name << " -> " << grade << "\n";
    }
    else {
        std::cout << "Added: " << name << " -> " << grade << "\n";
    }
}

// 2) Viewing all students and grades (sort by name ~ map is ordered)
void viewAll(const GradeBook& book) {
    if (book.empty()) {
        std::cout << "No students yet.\n";
        return;
    }
    std::cout << "Students and grades:\n";
    for (const auto& [name, grade] : book) {
        std::cout << "  " << name << " : " << grade << "\n";
    }
}

// 3) Finding specific student
void findStudent(const GradeBook& book) {
    std::cout << "Enter student name to search: ";
    std::string name;
    std::getline(std::cin, name);

    auto it = book.find(name);
    if (it == book.end()) {
        std::cout << "Student \"" << name << "\" not found.\n";
    }
    else {
        std::cout << "Found: " << it->first << " -> " << it->second << "\n";
    }
}

// 4) Removing a student
void removeStudent(GradeBook& book) {
    std::cout << "Enter student name to remove: ";
    std::string name;
    std::getline(std::cin, name);

    auto count = book.erase(name);
    if (count == 0) {
        std::cout << "No entry with name \"" << name << "\".\n";
    }
    else {
        std::cout << "Removed \"" << name << "\".\n";
    }
}

// Menu and user choices
int menu() {
    std::cout << "\n=== Grade Book Menu ===\n"
        << "1) Add / Update student\n"
        << "2) View all students\n"
        << "3) Find student\n"
        << "4) Remove student\n"
        << "5) Exit\n"
        << "Select: ";
    int choice;
    if (!(std::cin >> choice)) {
        clearInputLine();
        return -1; // invalid
    }
    clearInputLine(); // removing endline after the number
    return choice;
}

int main() {
    GradeBook book;
    while (true) {
        int choice = menu();
        switch (choice) {
        case 1: addOrUpdateStudent(book); break;
        case 2: viewAll(book); break;
        case 3: findStudent(book); break;
        case 4: removeStudent(book); break;
        case 5: std::cout << "Goodbye!\n"; return 0;
        default: std::cout << "Invalid option. Please try again.\n"; break;
        }
    }
}
