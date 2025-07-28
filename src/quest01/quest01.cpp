#include "quest01.hpp"
#include "input_reader.hpp"
#include <numeric>

std::any quest_01::solve_p1() {
    int result = std::accumulate(input_data.begin(), input_data.end(), 0,
                                 [](int sum, char c) {
                                     switch (c) {
                                     case 'B':
                                         return sum + 1;
                                     case 'C':
                                         return sum + 3;
                                     default:
                                         return sum; // Ignore other characters
                                     }
                                 });
    return result;
}
std::any quest_01::solve_p2() {
    return 0; // unimplemented
}

void quest_01::load_input(const std::string &filename) {
    input_data = utils::read_file(filename);
    if (input_data.empty()) {
        throw std::runtime_error("Failed to load input data from " + filename);
    }
}
