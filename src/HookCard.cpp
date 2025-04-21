#include "HookCard.h"
#include <iostream>

namespace dmd {

    HookCard::HookCard(int value)
        : Card(value, CardType::Hook) {
    }

    void HookCard::play(/*Game &game, Player &player*/) {
        // Logic to re-trigger the previous card will be handled in Game later
        std::cout << "[HookCard effect triggered - Repeat previous card’s effect]\n";
    }

    std::string HookCard::str() const {
        return "Hook (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
