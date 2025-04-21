#include "SwordCard.h"
#include <iostream>

namespace dmd {

    SwordCard::SwordCard(int value)
        : Card(value, CardType::Sword) {
    }

    void SwordCard::play(/*Game &game, Player &player*/) {
        // Logic to steal a card would go here
        // We'll implement this properly when we wire up Game and Player later
        std::cout << "[SwordCard effect triggered - Steal from opponent]\n";
    }

    std::string SwordCard::str() const {
        return "Sword (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
