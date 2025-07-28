#pragma once

#include <any>
#include <chrono>
#include <iostream>
#include <string>
#include <typeinfo>

class i_quest {
  public:
    virtual ~i_quest() = default;

    // Solves part 1 and returns the result (any type)
    virtual std::any solve_p1() = 0;

    // Solves part 2 and returns the result (any type)
    virtual std::any solve_p2() = 0;

    // Returns the name of the quest
    virtual std::string name() const = 0;

    // Loads input from a file
    virtual void load_input(const std::string &filename) = 0;

    // Runs and times both parts, prints result and time
    void run_with_timing() {
        using namespace std::chrono;

        load_input(
            "everybody_codes_e2024_q01_p1.txt"); // Load input data for part 1

        auto start_1 = high_resolution_clock::now();
        auto result_1 = solve_p1();
        auto end_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(end_1 - start_1);

        load_input(
            "everybody_codes_e2024_q01_p2.txt"); // Load input data for part 2
        auto start_2 = high_resolution_clock::now();
        auto result_2 = solve_p2();
        auto end_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(end_2 - start_2);

        print_result(result_1, "part_1", duration_1);
        print_result(result_2, "part_2", duration_2);
    }

  private:
    void print_result(const std::any &result, const std::string &label,
                      std::chrono::microseconds duration) {
        std::cout << name() << " - " << label << " solved in "
                  << duration.count() << " µs"
                  << ", result: ";

        if (result.type() == typeid(int)) {
            std::cout << std::any_cast<int>(result);
        } else if (result.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(result);
        } else if (result.type() == typeid(const char *)) {
            std::cout << std::any_cast<const char *>(result);
        } else if (result.type() == typeid(double)) {
            std::cout << std::any_cast<double>(result);
        } else if (result.type() == typeid(bool)) {
            std::cout << (std::any_cast<bool>(result) ? "true" : "false");
        } else {
            std::cout << "(unknown type)";
        }

        std::cout << '\n';
    }
};
