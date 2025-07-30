#include "quest01.hpp"
#include "input_reader.hpp"
#include <numeric>
#include <unordered_map>

constexpr char EMPTY = 'x';

namespace {
const std::array<uint32_t, 256> points = [] {
    std::array<uint32_t, 256> table{};
    table[static_cast<uint8_t>('B')] = 1;
    table[static_cast<uint8_t>('C')] = 3;
    table[static_cast<uint8_t>('D')] = 5;
    return table;
}();
} // namespace

std::any quest_01::solve_p1() {
    int result = std::accumulate(
        input_data.begin(), input_data.end(), 0, [](uint32_t sum, char c) {
            return sum + points[static_cast<uint8_t>(c)];
        });
    return result;
}

std::any quest_01::solve_p2() {
    int result = 0;
    for (size_t i = 0; i + 1 < input_data.size(); i += 2) {
        result += calculate_potions_for_two_elements(input_data[i],
                                                     input_data[i + 1]);
    }
    return result;
}

std::any quest_01::solve_p3() {
    int result = 0;

    for (size_t i = 0; i + 2 < input_data.size(); i += 3) {
        const char a = input_data[i];
        const char b = input_data[i + 1];
        const char c = input_data[i + 2];

        if (a == EMPTY) {
            result += calculate_potions_for_two_elements(b, c);
        } else if (b == EMPTY) {
            result += calculate_potions_for_two_elements(a, c);
        } else if (c == EMPTY) {
            result += calculate_potions_for_two_elements(a, b);
        } else {
            result += points[static_cast<uint8_t>(a)] +
                      points[static_cast<uint8_t>(b)] +
                      points[static_cast<uint8_t>(c)] + 6;
        }
    }
    return result;
}

void quest_01::load_input(const std::string &filename) {
    input_data = utils::read_file(filename);
    if (input_data.empty()) {
        throw std::runtime_error("Failed to load input data from " + filename);
    }
}

inline uint32_t quest_01::calculate_potions_for_two_elements(char a,
                                                             char b) const {
    if (a == EMPTY && b == EMPTY) {
        return 0;
    }
    if (a == EMPTY) {
        return points[static_cast<uint8_t>(b)];
    }
    if (b == EMPTY) {
        return points[static_cast<uint8_t>(a)];
    }
    return points[static_cast<uint8_t>(a)] + points[static_cast<uint8_t>(b)] +
           2;
}
