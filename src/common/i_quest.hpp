#pragma once

#include <any>
#include <chrono>
#include <filesystem>
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
    // Solves part 3 and returns the result (any type)
    virtual std::any solve_p3() = 0;
    // Returns the name of the quest
    virtual std::string name() const = 0;
    // Loads input from a file
    virtual void load_input(const std::string &filename) = 0;
    // Runs and times both parts, prints result and time
    void run_with_timing() {
        using namespace std::chrono;
        namespace fs = std::filesystem;
        const std::string quest_name = name(); // e.g., "q01"
        const std::string p1_file =
            "everybody_codes_e2024_" + quest_name + "_p1.txt";
        const std::string p2_file =
            "everybody_codes_e2024_" + quest_name + "_p2.txt";
        const std::string p3_file =
            "everybody_codes_e2024_" + quest_name + "_p3.txt";
        std::cout << "Running quest: " << quest_name << "\n";
        if (fs::exists(p1_file)) {
            load_input(p1_file);
            auto start_1 = high_resolution_clock::now();
            auto result_1 = solve_p1();
            auto end_1 = high_resolution_clock::now();
            auto duration_1 = duration_cast<microseconds>(end_1 - start_1);
            print_result(result_1, "part_1", duration_1);
        } else {
            std::cout << "Input file for part 1 not found: " << p1_file << "\n";
        }
        if (fs::exists(p2_file)) {
            load_input(p2_file);
            auto start_2 = high_resolution_clock::now();
            auto result_2 = solve_p2();
            auto end_2 = high_resolution_clock::now();
            auto duration_2 = duration_cast<microseconds>(end_2 - start_2);
            print_result(result_2, "part_2", duration_2);
        } else {
            std::cout << "Input file for part 2 not found: " << p2_file << "\n";
        }
        if (fs::exists(p3_file)) {
            load_input(p3_file);
            auto start_3 = high_resolution_clock::now();
            auto result_3 = solve_p3();
            auto end_3 = high_resolution_clock::now();
            auto duration_3 = duration_cast<microseconds>(end_3 - start_3);
            print_result(result_3, "part_3", duration_3);
        } else {
            std::cout << "Input file for part 3 not found: " << p3_file << "\n";
        }
    }

  private:
    void print_result(const std::any &result, const std::string &label,
                      std::chrono::microseconds duration) const {
        std::cout << label << " solved in " << duration.count() << " μs"
                  << ", result: ";
        if (result.type() == typeid(int)) {
            std::cout << std::any_cast<int>(result);
        } else if (result.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(result);
        } else if (result.type() == typeid(uint32_t)) {
            std::cout << std::any_cast<uint32_t>(result);
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
