#include "quest02.hpp"
#include "input_reader.hpp"

namespace {
std::string remove_punctuation(const std::string &word) {
    std::string clean_word;
    for (char ch : word) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            clean_word += ch;
        }
    }
    return clean_word;
}
} // namespace

std::any quest_02::solve_p1() {
    uint32_t result = 0;
    return result;
}

std::any quest_02::solve_p2() {
    uint32_t result = 0;
    return result;
}

std::any quest_02::solve_p3() {
    uint32_t result = 0;
    return result;
}

void quest_02::load_input(const std::string &filename) {
    std::vector<std::string> input = utils::read_lines(filename);
    size_t pos = input[0].find("WORDS:");
    if (pos != std::string::npos) {
        std::string after_words = input[0].substr(pos + 6); // skip "WORDS:"
        std::stringstream ss(after_words);
        std::string token;
        while (std::getline(ss, token, ',')) {
            words.push_back(token);
        }
    }
    std::stringstream ss(input[2]);
    std::string w;
    while (ss >> w) {
        sentence.push_back(remove_punctuation(w));
    }
}
