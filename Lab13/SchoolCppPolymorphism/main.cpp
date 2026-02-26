/* main.cpp(12 ex 2 & 3 + 13 ex 2 polymorphism) */
// Demonstrates polymorphism with human, student and teacher (n)

#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
    using std::cout;
    using std::endl;

    // (n) Preparing scores for a student
    std::vector<int> studentScores;
    studentScores.push_back(5);
    studentScores.push_back(3);
    studentScores.push_back(4);
    studentScores.push_back(4);
    studentScores.push_back(5);
    studentScores.push_back(3);
    studentScores.push_back(3);
    studentScores.push_back(3);

    // (n) Creating objects via base-class pointers (for polymorphism)
    human* person1 = new student("Petrov", "Ivan", "Alexeevich",
        studentScores);
    human* person2 = new teacher("Ivanov", "Petr", "Sergeevich",
        180);

    // (n) Storing all people in one collection of base pointers
    std::vector<human*> people;
    people.push_back(person1);
    people.push_back(person2);

    cout << "Polymorphic info about people:\n";

    // (n) Polymorphic call: the correct print_info() is chosen
    //     depending on the real type (student or teacher)
    for (const human* person : people) {
        person->print_info();  // virtual dispatch here
    }

    // (n) Cleaning up dynamically allocated objects
    for (human* person : people) {
        delete person;
    }

    return 0;
}
