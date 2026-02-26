/* main.cpp(ex 2 & 3) */
// Testing the student class (derived from human)

#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
    using std::cout;
    using std::endl;

    // Testing student
    // Scores of student
    std::vector<int> scores;
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    // Creating a concrete student object on the heap
    student* stud = new student("Petrov", "Ivan", "Alexeevich", scores);

    // Full name comes from the base class human
    cout << "Student full name: " << stud->get_full_name() << endl;

    // Average score comes from the derived class student
    cout << "Average score: " << stud->get_average_score() << endl;


    // Testing teacher
    teacher t1("Ivanov", "Petr", "Sergeevich", 180);

    cout << "\nTeacher full name: " << t1.get_full_name() << endl;
    cout << "Teacher work hours per semester: "
        << t1.get_work_time() << endl;

    // Freeing allocated memory
    delete stud;

    return 0;
}
