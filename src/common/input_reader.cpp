#include "input_reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

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

std::vector<std::string> read_lines(const std::string &filepath) {
    std::ifstream file(filepath);
    std::vector<std::string> lines;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
} // namespace utils
