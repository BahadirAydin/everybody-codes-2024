#pragma once

#include <string>
#include <vector>

namespace utils {

std::string read_file(const std::string &filepath);
std::vector<std::string> read_lines(const std::string &filepath);
std::vector<std::string> split(const std::string &s, char delim);

} // namespace utils
