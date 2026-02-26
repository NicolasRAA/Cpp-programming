/* human.h(base class) */
// Describes a generic human: last, first and middle name

#pragma once

#include <string>
#include <sstream>
#include <iostream>   // (n) For print_info() output

class human {
public:
    // (n) Virtual destructor to delete via base pointer safely
    virtual ~human() {}

    // Constructor of the human class
    human(const std::string& last_name,
        const std::string& first_name,
        const std::string& middle_name)
        : last_name_(last_name),
        first_name_(first_name),
        middle_name_(middle_name)
    {
    }

    // Returning full name as "Last First Middle"
    std::string get_full_name() const
    {
        std::ostringstream full_name;
        full_name << last_name_ << " "
            << first_name_ << " "
            << middle_name_;
        return full_name.str();
    }

    // (n) Virtual method for polymorphic printing of information
    virtual void print_info() const
    {
        std::cout << "Human: " << get_full_name() << std::endl;
    }

private:
    // Person's first name
    std::string first_name_;
    // Person's last name
    std::string last_name_;
    // Person's middle name / patronymic
    std::string middle_name_;
};
