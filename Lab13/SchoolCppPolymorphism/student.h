/* student.h(derived class from human) */
// Describes a student and stores his scores

#pragma once

#include "human.h"
#include <vector>
#include <iostream>   // (n) For print_info() in student

class student : public human {
public:
    // Constructor of student class
    student(const std::string& last_name,
        const std::string& first_name,
        const std::string& middle_name,
        const std::vector<int>& scores) // score's vector
        : human(last_name, first_name, middle_name),
        scores_(scores)
    {
    }

    // Calculate average score of student
    float get_average_score() const
    {
        // Total number of scores
        unsigned int count_scores =
            static_cast<unsigned int>(scores_.size());

        if (count_scores == 0) {
            // No scores -> average = 0.0
            return 0.0f;
        }

        // Sum of all scores
        unsigned int sum_scores = 0;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += scores_[i];
        }

        // Arithmetic mean (crednee)
        float average_score =
            static_cast<float>(sum_scores) /
            static_cast<float>(count_scores);

        return average_score;
    }

    // (n) Override of virtual method from human for polymorphic behavior
    void print_info() const override
    {
        std::cout << "Student: " << get_full_name()
            << ", average score = "
            << get_average_score()
            << std::endl;
    }

private:
    // All scores of the student
    std::vector<int> scores_;
};
