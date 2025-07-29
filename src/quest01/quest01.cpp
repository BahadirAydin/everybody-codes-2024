#include "quest01.hpp"
#include "input_reader.hpp"
#include <numeric>
#include <unordered_map>

constexpr char EMPTY = 'x';

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

// NOTE: Odd numbered data size is not expected since in the scenario they come
// in pairs.
std::any quest_01::solve_p2() {
    int result = 0;

    // Precompute point values using a lookup table for ASCII characters
    static const std::array<int, 256> points_needed = [] {
        std::array<int, 256> table{};
        table['B'] = 1;
        table['C'] = 3;
        table['D'] = 5;
        return table;
    }();

    for (size_t i = 0; i + 1 < input_data.size(); i += 2) {
        char a = input_data[i];
        char b = input_data[i + 1];

        if (a == EMPTY && b == EMPTY) {
            continue;
        }

        if (a == EMPTY) {
            result += points_needed[b];
        } else if (b == EMPTY) {
            result += points_needed[a];
        } else {
            result += points_needed[a] + points_needed[b] + 2;
        }
    }
    return result;
}

std::any quest_01::solve_p3() {
    // !unimplemented
    return 0;
}

void quest_01::load_input(const std::string &filename) {
    input_data = utils::read_file(filename);
    if (input_data.empty()) {
        throw std::runtime_error("Failed to load input data from " + filename);
    }
}
