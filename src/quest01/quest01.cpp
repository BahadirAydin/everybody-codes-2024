#include "quest01.hpp"
#include "input_reader.hpp"
#include <numeric>

std::any quest_01::solve_p1() {
    static const std::array<int, 256> points = [] {
        std::array<int, 256> table{};
        table['B'] = 1; // B is worth 1 point
        table['C'] = 3; // C is worth 3 points
                        // No D character in this part of the quest
        return table;
    }();
    int result = std::accumulate(
        input_data.begin(), input_data.end(), 0, [](int sum, char c) {
            return sum + points[static_cast<unsigned char>(c)];
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
