/* teacher.h(derived class from human) */
// Describes a teacher and the amount of working hours

#pragma once

#include "human.h"
#include <string>

class teacher : public human {
public:
    // Constructor
    teacher(const std::string& last_name,
        const std::string& first_name,
        const std::string& middle_name,
        unsigned int work_time_hours) // wrk hours
        : human(last_name, first_name, middle_name),
        work_time_(work_time_hours)
    {
    }

    // Geting number of working hours per semester
    unsigned int get_work_time() const
    {
        return work_time_;
    }

private:
    // Working hours per semester
    unsigned int work_time_;
};
