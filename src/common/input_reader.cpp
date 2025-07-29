#include "input_reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace utils {
std::string read_file(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
} // namespace utils
