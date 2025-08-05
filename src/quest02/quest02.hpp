#pragma once

#include "i_quest.hpp"
#include <string>

class quest_02 : public i_quest {
  public:
    std::any solve_p1() override;
    std::any solve_p2() override;
    std::any solve_p3() override;
    std::string name() const override { return "q02"; }
    void load_input(const std::string &filename) override;

  private:
    std::vector<std::string> words;
    std::vector<std::string> sentence;
};
