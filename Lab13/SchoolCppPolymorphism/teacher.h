/* teacher.h(derived class from human) */
// Describes a teacher and the amount of working hours

#pragma once

#include "human.h"
#include <string>
#include <iostream>   // (n) 

class teacher : public human {
public:
    // Constructor
    teacher(const std::string& last_name,
        const std::string& first_name,
        const std::string& middle_name,
        unsigned int work_time_hours) // work hours
        : human(last_name, first_name, middle_name),
        work_time_(work_time_hours)
    {
    }

    // Getting number of working hours per semester
    unsigned int get_work_time() const
    {
        return work_time_;
    }

    // (n) Override of virtual method from human
    void print_info() const override
    {
        std::cout << "Teacher: " << get_full_name()
            << ", work hours per semester = "
            << get_work_time()
            << std::endl;
    }

private:
    // Working hours per semester
    unsigned int work_time_;
};
