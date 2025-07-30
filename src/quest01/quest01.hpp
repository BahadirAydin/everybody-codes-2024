#pragma once

#include "i_quest.hpp"
#include <string>

class quest_01 : public i_quest {
  public:
    std::any solve_p1() override;
    std::any solve_p2() override;
    std::any solve_p3() override;
    std::string name() const override { return "quest_01"; }
    void load_input(const std::string &filename) override;

  private:
    inline uint32_t calculate_potions_for_two_elements(char a, char b) const;
    std::string input_data;
};
