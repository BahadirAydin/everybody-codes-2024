#include "i_quest.hpp"
#include "quest01.hpp"
#include "quest02.hpp"

#include <memory>
#include <vector>

int main() {
    std::vector<std::unique_ptr<i_quest>> quests;
    quests.emplace_back(std::make_unique<quest_01>());
    quests.emplace_back(std::make_unique<quest_02>());

    for (const auto &quest : quests) {
        quest->run_with_timing();
    }

    return 0;
}
